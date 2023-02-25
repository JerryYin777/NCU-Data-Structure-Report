void InitNArray(NArray &A) {               //定义整型多维数组
	int i, x, y, z, p, j, key = 1, elemtotal, address = 0;
	printf("请输入多维数组的维数：\n");           //输入多维数组的维数
	scanf("%d", &x);
	while (x < 1 || x > MaxDim) {
		printf("维数超出处理范围!!请重新输入\n");
		printf("请重新输入多维数组的维数：\n");
		scanf("%d", &x);
	}
	A.dim = x;
	A.upper = (int *)malloc(A.dim * sizeof(int));        //分配空间给A.upper
	A.lower = (int *)malloc(A.dim * sizeof(int));        //分配空间给A.lower
	for (i = 1; i <= A.dim; i++) {
		A.lower[i] = 0;                                      //给A.lower初始化为0
		A.upper[i] = 0;                                      //给A.upper初始化为0
	}
	for (i = 1; i <= A.dim; i++) {                      //循环输入多维数组各维的上下界
		key = 1;                                         //设置标志
		while (key) {                                         //循环输入多维数组各维的上界
			printf("请输入你要创建的%d维数组第%d维的上界：\n", A.dim, i);
			scanf("%d", &y);
			while (y < 0) {
				printf("你输入的上界超出处理范围!请重新输入\n");
				printf("请输入你要创建的%d维数组第%d维的上界：\n", A.dim, i);
				scanf("%d", &y);
			}
			A.upper[i] = y;                                 //将各维上界赋值给A.upper[i]
			//循环输入多维数组各维的下界
			printf("请输入你要创建的%d维数组第%d维的下界：\n", A.dim, i);
			scanf("%d", &z);
			while (z < 0) {
				printf("你输入的下界超出处理范围!请重新输入\n");
				printf("请输入你要创建的%d维数组第%d维的下界：\n", A.dim, i);
				scanf("%d", &z);
			}
			A.lower[i] = z;                                //将各维下界赋值给A.lower[i]
			if (A.upper[i] > A.lower[i])
				key = 0;
			else {
				printf("你所输入的下界大于上界，请按任意键返回!\n");
				getch();
			}
		}
	}
	elemtotal = 1;                              //初始化数组总个数为一个
	for (i = 0; i <= A.dim; i++) {
		elemtotal = elemtotal * (A.upper[i] - A.lower[i] + 1); //计算数组总个数
	}
	A.num = elemtotal;                             //将数组总个数赋值给结构体中的变量
	A.data = (int *)malloc(A.num * sizeof(int));   //为数据存放分配地址空间
	A.constants = (int *)malloc(A.dim * sizeof(int)); //为映象函数常量表的指针分配地址空间
	A.constants[A.dim] = 1;
	for (i = A.dim - 1; i >= 1; --i) {
		A.constants[i] = (A.upper[i + 1] - A.lower[i + 1] + 1) * A.constants[i + 1];   //映象函数常量的计算公式
	}
//-----------------------------------------------------------------
	address = 0;                            //初始化并计算元素的地址
	for (i = 1; i <= A.dim; i++) {
		address = address + A.constants[i] * (A.upper[i] - A.lower[i]);   //计算地址公式
	}
	for (i = 0; i <= address; i++) { //将所有元素赋值为0
		A.data[i] = 0;
	}
//-------------------------------------------------------------------

//--------------------------------------------------------------------------------
	printf("----------------------恭喜!恭喜!你要创建的多维数组已经生成!---------------------\n");
	printf("系统已经生成一个%d维数组a", A.dim);
	for (p = 1; p <= A.dim; p++)
		printf("[x]");
	printf("\n");          //输出数组的形式
	for (j = 1; j <= A.dim; j++)
		printf("生成的%d维数组第%d维的下标x的选择范围是:%d到%d\n", A.dim, j, A.lower[j], A.upper[j]);
	printf("多维数组已生成\n");
//--------------------------------------------------------------------------------
}

void Assign1(NArray &A) {      //对多维数组某个元素进行赋值
	int i, key, address, data, a[5];
	for (i = 1; i <= A.dim; i++) {
		key = 1;
		while (key) {
			//循环输入进行赋值的元素各维下标
			printf("请输入你要进行赋值的%d维数组中的元素第%d维下标是:", A.dim, i);
			scanf("%d", &a[i - 1]);
			if (a[i - 1] <= A.upper[i] && a[i - 1] >= A.lower[i])
				key = 0;
			else {
				printf("输入的下标超出定义的范围，请按任意键返回再输入!\n");
				getch();
			}
		}
	}
	//输出提示语句你要存入的位置是A[x][x]请输入你要对该元素赋值的内容
	printf("你要存入的位置是A");
	for (i = 0; i < A.dim; i++)
		printf("[%d]", a[i]);
	printf("请输入你要对该元素赋值的内容:\n");
	scanf("%d", &data);
	address = 0;      //计算地址
	for (i = 1; i <= A.dim; i++) {
		address = address + A.constants[i] * (a[i - 1] - A.lower[i]); //地址计算公式
	}
	A.data[address] = data;
	printf("              赋值成功\n");                           //输出赋值结果
	printf("                  你对%d维数组进行赋值的结果是A", A.dim);
	for (i = 0; i < A.dim; i++)
		printf("[%d]", a[i]);
	printf("=");
	printf("%d\n", A.data[address]);
	printf("\n\n\n☆☆☆若要执行其他赋值操作请输入执行选项;返回主界面请输入0.☆☆☆\n:");
}


void Assign2 (NArray &A) {               //对多维数组中指定的子数组赋值
	int i, key, b[10], address1, address2, k = 1, data; //初始化变量
	printf("请输入子数组的第一个元素的下标:\n");
	for (i = 1; i <= A.dim; i++) {
		key = 1;
		while (key) {
			printf("子数组第一个元素的下标%d是:", i);
			scanf("%d", &b[i - 1]);
			if (b[i - 1] >= A.lower[i])
				key = 0;
			else {
				printf("你输入的下标的结果超出定义的范围，请按任意键返回重新输入!\n");
				getch();
			}
		}
	}                                      //循环输入子数组b最后一个元素的下标
	printf("请输入子数组的最后一个元素的下标:\n");
	for (i = 1; i <= A.dim; i++) {
		key = 1;
		while (key) {
			printf("子数组最后一个元素的下标%d是:", i);
			scanf("%d", &b[i + 4]);
			if (b[i + 4] >= A.lower[i])
				key = 0;
			else {
				printf("你输入的下标的结果超出定义的范围，请按任意键返回重新输入!\n");
				getch();
			}
		}
	}
	printf("你输入的子数组是A");  //输出子数组
	for (i = 0; i < A.dim; i++)
		printf("[%d]", b[i]);
	printf("到A");
	for (i = 0; i < A.dim; i++)
		printf("[%d]", b[i + 5]);
	printf("\n");
	printf("请输入你要对该子数组所有元素赋值的内容:\n");
	scanf("%d", &data);
	address1 = 0;
	address2 = 0;
	for (i = 1; i <= A.dim; i++) {
		address1 = address1 + A.constants[i] * (b[i - 1] - A.lower[i]);
	}
	for (i = 1; i <= A.dim; i++) {
		address2 = address2 + A.constants[i] * (b[i + 4] - A.lower[i]);
	}
	for (i = address1; i <= address2; i++) {
		A.data[i] = data;
	}
	printf("              ☆☆☆☆☆☆☆赋值结果为子数组:☆☆☆☆☆☆☆\n");
	printf("                        A");
	for (i = 0; i < A.dim; i++)
		printf("[%d]", b[i]);
	printf("到A");
	for (i = 0; i < A.dim; i++)
		printf("[%d]", b[i + 5]);
	printf("=%d", data);
	printf("\n\n☆☆☆若要执行其他赋值操作请输入执行选项;返回主界面请输入0.☆☆☆\n:");


}

void Assign3 (NArray &A) {    //对数组所有元素进行赋值
	int i, data, address;
	printf("请输入你要对该数组所有元素赋值的内容:\n");
	scanf("%d", &data);
	A.constants[A.dim] = 1;
	for (i = A.dim - 1; i >= 1; --i) {
		A.constants[i] = (A.upper[i + 1] - A.lower[i + 1] + 1) * A.constants[i + 1];   //映象函数常量的计算公式
	}
	address = 0;                            //初始化并计算元素的地址
	for (i = 1; i <= A.dim; i++) {
		address = address + A.constants[i] * (A.upper[i] - A.lower[i]);   //计算地址公式
	}
//-------------------------------------------------------------
	for (i = 0; i <= address; i++) { //数组所有元素为为用户输入的值
		A.data[i] = data;
	}
//-------------------------------------------------------------
	printf("已经对多维数组中的所有元素初始赋值为%d.\n", data);
	printf("\n\n☆☆☆若要执行其他赋值操作请输入执行选项;返回主界面请输入0.☆☆☆\n:");


}


void Assign(NArray &A) {      //对多维数组某个元素进行赋值或指定的子数组赋值
	int i = -1;
	printf("本模块可以实现以下功能请选择：\n");           //输入选择操作
	printf("1.对多维数组某个元素进行赋值.\n");
	printf("2.对多维数组中指定的子数组赋值.\n");
	printf("3.对多维数组所有元素初始化赋值.\n");
	printf("0.退出.\n");
	printf("请输入你选择执行的选项:");
	while (i != 0) {
		scanf("%d", &i);                                 //输入功能选项

		switch (i) {
			case 1:
				Assign1(A);                                 //对多维数组某个元素进行赋值
				i = -1;                                      //复位标志
				break;
			case 2:
				Assign2(A);                                    //对多维数组中指定的子数组赋值
				i = -1;                                      //复位
				break;
			case 3:
				Assign3(A);                                    //对数组所有元素进行赋值
				i = -1;                                        //复位标志
				return;
			case 0:
				return ;                                     //退出

			default:                                        //输入错误
				printf("\n对不起!你的输入结果不正确!请重新输入!\n");       //选择错误.

		}
	}


	return ;
}

void Convey(NArray &A) {                 //子数组赋值
	int i, j, key, a[10], b[10], address1, address2, address3, address4, numa, numb, k = 1; //初始化变量
	for (i = 0; i <= A.dim; i++) {
		a[i] = A.lower[i];        //初始化子数组a第一个元素的各维下标为起址值
		a[i + 5] = A.lower[i];    //初始化子数组a最后个元素的各维下标为起址值
		b[i] = A.lower[i];        //初始化子数组b第一个元素的各维下标为起址值
		b[i + 5] = A.lower[i];    //初始化子数组b最后个元素的各维下标为起址值
	}
	while (k) {
		//循环输入子数组a第一个元素的下标
		printf("请输入子数组a的第一个元素的下标:\n");
		for (i = 1; i <= A.dim; i++) {
			key = 1;
			while (key) {
				printf("子数组a第一个元素下标%d是:", i);
				scanf("%d", &a[i - 1]);
				if (a[i - 1] <= A.upper[i] && a[i - 1] >= A.lower[i])
					key = 0;
				else {
					printf("你输入的下标的结果超出定义的范围，请按任意键返回重新输入!\n");
					getch();
				}
			}
		}
		printf("请输入子数组a的最后一个元素的下标:\n");
		for (i = 1; i <= A.dim; i++) {
			key = 1;
			while (key) {                        //循环输入子数组a最后一个元素的下标
				printf("子数组a最后一个元素下标%d是:", i);
				scanf("%d", &a[i + 4]);
				if (a[i + 4] <= A.upper[i] && a[i + 4] >= A.lower[i])
					key = 0;
				else {
					printf("你输入的下标的结果超出定义的范围，请按任意键返回重新输入!\n");
					getch();
				}
			}
		}
		//循环输入子数组b第一个元素的下标
		printf("请输入子数组b的第一个元素的下标:\n");
		for (i = 1; i <= A.dim; i++) {
			key = 1;
			while (key) {
				printf("子数组b第一个元素的下标%d是:", i);
				scanf("%d", &b[i - 1]);
				if (a[i - 1] <= A.upper[i] && b[i - 1] >= A.lower[i])
					key = 0;
				else {
					printf("你输入的下标的结果超出定义的范围，请按任意键返回重新输入!\n");
					getch();
				}
			}
		}                                      //循环输入子数组b最后一个元素的下标
		printf("请输入子数组b的最后一个元素的下标:\n");
		for (i = 1; i <= A.dim; i++) {
			key = 1;
			while (key) {
				printf("子数组b最后一个元素的下标%d是:", i);
				scanf("%d", &b[i + 4]);
				if (a[i + 4] <= A.upper[i] && b[i + 4] >= A.lower[i])
					key = 0;
				else {
					printf("你输入的下标的结果超出定义的范围，请按任意键返回重新输入!\n");
					getch();
				}
			}
		}
		numa = 1;                     //初始化子数组a的个数
		for (i = A.dim; i > 0; i--) {
			numa = numa * (abs(a[i] - a[i + 5]) + 1);   //计算子数组a的个数
		}

		numb = 1;                   //初始化子数组b的个数
		for (i = A.dim; i > 0; i--) {
			numb = numb * (abs(b[i] - b[i + 5]) + 1);   //计算子数组b的个数
		}
		if (numa == numb)
			k = 0;        //判断个数是否相等
		else {
			printf("对不起,你输入的两个子数组的元素个数不同，无法进行!请按任意键返回再输入\n");
			getch();
		}
	}
	printf("你输入的子数组a是A:");  //输出子数组a
	for (i = 0; i < A.dim; i++)
		printf("[%d]", a[i]);
	printf("到A:");
	for (i = 0; i < A.dim; i++)
		printf("[%d]", a[i + 5]);
	printf("\n");
	printf("你输入的子数组b是A:");  //输出子数组b
	for (i = 0; i < A.dim; i++)
		printf("[%d]", b[i]);
	printf("到A:");
	for (i = 0; i < A.dim; i++)
		printf("[%d]", b[i + 5]);
	printf("\n");
	address1 = 0;          //初始化子数组a的起始地址
	address2 = 0;          //初始化子数组a的结束地址                         //进行子数组赋值
	address3 = 0;          //初始化子数组b的起始地址
	address4 = 0;          //初始化子数组b的结束地址
	for (i = 1; i <= A.dim; i++) {
		address1 = address1 + A.constants[i] * (a[i - 1] - A.lower[i]);   //子数组a的起始地址计算公式
	}
	for (i = 1; i <= A.dim; i++) {
		address2 = address2 + A.constants[i] * (a[i + 4] - A.lower[i]);   //子数组a的结束地址计算公式
	}
	for (i = 1; i <= A.dim; i++) {
		address3 = address3 + A.constants[i] * (b[i - 1] - A.lower[i]);   //子数组b的起始地址计算公式
	}
	for (i = 1; i <= A.dim; i++) {
		address4 = address4 + A.constants[i] * (b[i + 4] - A.lower[i]);   //子数组b的结束地址计算公式
	}
	i = address1;
	j = address3;
	for (; j <= address4 && i <= address2;) {
		A.data[i] = A.data[j];
		i++;
		j++;
	}

	printf("你进行子数组赋值的结果是子数组b赋值于子数组a,即a=b\n");


}

void Size(NArray &A) {                //输出多维数组的总个数
	printf("☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆输出多维数组总个数☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆");
	printf("                      你所创建的多维数组总个数的大小是:%d\n", A.num);
	printf("☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆输出多维数组总个数☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");

}

void Output(NArray &A) {                       //输出多维数组中的元素
	int i, key, address, data, a[5];
	printf("*****************************输出多维数组*******************************\n");
	printf("请输入你想输出的多维数组的位置:\n");
	for (i = 1; i <= A.dim; i++) {
		key = 1;                            //设置标志
		while (key) {
			//循环输入元素各维下标
			printf("请输入要输出的元素在%d维数组中位置的第%d维下标是\n:", A.dim, i);
			scanf("%d", &a[i - 1]);
			if (a[i - 1] <= A.upper[i] && a[i - 1] >= A.lower[i])
				key = 0;
			else {
				printf("你输入的下标超出定义的范围，请按任意键返回重新输入!\n");
				getch();
			}
		}
	}
	address = 0;                            //初始化并计算元素的地址
	for (i = 1; i <= A.dim; i++) {
		address = address + A.constants[i] * (a[i - 1] - A.lower[i]);   //计算地址公式
	}
	data = A.data[address];
	printf("你要输出的位置是A");        //输出结果
	for (i = 0; i < A.dim; i++)
		printf("[%d]", a[i]);
	printf("=%d\n", data);
	printf("*****************************输出多维数组*******************************\n");

}
