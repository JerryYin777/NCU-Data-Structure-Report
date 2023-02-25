#include <iostream>
#include "huffmantree.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// ‰»Î chenkelsisthistttt
//c:1 h:2 e:2 n:1 k:1 l:1 s:3 i:2 t:5
int main(int argc, char** argv) {
	unsigned int w[] = {1,2,2,1,1,1,3,2,5};
	HuffmanTree HT;
	HuffmanCode HC;
	HuffmanCoding(HT,HC,w,9);
	for(int i=1;i<=9;i++){
		cout<<"HC"<<i<<"µƒ∫’∑Ú¬¸±‡¬Î"<<HC[i]<<endl;
	}
	return 0;
}
