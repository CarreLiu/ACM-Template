/**
 * Doolittle三角分解法可以用来解线性方程组，分解的对象是系数矩阵
 * Doolittle法中可以用顺序高斯消元思想，也可以用列主元高斯消元思想，此处选择了前者，即没有每次进行主元选择
 * 定理1：设n阶方阵A的各阶顺序主子式不为零，则存在唯一单位下三角矩阵L(单位是指主对角线都为1，而非下面的其他元素都为1)和上三角矩阵U使A=LU
 * 由A=LU,Ax=b => LUx=b,令Ux=y,得到两个式子:Ly=b和Ux=y
 */
#include <iostream>
#include <cmath>
using namespace std;

#define eps 1e-10
const int MAXN = 100;
double a[MAXN][MAXN];	//系数矩阵
double lu[MAXN][MAXN];	//同时存放L和U，两者共用一个二维数组
double b[MAXN];	//先用来表示常数b，再用来表示y，最后用来表示未知数x

int Doolittle(int n)
{
	for (int i = 0; i < n; i++)
		if (!a[i][i])	//无解
			return 0;

	for (int k = 0; k < n; k++) {
		for (int i = k; i < n; i++) {	//求U
			lu[k][i] = a[k][i];
			for (int j = 0; j < k; j++) {
				lu[k][i] -= lu[k][j] * lu[j][i];
			}	//最终需要除个1，但可省略
		}

		for (int i = k + 1; i < n; i++) {	//求L
			lu[i][k] = a[i][k];
			for (int j = 0; j < k; j++) {
				lu[i][k] -= lu[i][j] * lu[j][k];
			}
			lu[i][k] /= lu[k][k];	//最终需要除个lu[k][k]
		}
	}

	for (int i = 0; i < n; i++) {	//Ly=b,解出y
		for (int j = 0; j < i; j++) {
			b[i] -= lu[i][j] * b[j];
		}
	}

	for (int i = n - 1; i >= 0; i--) {	//Ux=y,解出x
		for (int j = n - 1; j > i; j--) {
			b[i] -= b[j] * lu[i][j];
		}
		b[i] /= lu[i][i];
	}
}

int main()
{
	int n;
	cin >> n;	//系数矩阵的阶数
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
		cin >> b[i];

	Doolittle(n);

	for (int i = 0; i < n; i++)
		cout << (fabs(b[i]) < eps ? 0 : b[i]) << " ";	//eps是为了防止精确解0显示为非0
	cout << endl;

	return 0;
}

/**
 * 例子：
 *		2  4 -2
 * A = 	1 -3 -3
 * 		4  2  2
 *
 * 		  2
 * b = 	 -1
 * 		  3
 *
 *		 1/2
 * x = 	 1/3
 * 		 1/6
 */