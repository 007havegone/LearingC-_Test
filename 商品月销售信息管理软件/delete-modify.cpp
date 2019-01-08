#include "commodity.h"

/************************************************
 * ����ָ���ļ�¼
 * ����:target:�����Ҽ�¼��ĳһ����target��ͬ
 *		targetType:����ͨ����һ��������
 *					0Ϊ��ţ�1Ϊ���ƣ�2Ϊ������
 *		from:�ӵ�from����¼��ʼ��
 * ����:�ҵ��ļ�¼����ţ����Ҳ����򷵻�-1
 ************************************************/
int findRecord(char* target, int targetType, int from)
{
	int i;
	for (i = from; i < numComs; i++)
	{
		if ((targetType == 0 && strcmp(target, records[i].number) == 0) ||
			(targetType == 1 && strcmp(target, records[i].name) == 0) ||
			(targetType == 2 && strcmp(target, records[i].place) == 0))
			return i;//����ҵ����������ļ�¼�����ؼ�¼��
	}
	return -1;//���û���ҵ�������-1
}

/************************
 * ɾ��ָ���ļ�¼
 ************************/
void deleteRecord(void)
{
	char str[5];
	char target[20];
	int type;
	int i, j;

	system("CLS");
	if (numComs == 0)
	{
		printf("\n\t\tû�пɹ�ɾ���ļ�¼!\n");
		back();
		return;
	}

	while (1)
	{
		printf("\n\t��ѡ��ɾ���ķ�ʽ����ֱ������س������ɾ��������\n");
		printf("\t1. �����\n");
		printf("\t2. ������\n");
		printf("\t3. ��������\n");
		gets(str);
		if (strlen(str) == 0) break;
		if (str[0] == '1')
		{
			printf("\n\t��������ɾ������Ʒ�ı�ţ�");
			gets(target);
			type = 0;
		}
		else if (str[0] == '2')
		{
			printf("\n\t��������ɾ������Ʒ�����ƣ�");
			gets(target);
			type = 1;
		}
		else
		{
			printf("\n\t��������ɾ������Ʒ�������أ�");
			gets(target);
			type = 2;
		}

		i = findRecord(target, type, 0);
		if (i == -1)
			printf("\n\tû���ҵ�������������Ʒ!\n");

		while (i != -1)
		{
			showTable();
			//��ӡ�ҵ�����Ʒ��¼����Ϣ
			printf("\t%s\t%s\t%s", records[i].number, records[i].name,
				records[i].place);
			printf("\t%.1f\t%d\t\t%.1f\t\t%d\n", records[i].price, records[i].sellnum,
				records[i].sum, records[i].inventory);
			printf("\t=======================================================================\n");

			printf("\n\tȷ��Ҫɾ�������Ʒ����Ϣ��(Y/N)");
			gets(str);

			if (str[0] == 'y' || str[0] == 'Y')
			{
				numComs--; //ɾ��һ����¼����Ʒ����1
				for (j = i; j < numComs; j++)
				{
					copyRecord(&records[j + 1], &records[j]);
				}
			}
			printf("\n\tɾ���ɹ�!\n");
			//ȡ��һ�����������ļ�¼
			i = findRecord(target, type, i);
		}
		printf("\t����һ����%d����¼\n\n", numComs);
	}
	savedTag = 1;//ɾ��һ����¼�󣬱����־��Ϊ1����ʾδ����
	back();
}

/*****************************************
 * ��srcָ���һ����¼���Ƹ�destָ��ļ�¼
 *****************************************/
void copyRecord(ComInfo* src, ComInfo* dest)
{
	//strcpy����:ʵ�������ַ����Ŀ���
	strcpy(dest->number, src->number);
	strcpy(dest->name, src->name);
	strcpy(dest->place, src->place);

	dest->price = src->price;
	dest->sellnum = src->sellnum;
	dest->sum = src->sum;
	dest->inventory = src->inventory;
}

/*************************
 * �޸�ָ����Ʒ����Ϣ
 *************************/
void modifyRecord(void)
{
	char str[5];
	char target[20];
	int type;
	int i, j, a;
	float price;
	int num;

	system("CLS");
	if (numComs == 0)
	{
		printf("\n\tû�пɹ��޸ĵļ�¼!\n");
		back();
		return;
	}

	while (1)
	{
		printf("\n\t��ѡ���޸ĵķ�ʽ����ֱ������س�������޸Ĳ�����\n");
		printf("\t1. �����\n");
		printf("\t2. ������\n");
		printf("\t3. ��������\n");
		gets(str);
		if (strlen(str) == 0) break;
		if (str[0] == '1')
		{
			printf("\n\t���������޸ĵ���Ʒ�ı�ţ�");
			gets(target);
			type = 0;
		}
		else if (str[0] == '2')
		{
			printf("\n\t���������޸ĵ���Ʒ�����ƣ�");
			gets(target);
			type = 1;
		}
		else
		{
			printf("\n\t���������޸ĵ���Ʒ�������أ�");
			gets(target);
			type = 2;
		}

		i = findRecord(target, type, 0);
		if (i == -1)
			printf("\n\tû���ҵ�������������Ʒ!\n");

		while (i != -1)
		{
			showTable();
			printf("\t%s\t%s\t%s", records[i].number, records[i].name,
				records[i].place);
			printf("\t%.1f\t%d\t\t%.1f\t\t%d\n", records[i].price, records[i].sellnum,
				records[i].sum, records[i].inventory);
			printf("\t=======================================================================\n");

			printf("\n\tȷ��Ҫ�޸������Ʒ����Ϣ��(Y/N)");
			gets(str);
			if (str[0] == 'y' || str[0] == 'Y')
			{
				printf("\n\t\t---------------------------------------\n");
				printf("\n\t\t1:���\t2:����\t3:������  4:����\n");
				printf("\n\t\t---------------------------------------");
				printf("\n\t\tѡ���޸ĵ����ݣ�");
				for (; ;)
				{
					gets(str);
					a = atoi(str); //���ַ���ת��������(int)
					if (a < 1 || a>4)
						printf("\n\t���������ѡ1-4 ");
					else break;
				}

				switch (a) {
				case 1:
					printf("\t\t�����µı�ţ�");
					gets(str);
					num = (int)atoi(str);
					j = findRecord(num, 0, 0);
					while (j != -1)
					{
						printf("\n");
						printf("\t\t����Ѵ��ڻ���޸�֮ǰһ��������������!\n\n");
						printf("\t\t�����µı�ţ�");
						gets(num);
						j = findRecord(num, 0, 0);
					}
					records[i].number = num;

					break;
				case 2:
					printf("\t\t�����µ����ƣ�");
					gets(records[i].name);
					break;
				case 3:
					printf("\t\t�����µ������أ�");
					gets(records[i].place);
					break;
				case 4:
					printf("\t\t�����µĵ��ۣ�");
					gets(str);
					price = (float)atof(str);
					records[i].price = price;
					break;
				}
			}
			printf("\n\t�޸ĳɹ�!\n");
		}
		printf("\n\t����һ����%d����¼\n\n", numComs);
	}
	savedTag = 1;
	back();
}