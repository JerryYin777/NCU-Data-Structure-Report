//二叉树操作示例
#include <iostream>
#include <string>
#include "BinTree.h"   //包含二叉树的头文件

using namespace std;

void main(void) {
	//定义二叉树
	BiTree T1, T2, T3 ;
	//初始化二叉树
	Init(T1);
	Init(T2);
	Init(T3);

	//创建二叉树
	cout << "按照先序顺序输入二叉树的值（字符型），空指针输入#" << endl;
	Create(T1) ;

	cout << "先序遍历序列为：";
	PreOrder(T1) ;
	cout << endl;

	cout << "中序遍历序列为：";
	InOrder(T1) ;
	cout << endl;

	cout << "后序遍历序列为：";
	PostOrder(T1) ;
	cout << endl;

	cout << "层次遍历序列为：";
	LevelOrder(T1) ;
	cout << endl;

	//复制二叉树
	T2 = Copy(T1);
	Copy(T1, T3);
	cout << "复制后的二叉树的遍历为：" << endl;
	//cout<< "先序遍历序列为(非递归)：";
	//PreOrderNR(T2) ;    cout<<endl;

	//cout<< "中序遍历序列为(非递归)：";
	//InOrderNR(T2) ;   cout<<endl;
	cout << "后序遍历序列为(非递归)：";
	PostOrderNR(T2) ;
	cout << endl;

	cout << "层次遍历序列为：";
	LevelOrder(T3) ;
	cout << endl;

	//请在此处加入其他的二叉树算法测试
	//比如：计算结点个数；深度等

	int n = Count(T1);
	cout << "二叉树的结点总数为：" << n << endl;

	int leaf = LeafCount(T1);
	cout << "二叉树的叶子结点个数为：" << leaf << endl;

	//另一个计算结点个数方法
	leaf = 0;
	LeafCount(T3, leaf);
	cout << "二叉树的叶子结点个数为：" << leaf << endl;

	int depth = Depth(T2);
	cout << "二叉树的深度为：" << depth << endl;

	//另一个计算深度方法
	depth = 0;
	Depth(T3, 1, depth);
	cout << "二叉树的深度为：" << depth << endl;

	//序列化二叉树
	string res = toSequence(T1);
	cout << "序列化结果:" << res.c_str();
	cout << endl;

	//程序结束，释放二叉树内存
	Destroy(T1);
	Destroy(T2);
	Destroy(T3);
}
