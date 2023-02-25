#include <iostream>
#include "bithrtree.h"
#include "status.h"
using namespace std;
//input: ABDG##H###CE#I##F##
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	BiThrTree T;
	BiThrTree Thrt;
	CreateBiThrTree(T);
	cout<<"����������������"<<endl;
	InOrderThreading(Thrt,T);
	cout<<"�����������"<<endl;
	InOrderTraverse_Thr(Thrt);
	cout<<"�ݻ�����������"<<endl; 
	DestroyBiThrTree(Thrt);
	return 0;
}
