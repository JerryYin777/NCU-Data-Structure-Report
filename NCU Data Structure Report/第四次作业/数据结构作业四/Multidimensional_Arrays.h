void InitNArray(NArray &A) {               //�������Ͷ�ά����
	int i, x, y, z, p, j, key = 1, elemtotal, address = 0;
	printf("�������ά�����ά����\n");           //�����ά�����ά��
	scanf("%d", &x);
	while (x < 1 || x > MaxDim) {
		printf("ά����������Χ!!����������\n");
		printf("�����������ά�����ά����\n");
		scanf("%d", &x);
	}
	A.dim = x;
	A.upper = (int *)malloc(A.dim * sizeof(int));        //����ռ��A.upper
	A.lower = (int *)malloc(A.dim * sizeof(int));        //����ռ��A.lower
	for (i = 1; i <= A.dim; i++) {
		A.lower[i] = 0;                                      //��A.lower��ʼ��Ϊ0
		A.upper[i] = 0;                                      //��A.upper��ʼ��Ϊ0
	}
	for (i = 1; i <= A.dim; i++) {                      //ѭ�������ά�����ά�����½�
		key = 1;                                         //���ñ�־
		while (key) {                                         //ѭ�������ά�����ά���Ͻ�
			printf("��������Ҫ������%dά�����%dά���Ͻ磺\n", A.dim, i);
			scanf("%d", &y);
			while (y < 0) {
				printf("��������Ͻ糬������Χ!����������\n");
				printf("��������Ҫ������%dά�����%dά���Ͻ磺\n", A.dim, i);
				scanf("%d", &y);
			}
			A.upper[i] = y;                                 //����ά�Ͻ縳ֵ��A.upper[i]
			//ѭ�������ά�����ά���½�
			printf("��������Ҫ������%dά�����%dά���½磺\n", A.dim, i);
			scanf("%d", &z);
			while (z < 0) {
				printf("��������½糬������Χ!����������\n");
				printf("��������Ҫ������%dά�����%dά���½磺\n", A.dim, i);
				scanf("%d", &z);
			}
			A.lower[i] = z;                                //����ά�½縳ֵ��A.lower[i]
			if (A.upper[i] > A.lower[i])
				key = 0;
			else {
				printf("����������½�����Ͻ磬�밴���������!\n");
				getch();
			}
		}
	}
	elemtotal = 1;                              //��ʼ�������ܸ���Ϊһ��
	for (i = 0; i <= A.dim; i++) {
		elemtotal = elemtotal * (A.upper[i] - A.lower[i] + 1); //���������ܸ���
	}
	A.num = elemtotal;                             //�������ܸ�����ֵ���ṹ���еı���
	A.data = (int *)malloc(A.num * sizeof(int));   //Ϊ���ݴ�ŷ����ַ�ռ�
	A.constants = (int *)malloc(A.dim * sizeof(int)); //Ϊӳ�����������ָ������ַ�ռ�
	A.constants[A.dim] = 1;
	for (i = A.dim - 1; i >= 1; --i) {
		A.constants[i] = (A.upper[i + 1] - A.lower[i + 1] + 1) * A.constants[i + 1];   //ӳ���������ļ��㹫ʽ
	}
//-----------------------------------------------------------------
	address = 0;                            //��ʼ��������Ԫ�صĵ�ַ
	for (i = 1; i <= A.dim; i++) {
		address = address + A.constants[i] * (A.upper[i] - A.lower[i]);   //�����ַ��ʽ
	}
	for (i = 0; i <= address; i++) { //������Ԫ�ظ�ֵΪ0
		A.data[i] = 0;
	}
//-------------------------------------------------------------------

//--------------------------------------------------------------------------------
	printf("----------------------��ϲ!��ϲ!��Ҫ�����Ķ�ά�����Ѿ�����!---------------------\n");
	printf("ϵͳ�Ѿ�����һ��%dά����a", A.dim);
	for (p = 1; p <= A.dim; p++)
		printf("[x]");
	printf("\n");          //����������ʽ
	for (j = 1; j <= A.dim; j++)
		printf("���ɵ�%dά�����%dά���±�x��ѡ��Χ��:%d��%d\n", A.dim, j, A.lower[j], A.upper[j]);
	printf("��ά����������\n");
//--------------------------------------------------------------------------------
}

void Assign1(NArray &A) {      //�Զ�ά����ĳ��Ԫ�ؽ��и�ֵ
	int i, key, address, data, a[5];
	for (i = 1; i <= A.dim; i++) {
		key = 1;
		while (key) {
			//ѭ��������и�ֵ��Ԫ�ظ�ά�±�
			printf("��������Ҫ���и�ֵ��%dά�����е�Ԫ�ص�%dά�±���:", A.dim, i);
			scanf("%d", &a[i - 1]);
			if (a[i - 1] <= A.upper[i] && a[i - 1] >= A.lower[i])
				key = 0;
			else {
				printf("������±곬������ķ�Χ���밴���������������!\n");
				getch();
			}
		}
	}
	//�����ʾ�����Ҫ�����λ����A[x][x]��������Ҫ�Ը�Ԫ�ظ�ֵ������
	printf("��Ҫ�����λ����A");
	for (i = 0; i < A.dim; i++)
		printf("[%d]", a[i]);
	printf("��������Ҫ�Ը�Ԫ�ظ�ֵ������:\n");
	scanf("%d", &data);
	address = 0;      //�����ַ
	for (i = 1; i <= A.dim; i++) {
		address = address + A.constants[i] * (a[i - 1] - A.lower[i]); //��ַ���㹫ʽ
	}
	A.data[address] = data;
	printf("              ��ֵ�ɹ�\n");                           //�����ֵ���
	printf("                  ���%dά������и�ֵ�Ľ����A", A.dim);
	for (i = 0; i < A.dim; i++)
		printf("[%d]", a[i]);
	printf("=");
	printf("%d\n", A.data[address]);
	printf("\n\n\n������Ҫִ��������ֵ����������ִ��ѡ��;����������������0.����\n:");
}


void Assign2 (NArray &A) {               //�Զ�ά������ָ���������鸳ֵ
	int i, key, b[10], address1, address2, k = 1, data; //��ʼ������
	printf("������������ĵ�һ��Ԫ�ص��±�:\n");
	for (i = 1; i <= A.dim; i++) {
		key = 1;
		while (key) {
			printf("�������һ��Ԫ�ص��±�%d��:", i);
			scanf("%d", &b[i - 1]);
			if (b[i - 1] >= A.lower[i])
				key = 0;
			else {
				printf("��������±�Ľ����������ķ�Χ���밴�����������������!\n");
				getch();
			}
		}
	}                                      //ѭ������������b���һ��Ԫ�ص��±�
	printf("����������������һ��Ԫ�ص��±�:\n");
	for (i = 1; i <= A.dim; i++) {
		key = 1;
		while (key) {
			printf("���������һ��Ԫ�ص��±�%d��:", i);
			scanf("%d", &b[i + 4]);
			if (b[i + 4] >= A.lower[i])
				key = 0;
			else {
				printf("��������±�Ľ����������ķ�Χ���밴�����������������!\n");
				getch();
			}
		}
	}
	printf("���������������A");  //���������
	for (i = 0; i < A.dim; i++)
		printf("[%d]", b[i]);
	printf("��A");
	for (i = 0; i < A.dim; i++)
		printf("[%d]", b[i + 5]);
	printf("\n");
	printf("��������Ҫ�Ը�����������Ԫ�ظ�ֵ������:\n");
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
	printf("              �������ֵ���Ϊ������:��������\n");
	printf("                        A");
	for (i = 0; i < A.dim; i++)
		printf("[%d]", b[i]);
	printf("��A");
	for (i = 0; i < A.dim; i++)
		printf("[%d]", b[i + 5]);
	printf("=%d", data);
	printf("\n\n������Ҫִ��������ֵ����������ִ��ѡ��;����������������0.����\n:");


}

void Assign3 (NArray &A) {    //����������Ԫ�ؽ��и�ֵ
	int i, data, address;
	printf("��������Ҫ�Ը���������Ԫ�ظ�ֵ������:\n");
	scanf("%d", &data);
	A.constants[A.dim] = 1;
	for (i = A.dim - 1; i >= 1; --i) {
		A.constants[i] = (A.upper[i + 1] - A.lower[i + 1] + 1) * A.constants[i + 1];   //ӳ���������ļ��㹫ʽ
	}
	address = 0;                            //��ʼ��������Ԫ�صĵ�ַ
	for (i = 1; i <= A.dim; i++) {
		address = address + A.constants[i] * (A.upper[i] - A.lower[i]);   //�����ַ��ʽ
	}
//-------------------------------------------------------------
	for (i = 0; i <= address; i++) { //��������Ԫ��ΪΪ�û������ֵ
		A.data[i] = data;
	}
//-------------------------------------------------------------
	printf("�Ѿ��Զ�ά�����е�����Ԫ�س�ʼ��ֵΪ%d.\n", data);
	printf("\n\n������Ҫִ��������ֵ����������ִ��ѡ��;����������������0.����\n:");


}


void Assign(NArray &A) {      //�Զ�ά����ĳ��Ԫ�ؽ��и�ֵ��ָ���������鸳ֵ
	int i = -1;
	printf("��ģ�����ʵ�����¹�����ѡ��\n");           //����ѡ�����
	printf("1.�Զ�ά����ĳ��Ԫ�ؽ��и�ֵ.\n");
	printf("2.�Զ�ά������ָ���������鸳ֵ.\n");
	printf("3.�Զ�ά��������Ԫ�س�ʼ����ֵ.\n");
	printf("0.�˳�.\n");
	printf("��������ѡ��ִ�е�ѡ��:");
	while (i != 0) {
		scanf("%d", &i);                                 //���빦��ѡ��

		switch (i) {
			case 1:
				Assign1(A);                                 //�Զ�ά����ĳ��Ԫ�ؽ��и�ֵ
				i = -1;                                      //��λ��־
				break;
			case 2:
				Assign2(A);                                    //�Զ�ά������ָ���������鸳ֵ
				i = -1;                                      //��λ
				break;
			case 3:
				Assign3(A);                                    //����������Ԫ�ؽ��и�ֵ
				i = -1;                                        //��λ��־
				return;
			case 0:
				return ;                                     //�˳�

			default:                                        //�������
				printf("\n�Բ���!�������������ȷ!����������!\n");       //ѡ�����.

		}
	}


	return ;
}

void Convey(NArray &A) {                 //�����鸳ֵ
	int i, j, key, a[10], b[10], address1, address2, address3, address4, numa, numb, k = 1; //��ʼ������
	for (i = 0; i <= A.dim; i++) {
		a[i] = A.lower[i];        //��ʼ��������a��һ��Ԫ�صĸ�ά�±�Ϊ��ֵַ
		a[i + 5] = A.lower[i];    //��ʼ��������a����Ԫ�صĸ�ά�±�Ϊ��ֵַ
		b[i] = A.lower[i];        //��ʼ��������b��һ��Ԫ�صĸ�ά�±�Ϊ��ֵַ
		b[i + 5] = A.lower[i];    //��ʼ��������b����Ԫ�صĸ�ά�±�Ϊ��ֵַ
	}
	while (k) {
		//ѭ������������a��һ��Ԫ�ص��±�
		printf("������������a�ĵ�һ��Ԫ�ص��±�:\n");
		for (i = 1; i <= A.dim; i++) {
			key = 1;
			while (key) {
				printf("������a��һ��Ԫ���±�%d��:", i);
				scanf("%d", &a[i - 1]);
				if (a[i - 1] <= A.upper[i] && a[i - 1] >= A.lower[i])
					key = 0;
				else {
					printf("��������±�Ľ����������ķ�Χ���밴�����������������!\n");
					getch();
				}
			}
		}
		printf("������������a�����һ��Ԫ�ص��±�:\n");
		for (i = 1; i <= A.dim; i++) {
			key = 1;
			while (key) {                        //ѭ������������a���һ��Ԫ�ص��±�
				printf("������a���һ��Ԫ���±�%d��:", i);
				scanf("%d", &a[i + 4]);
				if (a[i + 4] <= A.upper[i] && a[i + 4] >= A.lower[i])
					key = 0;
				else {
					printf("��������±�Ľ����������ķ�Χ���밴�����������������!\n");
					getch();
				}
			}
		}
		//ѭ������������b��һ��Ԫ�ص��±�
		printf("������������b�ĵ�һ��Ԫ�ص��±�:\n");
		for (i = 1; i <= A.dim; i++) {
			key = 1;
			while (key) {
				printf("������b��һ��Ԫ�ص��±�%d��:", i);
				scanf("%d", &b[i - 1]);
				if (a[i - 1] <= A.upper[i] && b[i - 1] >= A.lower[i])
					key = 0;
				else {
					printf("��������±�Ľ����������ķ�Χ���밴�����������������!\n");
					getch();
				}
			}
		}                                      //ѭ������������b���һ��Ԫ�ص��±�
		printf("������������b�����һ��Ԫ�ص��±�:\n");
		for (i = 1; i <= A.dim; i++) {
			key = 1;
			while (key) {
				printf("������b���һ��Ԫ�ص��±�%d��:", i);
				scanf("%d", &b[i + 4]);
				if (a[i + 4] <= A.upper[i] && b[i + 4] >= A.lower[i])
					key = 0;
				else {
					printf("��������±�Ľ����������ķ�Χ���밴�����������������!\n");
					getch();
				}
			}
		}
		numa = 1;                     //��ʼ��������a�ĸ���
		for (i = A.dim; i > 0; i--) {
			numa = numa * (abs(a[i] - a[i + 5]) + 1);   //����������a�ĸ���
		}

		numb = 1;                   //��ʼ��������b�ĸ���
		for (i = A.dim; i > 0; i--) {
			numb = numb * (abs(b[i] - b[i + 5]) + 1);   //����������b�ĸ���
		}
		if (numa == numb)
			k = 0;        //�жϸ����Ƿ����
		else {
			printf("�Բ���,������������������Ԫ�ظ�����ͬ���޷�����!�밴���������������\n");
			getch();
		}
	}
	printf("�������������a��A:");  //���������a
	for (i = 0; i < A.dim; i++)
		printf("[%d]", a[i]);
	printf("��A:");
	for (i = 0; i < A.dim; i++)
		printf("[%d]", a[i + 5]);
	printf("\n");
	printf("�������������b��A:");  //���������b
	for (i = 0; i < A.dim; i++)
		printf("[%d]", b[i]);
	printf("��A:");
	for (i = 0; i < A.dim; i++)
		printf("[%d]", b[i + 5]);
	printf("\n");
	address1 = 0;          //��ʼ��������a����ʼ��ַ
	address2 = 0;          //��ʼ��������a�Ľ�����ַ                         //���������鸳ֵ
	address3 = 0;          //��ʼ��������b����ʼ��ַ
	address4 = 0;          //��ʼ��������b�Ľ�����ַ
	for (i = 1; i <= A.dim; i++) {
		address1 = address1 + A.constants[i] * (a[i - 1] - A.lower[i]);   //������a����ʼ��ַ���㹫ʽ
	}
	for (i = 1; i <= A.dim; i++) {
		address2 = address2 + A.constants[i] * (a[i + 4] - A.lower[i]);   //������a�Ľ�����ַ���㹫ʽ
	}
	for (i = 1; i <= A.dim; i++) {
		address3 = address3 + A.constants[i] * (b[i - 1] - A.lower[i]);   //������b����ʼ��ַ���㹫ʽ
	}
	for (i = 1; i <= A.dim; i++) {
		address4 = address4 + A.constants[i] * (b[i + 4] - A.lower[i]);   //������b�Ľ�����ַ���㹫ʽ
	}
	i = address1;
	j = address3;
	for (; j <= address4 && i <= address2;) {
		A.data[i] = A.data[j];
		i++;
		j++;
	}

	printf("����������鸳ֵ�Ľ����������b��ֵ��������a,��a=b\n");


}

void Size(NArray &A) {                //�����ά������ܸ���
	printf("����������������������ά�����ܸ�������������������");
	printf("                      ���������Ķ�ά�����ܸ����Ĵ�С��:%d\n", A.num);
	printf("����������������������ά�����ܸ�������������������\n");

}

void Output(NArray &A) {                       //�����ά�����е�Ԫ��
	int i, key, address, data, a[5];
	printf("*****************************�����ά����*******************************\n");
	printf("��������������Ķ�ά�����λ��:\n");
	for (i = 1; i <= A.dim; i++) {
		key = 1;                            //���ñ�־
		while (key) {
			//ѭ������Ԫ�ظ�ά�±�
			printf("������Ҫ�����Ԫ����%dά������λ�õĵ�%dά�±���\n:", A.dim, i);
			scanf("%d", &a[i - 1]);
			if (a[i - 1] <= A.upper[i] && a[i - 1] >= A.lower[i])
				key = 0;
			else {
				printf("��������±곬������ķ�Χ���밴�����������������!\n");
				getch();
			}
		}
	}
	address = 0;                            //��ʼ��������Ԫ�صĵ�ַ
	for (i = 1; i <= A.dim; i++) {
		address = address + A.constants[i] * (a[i - 1] - A.lower[i]);   //�����ַ��ʽ
	}
	data = A.data[address];
	printf("��Ҫ�����λ����A");        //������
	for (i = 0; i < A.dim; i++)
		printf("[%d]", a[i]);
	printf("=%d\n", data);
	printf("*****************************�����ά����*******************************\n");

}
