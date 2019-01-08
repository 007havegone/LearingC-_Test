//头文件包含
#ifndef H_COMMODITY_HH//如果没有定义H_COMMODITY_HH,继续执行
#define H_COMMODITY_HH//定义H_COMMODITY_HH,可避免重复包含宏定义
#include <stdio.h>
#include <stdlib.h> //标准库函数
#include <conio.h>  //屏幕操作函数
#include <string.h> //字符串函数
#include <ctype.h>
#include <windows.h>//调用Sleep函数

//可根椐系统使用需要的常量定义
#define INITIAL_SIZE 10   // 数组初始大小
#define INCR_SIZE 5       // 数组每次增加的大小

//定义一个类型名ComInfo代表定义的结构体commodity_info
struct commodity_info {
	char number[15];	    // 编号
	char name[20];	        // 名称
	char place[20];	        // 生产地
	float price;	        // 单价
	int sellnum;			// 销售量
	float sum;	            // 销售总金额
	int inventory;	        // 库存量	
};
typedef struct commodity_info ComInfo;

//共享的全局变量定义
extern int numComs;	        // 记录的商品数
extern ComInfo* records;	// 记录商品信息的数组指针
extern char savedTag;	    // 信息是否已保存的标志，0为已保存，1为未保存
extern int arraySize;	    // 数组大小

//函数申明,注意()里必须包含对应函数形参类型
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