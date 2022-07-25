#include<iostream>
#include<string>
#include<stdlib.h>

#include "DataStore.h"
using namespace std;

DataStore::DataStore()  //构造函数
{
	m_head.next = NULL;
};
DataStore::~DataStore()   //析构函数
{
	Student* p = m_head.next;
	while (p) 
	{
		Student* next = p->next;
		free(p);
		p = next;
	}
}

void DataStore::Add(const Student* data)
{
	//創建對象,複製數據
	Student* copy = (Student*)malloc(sizeof(Student));
	*copy = *data;

	//插入一個對象到鏈表中
	Student* cur = m_head.next;    //當前節點current
	Student* pre = &m_head;
	while (cur) 
	{
		if (copy->id < cur->id) //找到這個位置
		{
			break;
		}
		pre = cur;
		cur = cur->next;    // 找到最後一個對象
	}

	// 插入到pre節點的後面
	copy->next = pre->next;
	pre->next = copy;
}
Student* DataStore::find(int id)
{
	Student* p = m_head.next;
	while (p) 
	{
		if (p->id == id) 
		{
			return p;
		}
		p = p->next;		//下一个对象 
	}
	return NULL;
}
void DataStore::Print()
{
	Student* p = m_head.next;
	while (p) 
	{
		cout << "ID: " << p->id << "    Name: " << p->name << endl;
		p = p->next;		//下一个对象
	}
}



