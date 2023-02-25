#include "s1.h"
#include "s2.h"
#include "sh1.h"
#include "qh.h"

int main() {

	Open();                                                   //用户选择界面
	NArray A;                                                //定义数组
	int i = -1, j = 0;                                      //设置标志
	while (i != 0) {
		scanf("%d", &i);                                 //输入功能选项
		getchar();
		switch (i) {                                   //程序分支

			case 1:
				InitNArray(A);                                //定义多维数组
				j = 1;
				i = -1;                                      //复位标志

				Open();                                        //回复用户选择界面
				break;
			case 2:                                          //输出元素总个数
				if (!j) {
					printf("对不起!多维数组还未进行定义，请先定义多维数组!\n");
					Open();                                  //回到用户选择界面
					break;
				}
				Size(A);                                      //输出元素总个数
				i = -1;                                      //复位标志
				printf("请输入你继续选择执行的选项:");
				break;
			case 3:                             //对多维数组进行多种赋值
				if (!j) {
					printf("对不起!数组还没有定义，请先定义数组!\n");
					Open();                                     //回到用户选择界面
					break;
				}
				Assign(A);                                    //多维数组进行多种赋值化
				i = -1;                                      //复位标志
				Open();                                        //回复用户选择界面
				break;
			case 4:                                       //子数组覆盖
				if (!j) {
					printf("对不起!数组还没有定义，请先定义数组!\n");
					Open();                                   //回到用户选择界面
					break;
				}
				Convey(A);                                  //子数组赋值
				i = -1;                                     //复位标志


				Open();                                        //回复用户选择界面
				break;

			case 5:                                       //输出元素
				if (!j) {
					printf("对不起!多维数组还未进行定义，请先定义多维数组!\n");
					Open();                                  //回到用户选择界面
					break;
				}
				Output(A) ;                                   //输出元素

				Open();                                        //回复用户选择界面
				i = -1;                                      //复位标志
				break;
			case 6:                                        //打开帮助界面

				Help();                                     //帮助界面
				i = -1;                                      //复位标志
				printf("请输入你继续选择执行的选项:");
				break;
			case 7:
				system("cls");                               //清屏
				Open();                                     //回到用户选择界面
				break;

			case 0:
				return 0;                                     //退出

			default:                                        //输入错误
				printf("\n对不起!你的输入结果不正确!请重新输入!\n");       //选择错误.

		}
	}

}