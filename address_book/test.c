#define _CRT_SECURE_NO_WARNINGS
#include "address_book.h"
void menu()
{
	printf("*******************************************************\n");
	printf("**********    1.add             2.del        **********\n");
	printf("**********    3.search          4.modify     **********\n");
	printf("**********    5,show            6,sort       **********\n");
	printf("**********    0.exit                         **********\n");
	printf("*******************************************************\n");

}
int main()
{
	int input;
	struct Address_book book;
	struct Address_book b;
	Init_Address_book(&book);
	do
	{
		menu();
		printf("请选择你要处理的方式--> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Add_book(&book);
			break;
		case 2:
			Del_book(&book);
			break;
		case 3:
			Search_book(&book);
			break;
		case 4:
			Modify_book(&book);
			break;
		case 5:
			Show_book(&book);
			break;
		case 6:
			Sort_book(&book);
			break;
		case 0:
			printf("结束\n");
			break;
		default:
			printf("请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}