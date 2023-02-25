#ifndef __HUFFMANTREE_H__
#define __HUFFMANTREE_H__
//ͨ���������Ա����ʽ�������շ����������ںշ�����������Ķ�������
//����n��Ҷ�ڵ㣬�ͻ���2n-1���ڵ㡣 
typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode, *HuffmanTree;

//һ���ַ������飬�洢ÿ���ַ��ı��롣 
typedef char ** HuffmanCode;

//ͨ��n��Ҷ�ڵ��Ȩ�أ������շ�����HT�������n���ڵ�ĺշ������롣 
void HuffmanCoding(HuffmanTree &T, HuffmanCode &HC,unsigned int *w,int n);
//ѡ���HT���ĵ�1����limit�Ľڵ��У�parentΪ0������weight��С�������ڵ㣬���Ϊs1��s2. 
void Select(HuffmanTree HT,int limit,int &s1,int &s2);


#endif
