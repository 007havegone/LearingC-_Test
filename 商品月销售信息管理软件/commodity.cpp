#include "commodity.h"

/**************************
 * ��ʼ��
 **************************/
int numComs = 0;	        //��¼����Ʒ��
ComInfo *records = NULL;	//��¼��Ʒ��Ϣ������
char savedTag = 0;	//��Ϣ�Ƿ��ѱ���ı�־��1Ϊδ���棬0Ϊ�ѱ���
int arraySize;	    //�����С
int count = 0;  //��¼�����û������������Ĵ���

/**************************
 * ������
 **************************/
int main()
{
	system("color 3F");//���ÿ���̨�ı�����������ɫ
	//��ʼ������
	records = (ComInfo*)malloc(sizeof(ComInfo)*INITIAL_SIZE);
	//������ComInfo����INITIAL_SIZE����¼�ռ��С
	if (records == NULL)
	{
		printf("memory fail!");
		exit(-1);
	}//����ڴ�ռ䲻������,�˳�����

	arraySize = INITIAL_SIZE;

	printf("\n");
	printf("\t\t   ------------------------------------\n");
	printf("\t\t   * *         ��ӭʹ�á�         * *\n");
	printf("\t\t   * *    ��Ʒ��������Ϣ����ϵͳ    * *\n");
	printf("\t\t   ------------------------------------\n");
	printf("\n");
	printf("\t\t   ************************************\n");
	printf("\t\t   * ******************************** *\n");
	printf("\t\t   * *    �༶��2016�������1��     * *\n");
	printf("\t\t   * *    ---------------------     * *\n");
	printf("\t\t   * *    ����ߣ�����Ӣ            * *\n");
	printf("\t\t   * *    ---------------------     * *\n");
	printf("\t\t   * *    ѧ�ţ�16251104111         * *\n");
	printf("\t\t   * *    ---------------------     * *\n");
	printf("\t\t   * *    ָ����ʦ������ƽ          * *\n");
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
	printf("\n\n\t\t��ϲ����¼�ɹ�,���ڽ���ϵͳ");
	delay();
	system("CLS"); //��������
	handle_menu();
}

/****************************
 * ��ʱ���� delay
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
 * ��¼����֤���� login
 ****************************/
void login(void)
{
	char user[8], pw[8];
	char c;
	int i = 0;

	while (1)
	{
		printf("\t\t\t�������û���:");
		gets(user);
		printf("\n");
		printf("\t\t\t����������:");
		while ((c = getch()) != '\r')//'\r':�س�
		{
			pw[i++] = c;
			printf("*");
		}
		pw[i] = '\0';//'\0':���ַ������ַ���������־

		//strcmp����:�Ƚ������ַ����Ĵ�С,���رȽϵĽ��
		if (strcmp(user, "gry") == 0 && strcmp(pw, "4111") == 0)
			break; //�˳�����ѭ��
		else
		{
			i = 0; //��֤�´���������ʱ������pw�ǿյ�
			count++;
			if (count < 3)
				printf("\n\n\t\t�û�����������󣬵�¼ʧ�ܣ�����������!\n\n");
			if (count == 3)
			{
				printf("\n\n\t\t�û�������������Ѵ�3�Σ�ϵͳ�Զ��˳�!\n\n");
				exit(0); //�����˳�ϵͳ
			}
		}
	}
}

/**************************
 * �˵�������
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
 * �˵�ѡ����menu_selected
 ****************************/
int menu_select()
{
	char s[2];
	int cn = 0;

	printf("\n");
	printf("\t\t************************************************\n");
	printf("\t\t*           ��Ʒ��������Ϣ�������             *\n");
	printf("\t\t************************************************\n");
	printf("\t\t*                 �����˵���                   *\n");
	printf("\t\t************************************************\n");
	printf("\t\t*                                              *\n");
	printf("\t\t*   1. ��ʾ��Ʒ��¼   ��   2. ������Ʒ��¼     *\n");
	printf("\t\t*----------------------------------------------*\n");
	printf("\t\t*   3. �۳���Ʒ       ��   4. ������Ʒ         *\n");
	printf("\t\t*----------------------------------------------*\n");
	printf("\t\t*   5. ������Ʒ��Ϣ   ��   6. ͳ������ܽ��   *\n");
	printf("\t\t*----------------------------------------------*\n");
	printf("\t\t*   7. �޸���Ʒ��¼   ��   8. ɾ����Ʒ��¼     *\n");
	printf("\t\t*----------------------------------------------*\n");
	printf("\t\t*   9. ������Ʒ��¼   ��  10. ��ȡ��Ʒ��¼     *\n");
	printf("\t\t*----------------------------------------------*\n");
	printf("\t\t*              11. �˳�ϵͳ                    *\n");
	printf("\t\t*                                              *\n");
	printf("\t\t************************************************\n");
	printf("\n\t\t��ѡ��1-11 ");

	for (; ;)
	{
		gets(s);
		cn = atoi(s); //���ַ���ת��������(int)
		if (cn < 1 || cn>11)
			printf("\n\t���������ѡ1-11 ");
		else break;
	}
	return cn;
}

/********************
*�������У��˳�
*������void
*********************/
void quit(void)
{
	char str[5];
	if (savedTag == 1)
	{
		printf("\n\t�Ƿ񱣴�ԭ���ļ�¼����Y/N��");
		gets(str);

		if (str[0] != 'n' && str[0] != 'N')
			saveRecords();
	}
	free(records);
	exit(0);
}