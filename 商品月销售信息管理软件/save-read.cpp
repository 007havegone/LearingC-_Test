#include "commodity.h"

/**********************************
 * 文件存储操作函数
 * 结果：数组records被保存至指定文件
 * 返回：成功0，失败-1
 **********************************/
int saveRecords()
{
	FILE *fp;
	char fname[30];

	system("CLS");
	if (numComs == 0)
	{
		printf("\n\t\t没有商品记录可保存!\n\n");
		back();
		return -1;
	}

	printf("\n\t请输入要存入的文件名（直接回车选择文件com_info）：");
	gets(fname);
	if (strlen(fname) == 0)
		strcpy(fname, "com_info");

	if ((fp = fopen(fname, "wb")) == NULL)
	{
		printf("\n\t不能存入文件!\n");
		return -1;
	}

	printf("\n\t正在存文件");
	delay();
	printf("\n");
	fwrite(records, sizeof(ComInfo)*numComs, 1, fp);
	fclose(fp);
	printf("\n\t%d条记录已经存入文件\n", numComs);
	savedTag = 0;	//更新是否已保存的标记
	back();
	return 0;
}

/*******************************************
 * 文件读取操作函数
 * 结果：records将为从指定文件中读取出的记录
 * 返回：成功0，失败-1
 *******************************************/
int readRecords(void)
{
	FILE *fp;
	char fname[30];
	char str[5];

	system("CLS");
	if (numComs != 0 && savedTag == 0)//如果内存记录的商品数非0且已保存
	{
		printf("\n\t请选择您是要覆盖现有记录(Y)，还是要将读取的记录添加到现有记录之后(N)？\n");
		printf("\n\t直接回车则覆盖现有记录");
		gets(str);
		if (str[0] != 'n' && str[0] != 'N')
			numComs = 0;
	}

	if (numComs != 0 && savedTag == 1) //如果内存记录的学生数非0且没有保存
	{
		printf("\n\t读取文件将会更改原来的记录，是否保存原来的记录？(Y/N)");
		printf("\n\t直接回车则保存原来记录");
		gets(str);
		if (str[0] != 'n' && str[0] != 'N')
			saveRecords();

		printf("\n\t请选择您是要覆盖现有记录(Y)，还是要将读取的记录添加到现有记录之后(N)？\n");
		printf("\n\t直接回车则覆盖现有记录");
		gets(str);
		if (str[0] != 'n' && str[0] != 'N')
			numComs = 0;
	}

	printf("\n\t请输入要读取的文件名（直接回车选择文件com_info）：");
	gets(fname);
	if (strlen(fname) == 0)
		strcpy(fname, "com_info");

	if ((fp = fopen(fname, "rb")) == NULL)
	{
		printf("\n\t打不开文件！请重新选择\n");
		return -1;
	}

	printf("\n\t正在取文件");
	delay();
	printf("\n");
	while (!feof(fp))
	{
		// 现在的数组空间不足，需要重新申请空间
		if (numComs >= arraySize)
		{
			records = realloc(records, (arraySize + INCR_SIZE) * sizeof(ComInfo));
			if (records == NULL)
			{
				printf("memory failed!");
				exit(-1);
			}
			arraySize = arraySize + INCR_SIZE;
		}

		if (fread(&records[numComs], sizeof(ComInfo), 1, fp) != 1) break;
		//读取一条新记录,保存到records[numComs],

		numComs++;//记录数加1
	}

	fclose(fp);
	printf("\n\t现在共有%d条记录。", numComs);
	back();
	return 0;
}