#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#include <stdio.h>
#include <stdlib.h>
typedef int Status;
typedef struct
{
	float coef;//ϵ��
	int expn;//ָ��
}Polynomial;
typedef struct
{
	Polynomial* elem;
	int length;
}SqList;
SqList L;
bool operator==(const SqList& e1, const SqList& e2) {
	if ((e1.elem->coef == e2.elem->coef) && (e1.elem->expn == e2.elem->expn))
		return true;
	else
		return false;
}
bool operator==(const Polynomial& p1, const Polynomial& p2) {
	if ((p1.coef == p2.coef) && (p1.expn == p2.expn))
		return true;
	else
		return false;
}
//˳���ĳ�ʼ��
Status InitList(SqList& L)
{
	L.elem = new Polynomial[MAXSIZE];
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	return OK;
}
//ȡֵ
Status GetElem(SqList& L, int i, Polynomial& e)
{
	if (i<1 || i>L.length) return ERROR;
	e = L.elem[i - 1];
	return OK;
}
//����
Status LocateElem(SqList& L, Polynomial e)
{
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == e) return i + 1;
	return 0;
}
//����
Status ListInsert(SqList& L, int i, Polynomial e) {
	if ((i<1) || (i>L.length + 1)) return ERROR;
	if (L.length == MAXSIZE) return ERROR;
	for (int j = L.length - 1; j <= i - 1; j--)
		L.elem[j + 1] = L.elem[j];
	L.elem[i - 1] = e;
	++L.length;
	return OK;
}
//ɾ��
Status ListDelete(SqList& L, int i)
{
	if ((i < 1) || (i > L.length)) return ERROR;
	for (int j = i; j < L.length; j++)
		L.elem[j-1] = L.elem[j];
	--L.length;
	return OK;
}
