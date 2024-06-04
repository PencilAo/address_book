#define _CRT_SECURE_NO_WARNINGS
#include "address_book.h"


//初始化通讯录
void Init_Address_book(struct Address_book* pc)
{
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}
void Add_book(struct Address_book* pc)
{
	assert(pc);
	if (pc->count == MAX)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入名字-> ");
		scanf("%s",pc->data[pc->count].name);     //名字是char 类型，不需要取地址
		printf("请输入年龄-> ");
		scanf("%d", &(pc->data[pc->count].age));  //年龄是需要取地址的
		printf("请输入性别-> ");
		scanf("%s", pc->data[pc->count].sex);
		printf("请输入电话-> ");
		scanf("%s", pc->data[pc->count].tele);
		printf("请输入地址-> ");
		scanf("%s", pc->data[pc->count].address);

		pc->count++;
		printf("增加成功\n");
	}
}
static int Findbyname(struct Address_book* pc, char name[])  // 加了static后，此函数只能在这个文件下使用
{
	assert(pc);
	int i;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void Del_book(struct Address_book* pc)
{
	assert(pc);
	char name[MAX_NAME];
	if (pc->count == 0)
	{
		printf("通讯录为空，没有信息可以删\n");
		return;
	}
	printf("请输入要删除人的名字-> ");
	scanf("%s", name);
	  //删除
	//1. 查找
	int i;
	int ret = Findbyname(pc, name);
	if (ret == -1)
	{
		printf("要删除的不在通讯录里面\n");
		return;
	}

	//2. 删除
	for (i = ret; i < pc->count-1; i++)   // 这里-1可以防止越界访问
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
}
void Show_book(struct Address_book* pc)
{
	assert(pc);
	int i;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n",     pc->data[i].name,
								pc->data[i].age, 
								pc->data[i].sex, 
								pc->data[i].tele,
								pc->data[i].address);
	}
}
void Search_book(struct Address_book* pc)
{
	assert(pc);
	printf("请输入你要查找的人-> ");
	char name[MAX_NAME];
	scanf("%s", name);
	int ret = Findbyname(pc, name);
	if (ret == -1)
	{
		printf("要查找的人不在通讯录中\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n",     pc->data[ret].name,
						        pc->data[ret].age,
							pc->data[ret].sex,
							pc->data[ret].tele,
							pc->data[ret].address);
}
void Modify_book(struct Address_book* pc)
{
	assert(pc);
	printf("请输入你要修改的人-> ");
	char name[MAX_NAME];
	scanf("%s", name);
	//查找
	int ret = Findbyname(pc, name);
	if (ret == -1)
	{
		printf("要修改的人不在通讯录中\n");
		return;
	}
	//修改
	printf("请输入修改后的名字-> ");
	scanf("%s", pc->data[ret].name);       //名字是char 类型，不需要取地址
	printf("请输入修改后的年龄-> ");
	scanf("%d", &(pc->data[ret].age));     //年龄是需要取地址的
	printf("请输入修改后的性别-> ");
	scanf("%s", pc->data[ret].sex);
	printf("请输入修改后的电话-> ");
	scanf("%s", pc->data[ret].tele);
	printf("请输入修改后的地址-> ");
	scanf("%s", pc->data[ret].address);

	printf("修改成功\n");
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[ret].name,
		pc->data[ret].age,
		pc->data[ret].sex,
		pc->data[ret].tele,
		pc->data[ret].address);
}

//按名字排序
int cmp_by_name(void* e1, void* e2)
{
	return strcmp(((struct Peo*)e1)->name,((struct Peo*)e2)->name);
}
int cmp_by_age(void* e1, void* e2)
{
	return strcmp(((struct Peo*)e1)->age, ((struct Peo*)e2)->age);
}
void Sort_book(struct Address_book* pc, struct Address_book* b)
{
	assert(pc);
	printf("选择你的排序方法-> (1为按名字排序，2为按年龄排序) \n");
	int i;
	scanf("%d", &i);
	if (i == 1)
	{
		qsort(pc->data, pc->count, sizeof(struct Peo), cmp_by_name);
		printf("排序成功\n");
	}
	else
	{
		qsort(pc->data, pc->count, sizeof(struct Peo), cmp_by_age);
		printf("排序成功\n");
	}

}
