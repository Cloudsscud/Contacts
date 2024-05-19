#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 6
#define MAX_TELE 12
#define MAX_ADDR 30

//���Ѹ�����Ϣ
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
//ͨѶ¼
struct Contact
{
	struct PeoInfo data[MAX];//���һ����Ϣ
	int size;//��¼��ǰ����Ԫ�صĸ���
};

enum Option//���ӿɶ���
{
	EXIT,//0
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

//��ʼ��ͨѶ¼
void InitContact(struct Contact* con);

//���Ӻ�����Ϣ
void AddContact(struct Contact* con);

//��ʾ������Ϣ
void ShowContact(const struct Contact* con);

//ɾ��������Ϣ
void DelContact(struct Contact* con);

//���Һ�����Ϣ
void SearchContact(const struct Contact* con);

//�޸ĺ�����Ϣ
void ModifyContact(struct Contact* con);

//���������Ϣ
void SortContact(struct Contact* con);