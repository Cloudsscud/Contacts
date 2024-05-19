#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 6
#define MAX_TELE 12
#define MAX_ADDR 30

//好友个人信息
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
//通讯录
struct Contact
{
	struct PeoInfo data[MAX];//存放一个信息
	int size;//记录当前已有元素的个数
};

enum Option//增加可读性
{
	EXIT,//0
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

//初始化通讯录
void InitContact(struct Contact* con);

//增加好友信息
void AddContact(struct Contact* con);

//显示好友信息
void ShowContact(const struct Contact* con);

//删除好友信息
void DelContact(struct Contact* con);

//查找好友信息
void SearchContact(const struct Contact* con);

//修改好友信息
void ModifyContact(struct Contact* con);

//排序好友信息
void SortContact(struct Contact* con);