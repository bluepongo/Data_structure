#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int front = 0, rear = 0;

typedef struct BiTNode {
	int data; //数据域
	struct BiTNode *lchild, *rchild;//左右孩子指针
}BiTNode, *BiTree;

void CreateBiTree(BiTree *T) {
	*T = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->data = 1;
	(*T)->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->rchild = (BiTNode*)malloc(sizeof(BiTNode));

	(*T)->lchild->data = 2;
	(*T)->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->lchild->rchild->data = 5;
	(*T)->lchild->rchild->lchild = NULL;
	(*T)->lchild->rchild->rchild = NULL;
	(*T)->rchild->data = 3;
	(*T)->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->rchild->lchild->data = 6;
	(*T)->rchild->lchild->lchild = NULL;
	(*T)->rchild->lchild->rchild = NULL;
	(*T)->rchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->rchild->rchild->data = 7;
	(*T)->rchild->rchild->lchild = NULL;
	(*T)->rchild->rchild->rchild = NULL;
	(*T)->lchild->lchild->data = 4;
	(*T)->lchild->lchild->lchild = NULL;
	(*T)->lchild->lchild->rchild = NULL;
}

//输出结点本身数值
void displayElem(BiTNode * elem) {
	printf("%d", elem->data);
}

//先序遍历
void PreOrderTraverse(BiTree T) {
	if (T) {
		displayElem(T);//调用操作节点数据的函数方法
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	//如果节点为空，返回上一层
	return;
}

//中序遍历
void INOrderTraverse(BiTree T) {
	if (T) {
		INOrderTraverse(T->lchild);//遍历左孩子
		displayElem(T);//调用操作结点数据的函数方法
		INOrderTraverse(T->rchild);//遍历右孩子
	}
	//如果结点为空，返回上一层
	return;
}

//后序遍历
void PostOrderTraverse(BiTree T) {
	if (T) {
		PostOrderTraverse(T->lchild);//遍历左孩子
		PostOrderTraverse(T->rchild);//遍历右孩子
		displayElem(T);//调用操作结点数据的函数方法
	}
	//如果结点为空，返回上一层
	return;
}

//入队函数
void EnQueue(BiTree * a, BiTree node) {
	a[rear++] = node;
}

//出队函数
BiTNode * DeQueue(BiTNode ** a) {
	return a[front++];
}

int main()
{
	BiTree tree;
	//初始化二叉树
	CreateBiTree(&tree);
	BiTNode * p;
	//采用顺序队列，初始化创建队列数组
	BiTree a[20];
	//根结点入队
	EnQueue(a, tree);
	//当队头和队尾相等时，表示队列为空
	while (front < rear) {
		//队头结点出队
		p = DeQueue(a);
		displayElem(p);
		//将队头结点的左右孩子依次入队
		if (p->lchild != NULL) {
			EnQueue(a, p->lchild);
		}
		if (p->rchild != NULL) {
			EnQueue(a, p->rchild);
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}