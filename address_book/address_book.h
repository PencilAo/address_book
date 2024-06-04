#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX  5
#define MAX_TELE 12
#define MAX_ADDRESS 30
//记录人的信息
struct Peo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
};
struct Address_book
{
	struct Peo data[MAX];    // 存放人的信息
	int count;               // 记录当前通讯录中实际人的个数
};
void Init_Address_book(struct Address_book* pc);
void Add_book(struct Address_book* pc);
void Del_book(struct Address_book* pc);
void Show_book(const struct Address_book* pc);
void Search_book(const struct Address_book* pc);
void Modify_book(struct Address_book* pc);
void Sort_book(struct Address_book* pc);