#include "huffmantree.h"
#include <iostream>
#include <string.h>
using namespace std;
 
void Select(HuffmanTree HT,int limit,int &s1,int &s2){
	s1=0;
	s2=0;
//	cout<<"HT+limit"<<(*(HT+limit)).weight<<"limit"<<limit<<endl;
	for(int i=1;i<=limit;i++){
		if((*(HT+i)).parent==0){
			//��ʼ����Ӧ��s1��s2��ֵ 
			if(s1==0){
				s1=i;
				continue;
			}
			else if(s2==0){
				s2=i;
				continue;
			}
			//ʹ��s1С��s2 
			if((*(HT+s1)).weight>(*(HT+s2)).weight){
				int tem=s1;
				s1=s2;
				s2=tem;
			}
			//�Ȱ�С�ķ����s1,s1��s2 
			if((*(HT+i)).weight<=(*(HT+s1)).weight){
//				cout<<"*(HT+i).weight"<<(*(HT+i)).weight<<"(*(HT+s1)).weight"<<(*(HT+s1)).weight<<endl;
				s2=s1; 
				s1=i;
//				cout<<"4"<<"i:"<<i<<"s1"<<s1<<endl;
			} 
			//Ѱ�ҵ� 
			if((*(HT+i)).weight>(*(HT+s1)).weight && (*(HT+i)).weight<(*(HT+s2)).weight){
				s2=i;
			}
		}
	}//for
	cout<<"Select s1: "<<s1<<" s2: "<<s2<<endl;
}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC,unsigned int *w,int n){
	if(n<=1) return;
	int m=2*n-1;
    HT = (HuffmanTree)malloc((m+1) * sizeof(HTNode));
	HuffmanTree p=HT;
	int i,s1,s2;
	//��ʼ������
	*(p) = {0,0,0,0}; 
	for(i=1;i<=n;++i,++p,++w){
		*(p+1) = {*w,0,0,0};
//		cout<<(*p).weight<<endl;
//		cout<<"HT[i]->weight: "<<(*HT).weight<<" "<<(*(HT+i)).weight<<endl;
//		cout<<"*w"<<*w<<endl;
	}
	for(;i<m;++i,++p) *(p+1)={0,0,0,0};
	for(int i=n+1;i<=m;++i){//�����շ����� 
		Select(HT,i-1,s1,s2);
		(*(HT+s1)).parent = i; (*(HT+s2)).parent = i;
		(*(HT+i)).lchild = s1; (*(HT+i)).rchild = s2;
		(*(HT+i)).weight = (*(HT+s1)).weight + (*(HT+s2)).weight;
		cout<<"HT[i].weight1:"<<(*(HT+i)).weight<<endl; 
	}
	//��Ҷ�ӽڵ㵽���ڵ�������ÿ���ַ��ĺշ�������
	HC = (HuffmanCode)malloc((n+1)*sizeof(char *));
	char *cd;
	cd = (char *)malloc(n*sizeof(char));
	*(cd+n-1)='\0';
	for(int i=1;i<=n;++i){
		int start = n-1;
		int c,f;
		for(c=i,f=(*(HT+i)).parent;f!=0;c=f,f=(*(HT+f)).parent){
			if((*(HT+f)).lchild == c){
				(*(cd+(--start))) = '0';
			}
			else{
				(*(cd+(--start))) = '1';
			}
//			cout<<"(cd+(start))"<<(cd+(start))<<endl;
		}
		(*(HC+i)) = (char *)malloc((n-start)*sizeof(char));
		strcpy((*(HC+i)),&(*(cd+start)));
	}
	free(cd);
}
