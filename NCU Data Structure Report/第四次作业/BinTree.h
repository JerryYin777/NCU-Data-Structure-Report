#include <iostream>
#include <string>
using namespace std;

const int MAXLEN = 100;   //定义栈和队列的最大空间
typedef char ElemType;

typedef struct BiTNode {
	ElemType data ;  //数据域
	struct BiTNode *lchild, *rchild ;//左右孩子指针
} BiTNode, *BiTree ;

//初始化二叉树
void Init(BiTree &T);
/*创建二叉树操作*/
void Create(BiTree &T);
/*先序遍历二叉树递归操作*/
void PreOrder(BiTree T);
/*中序遍历二叉树递归操作*/
void InOrder(BiTree T);
/*后序遍历二叉树递归操作*/
void PostOrder(BiTree T);
/*先序遍历二叉树非递归操作*/
void PreOrderNR(BiTree T);
/*中序遍历二叉树非递归操作*/
void InOrderNR(BiTree T);
/*后序遍历二叉树非递归操作*/
void PostOrderNR(BiTree T);
/*层次遍历二叉树操作*/
void LevelOrder(BiTree T);
//求二叉树叶子结点个数
void LeafCount(BiTree T, int &count);
//求二叉树叶子结点个数
int LeafCount(BiTree T);
//求二叉树结点个数
int Count(BiTree T);
//求二叉树的深度
int Depth(BiTree T);
//求二叉树的深度
void Depth(BiTree T, int level, int &dval);
//复制二叉树
BiTree Copy(BiTree T);
//复制二叉树
void Copy(BiTree T, BiTree &newT);
//清空二叉树
void Clear(BiTree &T);
//销毁二叉树
void Destroy(BiTree &T);
//序列化二叉树
string toSequence(BiTNode *root);
//转字符
void tostring(BiTNode *root, string &res);
