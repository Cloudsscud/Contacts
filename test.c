#include "Contact.h"

void menu()
{
	printf("****************************\n");
	printf("***1、Add       2、del   ***\n");
	printf("***3、search    4、modify***\n");
	printf("***5、show      6、sort  ***\n");
	printf("***       0、exit        ***\n");
	printf("****************************\n");
}
int main()
{
	int input = 0;
	//生成通讯录
	struct Contact con;//con即为一个通讯录，内含1000个元素的数据的和，与size
	//初始化通讯录
	InitContact(&con);

	do
	{
		menu();
		printf("请选择:> ");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			//增加好友信息
			AddContact(&con);
			break;
		case DEL:
			//删除
			DelContact(&con);
			break;
		case SEARCH:
			//查找
			SearchContact(&con);
			break;
		case MODIFY:
			//修改
			ModifyContact(&con);
			break;
		case SHOW:
			//显示
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("您已退出\n");
			break;
		default:
			printf("您输入了错误信息\n");
			break;
		}
	} while (input);
	return 0;
}