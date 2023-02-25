//����������ʾ��
#include <iostream>
#include <string>
#include "BinTree.h"   //������������ͷ�ļ�

using namespace std;

void main(void) {
	//���������
	BiTree T1, T2, T3 ;
	//��ʼ��������
	Init(T1);
	Init(T2);
	Init(T3);

	//����������
	cout << "��������˳�������������ֵ���ַ��ͣ�����ָ������#" << endl;
	Create(T1) ;

	cout << "�����������Ϊ��";
	PreOrder(T1) ;
	cout << endl;

	cout << "�����������Ϊ��";
	InOrder(T1) ;
	cout << endl;

	cout << "�����������Ϊ��";
	PostOrder(T1) ;
	cout << endl;

	cout << "��α�������Ϊ��";
	LevelOrder(T1) ;
	cout << endl;

	//���ƶ�����
	T2 = Copy(T1);
	Copy(T1, T3);
	cout << "���ƺ�Ķ������ı���Ϊ��" << endl;
	//cout<< "�����������Ϊ(�ǵݹ�)��";
	//PreOrderNR(T2) ;    cout<<endl;

	//cout<< "�����������Ϊ(�ǵݹ�)��";
	//InOrderNR(T2) ;   cout<<endl;
	cout << "�����������Ϊ(�ǵݹ�)��";
	PostOrderNR(T2) ;
	cout << endl;

	cout << "��α�������Ϊ��";
	LevelOrder(T3) ;
	cout << endl;

	//���ڴ˴����������Ķ������㷨����
	//���磺�������������ȵ�

	int n = Count(T1);
	cout << "�������Ľ������Ϊ��" << n << endl;

	int leaf = LeafCount(T1);
	cout << "��������Ҷ�ӽ�����Ϊ��" << leaf << endl;

	//��һ���������������
	leaf = 0;
	LeafCount(T3, leaf);
	cout << "��������Ҷ�ӽ�����Ϊ��" << leaf << endl;

	int depth = Depth(T2);
	cout << "�����������Ϊ��" << depth << endl;

	//��һ��������ȷ���
	depth = 0;
	Depth(T3, 1, depth);
	cout << "�����������Ϊ��" << depth << endl;

	//���л�������
	string res = toSequence(T1);
	cout << "���л����:" << res.c_str();
	cout << endl;

	//����������ͷŶ������ڴ�
	Destroy(T1);
	Destroy(T2);
	Destroy(T3);
}
