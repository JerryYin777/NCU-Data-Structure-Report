#ifndef __BITHRTREE_H__
#define __BITHRTREE_H__
#include <iostream>
#include "status.h"
using namespace std;

#define TElemType int

typedef enum PointerTag { Link, Thread }; //Link为0，Thread为1
typedef struct BiThrNode {
	TElemType	data;
	struct BiThrNode *lchild, *rchild;	//左右子节点
	PointerTag LTag = Link, RTag = Link;
} BiThrNode, *BiThrTree;

Status InitBiThrTree(BiThrTree &T);
Status DestroyBiThrTree(BiThrTree &T);
Status CreateBiThrTree(BiThrTree &T);	//输入来创建一个线性二叉树（未线索化）
Status ClearBiThrTree(BiThrTree &T);
Status BiThrTreeEmpty(BiThrTree T);
int BiThrTreeDepth(BiThrTree T);
BiThrTree Root(BiThrTree T);
TElemType Value(BiThrTree T, BiThrTree e);
Status Assign(BiThrTree T, BiThrTree &e, TElemType value);
BiThrTree Parent(BiThrTree T, BiThrTree e);

//Status PreOrderTraverse(BiTree &T,Status(*Visit)(TElemType));
Status PreOrderTraverse(BiThrTree T);
Status InOrderTraverse(BiThrTree T);
Status PostOrderTraverse(BiThrTree T);

//threading
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T);
void InThreading(BiThrTree p);
Status InOrderTraverse_Thr(BiThrTree T);
Status Printf_Node(TElemType e);
#endif
