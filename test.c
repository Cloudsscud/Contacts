#include "Contact.h"

void menu()
{
	printf("****************************\n");
	printf("***1��Add       2��del   ***\n");
	printf("***3��search    4��modify***\n");
	printf("***5��show      6��sort  ***\n");
	printf("***       0��exit        ***\n");
	printf("****************************\n");
}
int main()
{
	int input = 0;
	//����ͨѶ¼
	struct Contact con;//con��Ϊһ��ͨѶ¼���ں�1000��Ԫ�ص����ݵĺͣ���size
	//��ʼ��ͨѶ¼
	InitContact(&con);

	do
	{
		menu();
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			//���Ӻ�����Ϣ
			AddContact(&con);
			break;
		case DEL:
			//ɾ��
			DelContact(&con);
			break;
		case SEARCH:
			//����
			SearchContact(&con);
			break;
		case MODIFY:
			//�޸�
			ModifyContact(&con);
			break;
		case SHOW:
			//��ʾ
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("�����˳�\n");
			break;
		default:
			printf("�������˴�����Ϣ\n");
			break;
		}
	} while (input);
	return 0;
}