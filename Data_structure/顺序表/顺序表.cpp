#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5 //对SIZE进行宏定义，表示顺序表申请空间的大小

//顺序表的初始化
//顺序表需要实时记录以下两项数据
//1、顺序表的长度，也就是表中存储数据元素的个数
//2、顺序表申请的存储容量
typedef struct Table {
	int * head;//声明一个名为head的长度不确定的数组，也叫动态数组
	int length;//记录了当前顺序表的长度
	int size;//记录顺序表分配的存储容量
}table;

//初始化顺序表
table initTable() {
	table t;
	t.head = (int*)malloc(SIZE * sizeof(int));//构造一个空的顺序表，动态申请存储空间
	if (!t.head) //如果申请失败，作出提示并直接退出程序
	{
		printf("初始化失败");
		exit(0);
	}
	t.length = 0;
	t.size = SIZE;
	return t;
}

//遍历顺序表中元素的函数
void displayTable(table t) {
	for (int i = 0; i < t.length; i++) {
		printf("%d ", t.head[i]);
	}
	printf("\n");
}

//插入函数，其中，elem为插入的元素，add为插入到顺序表的位置
table addTable(table t, int elem, int add) {
	//判断插入本身是否存在问题
	//如果插入元素位置比整张表的长度+1还大（相等的话，是尾随情况）
	//或者插入位置本身不存在，程序提示并返回原顺序表
	if (add > t.length + 1 || add < 1) {
		printf("插入位置有问题\n");
		return t;
	}
	//插入操作时，首先需要看顺序表是否有多余的存储空间提供给插入的元素
	//如果没有，则需要申请
	if (t.length == t.size) {
		t.head = (int*)realloc(t.head, (t.size + 1) * sizeof(int));
		if (!t.head)
		{
			printf("存储分配失败\n");
			return t;
		}
		t.size++;
	}
	//插入操作，需要从插入位置开始的后续元素，逐个后移
	for (int i = t.length - 1; i >= add - 1; i--) {
		t.head[i + 1] = t.head[i];
	}
	//后移完成后，直接将所需要插入元素，添加到顺序表的相应位置
	t.head[add - 1] = elem;
	//添加了元素，长度+1
	t.length++;
	return t;
}

//删除元素
table delTable(table t, int add) {
	if (add > t.length || add < 1) {
		printf("删除位置有误\n");
		return t;
	}
	//删除操作
	for (int i = add; i < t.length; i++) {
		t.head[i - 1] = t.head[i];
	}
	t.length--;
	return t;
}

//查找函数，其中elem为所要查找的数据元素的值
int selectTable(table t, int elem) {
	for (int i = 0; i < t.length; i++) {
		if (t.head[i] == elem) {
			return i + 1;
		}
	}
	//如果查找失败，返回-1
	return -1;
}

//顺序表更改元素
//1、找到目标元素
//2、直接修改该元素的值
table amendTable(table t, int elem, int newElem) {
	int add = selectTable(t, elem);
	//返回的元素是顺序表中的位置，所以-1就是该元素在数组中的下标
	t.head[add - 1] = newElem;
	return t;
}

int main()
{
	table t = initTable();
	//向顺序表中添加元素
	for (int i = 0; i < SIZE; i++) {
		t.head[i] = i + 1;
		t.length++;
	}
	displayTable(t);
	t = addTable(t, 88, 3);
	displayTable(t);
	t = delTable(t, 4);
	displayTable(t);
	int a = selectTable(t, 88);
	printf("位置：%d\n", a);
	t = amendTable(t, 88, 77);
	displayTable(t);
	system("pause");
	return EXIT_SUCCESS;
}
