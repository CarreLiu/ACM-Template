/**
 * 素数筛选，prime生成连续素数表
 * prime[i]在标记i是否为素数(0为素数,1不为素数)的同时，亦用来从下标1开始存放素数，标记的速度比存素数的速度快，所以不会冲突
 * prime[0]用来存放当前素数的个数
 * 也可以再创一个数组专门判断每个数是否为素数，但没有必要，用一个数组即可
 */
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 100000;
int prime[MAXN+1];

int main()
{
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= MAXN; i++) {
		if (!prime[i]) {
			prime[++prime[0]] = i;
		}
		for (int j = 1; j <= prime[0] && prime[j]*i <= MAXN; j++) {
			prime[prime[j]*i] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}

	for (int i = 1; i <= prime[0]; i++) {
		cout << prime[i] << " ";
		if (i % 10 == 0)
			cout << endl;
	}

	return 0;
}
