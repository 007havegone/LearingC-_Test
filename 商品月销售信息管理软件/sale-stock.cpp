#include "commodity.h"

/*****************************************
 * �۳����ܺ���sale_Commodity
 *****************************************/
void sale_Commodity(void)
{
	char str[5];//��ѯ��ʽ�ַ���
	char target[20];//��ѯ��Ŀ��������
	int type;//��ѯ��
	char s[2];
	int i, amount;

	system("CLS");
	if (numComs == 0)
	{
		printf("\n\tû�пɹ����۵ļ�¼!�Ƿ������µ���Ʒ��¼��(Y/N)");
		gets(s);
		if (s[0] == 'n' || s[0] == 'N') //��������µ���Ϣ
			back();
		else
			addRecord();//����������Ʒ��¼����		
	}

	while (1)
	{
		printf("\n\t��ѡ�������������Ʒ�ķ�ʽ����ֱ������س���������۲�����\n");
		printf("\t 1.����Ʒ���\n");
		printf("\t 2.����Ʒ����\n");
		gets(str);
		if (strlen(str) == 0) break;
		if (str[0] == '1')
		{
			printf("\n\t��������Ʒ�ı�ţ�");
			gets(target);
			type = 0;
		}
		else
		{
			printf("\n\t��������Ʒ�����ƣ�");
			gets(target);
			type = 1;
		}

		i = findRecord(target, type, 0);
		//��0�ż�¼����ң���ѯ��type����ѯĿ��������target
		if (i == -1)
			printf("\n\tû�д���Ʒ!\n\n");

		while (i != -1)
		{
			printf("\n\t�����������۳���Ʒ��������");
			gets(str);
			amount = (int)atoi(str);

			while (amount > records[i].inventory)
			{
				printf("\n\t����Ʒ�Ŀ���������㣬�����������۳�������");
				gets(str);
				amount = (int)atoi(str);
			}

			records[i].inventory = records[i].inventory - amount;
			records[i].sellnum = records[i].sellnum + amount;
			records[i].sum = records[i].sum + (amount * records[i].price);

			printf("\n\t���Ϊ%s����Ʒ�ѳɹ��۳�%d��\n", records[i].number, amount);

			showTable();
			printf("\t%s\t%s\t%s", records[i].number, records[i].name,
				records[i].place);
			printf("\t%.1f\t%d\t\t%.1f\t\t%d\n", records[i].price, records[i].sellnum,
				records[i].sum, records[i].inventory);
			printf("\t=======================================================================\n");
			//��i+1����¼�������һ�����������ļ�¼
			i = findRecord(target, type, i + 1);
		}
		printf("\n\t����һ����%d����¼\n\n", numComs);
	}
	savedTag = 1;
	back();
}


/*****************************************
 * �������ܺ���stock_Commodity
 *****************************************/
void stock_Commodity(void)
{
	char str[5];
	char target[20];
	int type;
	char s[2];
	int i, amount;
	float price;
	int sellnum, inventory;


	system("CLS");
	if (numComs == 0)
	{
		printf("\n\t�ֿ�û����Ʒ!�Ƿ������µ���Ʒ��¼��(Y/N)");
		gets(s);
		if (s[0] == 'n' || s[0] == 'N') //��������µ���Ϣ
			back();
		else
			addRecord();//����������Ʒ��¼����
	}

	while (1)
	{
		printf("\n\t��ѡ�������������Ʒ�ķ�ʽ����ֱ������س����������������\n");
		printf("\t 1.����Ʒ���\n");
		printf("\t 2.����Ʒ����\n");
		gets(str);
		if (strlen(str) == 0) break;
		if (str[0] == '1')
		{
			printf("\n\t��������Ʒ�ı�ţ�");
			gets(target);
			type = 0;
		}
		else
		{
			printf("\n\t��������Ʒ�����ƣ�");
			gets(target);
			type = 1;
		}

		i = findRecord(target, type, 0);

		if (i == -1)
		{
			printf("\n\tû�д���Ʒ!�Ƿ񹺽��µ���Ʒ?(Y/N)");
			gets(str);
			if (str[0] == 'N' || str[0] == 'n')
				break;
			else
			{
				printf("\n\t�����������¹�������Ʒ����Ϣ��\n");
				printf("\t\t***********************\n");
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

				printf("\n\t��������Ʒ�ɹ�!\n");
				numComs++; //����һ����Ʒ��¼��,��Ʒ����1
			}
			savedTag = 1;//����һ���µ���Ʒ��,��Ϣ�����־Ϊ1,��ʾδ����
			printf("\n\t�Ƿ񱣴��¼��(Y/N)");
			gets(str);
			if (str[0] == 'y' || str[0] == 'Y')
				saveRecords();
		}

		while (i != -1)
		{
			printf("\n\t���������빺����Ʒ��������");
			gets(str);
			amount = (int)atoi(str);
			records[i].inventory = records[i].inventory + amount;

			printf("\n\t���Ϊ%s����Ʒ�ѳɹ�����%d��\n", records[i].number, amount);

			showTable();
			printf("\t%s\t%s\t%s", records[i].number, records[i].name,
				records[i].place);
			printf("\t%.1f\t%d\t\t%.1f\t\t%d\n", records[i].price, records[i].sellnum,
				records[i].sum, records[i].inventory);
			printf("\t=======================================================================\n");
			//��i+1����¼�������һ�����������ļ�¼
			i = findRecord(target, type, i + 1);
		}
		printf("\n\t����һ����%d����¼\n\n", numComs);
	}
	savedTag = 1;
	back();
}