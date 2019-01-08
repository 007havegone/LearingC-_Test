#include "commodity.h"

/*****************************************
 * 售出功能函数sale_Commodity
 *****************************************/
void sale_Commodity(void)
{
	char str[5];//查询方式字符串
	char target[20];//查询的目标数据项
	int type;//查询项
	char s[2];
	int i, amount;

	system("CLS");
	if (numComs == 0)
	{
		printf("\n\t没有可供销售的记录!是否增加新的商品记录？(Y/N)");
		gets(s);
		if (s[0] == 'n' || s[0] == 'N') //不再添加新的信息
			back();
		else
			addRecord();//调用增加商品记录函数		
	}

	while (1)
	{
		printf("\n\t请选择查找欲销售商品的方式：（直接输入回车则结束销售操作）\n");
		printf("\t 1.按商品编号\n");
		printf("\t 2.按商品名称\n");
		gets(str);
		if (strlen(str) == 0) break;
		if (str[0] == '1')
		{
			printf("\n\t请输入商品的编号：");
			gets(target);
			type = 0;
		}
		else
		{
			printf("\n\t请输入商品的名称：");
			gets(target);
			type = 1;
		}

		i = findRecord(target, type, 0);
		//从0号记录起查找，查询项type，查询目标数据项target
		if (i == -1)
			printf("\n\t没有此商品!\n\n");

		while (i != -1)
		{
			printf("\n\t下面请输入售出商品的数量：");
			gets(str);
			amount = (int)atoi(str);

			while (amount > records[i].inventory)
			{
				printf("\n\t该商品的库存余量不足，请重新输入售出数量：");
				gets(str);
				amount = (int)atoi(str);
			}

			records[i].inventory = records[i].inventory - amount;
			records[i].sellnum = records[i].sellnum + amount;
			records[i].sum = records[i].sum + (amount * records[i].price);

			printf("\n\t编号为%s的商品已成功售出%d件\n", records[i].number, amount);

			showTable();
			printf("\t%s\t%s\t%s", records[i].number, records[i].name,
				records[i].place);
			printf("\t%.1f\t%d\t\t%.1f\t\t%d\n", records[i].price, records[i].sellnum,
				records[i].sum, records[i].inventory);
			printf("\t=======================================================================\n");
			//从i+1条记录起查找下一条符合条件的记录
			i = findRecord(target, type, i + 1);
		}
		printf("\n\t现在一共有%d条记录\n\n", numComs);
	}
	savedTag = 1;
	back();
}


/*****************************************
 * 进货功能函数stock_Commodity
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
		printf("\n\t仓库没有商品!是否增加新的商品记录？(Y/N)");
		gets(s);
		if (s[0] == 'n' || s[0] == 'N') //不再添加新的信息
			back();
		else
			addRecord();//调用增加商品记录函数
	}

	while (1)
	{
		printf("\n\t请选择查找欲进货商品的方式：（直接输入回车则结束进货操作）\n");
		printf("\t 1.按商品编号\n");
		printf("\t 2.按商品名称\n");
		gets(str);
		if (strlen(str) == 0) break;
		if (str[0] == '1')
		{
			printf("\n\t请输入商品的编号：");
			gets(target);
			type = 0;
		}
		else
		{
			printf("\n\t请输入商品的名称：");
			gets(target);
			type = 1;
		}

		i = findRecord(target, type, 0);

		if (i == -1)
		{
			printf("\n\t没有此商品!是否购进新的商品?(Y/N)");
			gets(str);
			if (str[0] == 'N' || str[0] == 'n')
				break;
			else
			{
				printf("\n\t下面请输入新购进的商品的信息：\n");
				printf("\t\t***********************\n");
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

				printf("\n\t购进新商品成功!\n");
				numComs++; //输入一个商品记录后,商品数加1
			}
			savedTag = 1;//输入一个新的商品后,信息保存标志为1,表示未保存
			printf("\n\t是否保存记录？(Y/N)");
			gets(str);
			if (str[0] == 'y' || str[0] == 'Y')
				saveRecords();
		}

		while (i != -1)
		{
			printf("\n\t下面请输入购进商品的数量：");
			gets(str);
			amount = (int)atoi(str);
			records[i].inventory = records[i].inventory + amount;

			printf("\n\t编号为%s的商品已成功进货%d件\n", records[i].number, amount);

			showTable();
			printf("\t%s\t%s\t%s", records[i].number, records[i].name,
				records[i].place);
			printf("\t%.1f\t%d\t\t%.1f\t\t%d\n", records[i].price, records[i].sellnum,
				records[i].sum, records[i].inventory);
			printf("\t=======================================================================\n");
			//从i+1条记录起查找下一条符合条件的记录
			i = findRecord(target, type, i + 1);
		}
		printf("\n\t现在一共有%d条记录\n\n", numComs);
	}
	savedTag = 1;
	back();
}