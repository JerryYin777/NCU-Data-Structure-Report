#include <iostream>
#include <string>
#include <BinTree.h>

using namespace std;


//��ʼ��������
void Init(BiTree &T) {
	T = NULL;
}
/*��������������*/

//�����������˼��
void Create(BiTree &T) {
	ElemType ch ;
	cin >> ch;
	if (ch == '#')            //'#' �����ָ��
		T = NULL ;
	else {
		T = new BiTNode ;     //���������
		T->data = ch ;
		Create(T->lchild) ;   //���򴴽�������
		Create(T->rchild) ;   //���򴴽�������
	}
}

/*��������������ݹ����*/
void PreOrder(BiTree T) {
	if (T) {
		cout << T->data << "  " ; //��������
		PreOrder(T->lchild) ;  //�������������
		PreOrder(T->rchild) ;  //�������������
	}
}

/*��������������ݹ����*/
void InOrder(BiTree T) {
	if (T) {
		InOrder(T->lchild) ;   //�������������
		cout << T->data << "  " ; //��������
		InOrder(T->rchild) ;   //�������������
	}
}

/*��������������ݹ����*/
void PostOrder(BiTree T) {
	if (T) {
		PostOrder(T->lchild) ;  //�������������
		PostOrder(T->rchild) ;  //�������������
		cout << T->data << "  " ; //��������
	}
}

/*��������������ǵݹ����*/
void PreOrderNR(BiTree T)
{}
/*��������������ǵݹ����*/
void InOrderNR(BiTree T) {
	BiTree stack[MAXLEN];  //����˳��ջ
	int top = 0;           //����ջ��ָ�룬��ջ
	BiTree p = T;          //ָ��������ĸ�

	while (p || top) {     //��ǰ���ָ�벻Ϊ�ջ�ջ��Ϊ��ʱ
		while (p) {    //˳�������������½ǽ��
			stack[top++] = p;   //��Ϊ�գ���ջ
			p = p->lchild;      //˳��������
		}
		if (top) {     //ջ��Ϊ��
			p = stack[--top];       //��ջ
			cout << p->data << "  "; //����
		}
		p = p->rchild; //����������
	}
}
/*��������������ǵݹ����*/
void PostOrderNR(BiTree T)
{}
/*��α�������������*/
void LevelOrder(BiTree T) {
	BiTree queue[MAXLEN] ;  //����ѭ������
	int front, rear ;       //������еĶ�ͷ�Ͷ�βָ��
	BiTree p ;              //����ָ���������ǰ����ָ��

	front = rear = 0 ;      //���г�ʼ�������ն���
	p = T ;
	rear = (rear + 1) % MAXLEN ;
	queue[rear] = p ;      //��������ǰ��㣨ָ�룩�����
	while (front != rear) {  //�����зǿ�
		front = (front + 1) % MAXLEN ;
		p = queue[front] ;    //ɾ����ͷ
		cout << p->data << "  " ; //���ʣ��������
		if (p->lchild) {       //���ӷǿգ������
			rear = (rear + 1) % MAXLEN ;
			queue[rear] = p->lchild ;
		}
		if (p->rchild) {       //�Һ��ӷǿգ������
			rear = (rear + 1) % MAXLEN ;
			queue[rear] = p->rchild ;
		}
	}
}
//�������������
//���ú������˼��
int Count(BiTree T) {
	int lnum, rnum ;
	if (!T)
		return 0 ;   //������Ϊ�գ�����0��
	else if (!T->lchild && !T->rchild)
		return 1 ; //������ֻ�и���㣬����1��
	else {
		lnum = Count(T->lchild) ;   //�������������������������������
		rnum = Count(T->rchild) ;   //�������������������������������
		return lnum + rnum + 1 ;    //���ʸ���㣬���������������
	}
}


//�������Ҷ�ӽ�����
//���ú���ʱ������count��ʼֵΪ0
//Ҳ����������ͺ����������
void LeafCount(BiTree T, int &count) {
	if (T) {
		if (!T->lchild && !T->rchild)
			count++; //��Ҷ�ӽ�㣬��������1
		LeafCount(T->lchild, count); //�������������������Ҷ�ӽ�����
		LeafCount(T->rchild, count); //�������������������Ҷ�ӽ�����
	}
}
//�������Ҷ�ӽ�����
//���ú������˼��
int LeafCount(BiTree T) {
	int lnum, rnum ;
	if (!T)
		return 0 ;   //������Ϊ�գ���Ҷ�ӽ��0��
	else if (!T->lchild && !T->rchild)
		return 1 ; //������ֻ�и���㣬��Ҷ�ӽ��1��
	else {
		lnum = LeafCount(T->lchild) ;   //�������������������������Ҷ�ӽ�����
		rnum = LeafCount(T->rchild) ;   //�������������������������Ҷ�ӽ�����
		return lnum + rnum ;            //���ʸ���㣬���������������
	}
}

//������������
//���ú������˼��
int Depth(BiTree T) {
	int ldepth, rdepth ;
	if (!T)
		return 0 ;  //������Ϊ�գ������Ϊ0
	else {
		ldepth = Depth(T->lchild) ;  //����������������������������
		rdepth = Depth(T->rchild) ;  //����������������������������
		//���ʸ���㣬���������Ϊ�����������߼�1
		return (ldepth > rdepth ? ldepth : rdepth) + 1 ;
	}
}

//������������
//����֮ǰ level �ĳ�ֵΪ 1
//dval �ĳ�ֵΪ 0
void Depth(BiTree T, int level, int &dval) {
	if ( T ) {
		//������ĵ�ǰ��δ�����ȣ��޸����Ϊ��ǰ���ֵ
		if (level > dval)
			dval = level;
		//�����������������μ�1
		Depth( T->lchild, level + 1, dval );
		//�����������������μ�1
		Depth( T->rchild, level + 1, dval );
	}
}

//���ƶ�����
//���ú������˼�룬���ظ��ƺ�Ķ�����
BiTree Copy(BiTree T) {
	if (T == NULL)
		return NULL;
	else {
		BiTree lbt, rbt, root;
		lbt = Copy(T->lchild); //������������
		rbt = Copy(T->rchild); //������������
		root = new BiTNode;  //���������
		root->data = T->data; //��������
		root->lchild = lbt;  //ָ��������
		root->rchild = rbt;  //ָ��������
		return root;         //���ظ��ƺ�Ķ�����
	}
}

//���ƶ�����
//�����������˼�룬newTָ���ƺ�Ķ�����
void Copy(BiTree T, BiTree &newT) {
	if (T == NULL)
		newT = NULL;
	else {
		newT = new BiTNode;  //���������
		newT->data = T->data;  //��������
		Copy(T->lchild, newT->lchild); //������������
		Copy(T->rchild, newT->rchild); //������������
	}
}

//��ն�����
//���ú������˼��
//������������������ͷŸ����
void Clear(BiTree &T) {
	if (T) {
		Clear(T->lchild);  //����������������
		Clear(T->rchild);  //����������������
		delete T;          //�ͷŸ����
		T = NULL;          //�ÿ�
	}
}
//���ٶ�����
void Destroy(BiTree &T) {
	Clear(T);
}
//���л�������
void tostring(BiTNode *root, string &res) {
	if (root) {
		// res.push_back('��');
		res += "(";
		res += root->data;
		tostring(root->lchild, res);
		tostring(root->rchild, res);
		// res.push_back('��');

		res += ")";
	}
}
string toSequence(BiTNode *root) {
	string res;
	tostring(root, res);
	return res;
}
