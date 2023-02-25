#include <iostream>
#include "status.h"
#include "linklist.h"

using namespace std;
/*---length---�����ĳ���*/
int Length(Link s)
{ 
    int i=0;
    Link p;
    p=s;
    while(p->next){
        p = p->next;
        i++;
    }
    return i;
}//Length
Status compare(int a,int b)
{  
    return a-b;
}//Compare

Status MakeNode(Link &p, ElemType e ){
	//һ����������ڴ�ռ� 
	p = (Link)malloc(sizeof(LNode));
	if(!p) exit(OVERFLOW); 	//����ʧ�ܣ����� 
	p->data=e;
	p->next=NULL; 			//�� 
	return OK;
}//MakeNode

void FreeNode(Link &p){
	if(!p) exit(OVERFLOW);
	free(p);
}//FreeNode

Status InitList(LinkList &L){
	Link h;
	ElemType e;
	MakeNode(h,e);
	L.head=h;
	L.head->next=NULL;
	L.tail=L.head;
	L.len=0;	//ע�ⲻ����ͷ��� 
	if (!L.head) exit(OVERFLOW);
	return OK;
}//InitList

Status DestroyList(LinkList &L){
	Link p;
	p = L.tail;
	while(p!=L.head){
		p=PriorPos(L,p);
		FreeNode(p->next);
	}
	FreeNode(L.head);
	return OK;
}//DestroyList

//��L����������գ��ͷ�����ռ䣬����ͷ��� 
Status ClearList(LinkList &L){
    Link p;
	p = L.tail;
	while(p!=L.head){
		p=PriorPos(L,p);
		FreeNode(p->next);
	}
	L.len=0;
	return OK;
}//ClearList

Status InsFirst(LinkList &L, Link s){
	s->next=L.head->next;
	if(!L.head->next) L.tail=s;
	L.head->next=s;
	L.len++;
	return OK;
}//InsFirst

Status DelFirst(LinkList &L, Link &q){
	if(!L.head->next){
	    return ERROR;
	}
	q = L.head->next;
	L.head->next=L.head->next->next;
	if(!L.head->next){
	    L.tail=L.head;
	}
	L.len--;
	return OK;
}//DelFirst

Status Append(LinkList &L,Link s){
	Link q;
	q=L.head;
	if (!L.tail){
		L.head->next=s;
		//����β��� 
		while(q->next) q=q->next;
		L.tail=q;
	}
	L.tail->next=s;
	while(q->next) q=q->next;
	L.tail=q;
	L.len+=Length(s);
	return OK; 
}//Append
Status Remove(LinkList &L,Link &q){
	if(!L.tail) return ERROR;
	q=L.tail;
	L.tail=PriorPos(L,q);
	L.tail->next=NULL;
	return OK;
}//Remove
Status InsBefore(LinkList &L, Link &p,Link s){
	Link q;
	q=PriorPos(L,p);
	s->next=p;
	q->next=s;
	return OK;
}//InsBefore
Status InsAfter(LinkList &L, Link &p,Link s){
	s->next=p->next;
	p->next=s;
	return OK;
}//InsAfter

Status SetCurElem(Link &p,ElemType e){
	p->data=e;
	return OK;
}//SetCurElem
ElemType GetCurElem(Link p){
	return p->data;
}
Status ListEmpty(LinkList L){
	if(L.head==L.tail) return TRUE;
	return FALSE;
}//ListEmpty
int ListLength(LinkList L){
	return L.len;
}//ListLength
Position GetHead(LinkList L){
	return L.head;
}
Position GetLast(LinkList L){
	return L.tail;
}
Position PriorPos(LinkList L, Link p){
	Link q;
	q=L.head;
	if(q->next==p) return ERROR;
	while(q->next!=p) q=q->next;
	return q;
}//PriorPos
Link NextPos(LinkList L, Link p){
	Link q;
	if(!p->next) {
	    return NULL;
	}
	q=p->next;
	return q;
}
//�����i��0��ʼ
Status LocatePos(LinkList L, int i, Link &p){ 
	p=L.head;
	if (i<=0||i>ListLength(L)) return ERROR;
	while(i){
		p=p->next;
		i--;
	}
	return OK;
}//LocatePos

Position LocateElem(LinkList L, ElemType e, Status (* compare)(ElemType, ElemType)){
	int i=0;
	Link p;
	p=L.head->next;
	while(compare(p->data,e)&&p){
		p=p->next;
		++i;
	}
	if(!p) return ERROR;	//�Ҳ���ָ��Ԫ�� 
	return p;
}//LocateElem
//void ListTraverse(LinkList L,Status(* visit)())
//{         
//    Link p;
//    p=L.head;
//    while(!visit(p))  
//        p=p->next;   
//}//ListTraverse
