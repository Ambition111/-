#pragma once

typedef int Elemtype;
typedef struct Node
{
	Elemtype data;
	struct Node* next;
}List;

void InitList(List** list);

void InsertListHead(List** list, Elemtype val);
void InsertList(List** list, Elemtype val, int pos);
void InsertListTail(List** list, Elemtype val);

void DeleteList(List** list, int pos);
void DeleteListHead(List** list);
void DeleteListTail(List** list);
void DeleteListValue(List** list, Elemtype val);

void ShowList(List** list);

void DestroyList(List** list);
