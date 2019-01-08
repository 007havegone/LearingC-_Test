#include "commodity.h"

/***********************************
 * 查询指定商品的信息
 * 可以按照编号、名称、生产地来查询
 ***********************************/
void queryInfo(void)
{
	char str[5]; //查询方式字符串
	char target[20]; //查询的目标数据项
	int type; //查询项
	int count; //查询到的商品数
	int i;

	system("CLS");
	if (numComs == 0)
	{
		printf("\n\t\t没有可供查询的记录!");
		back();
		return;
	}

	while (1)
	{
		printf("\n\t请选择查找的方式：（直接输入回车则结束查找操作）\n");
		printf("\t1. 按编号\n");
		printf("\t2. 按名称\n");
		printf("\t3. 按生产地\n");
		gets(str);
		if (strlen(str) == 0) break;
		if (str[0] == '1')
		{
			printf("\n\t请输入欲查询的商品的编号：");
			gets(target);
			type = 0;
		}
		else if (str[0] == '2')
		{
			printf("\n\t请输入欲查询的商品的名称：");
			gets(target);
			type = 1;
		}
		else
		{
			printf("\n\t请输入欲查询的商品的生产地：");
			gets(target);
			type = 2;
		}

		i = findRecord(target, type, 0);
		//从0号记录起查找，查询项type，查询目标数据项target
		if (i != -1)
		{
			printf("\t=================================\n");
			printf("\t编号\t名称\t单价\t库存量\n");
			printf("\t---------------------------------\n");
		}
		count = 0;
		while (i != -1)
		{
			count++;//查询到的商品数加1
			printf("\t%s\t%s", records[i].number, records[i].name);
			printf("\t%.1f\t%d\n", records[i].price, records[i].inventory);
			//从i+1条记录起查找下一条符合条件的记录
			i = findRecord(target, type, i + 1);
			//编号唯一,但名称或生产地可能相同
		}
		printf("\t=================================\n");

		if (count == 0)
			printf("\n\t没有找到符合条件的商品!\n");
		else
			printf("\n\t一共找到了%d条商品记录的信息\n\n", count);
	}
	back();
}

/*****************************************
 * 找出当前销售总金额最大的商品 statistics
 *****************************************/
void statistics(void)
{
	int i, j = 0;
	float Max;

	system("CLS");
	if (numComs == 0)
	{
		printf("\n\t没有可供查找的记录!\n");
		back();
		return;
	}
	else
	{
		printf("\n\t下面是当前所有商品记录的信息：\n");
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

	printf("\n\t本月当前销售总金额最大的商品的主要信息如下：\n");
	printf("\t=========================================\n");
	printf("\t编号\t名称\t生产地\t本月销售总金额\n");
	printf("\t-----------------------------------------\n");

	printf("\t%s\t%s\t%s\t%.1f\n", records[j].number, records[j].name,
		records[j].place, records[j].sum);
	printf("\t=========================================\n");

	back();
}