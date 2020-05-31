/**
 * 列主元高斯消去法
 * 列主元消去法是在每一步消元前，在主元所在的一列选取绝对值最大的元素作为主元素
 * 列主元高斯消去法进行下去的充要条件为系数矩阵A的行列式不为零
 * 当主元较小时，宜使用列主元高斯消去法
 */
#include <iostream>
#include <cmath>
using namespace std;

#define eps 1e-10
const int MAXN = 100;
double a[MAXN][MAXN];	//系数矩阵
double b[MAXN];	//存放常数矩阵
double c[MAXN];	//同时用作初等变换的系数和结果x矩阵

int gaussCpivot(int n)
{
	int row;
	double MAXP;

	for (int k = 0; k < n; k++) {	//k为主元所在行列
		row = 0;
		MAXP = 0.0;
		for (int i = k; i < n; i++) {	//在主元所在的一列选取绝对值最大的元素作为主元素
			if (fabs(a[i][k]) > MAXP) {
				MAXP = a[i][k];
				row = i;	//记录选取的主元所在的行
			}
		}
		if (fabs(MAXP) < eps) {	//主元所在列全为零，行列式为零，无解
			return 0;
		}

		if (row != k) {	//所选主元行不为原主元行时，交换行
			for (int i = k; i < n; i++) {
				swap(a[k][i], a[row][i]);
			}
			swap(b[k], b[row]);	//交换常数行
		}

		for (int i = k + 1; i < n; i++) {	//i为行号
			c[i] = a[i][k] / a[k][k];	//当前主元下面列的元素除以主元的结果系数
			for (int j = k; j < n; j++) {	//j为列号
				a[i][j] -= a[k][j] * c[i];	//初等行变换ri-c[i]*r[k]
			}
			b[i] -= b[k] * c[i];	//常数矩阵
		}
	}

	for (int i = n - 1; i >= 0; i--) {	//对化简后的上三角矩阵方程进行回代，就可求出方程的解；从最后一个未知数开始求
		double temp = 0;	//暂存其他已求出的未知数构成的值
		for (int j = n - 1; j > i; j--) {
			temp += c[j] * a[i][j];
		}
		c[i] = (b[i] - temp) / a[i][i];
	}

	return 1;
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

	gaussCpivot(n);

	for (int i = 0; i < n; i++)
		cout << (fabs(c[i]) < eps ? 0 : c[i]) << " ";	//eps是为了防止精确解0显示为非0
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