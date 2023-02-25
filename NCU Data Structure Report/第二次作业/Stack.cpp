#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 9999

//���ڴ���������ջ���������Ͷ��弰����������

//�������Ͷ���
#define ElemType1 char

typedef struct {
	ElemType1 data[MaxSize];
	int top;
} SqStack1;

//�����ջ�ĳ�ʼ��������
void InitStack_1(SqStack1 &S) {
	memset(S.data, '\0', MaxSize);
	S.top = -1;
}

//ȡ�����ջ��ջ��Ԫ��:
bool GetTop_1(SqStack1 &S, ElemType1 &x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

//�����ջ��ջ����:
bool Push_1(SqStack1 &S, ElemType1 x) {
	if (S.top == (MaxSize - 1))
		return false;
	S.data[++S.top] = x;
	return true;
}

//�����ջ��ջ����:
bool Pop_1(SqStack1 &S, ElemType1 &x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}

//���ڴ�Ų�������ջ���������Ͷ��弰�������Ͳ���

//�������Ͷ���
#define ElemType2 float

typedef struct {
	ElemType2 data[MaxSize];
	int top;
} SqStack2;

//������ջ�ĳ�ʼ��������
void InitStack_2(SqStack2 &S) {
	S.top = -1;
}

//ȡ������ջ��ջ��Ԫ��:
bool GetTop_2(SqStack2 &S, ElemType2 &x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

//������ջ��ջ����:
bool Push_2(SqStack2 &S, ElemType2 x) {
	if (S.top == (MaxSize - 1))
		return false;
	S.data[++S.top] = x;
	return true;
}

//������ջ��ջ����:
bool Pop_2(SqStack2 &S, ElemType2 &x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}

//�����ж���������ȼ��ĸߵͣ����ȼ����ڻ���ھͷ���true������Ϊfalse
bool Priority(char a, char b) {
	if ((a == '+' || a == '-') && (b == '+' || b == '-' || b == '*' || b == '/')) {
		return true;
	} else if ((a == '*' || a == '/') && (b == '*' || b == '/')) {
		return true;
	}
	return false;
}

//��������������֮��ļ���
ElemType2 CalculateTwo(ElemType2 n1, ElemType2 n2, ElemType1 t) {
	//n1���Ҳ�����,n2���������
	if (t == '+')
		return n1 + n2;
	if (t == '-')
		return n2 - n1;
	if (t == '/')
		return n2 / n1;
	if (t == '*')
		return n2 * n1;
}

//������׺���ʽ���㷨:
void Calculate(ElemType1 str[], ElemType2 &e) {
	SqStack1 S1;//S1�������ջ
	SqStack2 S2;//S2�ǲ�����ջ
	InitStack_1(S1);//��ʼ��S1
	InitStack_2(S2);//��ʼ��S2
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
				Pop_2(S2, n1); //n1���Ҳ�����
				Pop_2(S2, n2); //n2���������
				Push_2(S2, CalculateTwo(n1, n2, t));
			}
			Push_1(S1, str[i]);
		} else {
			while (Pop_1(S1, t)) {
				if (t == '(')
					break;
				Pop_2(S2, n1); //n1���Ҳ�����
				Pop_2(S2, n2); //n2���������
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

	printf("\n������Ҫ����ı��ʽ:\n");
	scanf("%s", str);
	printf("\n���㲢������:\n");
	Calculate(str, e);
	printf("%f\n", e);
	return 0;
}
