#include "commodity.h"

/********************
 * 打印表头
 ********************/
void showTable(void)
{
	printf("\n");
	printf("\t=======================================================================\n");
	printf("\t编号\t名称\t生产地");
	printf("\t单价\t销售总量\t销售总金额\t库存量\n");
	printf("\t-----------------------------------------------------------------------\n");
}


/***********************
 * 回退操作
 ***********************/
void back(void)
{
	char c;
	printf("\n\t\t按回车则退回到菜单选择");
	c = getch();
	if (c == '\r')
	{
		system("CLS");
		return;
	}
}

/***********************
 * 显示所有的商品信息
 ***********************/
void display(void)
{
	int i;
	system("CLS");
	if (numComs == 0)
	{
		printf("\n\t\t没有可供显示的记录!\n");
		back();
		return;
	}

	showTable();//打印表头
	for (i = 0; i < numComs; i++)
	{
		// 打印商品记录的信息
		printf("\n");
		printf("\t%s\t%s\t%s", records[i].number, records[i].name,
			records[i].place);
		printf("\t%.1f\t%d\t\t%.1f\t\t%d\n", records[i].price, records[i].sellnum,
			records[i].sum, records[i].inventory);

		// 打印满20个记录后停下来
		if (i % 20 == 0 && i != 0)//如果i整除20且不是0则显示停下来
		{
			printf("\n\t输入任意字符后继续...\n");
			getch();
			printf("\n\n");
			showTable();
		}
	}
	printf("\t=======================================================================\n");
	back();
}

/*************************************
 * 在当前表的末尾增加新的信息
 * 结果：records中将记录新的信息，如
 * 果数组大小不够，会重新申请数组空间
 *************************************/
void addRecord(void)
{
	char str[10];
	int i;
	float price;
	int sellnum, inventory;


	system("CLS");
	if (numComs == 0)
		printf("\n\t原来没有记录，现在建立新表\n");
	else
		printf("\n\t下面在当前表的末尾增加新的信息\n");

	while (1)//()中为1表示无条件反复循环
	{
		printf("\n\t您将要添加一组信息，确定吗？(Y/N)");
		gets(str);

		if (str[0] == 'n' || str[0] == 'N') //不再添加新的信息
			break;

		if (numComs >= arraySize) //现在的数组空间不足，需要重新申请空间
		{
			records = realloc(records, (arraySize + INCR_SIZE) * sizeof(ComInfo));
			//新空间大小变为(arraySize+INCR_SIZE)记录大小,
			//即在原来基础上增加INCR_SIZE个记录大小
			if (records == NULL)
			{
				printf("memory failed!");
				exit(-1);
			}
			arraySize = arraySize + INCR_SIZE;
			//arraySize修改为新空间可保存的记录数
		}

		printf("\t\t**********************\n");
	p:printf("\t\t编号：");
		gets(records[numComs].number);
		i = findRecord(records[numComs].number, 0, 0);
		if (i != -1)
		{
			printf("\t\t-----------------------\n");
			printf("\t\t编号已存在，请重新输入!\n");
			printf("\t\t***********************\n");
			goto p;
		}
		//因为编号不能重复，所以有且只能找到一条编号重复的记录

		printf("\t\t名称：");
		gets(records[numComs].name);
		printf("\t\t生产地：");
		gets(records[numComs].place);
		printf("\t\t单价：");
		gets(str);
		price = (float)atof(str);
		printf("\t\t当前销售总量：");
		gets(str);
		sellnum = (int)atoi(str);
		printf("\t\t库存量：");
		gets(str);
		inventory = (int)atoi(str);
		printf("\t\t**********************\n\n");

		records[numComs].price = price;
		records[numComs].sellnum = sellnum;
		records[numComs].inventory = inventory;
		records[numComs].sum = records[numComs].price * records[numComs].sellnum;

		numComs++; //输入一个商品记录后,商品数加1
	}

	printf("\n\t现在一共有%d条信息\n", numComs);
	savedTag = 1;//输入一个新的商品后,信息保存标志为1,表示未保存

	printf("\n\t是否保存记录？(Y/N)");
	gets(str);
	if (str[0] == 'y' || str[0] == 'Y')
		saveRecords();
	else
		back();
}