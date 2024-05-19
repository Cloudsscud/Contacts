#include "Contact.h"

//初始化通讯录
void InitContact(struct Contact* con)
{
	memset(con->data, 0, sizeof(con->data));
	con->size = 0;//通讯录最初有0个元素
}

//在对应下标输入元素信息
static void InputInfo(struct Contact* con, int cmp)
{
	printf("请输入名字:> ");
	scanf("%s", con->data[cmp].name);
	printf("请输入年龄:> ");
	scanf("%d", &(con->data[cmp].age));
	printf("请输入性别:> ");
	scanf("%s", con->data[cmp].sex);
	printf("请输入电话:> ");
	scanf("%s", con->data[cmp].tele);
	printf("请输入地址:> ");
	scanf("%s", con->data[cmp].addr);
}

//输出对应下标元素信息
static void PrintInfo(const struct Contact* con, int cmp)
{
	printf("%-20s\t%-4d\t%-6s\t%-12s\t%-30s\n",
		con->data[cmp].name,
		con->data[cmp].age,
		con->data[cmp].sex,
		con->data[cmp].tele,
		con->data[cmp].addr);
}

//输出信息的菜单
static void PrintMenu()
{
	printf("%-20s\t%-4s\t%-6s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
}

//增加好友信息
void AddContact(struct Contact* con)
{
	if (con->size == MAX)
	{
		printf("好友位满了,无法添加!\n");
	}
	else
	{
		InputInfo(con, con->size);
		con->size++;
		printf("添加成功!\n");
	}
}

//判断好友是否为空
static int Whether(const struct Contact* con)
{
	if (con->size == 0)
	{
		printf("当前无好友，请先添加好友!\n");
		return 0;
	}
	return 1;
}

//通过名字找好友--找到就返回所在元素的下标，否则返回-1
static int FindByName(const struct Contact* con, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < con->size; i++)
	{
		if (strcmp(con->data[i].name, name) == 0)
			return i;//找到
	}
	return -1;//未找到
}

//显示好友信息
void ShowContact(const struct Contact* con)
{
	if (Whether(con))//判断是否有好友
	{
		int i = 0;
		PrintMenu();
		for (i = 0; i < con->size; i++)
		{
			PrintInfo(con, i);
		}
	}
}

//删除好友信息
void DelContact(struct Contact* con)
{
	if (Whether(con))
	{
		char name[MAX_NAME];
		printf("请输入您要删除的好友名字:>");
		scanf("%s", name);
		int ret = FindByName(con, name);
		if (ret == -1)
			printf("未找到该好友\n");
		else if (ret == 0)//删除最后一个好友
		{
			con->size--;
			printf("删除成功\n");
		}
		else
		{
			int j = 0;
			for (j = ret; j < con->size - 1; j++)
			{
				con->data[j] = con->data[j + 1];
			}
			con->size--;
			printf("删除成功\n");
		}
	}
}

//查找好友信息
void SearchContact(const struct Contact* con)
{
	if (Whether(con))
	{
		char name[MAX_NAME];
		printf("请输入要查找的好友名:> \n");
		scanf("%s", name);
		int ret = FindByName(con, name);
		if (ret == -1)
		{
			printf("未找到该好友!\n");
		}
		else
		{
			printf("好友信息为:\n");
			PrintMenu();
			PrintInfo(con, ret);
		}
	}
}

//修改好友信息
void ModifyContact(struct Contact* con)
{
	if (Whether(con))
	{
		char name[MAX_NAME];
		printf("请输入要修改的好友名:> \n");
		scanf("%s", name);
		int ret = FindByName(con, name);
		if (ret == -1)
		{
			printf("未找到该好友!\n");
		}
		else
		{
			InputInfo(con, ret);
			printf("修改成功!\n");
		}
	}
}

//排序好友信息(按名字首字母排序，从小到大)
void SortContact(struct Contact* con)
{
	struct PeoInfo cmp;
	int i = 0;
	int j = 0;
	for (i = 0; i < con->size; i++)
	{
		for (j = 0; j < con->size-1-i; j++)
		{
			if (strcmp(con->data[j].name, con->data[j + 1].name) > 0)
			{
				cmp = con->data[j];
				con->data[j] = con->data[j+1];
				con->data[j+1] = cmp;
			}
		}
	}
	printf("已按名字从小到大排序成功!\n");
}