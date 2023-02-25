#include <iostream>
#include <string>
#include <BinTree.h>

using namespace std;


//初始化二叉树
void Init(BiTree &T) {
	T = NULL;
}
/*创建二叉树操作*/

//利用先序遍历思想
void Create(BiTree &T) {
	ElemType ch ;
	cin >> ch;
	if (ch == '#')            //'#' 代表空指针
		T = NULL ;
	else {
		T = new BiTNode ;     //创建根结点
		T->data = ch ;
		Create(T->lchild) ;   //先序创建左子树
		Create(T->rchild) ;   //先序创建右子树
	}
}

/*先序遍历二叉树递归操作*/
void PreOrder(BiTree T) {
	if (T) {
		cout << T->data << "  " ; //输出根结点
		PreOrder(T->lchild) ;  //先序遍历左子树
		PreOrder(T->rchild) ;  //先序遍历右子树
	}
}

/*中序遍历二叉树递归操作*/
void InOrder(BiTree T) {
	if (T) {
		InOrder(T->lchild) ;   //中序遍历左子树
		cout << T->data << "  " ; //输出根结点
		InOrder(T->rchild) ;   //中序遍历右子树
	}
}

/*后序遍历二叉树递归操作*/
void PostOrder(BiTree T) {
	if (T) {
		PostOrder(T->lchild) ;  //后序遍历左子树
		PostOrder(T->rchild) ;  //先序遍历右子树
		cout << T->data << "  " ; //输出根结点
	}
}

/*先序遍历二叉树非递归操作*/
void PreOrderNR(BiTree T)
{}
/*中序遍历二叉树非递归操作*/
void InOrderNR(BiTree T) {
	BiTree stack[MAXLEN];  //定义顺序栈
	int top = 0;           //设置栈顶指针，空栈
	BiTree p = T;          //指向二叉树的根

	while (p || top) {     //当前结点指针不为空或栈不为空时
		while (p) {    //顺着左链找最左下角结点
			stack[top++] = p;   //不为空，入栈
			p = p->lchild;      //顺着左链找
		}
		if (top) {     //栈不为空
			p = stack[--top];       //出栈
			cout << p->data << "  "; //访问
		}
		p = p->rchild; //处理右子树
	}
}
/*后序遍历二叉树非递归操作*/
void PostOrderNR(BiTree T)
{}
/*层次遍历二叉树操作*/
void LevelOrder(BiTree T) {
	BiTree queue[MAXLEN] ;  //定义循环队列
	int front, rear ;       //定义队列的队头和队尾指针
	BiTree p ;              //定义指向二叉树当前结点的指针

	front = rear = 0 ;      //队列初始化，即空队列
	p = T ;
	rear = (rear + 1) % MAXLEN ;
	queue[rear] = p ;      //二叉树当前结点（指针）入队列
	while (front != rear) {  //当队列非空
		front = (front + 1) % MAXLEN ;
		p = queue[front] ;    //删除队头
		cout << p->data << "  " ; //访问（即输出）
		if (p->lchild) {       //左孩子非空，入队列
			rear = (rear + 1) % MAXLEN ;
			queue[rear] = p->lchild ;
		}
		if (p->rchild) {       //右孩子非空，入队列
			rear = (rear + 1) % MAXLEN ;
			queue[rear] = p->rchild ;
		}
	}
}
//求二叉树结点个数
//利用后序遍历思想
int Count(BiTree T) {
	int lnum, rnum ;
	if (!T)
		return 0 ;   //二叉树为空，则结点0个
	else if (!T->lchild && !T->rchild)
		return 1 ; //二叉树只有根结点，则结点1个
	else {
		lnum = Count(T->lchild) ;   //后序遍历左子树，返回左子树结点个数
		rnum = Count(T->rchild) ;   //后序遍历右子树，返回右子树结点个数
		return lnum + rnum + 1 ;    //访问根结点，计算二叉树结点个数
	}
}


//求二叉树叶子结点个数
//调用函数时，参数count初始值为0
//也可以用中序和后序遍历计算
void LeafCount(BiTree T, int &count) {
	if (T) {
		if (!T->lchild && !T->rchild)
			count++; //是叶子结点，计数器增1
		LeafCount(T->lchild, count); //先序遍历左子树，计算叶子结点个数
		LeafCount(T->rchild, count); //先序遍历右子树，计算叶子结点个数
	}
}
//求二叉树叶子结点个数
//利用后序遍历思想
int LeafCount(BiTree T) {
	int lnum, rnum ;
	if (!T)
		return 0 ;   //二叉树为空，则叶子结点0个
	else if (!T->lchild && !T->rchild)
		return 1 ; //二叉树只有根结点，则叶子结点1个
	else {
		lnum = LeafCount(T->lchild) ;   //后序遍历左子树，返回左子树叶子结点个数
		rnum = LeafCount(T->rchild) ;   //后序遍历右子树，返回右子树叶子结点个数
		return lnum + rnum ;            //访问根结点，计算二叉树结点个数
	}
}

//求二叉树的深度
//利用后序遍历思想
int Depth(BiTree T) {
	int ldepth, rdepth ;
	if (!T)
		return 0 ;  //二叉树为空，则深度为0
	else {
		ldepth = Depth(T->lchild) ;  //后序遍历左子树，计算左子树深度
		rdepth = Depth(T->rchild) ;  //后序遍历右子树，计算右子树深度
		//访问根结点，二叉树深度为左右子树大者加1
		return (ldepth > rdepth ? ldepth : rdepth) + 1 ;
	}
}

//求二叉树的深度
//调用之前 level 的初值为 1
//dval 的初值为 0
void Depth(BiTree T, int level, int &dval) {
	if ( T ) {
		//如果结点的当前层次大于深度，修改深度为当前层次值
		if (level > dval)
			dval = level;
		//先序遍历左子树，层次加1
		Depth( T->lchild, level + 1, dval );
		//先序遍历右子树，层次加1
		Depth( T->rchild, level + 1, dval );
	}
}

//复制二叉树
//利用后序遍历思想，返回复制后的二叉树
BiTree Copy(BiTree T) {
	if (T == NULL)
		return NULL;
	else {
		BiTree lbt, rbt, root;
		lbt = Copy(T->lchild); //后序复制左子树
		rbt = Copy(T->rchild); //后序复制右子树
		root = new BiTNode;  //创建根结点
		root->data = T->data; //复制数据
		root->lchild = lbt;  //指向左子树
		root->rchild = rbt;  //指向右子树
		return root;         //返回复制后的二叉树
	}
}

//复制二叉树
//利用先序遍历思想，newT指向复制后的二叉树
void Copy(BiTree T, BiTree &newT) {
	if (T == NULL)
		newT = NULL;
	else {
		newT = new BiTNode;  //创建根结点
		newT->data = T->data;  //复制数据
		Copy(T->lchild, newT->lchild); //先序复制左子树
		Copy(T->rchild, newT->rchild); //先序复制右子树
	}
}

//清空二叉树
//利用后序遍历思想
//先清空左右子树，再释放根结点
void Clear(BiTree &T) {
	if (T) {
		Clear(T->lchild);  //后序遍历清空左子树
		Clear(T->rchild);  //后序遍历清空右子树
		delete T;          //释放根结点
		T = NULL;          //置空
	}
}
//销毁二叉树
void Destroy(BiTree &T) {
	Clear(T);
}
//序列化二叉树
void tostring(BiTNode *root, string &res) {
	if (root) {
		// res.push_back('（');
		res += "(";
		res += root->data;
		tostring(root->lchild, res);
		tostring(root->rchild, res);
		// res.push_back('）');

		res += ")";
	}
}
string toSequence(BiTNode *root) {
	string res;
	tostring(root, res);
	return res;
}
