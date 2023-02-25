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
	SElemType *base;//栈底指针 
	SElemType *top;//栈顶指针 
	int stacksize;
}SqStack;
//*基本操作函数
//初始化函数
Status InitStack(SqStack &s)
{
	s.base=new SElemType[MaxSize];//动态分配最大容量
	if(!s.base)
	{
		printf("分配失败\n");
		return 0;
	}
	s.top=s.base;
	s.stacksize=MaxSize;
	return 1;
}
//入栈
Status Push(SqStack &s,SElemType e)
{
	if(s.top-s.base==s.stacksize) return 0;//栈满
	*(s.top++)=e;
	return 1;	
}
//出栈 用e返回值
Status Pop(SqStack &s,SElemType &e)
{
	if(s.top==s.base) return 0;//栈空
	e=*--s.top;
	return 1;	
}
//得到栈顶元素，不修改指针
bool GetTop(SqStack s,SElemType &e) 
{
	if(s.top==s.base) return false;//栈空			
	else e=*--s.top;
	return true;
		
}

//*功能实现函数

void menu()
{
   printf("********1.入栈      2.出栈*********\n");
   printf("********3.取栈顶    4.退出*********\n");
}
//入栈功能函数 调用Push函数
void PushToStack(SqStack &s)
{
	int n;SElemType e;int flag;
	printf("请输入入栈元素个数(>=1)：\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	 printf("请输入第%d个元素的值:",i+1);
	 scanf("%d",&e);
	 flag=Push(s,e);
	 if(flag)printf("%d已入栈\n",e);
	 else {printf("栈已满！！！\n");break;}
	}
}
//出栈功能函数 调用Pop函数
void PopFromStack(SqStack &s)
{
	int n;SElemType e;int flag;
	printf("请输入出栈元素个数(>=1)：\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	 flag=Pop(s,e);
	 if(flag)printf("%d已出栈\n",e);
	 else {printf("栈已空！！！\n");break;}
	}
}
//取栈顶功能函数 调用GetTop
void GetTopOfStack(SqStack &s)
{
	SElemType e;bool flag; 
	flag=GetTop(s,e);
	if(flag)printf("栈顶元素为:%d\n",e);
	else printf("栈已空！！！\n");
}
//主函数
int main()
{
 SqStack s;int choice;
 InitStack(s);
 while(1)
 {
  menu();
  printf("请输入菜单序号：\n");
  scanf("%d",&choice);
  if(choice==4) break;
  switch(choice)
  {
  case 1:PushToStack(s);break;
  case 2:PopFromStack(s);break;
  case 3:GetTopOfStack(s);break;
  default:printf("输入错误！！！\n");
  }
 }
 return 0;
}



