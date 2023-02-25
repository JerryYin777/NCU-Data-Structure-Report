#ifndef __HUFFMANTREE_H__
#define __HUFFMANTREE_H__
//通过类似线性表的形式来构建赫夫曼树，由于赫夫曼树是正则的二叉树。
//即有n个叶节点，就会有2n-1个节点。 
typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode, *HuffmanTree;

//一个字符串数组，存储每个字符的编码。 
typedef char ** HuffmanCode;

//通过n个叶节点的权重，构建赫夫曼树HT，并求得n个节点的赫夫曼编码。 
void HuffmanCoding(HuffmanTree &T, HuffmanCode &HC,unsigned int *w,int n);
//选择出HT树的第1到第limit的节点中，parent为0，并且weight最小的两个节点，标号为s1，s2. 
void Select(HuffmanTree HT,int limit,int &s1,int &s2);


#endif
