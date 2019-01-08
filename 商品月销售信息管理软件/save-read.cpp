#include "commodity.h"

/**********************************
 * �ļ��洢��������
 * ���������records��������ָ���ļ�
 * ���أ��ɹ�0��ʧ��-1
 **********************************/
int saveRecords()
{
	FILE *fp;
	char fname[30];

	system("CLS");
	if (numComs == 0)
	{
		printf("\n\t\tû����Ʒ��¼�ɱ���!\n\n");
		back();
		return -1;
	}

	printf("\n\t������Ҫ������ļ�����ֱ�ӻس�ѡ���ļ�com_info����");
	gets(fname);
	if (strlen(fname) == 0)
		strcpy(fname, "com_info");

	if ((fp = fopen(fname, "wb")) == NULL)
	{
		printf("\n\t���ܴ����ļ�!\n");
		return -1;
	}

	printf("\n\t���ڴ��ļ�");
	delay();
	printf("\n");
	fwrite(records, sizeof(ComInfo)*numComs, 1, fp);
	fclose(fp);
	printf("\n\t%d����¼�Ѿ������ļ�\n", numComs);
	savedTag = 0;	//�����Ƿ��ѱ���ı��
	back();
	return 0;
}

/*******************************************
 * �ļ���ȡ��������
 * �����records��Ϊ��ָ���ļ��ж�ȡ���ļ�¼
 * ���أ��ɹ�0��ʧ��-1
 *******************************************/
int readRecords(void)
{
	FILE *fp;
	char fname[30];
	char str[5];

	system("CLS");
	if (numComs != 0 && savedTag == 0)//����ڴ��¼����Ʒ����0���ѱ���
	{
		printf("\n\t��ѡ������Ҫ�������м�¼(Y)������Ҫ����ȡ�ļ�¼��ӵ����м�¼֮��(N)��\n");
		printf("\n\tֱ�ӻس��򸲸����м�¼");
		gets(str);
		if (str[0] != 'n' && str[0] != 'N')
			numComs = 0;
	}

	if (numComs != 0 && savedTag == 1) //����ڴ��¼��ѧ������0��û�б���
	{
		printf("\n\t��ȡ�ļ��������ԭ���ļ�¼���Ƿ񱣴�ԭ���ļ�¼��(Y/N)");
		printf("\n\tֱ�ӻس��򱣴�ԭ����¼");
		gets(str);
		if (str[0] != 'n' && str[0] != 'N')
			saveRecords();

		printf("\n\t��ѡ������Ҫ�������м�¼(Y)������Ҫ����ȡ�ļ�¼��ӵ����м�¼֮��(N)��\n");
		printf("\n\tֱ�ӻس��򸲸����м�¼");
		gets(str);
		if (str[0] != 'n' && str[0] != 'N')
			numComs = 0;
	}

	printf("\n\t������Ҫ��ȡ���ļ�����ֱ�ӻس�ѡ���ļ�com_info����");
	gets(fname);
	if (strlen(fname) == 0)
		strcpy(fname, "com_info");

	if ((fp = fopen(fname, "rb")) == NULL)
	{
		printf("\n\t�򲻿��ļ���������ѡ��\n");
		return -1;
	}

	printf("\n\t����ȡ�ļ�");
	delay();
	printf("\n");
	while (!feof(fp))
	{
		// ���ڵ�����ռ䲻�㣬��Ҫ��������ռ�
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
		//��ȡһ���¼�¼,���浽records[numComs],

		numComs++;//��¼����1
	}

	fclose(fp);
	printf("\n\t���ڹ���%d����¼��", numComs);
	back();
	return 0;
}