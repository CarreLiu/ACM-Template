/**
 * 顺序高斯消去法，简称高斯消去法，Gauss消去法
 * 普通的高斯消去法，将增广矩阵化为上三角矩阵，下面都为0
 * 高斯消去法能进行下去的条件是消去时每一层的主元素都不为0，而其充要条件为系数矩阵A的各阶顺序主子式都不为零
 * 高斯消去法的局限性：当主元较小时，不适用，此时主元做除数的话，整体会很大；解决方法是使用列主元高斯消去法
 */
#include <iostream>
#include <cmath>
using namespace std;

#define eps 1e-10
const int MAXN = 100;
double a[MAXN][MAXN];	//系数矩阵
double b[MAXN];	//存放常数矩阵
double c[MAXN];	//同时用作初等变换的系数和结果x矩阵

int gauss(int n)
{
	for (int i = 0; i < n; i++)
		if (!a[i][i])	//无解
			return 0;

	for (int k = 0; k < n; k++) {	//k为主元所在行列
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

	gauss(n);

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