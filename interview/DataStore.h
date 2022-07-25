#pragma once

struct Student
{
	int id;
	char name[16];
	Student* next;
};


class DataStore
{
public:
	DataStore();
	~DataStore();

public:
	void Add(const Student* data);
	Student* find(int id);
	void Print();

private:
	Student m_head;

};
