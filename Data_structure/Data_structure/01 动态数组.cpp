#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1、先把所需要的数据信息结构定义下来
struct DynamicArray
{
	//数组存储元素的空间的首地址
	void **addr;
	//存储数据的内存中最大能够容纳多少元素
	int capacity; //容量
	//当前存储数据的内存中有多少个元素
	int size; //大小
};


//初始化数组
struct DynamicArray *Init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}
	struct DynamicArray *arr = (DynamicArray *)malloc(sizeof(struct DynamicArray));
	if (NULL == arr)
	{
		return NULL;
	}
	arr->capacity = capacity;
	arr->addr = (void **)malloc(sizeof(void *)*arr->capacity);
	arr->size = 0;
}
//插入元素
void Insert(struct DynamicArray *arr, int pos, void *data)
{
	if (NULL == arr)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}

}
//遍历
void Foreach(struct DynamicArray *arr, void(*_callback)(void *))
{
	if (NULL == arr)
	{
		return;
	}

	if (NULL == _callback)
	{
		return;
	}

	for (int i = 0; i < arr->size; ++i)
	{
		_callback(arr->addr[i]);
	}
}



int main()
{




	system("pause");
	return EXIT_SUCCESS;
}
