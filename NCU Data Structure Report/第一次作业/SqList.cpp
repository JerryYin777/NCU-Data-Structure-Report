#include <iostream>
#include "status.h"
#include "sqlist.h"

#define LIST_INIT_SIZE 100 //初始分配 
#define LISTINCREMENT 10 	//动态分配增加量 
using namespace std;

Status InitList_Sq(SqList &L){
	//申请内存空间 
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW); 	//申请失败，报错 
	L.length = 0;					//空表长度为0 
	L.listsize = LIST_INIT_SIZE;	//初始存储量 
	return OK;
}//InitList_Sq

Status DestroyList_Sq(SqList &L){
	if(L.elem) free(L.elem);	//如果线性表存在，则释放空间 
	if(!L.elem) exit(OVERFLOW); //如果线性表不存在，则报错
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
	if (i<1 || i>L.length+1) return ERROR; //如果i不在当前L中
	ElemType *q = &(L.elem[i-1]); //取出位置
 	e = *q;				//取出元素 
	return OK;
}//GetElem_Sq

Status LocateElem(SqList L, ElemType e,Status (* compare)(ElemType, ElemType)){
	//如果找到满足要求的，返回位序，否则返回0 
	int i = 1;		//i的初值为第1个元素的位序
	int *p = L.elem;	//p的初值为第1个元素的存储位置
	while(i<=L.length && !(* compare)(*p++, e)) ++i;
	if(i<=L.length) return i;
	else return 0; 
}//LocateElem

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e){
	int i = 1;
	while(i<=L.length && cur_e!=L.elem[i-1]) i++;
	if (i<=L.length){
		pre_e = L.elem[i-2];	//当前值的前驱取出来 
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
		next_e = L.elem[i];	//当前值的前驱取出来 
		return OK;
	}
	else{
		return ERROR;
	}
}//NextElem

Status ListInsert_Sq(SqList &L, int i, ElemType e){
	if(i<1 || i>L.length+1) return ERROR;
	
	if(L.length >= L.listsize){		//当前长度大于等于最大存储容量 
		ElemType *newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)* sizeof(ElemType));
		if(!newbase) exit(OVERFLOW); //分配失败 
		L.elem = newbase;	//新基址 
		L.listsize += LISTINCREMENT;	//记录当前的最大容量 
	}
	
	ElemType *q = &(L.elem[i-1]); //q插入位置
	for(ElemType *p = &(L.elem[L.length-1]); p >= q; --p) *(p+1) = *p; //插入位置及之后的元素右移

	*q = e; //插入e
	++L.length; //当前长度+1
	return OK; 
}//ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e){
	//线性表中删除第i个元素，并用e返回
	if((i<1)||(i>L.length)) return ERROR;
	ElemType *p = &(L.elem[i-1]);
	e = *p;
	ElemType *q = L.elem + L.length -1 ;
	for(++p; p<=q; ++p) *(p-1)= *p;	//删除元素之后的元素左移 
	--L.length;
	return OK;
}//ListDelete_Sq



