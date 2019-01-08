//ͷ�ļ�����
#ifndef H_COMMODITY_HH//���û�ж���H_COMMODITY_HH,����ִ��
#define H_COMMODITY_HH//����H_COMMODITY_HH,�ɱ����ظ������궨��
#include <stdio.h>
#include <stdlib.h> //��׼�⺯��
#include <conio.h>  //��Ļ��������
#include <string.h> //�ַ�������
#include <ctype.h>
#include <windows.h>//����Sleep����

//�ɸ��ϵͳʹ����Ҫ�ĳ�������
#define INITIAL_SIZE 10   // �����ʼ��С
#define INCR_SIZE 5       // ����ÿ�����ӵĴ�С

//����һ��������ComInfo������Ľṹ��commodity_info
struct commodity_info {
	char number[15];	    // ���
	char name[20];	        // ����
	char place[20];	        // ������
	float price;	        // ����
	int sellnum;			// ������
	float sum;	            // �����ܽ��
	int inventory;	        // �����	
};
typedef struct commodity_info ComInfo;

//�����ȫ�ֱ�������
extern int numComs;	        // ��¼����Ʒ��
extern ComInfo* records;	// ��¼��Ʒ��Ϣ������ָ��
extern char savedTag;	    // ��Ϣ�Ƿ��ѱ���ı�־��0Ϊ�ѱ��棬1Ϊδ����
extern int arraySize;	    // �����С

//��������,ע��()����������Ӧ�����β�����
void login(void);
void delay(void);
void handle_menu(void);
int menu_select(void);
void quit(void);

void showTable(void);
void display(void);
void addRecord(void);
void back(void);

void sale_Commodity(void);
void stock_Commodity(void);
void statistics(void);

void queryInfo(void);
void deleteRecord(void);
void modifyRecord(void);

int saveRecords(void);
int readRecords(void);

int findRecord(char* target, int targetType, int from);
void copyRecord(ComInfo* src, ComInfo* dest);

#endif // H_COMMODITY_HH