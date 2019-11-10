#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Link {
	char elem;//代表数据域
	struct Link * next;//代表指针域，指向直接后继元素
}link; //link为节点名，每个节点都是一个link结构体

//链表的创建（初始化）
//1、声明一个头指针（如果有必要，可以声明一个头结点）
//2、创建多个存储数据的节点，在创建过程中，要随时与其前驱节点简历逻辑关系
link * initLink() {
	link * p = NULL;//创建头指针
	link * temp = (link*)malloc(sizeof(link));//创建首元结点
	//首元结点先初始化
	temp->elem = 1;
	temp->next = NULL;
	p = temp; //头指针指向首元结点

	//从第二个节点开始创建
	for (int i = 2; i < 5; i++) {
		//创建一个新节点并初始化
		link *a = (link*)malloc(sizeof(link));
		a->elem = i;
		a->next = NULL;
		//将temp节点与新建立的a节点建立逻辑关系
		temp->next = a;
		temp = a;
	}
	//返回建立的节点，只返回头指针p即可，通过头指针即可找到整个链表
	return p;
}

//链表的创建（包含头结点）
link * initLink_head() {
	link * p = (link*)malloc(sizeof(link)); //创建一个头结点
	link * temp = p;//声明一个指针指向头结点
	//生成链表
	for (int i = 1; i < 5; i++) {
		link *a = (link*)malloc(sizeof(link));
		a->elem = i;
		a->next = NULL;
		temp->next = a;
		temp = temp->next;//也可以写成temp = a;
	}
	return p;
}

//遍历链表内元素(无头结点）
void display(link *p) {
	link * temp = p;//将temp指针重新指向头结点
	//只要temp指针指向的节点不是NULL，就执行输出语句。
	while (temp) {
		printf("%d ", temp->elem);
		temp = temp->next;
	}
	printf("\n");
}

//遍历链表内元素(有头结点）
void display_head(link *p) {
	link * temp = p;//将temp指针重新指向头结点
	//只要temp指针指向的节点的next不是NULL，就执行输出语句。
	while (temp->next) {
		printf("%d ", temp->next->elem);
		temp = temp->next;
	}
	printf("\n");
}

//***********以下操作针对有头结点的链表***********//
//插入操作
//p为原链表，elem表示新的数据元素，add表示新元素要插入的位置
link * insertElem(link * p, int elem, int add) {
	link * temp = p;//创建临时节点temp
	//首先找到要插入位置的上一个节点
	for (int i = 1; i < add; i++) {
		temp = temp->next;
		if (temp == NULL) {
			printf("插入位置无效\n");
			return p;
		}
	}
	//创建插入节点c
	link * c = (link*)malloc(sizeof(link));
	c->elem = elem;
	c->next = temp->next;
	temp->next = c;
	return p;
}

//删除操作
//p为原链表，add为要删除元素的位置
link * delElem(link * p, int add) {
	link * temp = p;
	//遍历到被删除节点的上一个节点
	for (int i = 1; i < add; i++) {
		temp = temp->next;
		if (temp->next == NULL) {
			printf("没有该节点\n");
			return p;
		}
	}
	link * del = temp->next;// 单独设置一个指针指向被删除的节点，以防丢失
	temp->next = temp->next->next;//删除某个节点的方法就是更改前一个节点的指针域
	free(del);//手动释放该节点，防止内存泄露
	return p;
}

//链表查找元素
//p为原链表，elem表示被查找元素
int selectElem(link * p, int elem) {
	//新建一个指针t，初始化为头指针p
	link * t = p;
	int i = 1;
	//由于头结点的存在，因此while中的判断为t->next
	while (t->next) {
		t = t->next;
		if (t->elem == elem) {
			return i;
		}
		i++;
	}
	//程序执行至此处，表示查找失败
	return -1;
}

//链表更新元素
//add表示更该节点在链表中的位置，newElem为新的数据域的值
link *amendElem(link * p, int add, int newElem) {
	link * temp = p;
	temp = temp->next;//遍历之前，temp指向首元结点
	//遍历到待更新节点
	for (int i = 1; i < add; i++) {
		temp = temp->next;
	}
	temp->elem = newElem;
	return p;
}


int main()
{
	link *p = initLink_head();
	display_head(p);
	p = insertElem(p, 88, 3);
	display_head(p);
	p = delElem(p, 2);
	display_head(p);
	int a = selectElem(p, 88);
	printf("位置：%d\n", a);
	p = amendElem(p, 2, 77);
	display_head(p);

	system("pause");
	return EXIT_SUCCESS;
}

