#include "commodity.h"

/***********************************
 * ��ѯָ����Ʒ����Ϣ
 * ���԰��ձ�š����ơ�����������ѯ
 ***********************************/
void queryInfo(void)
{
	char str[5]; //��ѯ��ʽ�ַ���
	char target[20]; //��ѯ��Ŀ��������
	int type; //��ѯ��
	int count; //��ѯ������Ʒ��
	int i;

	system("CLS");
	if (numComs == 0)
	{
		printf("\n\t\tû�пɹ���ѯ�ļ�¼!");
		back();
		return;
	}

	while (1)
	{
		printf("\n\t��ѡ����ҵķ�ʽ����ֱ������س���������Ҳ�����\n");
		printf("\t1. �����\n");
		printf("\t2. ������\n");
		printf("\t3. ��������\n");
		gets(str);
		if (strlen(str) == 0) break;
		if (str[0] == '1')
		{
			printf("\n\t����������ѯ����Ʒ�ı�ţ�");
			gets(target);
			type = 0;
		}
		else if (str[0] == '2')
		{
			printf("\n\t����������ѯ����Ʒ�����ƣ�");
			gets(target);
			type = 1;
		}
		else
		{
			printf("\n\t����������ѯ����Ʒ�������أ�");
			gets(target);
			type = 2;
		}

		i = findRecord(target, type, 0);
		//��0�ż�¼����ң���ѯ��type����ѯĿ��������target
		if (i != -1)
		{
			printf("\t=================================\n");
			printf("\t���\t����\t����\t�����\n");
			printf("\t---------------------------------\n");
		}
		count = 0;
		while (i != -1)
		{
			count++;//��ѯ������Ʒ����1
			printf("\t%s\t%s", records[i].number, records[i].name);
			printf("\t%.1f\t%d\n", records[i].price, records[i].inventory);
			//��i+1����¼�������һ�����������ļ�¼
			i = findRecord(target, type, i + 1);
			//���Ψһ,�����ƻ������ؿ�����ͬ
		}
		printf("\t=================================\n");

		if (count == 0)
			printf("\n\tû���ҵ�������������Ʒ!\n");
		else
			printf("\n\tһ���ҵ���%d����Ʒ��¼����Ϣ\n\n", count);
	}
	back();
}

/*****************************************
 * �ҳ���ǰ�����ܽ��������Ʒ statistics
 *****************************************/
void statistics(void)
{
	int i, j = 0;
	float Max;

	system("CLS");
	if (numComs == 0)
	{
		printf("\n\tû�пɹ����ҵļ�¼!\n");
		back();
		return;
	}
	else
	{
		printf("\n\t�����ǵ�ǰ������Ʒ��¼����Ϣ��\n");
		showTable();
		for (i = 0; i < numComs; i++)
		{
			printf("\t%s\t%s\t%s", records[i].number, records[i].name,
				records[i].place);
			printf("\t%.1f\t%d\t\t%.1f\t\t%d\n", records[i].price, records[i].sellnum,
				records[i].sum, records[i].inventory);
		}
		printf("\t=======================================================================\n");
	}

	Max = records[0].sum;
	for (i = 0; i <= numComs; i++)
	{
		if (Max < records[i].sum)
		{
			Max = records[i].sum;
			j = i;
		}
	}

	printf("\n\t���µ�ǰ�����ܽ��������Ʒ����Ҫ��Ϣ���£�\n");
	printf("\t=========================================\n");
	printf("\t���\t����\t������\t���������ܽ��\n");
	printf("\t-----------------------------------------\n");

	printf("\t%s\t%s\t%s\t%.1f\n", records[j].number, records[j].name,
		records[j].place, records[j].sum);
	printf("\t=========================================\n");

	back();
}