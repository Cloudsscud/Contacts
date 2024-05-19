#include "Contact.h"

//��ʼ��ͨѶ¼
void InitContact(struct Contact* con)
{
	memset(con->data, 0, sizeof(con->data));
	con->size = 0;//ͨѶ¼�����0��Ԫ��
}

//�ڶ�Ӧ�±�����Ԫ����Ϣ
static void InputInfo(struct Contact* con, int cmp)
{
	printf("����������:> ");
	scanf("%s", con->data[cmp].name);
	printf("����������:> ");
	scanf("%d", &(con->data[cmp].age));
	printf("�������Ա�:> ");
	scanf("%s", con->data[cmp].sex);
	printf("������绰:> ");
	scanf("%s", con->data[cmp].tele);
	printf("�������ַ:> ");
	scanf("%s", con->data[cmp].addr);
}

//�����Ӧ�±�Ԫ����Ϣ
static void PrintInfo(const struct Contact* con, int cmp)
{
	printf("%-20s\t%-4d\t%-6s\t%-12s\t%-30s\n",
		con->data[cmp].name,
		con->data[cmp].age,
		con->data[cmp].sex,
		con->data[cmp].tele,
		con->data[cmp].addr);
}

//�����Ϣ�Ĳ˵�
static void PrintMenu()
{
	printf("%-20s\t%-4s\t%-6s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
}

//���Ӻ�����Ϣ
void AddContact(struct Contact* con)
{
	if (con->size == MAX)
	{
		printf("����λ����,�޷����!\n");
	}
	else
	{
		InputInfo(con, con->size);
		con->size++;
		printf("��ӳɹ�!\n");
	}
}

//�жϺ����Ƿ�Ϊ��
static int Whether(const struct Contact* con)
{
	if (con->size == 0)
	{
		printf("��ǰ�޺��ѣ�������Ӻ���!\n");
		return 0;
	}
	return 1;
}

//ͨ�������Һ���--�ҵ��ͷ�������Ԫ�ص��±꣬���򷵻�-1
static int FindByName(const struct Contact* con, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < con->size; i++)
	{
		if (strcmp(con->data[i].name, name) == 0)
			return i;//�ҵ�
	}
	return -1;//δ�ҵ�
}

//��ʾ������Ϣ
void ShowContact(const struct Contact* con)
{
	if (Whether(con))//�ж��Ƿ��к���
	{
		int i = 0;
		PrintMenu();
		for (i = 0; i < con->size; i++)
		{
			PrintInfo(con, i);
		}
	}
}

//ɾ��������Ϣ
void DelContact(struct Contact* con)
{
	if (Whether(con))
	{
		char name[MAX_NAME];
		printf("��������Ҫɾ���ĺ�������:>");
		scanf("%s", name);
		int ret = FindByName(con, name);
		if (ret == -1)
			printf("δ�ҵ��ú���\n");
		else if (ret == 0)//ɾ�����һ������
		{
			con->size--;
			printf("ɾ���ɹ�\n");
		}
		else
		{
			int j = 0;
			for (j = ret; j < con->size - 1; j++)
			{
				con->data[j] = con->data[j + 1];
			}
			con->size--;
			printf("ɾ���ɹ�\n");
		}
	}
}

//���Һ�����Ϣ
void SearchContact(const struct Contact* con)
{
	if (Whether(con))
	{
		char name[MAX_NAME];
		printf("������Ҫ���ҵĺ�����:> \n");
		scanf("%s", name);
		int ret = FindByName(con, name);
		if (ret == -1)
		{
			printf("δ�ҵ��ú���!\n");
		}
		else
		{
			printf("������ϢΪ:\n");
			PrintMenu();
			PrintInfo(con, ret);
		}
	}
}

//�޸ĺ�����Ϣ
void ModifyContact(struct Contact* con)
{
	if (Whether(con))
	{
		char name[MAX_NAME];
		printf("������Ҫ�޸ĵĺ�����:> \n");
		scanf("%s", name);
		int ret = FindByName(con, name);
		if (ret == -1)
		{
			printf("δ�ҵ��ú���!\n");
		}
		else
		{
			InputInfo(con, ret);
			printf("�޸ĳɹ�!\n");
		}
	}
}

//���������Ϣ(����������ĸ���򣬴�С����)
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
	printf("�Ѱ����ִ�С��������ɹ�!\n");
}