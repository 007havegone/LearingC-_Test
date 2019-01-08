#include "commodity.h"

/************************************************
 * 查找指定的记录
 * 参数:target:欲查找记录的某一项与target相同
 *		targetType:表明通过哪一项来查找
 *					0为编号，1为名称，2为生产地
 *		from:从第from个记录开始找
 * 返回:找到的记录的序号，若找不到则返回-1
 ************************************************/
int findRecord(char* target, int targetType, int from)
{
	int i;
	for (i = from; i < numComs; i++)
	{
		if ((targetType == 0 && strcmp(target, records[i].number) == 0) ||
			(targetType == 1 && strcmp(target, records[i].name) == 0) ||
			(targetType == 2 && strcmp(target, records[i].place) == 0))
			return i;//如果找到符合条件的记录，返回记录号
	}
	return -1;//如果没有找到，返回-1
}

/************************
 * 删除指定的记录
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
		printf("\n\t\t没有可供删除的记录!\n");
		back();
		return;
	}

	while (1)
	{
		printf("\n\t请选择删除的方式：（直接输入回车则结束删除操作）\n");
		printf("\t1. 按编号\n");
		printf("\t2. 按名称\n");
		printf("\t3. 按生产地\n");
		gets(str);
		if (strlen(str) == 0) break;
		if (str[0] == '1')
		{
			printf("\n\t请输入欲删除的商品的编号：");
			gets(target);
			type = 0;
		}
		else if (str[0] == '2')
		{
			printf("\n\t请输入欲删除的商品的名称：");
			gets(target);
			type = 1;
		}
		else
		{
			printf("\n\t请输入欲删除的商品的生产地：");
			gets(target);
			type = 2;
		}

		i = findRecord(target, type, 0);
		if (i == -1)
			printf("\n\t没有找到符合条件的商品!\n");

		while (i != -1)
		{
			showTable();
			//打印找到的商品记录的信息
			printf("\t%s\t%s\t%s", records[i].number, records[i].name,
				records[i].place);
			printf("\t%.1f\t%d\t\t%.1f\t\t%d\n", records[i].price, records[i].sellnum,
				records[i].sum, records[i].inventory);
			printf("\t=======================================================================\n");

			printf("\n\t确定要删除这个商品的信息吗？(Y/N)");
			gets(str);

			if (str[0] == 'y' || str[0] == 'Y')
			{
				numComs--; //删除一条记录后，商品数减1
				for (j = i; j < numComs; j++)
				{
					copyRecord(&records[j + 1], &records[j]);
				}
			}
			printf("\n\t删除成功!\n");
			//取下一个符合条件的记录
			i = findRecord(target, type, i);
		}
		printf("\t现在一共有%d条记录\n\n", numComs);
	}
	savedTag = 1;//删除一条记录后，保存标志变为1，表示未保存
	back();
}

/*****************************************
 * 将src指向的一条记录复制给dest指向的记录
 *****************************************/
void copyRecord(ComInfo* src, ComInfo* dest)
{
	//strcpy函数:实现两个字符串的拷贝
	strcpy(dest->number, src->number);
	strcpy(dest->name, src->name);
	strcpy(dest->place, src->place);

	dest->price = src->price;
	dest->sellnum = src->sellnum;
	dest->sum = src->sum;
	dest->inventory = src->inventory;
}

/*************************
 * 修改指定商品的信息
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
		printf("\n\t没有可供修改的记录!\n");
		back();
		return;
	}

	while (1)
	{
		printf("\n\t请选择修改的方式：（直接输入回车则结束修改操作）\n");
		printf("\t1. 按编号\n");
		printf("\t2. 按名称\n");
		printf("\t3. 按生产地\n");
		gets(str);
		if (strlen(str) == 0) break;
		if (str[0] == '1')
		{
			printf("\n\t请输入欲修改的商品的编号：");
			gets(target);
			type = 0;
		}
		else if (str[0] == '2')
		{
			printf("\n\t请输入欲修改的商品的名称：");
			gets(target);
			type = 1;
		}
		else
		{
			printf("\n\t请输入欲修改的商品的生产地：");
			gets(target);
			type = 2;
		}

		i = findRecord(target, type, 0);
		if (i == -1)
			printf("\n\t没有找到符合条件的商品!\n");

		while (i != -1)
		{
			showTable();
			printf("\t%s\t%s\t%s", records[i].number, records[i].name,
				records[i].place);
			printf("\t%.1f\t%d\t\t%.1f\t\t%d\n", records[i].price, records[i].sellnum,
				records[i].sum, records[i].inventory);
			printf("\t=======================================================================\n");

			printf("\n\t确定要修改这个商品的信息吗？(Y/N)");
			gets(str);
			if (str[0] == 'y' || str[0] == 'Y')
			{
				printf("\n\t\t---------------------------------------\n");
				printf("\n\t\t1:编号\t2:名称\t3:生产地  4:单价\n");
				printf("\n\t\t---------------------------------------");
				printf("\n\t\t选择修改的内容：");
				for (; ;)
				{
					gets(str);
					a = atoi(str); //将字符串转换成整数(int)
					if (a < 1 || a>4)
						printf("\n\t输入错误，重选1-4 ");
					else break;
				}

				switch (a) {
				case 1:
					printf("\t\t输入新的编号：");
					gets(str);
					num = (int)atoi(str);
					j = findRecord(num, 0, 0);
					while (j != -1)
					{
						printf("\n");
						printf("\t\t编号已存在或跟修改之前一样，请重新输入!\n\n");
						printf("\t\t输入新的编号：");
						gets(num);
						j = findRecord(num, 0, 0);
					}
					records[i].number = num;

					break;
				case 2:
					printf("\t\t输入新的名称：");
					gets(records[i].name);
					break;
				case 3:
					printf("\t\t输入新的生产地：");
					gets(records[i].place);
					break;
				case 4:
					printf("\t\t输入新的单价：");
					gets(str);
					price = (float)atof(str);
					records[i].price = price;
					break;
				}
			}
			printf("\n\t修改成功!\n");
		}
		printf("\n\t现在一共有%d条记录\n\n", numComs);
	}
	savedTag = 1;
	back();
}