#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define SElemType int
#define MaxSize 100

typedef struct Stack
{
	SElemType *base;//ջ��ָ�� 
	SElemType *top;//ջ��ָ�� 
	int stacksize;
}SqStack;
//*������������
//��ʼ������
Status InitStack(SqStack &s)
{
	s.base=new SElemType[MaxSize];//��̬�����������
	if(!s.base)
	{
		printf("����ʧ��\n");
		return 0;
	}
	s.top=s.base;
	s.stacksize=MaxSize;
	return 1;
}
//��ջ
Status Push(SqStack &s,SElemType e)
{
	if(s.top-s.base==s.stacksize) return 0;//ջ��
	*(s.top++)=e;
	return 1;	
}
//��ջ ��e����ֵ
Status Pop(SqStack &s,SElemType &e)
{
	if(s.top==s.base) return 0;//ջ��
	e=*--s.top;
	return 1;	
}
//�õ�ջ��Ԫ�أ����޸�ָ��
bool GetTop(SqStack s,SElemType &e) 
{
	if(s.top==s.base) return false;//ջ��			
	else e=*--s.top;
	return true;
		
}

//*����ʵ�ֺ���

void menu()
{
   printf("********1.��ջ      2.��ջ*********\n");
   printf("********3.ȡջ��    4.�˳�*********\n");
}
//��ջ���ܺ��� ����Push����
void PushToStack(SqStack &s)
{
	int n;SElemType e;int flag;
	printf("��������ջԪ�ظ���(>=1)��\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	 printf("�������%d��Ԫ�ص�ֵ:",i+1);
	 scanf("%d",&e);
	 flag=Push(s,e);
	 if(flag)printf("%d����ջ\n",e);
	 else {printf("ջ����������\n");break;}
	}
}
//��ջ���ܺ��� ����Pop����
void PopFromStack(SqStack &s)
{
	int n;SElemType e;int flag;
	printf("�������ջԪ�ظ���(>=1)��\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	 flag=Pop(s,e);
	 if(flag)printf("%d�ѳ�ջ\n",e);
	 else {printf("ջ�ѿգ�����\n");break;}
	}
}
//ȡջ�����ܺ��� ����GetTop
void GetTopOfStack(SqStack &s)
{
	SElemType e;bool flag; 
	flag=GetTop(s,e);
	if(flag)printf("ջ��Ԫ��Ϊ:%d\n",e);
	else printf("ջ�ѿգ�����\n");
}
//������
int main()
{
 SqStack s;int choice;
 InitStack(s);
 while(1)
 {
  menu();
  printf("������˵���ţ�\n");
  scanf("%d",&choice);
  if(choice==4) break;
  switch(choice)
  {
  case 1:PushToStack(s);break;
  case 2:PopFromStack(s);break;
  case 3:GetTopOfStack(s);break;
  default:printf("������󣡣���\n");
  }
 }
 return 0;
}



