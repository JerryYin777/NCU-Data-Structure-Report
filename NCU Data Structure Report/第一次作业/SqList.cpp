#include <iostream>
#include "status.h"
#include "sqlist.h"

#define LIST_INIT_SIZE 100 //��ʼ���� 
#define LISTINCREMENT 10 	//��̬���������� 
using namespace std;

Status InitList_Sq(SqList &L){
	//�����ڴ�ռ� 
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW); 	//����ʧ�ܣ����� 
	L.length = 0;					//�ձ���Ϊ0 
	L.listsize = LIST_INIT_SIZE;	//��ʼ�洢�� 
	return OK;
}//InitList_Sq

Status DestroyList_Sq(SqList &L){
	if(L.elem) free(L.elem);	//������Ա���ڣ����ͷſռ� 
	if(!L.elem) exit(OVERFLOW); //������Ա����ڣ��򱨴�
	return OK;
}//DestroyList_Sq

Status ClearList_Sq(SqList &L){
	L.length = 0;
	return OK;
}//ClearList_Sq

int ListLength_Sq(SqList L){
	return L.length;
}//ListLength_Sq

Status GetElem_Sq(SqList L, int i, ElemType &e){
	if (i<1 || i>L.length+1) return ERROR; //���i���ڵ�ǰL��
	ElemType *q = &(L.elem[i-1]); //ȡ��λ��
 	e = *q;				//ȡ��Ԫ�� 
	return OK;
}//GetElem_Sq

Status LocateElem(SqList L, ElemType e,Status (* compare)(ElemType, ElemType)){
	//����ҵ�����Ҫ��ģ�����λ�򣬷��򷵻�0 
	int i = 1;		//i�ĳ�ֵΪ��1��Ԫ�ص�λ��
	int *p = L.elem;	//p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��
	while(i<=L.length && !(* compare)(*p++, e)) ++i;
	if(i<=L.length) return i;
	else return 0; 
}//LocateElem

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e){
	int i = 1;
	while(i<=L.length && cur_e!=L.elem[i-1]) i++;
	if (i<=L.length){
		pre_e = L.elem[i-2];	//��ǰֵ��ǰ��ȡ���� 
		return OK;
	}
	else{
		return ERROR;
	}
}//PriorElem 

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e){
	int i = 0;
	while(i<L.length && cur_e!=L.elem[i-1]) i++;
	if (i<L.length){
		next_e = L.elem[i];	//��ǰֵ��ǰ��ȡ���� 
		return OK;
	}
	else{
		return ERROR;
	}
}//NextElem

Status ListInsert_Sq(SqList &L, int i, ElemType e){
	if(i<1 || i>L.length+1) return ERROR;
	
	if(L.length >= L.listsize){		//��ǰ���ȴ��ڵ������洢���� 
		ElemType *newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)* sizeof(ElemType));
		if(!newbase) exit(OVERFLOW); //����ʧ�� 
		L.elem = newbase;	//�»�ַ 
		L.listsize += LISTINCREMENT;	//��¼��ǰ��������� 
	}
	
	ElemType *q = &(L.elem[i-1]); //q����λ��
	for(ElemType *p = &(L.elem[L.length-1]); p >= q; --p) *(p+1) = *p; //����λ�ü�֮���Ԫ������

	*q = e; //����e
	++L.length; //��ǰ����+1
	return OK; 
}//ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e){
	//���Ա���ɾ����i��Ԫ�أ�����e����
	if((i<1)||(i>L.length)) return ERROR;
	ElemType *p = &(L.elem[i-1]);
	e = *p;
	ElemType *q = L.elem + L.length -1 ;
	for(++p; p<=q; ++p) *(p-1)= *p;	//ɾ��Ԫ��֮���Ԫ������ 
	--L.length;
	return OK;
}//ListDelete_Sq



