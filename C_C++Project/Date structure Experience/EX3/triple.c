/*
*三元组主要是用来存储稀疏矩阵的一种压缩方式，也叫三元组表。
*假设以顺序存储结构 来表示三元组表（triple table），则得到 稀疏矩阵的一种压缩存储方式，即三元组顺序表，简称三元组表。
*要求根据稀疏矩阵实现三元组的一些基本操作
*构建一个三元组并输出
*实现一个三元组的转置
*实现两个三元组相加
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100     // 三元组表的最大长度
#define MAXRC 100       // 矩阵的最大行数和列数

// 三元组结构体
typedef struct
{
	int i, j;   // 该非零元的行下标和列下标
	int e;      // 该非零元的值
}Triple;

// 三元组顺序表结构体
typedef struct
{
	Triple data[MAXSIZE + 1]; // 非零元三元组表，data[0]未用，data[1]存储矩阵的行数、列数和非零元个数，其余元素存储三元组，按行序顺序存储，即先行后列，
	int mu, nu, tu; // 矩阵的行数、列数和非零元个数
}TSMatrix;

void CreateMatrix(TSMatrix *M, int mu, int nu, int tu)
{
	int i;
	M->mu = mu;
	M->nu = nu;
	M->tu = tu;
	
	for (i = 1; i <= tu; i++)
	{
		printf("请输入第%d个非零元素的行数、列数和值：", i);
		scanf("%d%d%d", &M->data[i].i, &M->data[i].j, &M->data[i].e);
	}
}

void PrintMatrix(TSMatrix M)
{
	int i;
	for (i = 1; i <= M.tu; i++)
	{
		printf("%d %d %d\n", M.data[i].i, M.data[i].j, M.data[i].e);
	}
}

// 三元组转置
void TransposeMatrix(TSMatrix M, TSMatrix *T){
	int i, j, k;
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	if (T->tu)
	{
		k = 1;
		for (j = 1; j <= M.nu; j++)
		{
			for (i = 1; i <= M.tu; i++)
			{
				if (M.data[i].j == j)
				{
					T->data[k].i = M.data[i].j;
					T->data[k].j = M.data[i].i;
					T->data[k].e = M.data[i].e;
					k++;
				}
			}
		}
	}
	
}

// 三元组相加
void AddMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q)
{
	int i, j, k;
	if (M.mu != N.mu || M.nu != N.nu)
	{
		printf("两个矩阵的行数或列数不相等，不能相加\n");
		exit(0);
	}
	Q->mu = M.mu;
	Q->nu = M.nu;
	Q->tu = 0;
	if (M.tu && N.tu)
	{
		i = j = k = 1;
		while (i <= M.tu && j <= N.tu)
		{
			if (M.data[i].i < N.data[j].i)
			{
				Q->data[k].i = M.data[i].i;
				Q->data[k].j = M.data[i].j;
				Q->data[k].e = M.data[i].e;
				i++;
				k++;
			}
			else if (M.data[i].i > N.data[j].i)
			{
				Q->data[k].i = N.data[j].i;
				Q->data[k].j = N.data[j].j;
				Q->data[k].e = N.data[j].e;
				j++;
				k++;
			}
			else
			{
				if (M.data[i].j < N.data[j].j)
				{
					Q->data[k].i = M.data[i].i;
					Q->data[k].j = M.data[i].j;
					Q->data[k].e = M.data[i].e;
					i++;
					k++;
				}
				else if (M.data[i].j > N.data[j].j)
				{
					Q->data[k].i = N.data[j].i;
					Q->data[k].j = N.data[j].j;
					Q->data[k].e = N.data[j].e;
					j++;
					k++;
				}
				else
				{
					Q->data[k].i = M.data[i].i;
					Q->data[k].j = M.data[i].j;
					Q->data[k].e = M.data[i].e + N.data[j].e;
					i++;
					j++;
					k++;
				}
			}
		}
		while (i <= M.tu)
		{
			Q->data[k].i = M.data[i].i;
			Q->data[k].j = M.data[i].j;
			Q->data[k].e = M.data[i].e;
			i++;
			k++;
		}
		while (j <= N.tu)
		{
			Q->data[k].i = N.data[j].i;
			Q->data[k].j = N.data[j].j;
			Q->data[k].e = N.data[j].e;
			j++;
			k++;
		}
		Q->tu = k - 1;
	}
}

// 主函数，测试
int main(){
	
	// 测试三元组的创建与输出,转置,相加
	TSMatrix M;
	int mu, nu, tu;
	printf("请输入矩阵的行数、列数和非零元个数：");
	scanf("%d%d%d", &mu, &nu, &tu);
	CreateMatrix(&M, mu, nu, tu);
    printf("此矩阵的三元组表为：\n");
	PrintMatrix(M);
	
	TSMatrix T;
	TransposeMatrix(M, &T);
    printf("此矩阵的转置矩阵的三元组表为：\n");
	PrintMatrix(T);
	
	TSMatrix Q;
	AddMatrix(M, T, &Q);
    printf("此矩阵与其转置矩阵相加的三元组表为：\n");
	PrintMatrix(Q);;
	
	return 0;
}