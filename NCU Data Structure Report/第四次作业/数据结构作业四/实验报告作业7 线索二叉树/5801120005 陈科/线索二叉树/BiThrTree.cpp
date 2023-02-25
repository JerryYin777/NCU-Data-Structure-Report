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

Status DestroyBiThrTree(BiThrTree &T){ //摧毁二叉树 
    if(!T) exit(OVERFLOW);
    free(T);
    return OK;
} //DestroyBiThrTree 

Status PreOrderTraverse(BiThrTree T)//二叉树的先序遍历
{
    if(T==NULL)
        return OK;
    printf("%c ",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}//PreOrderTraverse
Status InOrderTraverse(BiThrTree T)//二叉树的中序遍历
{
   if(T==NULL)
       return OK;
   InOrderTraverse(T->lchild);
    printf("%c ",T->data);
   InOrderTraverse(T->rchild);
}//InOrderTraverse
Status PostOrderTraverse(BiThrTree T)//后序遍历
{
    if(T==NULL){
    	return OK;
	}
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c ",T->data);
}//PostOrderTraverse

//Threading
BiThrTree pre; //一直指向前驱 

Status InOrderThreading(BiThrTree &Thrt,BiThrTree T){
	if(!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
	Thrt->LTag = Link; Thrt->RTag=Thread;
	Thrt->rchild = Thrt;
	if(!T) Thrt->lchild=Thrt;
	else{
		Thrt->lchild=T; pre=Thrt;
		InThreading(T);	//中序线索化 
		pre->rchild = Thrt; pre->RTag=Thread;	//最后一个节点线索化 
		Thrt->rchild=pre; 
	}
	return OK;
}//InOrderThreading
void InThreading(BiThrTree p){
	if(p){
		InThreading(p->lchild);	//左子树线索化
		if(!p->lchild) {p->LTag=Thread; p->lchild=pre;}	//前驱
		if(!pre->rchild){pre->RTag=Thread;pre->rchild=p;}//后继
		pre=p; //保持pre指向p的前驱 
		InThreading(p->rchild); 
	}
}//InThreading
Status Printf_Node(TElemType e){
    printf("当前中序遍历节点%c \n",e);
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
