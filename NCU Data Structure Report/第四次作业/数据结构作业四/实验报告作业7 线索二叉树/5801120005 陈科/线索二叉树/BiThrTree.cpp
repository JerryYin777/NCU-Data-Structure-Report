#include <iostream>
#include "bithrtree.h"
#include "status.h"
#include <stdio.h>
using namespace std;

Status CreateBiThrTree(BiThrTree &T){
	char ch;
	scanf("%c",&ch);
	if (ch =='#') T =NULL;
	else{
		if(!(T = (BiThrNode *)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
		T->data = ch;
		T->LTag=Link;
		T->RTag=Link;
		CreateBiThrTree(T->lchild);
		CreateBiThrTree(T->rchild);
	}
	return OK;
}//CreateBiThrTree

Status DestroyBiThrTree(BiThrTree &T){ //�ݻٶ����� 
    if(!T) exit(OVERFLOW);
    free(T);
    return OK;
} //DestroyBiThrTree 

Status PreOrderTraverse(BiThrTree T)//���������������
{
    if(T==NULL)
        return OK;
    printf("%c ",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}//PreOrderTraverse
Status InOrderTraverse(BiThrTree T)//���������������
{
   if(T==NULL)
       return OK;
   InOrderTraverse(T->lchild);
    printf("%c ",T->data);
   InOrderTraverse(T->rchild);
}//InOrderTraverse
Status PostOrderTraverse(BiThrTree T)//�������
{
    if(T==NULL){
    	return OK;
	}
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c ",T->data);
}//PostOrderTraverse

//Threading
BiThrTree pre; //һֱָ��ǰ�� 

Status InOrderThreading(BiThrTree &Thrt,BiThrTree T){
	if(!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
	Thrt->LTag = Link; Thrt->RTag=Thread;
	Thrt->rchild = Thrt;
	if(!T) Thrt->lchild=Thrt;
	else{
		Thrt->lchild=T; pre=Thrt;
		InThreading(T);	//���������� 
		pre->rchild = Thrt; pre->RTag=Thread;	//���һ���ڵ������� 
		Thrt->rchild=pre; 
	}
	return OK;
}//InOrderThreading
void InThreading(BiThrTree p){
	if(p){
		InThreading(p->lchild);	//������������
		if(!p->lchild) {p->LTag=Thread; p->lchild=pre;}	//ǰ��
		if(!pre->rchild){pre->RTag=Thread;pre->rchild=p;}//���
		pre=p; //����preָ��p��ǰ�� 
		InThreading(p->rchild); 
	}
}//InThreading
Status Printf_Node(TElemType e){
    printf("��ǰ��������ڵ�%c \n",e);
    return OK; 
}//Visit
Status InOrderTraverse_Thr(BiThrTree T){
	BiThrTree p;
	p=T->lchild;
	while(p!=T){
		while(p->LTag==Link) {
			p=p->lchild;
		}
        Printf_Node(p->data);
		while(p->RTag==Thread && p->rchild!=T){
			p=p->rchild; Printf_Node(p->data);
		}
		p=p->rchild;
	}
	return OK;
}//InOrderTraverse_Thr
