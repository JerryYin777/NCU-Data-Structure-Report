#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 9999

//用于存放运算符的栈的数据类型定义及基本操作：

//数据类型定义
#define ElemType1 char

typedef struct {
	ElemType1 data[MaxSize];
	int top;
} SqStack1;

//运算符栈的初始化操作：
void InitStack_1(SqStack1 &S) {
	memset(S.data, '\0', MaxSize);
	S.top = -1;
}

//取运算符栈的栈顶元素:
bool GetTop_1(SqStack1 &S, ElemType1 &x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

//运算符栈入栈操作:
bool Push_1(SqStack1 &S, ElemType1 x) {
	if (S.top == (MaxSize - 1))
		return false;
	S.data[++S.top] = x;
	return true;
}

//运算符栈出栈操作:
bool Pop_1(SqStack1 &S, ElemType1 &x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}

//用于存放操作数的栈的数据类型定义及基本类型操作

//数据类型定义
#define ElemType2 float

typedef struct {
	ElemType2 data[MaxSize];
	int top;
} SqStack2;

//操作数栈的初始化操作：
void InitStack_2(SqStack2 &S) {
	S.top = -1;
}

//取操作数栈的栈顶元素:
bool GetTop_2(SqStack2 &S, ElemType2 &x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

//操作数栈入栈操作:
bool Push_2(SqStack2 &S, ElemType2 x) {
	if (S.top == (MaxSize - 1))
		return false;
	S.data[++S.top] = x;
	return true;
}

//操作数栈出栈操作:
bool Pop_2(SqStack2 &S, ElemType2 &x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}

//用于判断运算符优先级的高低，优先级高于或等于就返回true，否则为false
bool Priority(char a, char b) {
	if ((a == '+' || a == '-') && (b == '+' || b == '-' || b == '*' || b == '/')) {
		return true;
	} else if ((a == '*' || a == '/') && (b == '*' || b == '/')) {
		return true;
	}
	return false;
}

//用于两个操作数之间的计算
ElemType2 CalculateTwo(ElemType2 n1, ElemType2 n2, ElemType1 t) {
	//n1是右操作数,n2是左操作数
	if (t == '+')
		return n1 + n2;
	if (t == '-')
		return n2 - n1;
	if (t == '/')
		return n2 / n1;
	if (t == '*')
		return n2 * n1;
}

//计算中缀表达式的算法:
void Calculate(ElemType1 str[], ElemType2 &e) {
	SqStack1 S1;//S1是运算符栈
	SqStack2 S2;//S2是操作数栈
	InitStack_1(S1);//初始化S1
	InitStack_2(S2);//初始化S2
	float n = 0;
	ElemType2 n1, n2;
	ElemType1 t;
	for (unsigned int i = 0; i < strlen(str); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			while (1) {
				n *= 10;
				n += (str[i] - '0');
				if (str[i + 1] >= '0' && str[i + 1] <= '9')
					i++;
				else
					break;
			}
			Push_2(S2, n);
			n = 0;
		} else if (str[i] != ')') {
			while (GetTop_1(S1, t) && t != '(' && Priority(str[i], t)) {
				Pop_1(S1, t);
				Pop_2(S2, n1); //n1是右操作数
				Pop_2(S2, n2); //n2是左操作数
				Push_2(S2, CalculateTwo(n1, n2, t));
			}
			Push_1(S1, str[i]);
		} else {
			while (Pop_1(S1, t)) {
				if (t == '(')
					break;
				Pop_2(S2, n1); //n1是右操作数
				Pop_2(S2, n2); //n2是左操作数
				Push_2(S2, CalculateTwo(n1, n2, t));
			}
		}
	}
	while (Pop_1(S1, t) && Pop_2(S2, n1) && Pop_2(S2, n2)) {
		Push_2(S2, CalculateTwo(n1, n2, t));
	}
	Pop_2(S2, e);
}

int main() {
	ElemType1 str[MaxSize];
	ElemType2 e;
	memset(str, '\0', MaxSize);

	printf("\n请输入要计算的表达式:\n");
	scanf("%s", str);
	printf("\n计算并输出结果:\n");
	Calculate(str, e);
	printf("%f\n", e);
	return 0;
}
