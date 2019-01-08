#include "commodity.h"

/********************
 * ��ӡ��ͷ
 ********************/
void showTable(void)
{
	printf("\n");
	printf("\t=======================================================================\n");
	printf("\t���\t����\t������");
	printf("\t����\t��������\t�����ܽ��\t�����\n");
	printf("\t-----------------------------------------------------------------------\n");
}


/***********************
 * ���˲���
 ***********************/
void back(void)
{
	char c;
	printf("\n\t\t���س����˻ص��˵�ѡ��");
	c = getch();
	if (c == '\r')
	{
		system("CLS");
		return;
	}
}

/***********************
 * ��ʾ���е���Ʒ��Ϣ
 ***********************/
void display(void)
{
	int i;
	system("CLS");
	if (numComs == 0)
	{
		printf("\n\t\tû�пɹ���ʾ�ļ�¼!\n");
		back();
		return;
	}

	showTable();//��ӡ��ͷ
	for (i = 0; i < numComs; i++)
	{
		// ��ӡ��Ʒ��¼����Ϣ
		printf("\n");
		printf("\t%s\t%s\t%s", records[i].number, records[i].name,
			records[i].place);
		printf("\t%.1f\t%d\t\t%.1f\t\t%d\n", records[i].price, records[i].sellnum,
			records[i].sum, records[i].inventory);

		// ��ӡ��20����¼��ͣ����
		if (i % 20 == 0 && i != 0)//���i����20�Ҳ���0����ʾͣ����
		{
			printf("\n\t���������ַ������...\n");
			getch();
			printf("\n\n");
			showTable();
		}
	}
	printf("\t=======================================================================\n");
	back();
}

/*************************************
 * �ڵ�ǰ���ĩβ�����µ���Ϣ
 * �����records�н���¼�µ���Ϣ����
 * �������С��������������������ռ�
 *************************************/
void addRecord(void)
{
	char str[10];
	int i;
	float price;
	int sellnum, inventory;


	system("CLS");
	if (numComs == 0)
		printf("\n\tԭ��û�м�¼�����ڽ����±�\n");
	else
		printf("\n\t�����ڵ�ǰ���ĩβ�����µ���Ϣ\n");

	while (1)//()��Ϊ1��ʾ����������ѭ��
	{
		printf("\n\t����Ҫ���һ����Ϣ��ȷ����(Y/N)");
		gets(str);

		if (str[0] == 'n' || str[0] == 'N') //��������µ���Ϣ
			break;

		if (numComs >= arraySize) //���ڵ�����ռ䲻�㣬��Ҫ��������ռ�
		{
			records = realloc(records, (arraySize + INCR_SIZE) * sizeof(ComInfo));
			//�¿ռ��С��Ϊ(arraySize+INCR_SIZE)��¼��С,
			//����ԭ������������INCR_SIZE����¼��С
			if (records == NULL)
			{
				printf("memory failed!");
				exit(-1);
			}
			arraySize = arraySize + INCR_SIZE;
			//arraySize�޸�Ϊ�¿ռ�ɱ���ļ�¼��
		}

		printf("\t\t**********************\n");
	p:printf("\t\t��ţ�");
		gets(records[numComs].number);
		i = findRecord(records[numComs].number, 0, 0);
		if (i != -1)
		{
			printf("\t\t-----------------------\n");
			printf("\t\t����Ѵ��ڣ�����������!\n");
			printf("\t\t***********************\n");
			goto p;
		}
		//��Ϊ��Ų����ظ�����������ֻ���ҵ�һ������ظ��ļ�¼

		printf("\t\t���ƣ�");
		gets(records[numComs].name);
		printf("\t\t�����أ�");
		gets(records[numComs].place);
		printf("\t\t���ۣ�");
		gets(str);
		price = (float)atof(str);
		printf("\t\t��ǰ����������");
		gets(str);
		sellnum = (int)atoi(str);
		printf("\t\t�������");
		gets(str);
		inventory = (int)atoi(str);
		printf("\t\t**********************\n\n");

		records[numComs].price = price;
		records[numComs].sellnum = sellnum;
		records[numComs].inventory = inventory;
		records[numComs].sum = records[numComs].price * records[numComs].sellnum;

		numComs++; //����һ����Ʒ��¼��,��Ʒ����1
	}

	printf("\n\t����һ����%d����Ϣ\n", numComs);
	savedTag = 1;//����һ���µ���Ʒ��,��Ϣ�����־Ϊ1,��ʾδ����

	printf("\n\t�Ƿ񱣴��¼��(Y/N)");
	gets(str);
	if (str[0] == 'y' || str[0] == 'Y')
		saveRecords();
	else
		back();
}