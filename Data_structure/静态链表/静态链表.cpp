#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxSize 6

typedef struct {
	int data;//数据域
	int cur;//游标
}component;

//创建备用链表
void reserveArr(component *arr) {
	for (int i = 0; i < maxSize; i++) {
		arr[i].cur = i + 1;//将每个分组分量链接在一起
		arr[i].data = -1;
	}
	arr[maxSize - 1].cur = 0;//链表最后一个节点的游标值为0
}

//提取分配空间
int mallocArr(component *arr) {
	//若备用链表非空，则返回分配的节点下标，否则返回0（当分配最后一个节点时，该节点的游标值为0）
	int i = arr[0].cur;
	if (arr[0].cur) {
		arr[0].cur = arr[i].cur;
	}
	return i;
}

//初始化静态链表
int initArr(component *arr) {
	reserveArr(arr);
	int body = mallocArr(arr);
	//声明一个变量，把它当做指针，指向链表的最后一个节点，因为链表为空，所以和头结点重合
	int tempBody = body;
	for (int i = 1; i < 4; i++) {
		int j = mallocArr(arr);//从备用链表中拿出空闲的分量
		arr[tempBody].cur = j; //将申请的空闲分量链接在链表的最后一个节点后面
		arr[j].data = i;//给新申请的分量的数据域初始化
		tempBody = j;
	}
	arr[tempBody].cur = 0;
	return body;
}

//遍历静态链表所有元素
void displayArr(component * arr, int body) {
	int tempBody = body;//tempBody准备做遍历使用
	while (arr[tempBody].cur) {
		printf("%d,%d ", arr[tempBody].data, arr[tempBody].cur);
		tempBody = arr[tempBody].cur;
	}
	printf("%d,%d\n", arr[tempBody].data, arr[tempBody].cur);
}

//向链表中插入数据
//body表示链表的头结点在数组中的位置，add表示插入元素的位置，a表示要插入的数据
void insertArr(component * arr, int body, int add, char a) {
	int tempBody = body;//tempBody做遍历结构体数组使用
	//找到要插入位置的上一个节点在数组中的位置
	for (int i = 1; i < add; i++) {
		tempBody = arr[tempBody].cur;
	}
	int insert = mallocArr(arr);//申请空间，准备插入
	arr[insert].data = a;
	arr[insert].cur = arr[tempBody].cur;//新插入节点的游标等于其直接前驱节点的游标
	arr[tempBody].cur = insert;//直接前驱节点的游标等于新插入节点所在数组中的下标
}

//备用链表回收空间的函数，其中arr为存储数据的数组，k表示未使用节点所在数组的下标
void freeArr(component * arr, int k) {
	arr[k].cur = arr[0].cur;
	arr[0].cur = k;
}
//删除节点函数
//a表示被删除结点中数据域存放的数据
void deletArr(component * arr, int body, char a) {
	int tempBody = body;
	//找到被删除节点的位置
	while (arr[tempBody].data != a) {
		tempBody = arr[tempBody].cur;
		//当tempBody为0时，表示链表遍历结束，说明链表中没有存储该数据的节点
		if (tempBody == 0) {
			printf("链表中没有此数据");
			return;
		}
	}
	//运行到此，证明有该节点
	int del = tempBody;
	tempBody = body;
	//找到该节点的上一个节点，做删除操作
	while (arr[tempBody].cur != del) {
		tempBody = arr[tempBody].cur;
	}
	//将被删除节点的游标直接给被删除节点的上一个节点
	arr[tempBody].cur = arr[del].cur;
	//回收被摘除节点的空间
	freeArr(arr, del);
}

//查找元素
//在以body作为头结点的链表中查找数据域为elem的节点在数组中的位置
int selectElem(component * arr, int body, char elem) {
	int tempBody = body;
	//当游标值为0时，表示链表结束
	while (arr[tempBody].cur != 0) {
		if (arr[tempBody].data == elem) {
			return tempBody;
		}
		tempBody = arr[tempBody].cur;
	}
	return -1;//返回-1，表示在链表中没有找到该元素
}

//更改数据
//在以body作为头结点的链表中将数据域为oldElem的节点，数据域为newElem
void amendElem(component * arr, int body, char oldElem, char newElem) {
	int add = selectElem(arr, body, oldElem);
	if (add == -1) {
		printf("无更改元素");
		return;
	}
	arr[add].data = newElem;
}

int main()
{
	component arr[maxSize];
	int body = initArr(arr);
	printf("静态链表为：\n");
	displayArr(arr, body);

	printf("在第3的位置上插入结点‘e’:\n");
	insertArr(arr, body, 3, 'e');
	displayArr(arr, body);

	printf("删除数据域为‘a’的结点:\n");
	deletArr(arr, body, 'a');
	displayArr(arr, body);

	printf("查找数据域为‘e’的结点的位置:\n");
	int selectAdd = selectElem(arr, body, 'e');
	printf("%d\n", selectAdd);
	printf("将结点数据域为‘e’改为‘h’:\n");
	amendElem(arr, body, 'e', 'h');
	displayArr(arr, body);

	system("pause");
	return EXIT_SUCCESS;
}

