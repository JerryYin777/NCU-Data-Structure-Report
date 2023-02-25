#include <iostream>
#include <string>
using namespace std;

const int MAXLEN = 100;   //����ջ�Ͷ��е����ռ�
typedef char ElemType;

typedef struct BiTNode {
	ElemType data ;  //������
	struct BiTNode *lchild, *rchild ;//���Һ���ָ��
} BiTNode, *BiTree ;

//��ʼ��������
void Init(BiTree &T);
/*��������������*/
void Create(BiTree &T);
/*��������������ݹ����*/
void PreOrder(BiTree T);
/*��������������ݹ����*/
void InOrder(BiTree T);
/*��������������ݹ����*/
void PostOrder(BiTree T);
/*��������������ǵݹ����*/
void PreOrderNR(BiTree T);
/*��������������ǵݹ����*/
void InOrderNR(BiTree T);
/*��������������ǵݹ����*/
void PostOrderNR(BiTree T);
/*��α�������������*/
void LevelOrder(BiTree T);
//�������Ҷ�ӽ�����
void LeafCount(BiTree T, int &count);
//�������Ҷ�ӽ�����
int LeafCount(BiTree T);
//�������������
int Count(BiTree T);
//������������
int Depth(BiTree T);
//������������
void Depth(BiTree T, int level, int &dval);
//���ƶ�����
BiTree Copy(BiTree T);
//���ƶ�����
void Copy(BiTree T, BiTree &newT);
//��ն�����
void Clear(BiTree &T);
//���ٶ�����
void Destroy(BiTree &T);
//���л�������
string toSequence(BiTNode *root);
//ת�ַ�
void tostring(BiTNode *root, string &res);
