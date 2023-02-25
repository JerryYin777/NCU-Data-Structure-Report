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
	cout<<"二叉树中序线索化"<<endl;
	InOrderThreading(Thrt,T);
	cout<<"线索中序遍历"<<endl;
	InOrderTraverse_Thr(Thrt);
	cout<<"摧毁线索二叉树"<<endl; 
	DestroyBiThrTree(Thrt);
	return 0;
}
