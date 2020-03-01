/*
	素数筛选，prime生成连续素数表
	nump存素数的个数
 */
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 100000;
int prime[MAXN];

int main()
{
	int nump = 0;
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= MAXN; i++) {
		if (!prime[i]) {
			prime[++nump] = i;
		}
		for (int j = 1; j <= nump && prime[j]*i <= MAXN; j++) {
			prime[prime[j]*i] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}

	for (int i = 1; i <= nump; i++) {
		cout << prime[i] << " ";
		if (i % 10 == 0)
			cout << endl;
	}

	return 0;
}
