#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct line {
	struct line * prior;//指向直接前驱
	int data;
	struct line * next;//指向直接后继
}line;

//创建双链表
line* initLine(line * head) {
	head = (line*)malloc(sizeof(line));//创建双链表的第一个节点（首元结点）
	head->prior = NULL;
	head->next = NULL;
	head->data = 1;
	line * list = head;
	for (int i = 2; i <= 5; i++) {
		//创建并初始化一个新节点
		line * body = (line*)malloc(sizeof(line));
		body->prior = NULL;
		body->next = NULL;
		body->data = i;

		list->next = body;//直接前驱节点的next指针指向新的节点
		body->prior = list;//新节点指向直接前驱节点
		list = list->next;
	}
	return head;
}

//遍历双链表
void display(line * head) {
	line * temp = head;
	while (temp) {
		//如果该节点无后继节点，说明此节点是链表的最后一个节点
		if (temp->next == NULL) {
			printf("%d\n", temp->data);
		}
		else {
			printf("%d<->", temp->data);
		}
		temp = temp->next;
	}
}

//插入操作
line * insertLine(line * head, int data, int add) {
	//新建数据域为data的结点
	line * temp = (line*)malloc(sizeof(line));
	temp->data = data;
	temp->prior = NULL;
	temp->next = NULL;
	//插入到链表头，要特殊考虑
	if (add == 1) {
		temp->next = head;
		head->prior = temp;
		head = temp;
	}
	else {
		line * body = head;
		//找到要插入位置的前一个节点
		for (int i = 1; i < add - 1; i++) {
			body = body->next;
		}
		//判断条件为真，说明插入位置为链表尾
		if (body->next == NULL) {
			body->next = temp;
			temp->prior = body;
		}
		else {
			body->next->prior = temp;
			temp->next = body->next;
			body->next = temp;
			temp->prior = body;
		}
	}
	return head;
}

//删除节点
//data为要删除节点的数据域的值
line * delLine(line * head, int data) {
	line * temp = head;
	//遍历链表
	while (temp) {
		//判断当前节点中的数据域和data是否相等，若相等，摘除该节点
		if (temp->data == data) {
			temp->prior->next = temp->next;
			temp->next->prior = temp->prior;
			free(temp);
			return head;
		}
		temp = temp->next;
	}
	printf("链表中无该数据元素。");
	return head;
}

//查找节点
//head为原双链表，elem表示被查找元素
int selectElem(line * head, int elem) {
	//新建一个指针t，初始化为头指针head
	line * t = head;
	int i = 1;
	while(t) {
		if (t->data == elem) {
			return i;
		}
		i++;
		t = t->next;
	}
	//程序至此，说明查找失败
	return -1;
}

//更改节点
//其中，add表示更该节点在双链表中的位置，newElem为新数据的值
line * amendElem(line * p, int add, int newElem) {
	line * temp = p;
	//遍历到被删除的节点
	for (int i = 1; i < add; i++) {
		temp = temp->next;
	}
	temp->data = newElem;
	return p;
}

int main()
{
	line * head = NULL;
	//创建双链表
	head = initLine(head);
	display(head);
	//在表中第 3 的位置插入元素 7
	head = insertLine(head, 7, 3);
	display(head);
	//表中删除元素 2
	head = delLine(head, 2);
	display(head);
	printf("元素 3 的位置是：%d\n", selectElem(head, 3));
	//表中第 3 个节点中的数据改为存储 6
	head = amendElem(head, 3, 6);
	display(head);

	system("pause");
	return EXIT_SUCCESS;
}

