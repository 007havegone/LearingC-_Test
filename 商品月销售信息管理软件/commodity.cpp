#include "commodity.h"

/**************************
 * 初始化
 **************************/
int numComs = 0;	        //记录的商品数
ComInfo *records = NULL;	//记录商品信息的数组
char savedTag = 0;	//信息是否已保存的标志，1为未保存，0为已保存
int arraySize;	    //数组大小
int count = 0;  //记录输入用户名或密码错误的次数

/**************************
 * 主函数
 **************************/
int main()
{
	system("color 3F");//设置控制台的背景和字体颜色
	//初始化数组
	records = (ComInfo*)malloc(sizeof(ComInfo)*INITIAL_SIZE);
	//给数组ComInfo分配INITIAL_SIZE个记录空间大小
	if (records == NULL)
	{
		printf("memory fail!");
		exit(-1);
	}//如果内存空间不够分配,退出程序

	arraySize = INITIAL_SIZE;

	printf("\n");
	printf("\t\t   ------------------------------------\n");
	printf("\t\t   * *         ●欢迎使用●         * *\n");
	printf("\t\t   * *    商品月销售信息管理系统    * *\n");
	printf("\t\t   ------------------------------------\n");
	printf("\n");
	printf("\t\t   ************************************\n");
	printf("\t\t   * ******************************** *\n");
	printf("\t\t   * *    班级：2016软件工程1班     * *\n");
	printf("\t\t   * *    ---------------------     * *\n");
	printf("\t\t   * *    设计者：郭瑞英            * *\n");
	printf("\t\t   * *    ---------------------     * *\n");
	printf("\t\t   * *    学号：16251104111         * *\n");
	printf("\t\t   * *    ---------------------     * *\n");
	printf("\t\t   * *    指导老师：胡玉平          * *\n");
	printf("\t\t   * ******************************** *\n");
	printf("\t\t   ************************************\n");
	printf("\t\t          **                  **       \n");
	printf("\t\t          **                  **       \n");
	printf("\t\t   ************************************\n");
	printf("\t\t  * ################################## *\n");
	printf("\t\t * #################################### *\n");
	printf("\t\t******************************************\n");
	printf("\t\t******************************************\n");
	printf("\n");

	login();
	printf("\n\n\t\t恭喜您登录成功,正在进入系统");
	delay();
	system("CLS"); //清屏函数
	handle_menu();
}

/****************************
 * 延时程序 delay
 ****************************/
void delay(void)
{
	int i;
	for (i = 0; i < 15; i++)
	{
		printf(".");
		Sleep(80);
	}
	return;
}

/****************************
 * 登录及验证函数 login
 ****************************/
void login(void)
{
	char user[8], pw[8];
	char c;
	int i = 0;

	while (1)
	{
		printf("\t\t\t请输入用户名:");
		gets(user);
		printf("\n");
		printf("\t\t\t请输入密码:");
		while ((c = getch()) != '\r')//'\r':回车
		{
			pw[i++] = c;
			printf("*");
		}
		pw[i] = '\0';//'\0':空字符，即字符串结束标志

		//strcmp函数:比较两个字符串的大小,返回比较的结果
		if (strcmp(user, "gry") == 0 && strcmp(pw, "4111") == 0)
			break; //退出本次循环
		else
		{
			i = 0; //保证下次输入密码时，数组pw是空的
			count++;
			if (count < 3)
				printf("\n\n\t\t用户名或密码错误，登录失败，请重新输入!\n\n");
			if (count == 3)
			{
				printf("\n\n\t\t用户名或密码错误已达3次，系统自动退出!\n\n");
				exit(0); //正常退出系统
			}
		}
	}
}

/**************************
 * 菜单处理函数
 **************************/
void handle_menu(void)
{
	for (; ; ) {
		switch (menu_select())
		{
		case 1:
			display();
			break;
		case 2:
			addRecord();
			break;
		case 3:
			sale_Commodity();
			break;
		case 4:
			stock_Commodity();
			break;
		case 5:
			queryInfo();
			break;
		case 6:
			statistics();
			break;
		case 7:
			modifyRecord();
			break;
		case 8:
			deleteRecord();
			break;
		case 9:
			saveRecords();
			break;
		case 10:
			readRecords();
			break;
		case 11:
			quit();
		}
	}
}

/****************************
 * 菜单选择函数menu_selected
 ****************************/
int menu_select()
{
	char s[2];
	int cn = 0;

	printf("\n");
	printf("\t\t************************************************\n");
	printf("\t\t*           商品月销售信息管理软件             *\n");
	printf("\t\t************************************************\n");
	printf("\t\t*                 『主菜单』                   *\n");
	printf("\t\t************************************************\n");
	printf("\t\t*                                              *\n");
	printf("\t\t*   1. 显示商品记录   ※   2. 增加商品记录     *\n");
	printf("\t\t*----------------------------------------------*\n");
	printf("\t\t*   3. 售出商品       ※   4. 购进商品         *\n");
	printf("\t\t*----------------------------------------------*\n");
	printf("\t\t*   5. 查找商品信息   ※   6. 统计最大总金额   *\n");
	printf("\t\t*----------------------------------------------*\n");
	printf("\t\t*   7. 修改商品记录   ※   8. 删除商品记录     *\n");
	printf("\t\t*----------------------------------------------*\n");
	printf("\t\t*   9. 保存商品记录   ※  10. 读取商品记录     *\n");
	printf("\t\t*----------------------------------------------*\n");
	printf("\t\t*              11. 退出系统                    *\n");
	printf("\t\t*                                              *\n");
	printf("\t\t************************************************\n");
	printf("\n\t\t请选择1-11 ");

	for (; ;)
	{
		gets(s);
		cn = atoi(s); //将字符串转换成整数(int)
		if (cn < 1 || cn>11)
			printf("\n\t输入错误，重选1-11 ");
		else break;
	}
	return cn;
}

/********************
*结束运行，退出
*参数量void
*********************/
void quit(void)
{
	char str[5];
	if (savedTag == 1)
	{
		printf("\n\t是否保存原来的记录？（Y/N）");
		gets(str);

		if (str[0] != 'n' && str[0] != 'N')
			saveRecords();
	}
	free(records);
	exit(0);
}