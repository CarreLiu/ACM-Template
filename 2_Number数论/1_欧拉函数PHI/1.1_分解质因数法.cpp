/**
 * 定义法
 */
#include <iostream>
#include <cstring>
#define MAXN 10000
using namespace std;

int prime[MAXN+1];
int factor[100][2];
int fatCnt;

//欧拉筛选法求素数表
void getPrime()
{
	for (int i = 2; i <= MAXN; i++) {
		if (!prime[i])
			prime[++prime[0]] = i;	//prime[0]存放的是素数的个数
		for (int j = 1; j <= prime[0] && i * prime[j] <= MAXN; j++) {
			prime[i * prime[j]] = 1;
			if (!(i % prime[j]))
				break;
		}
	}
}

//求当前输入的数的质因数
int getFactor(int x)
{
	for (int i = 1; i <= prime[0] && prime[i] * prime[i] <= x; i++) {
		if (!(x % prime[i])) {
			factor[fatCnt][0] =  prime[i];
			while (!(x % prime[i])) {
				factor[fatCnt][1]++;
				x /= prime[i];
			}
			fatCnt++;
		}
	}

	if (x != 1) {
		factor[fatCnt][0] = x;
		factor[fatCnt++][1]++;
	}

	return fatCnt;
}

int main()
{
	memset(prime, 0, sizeof(prime));
	getPrime();
	int x;
	while (cin >> x) {
		fatCnt = 0;
		memset(factor, 0, sizeof(factor));
		getFactor(x);
		int res = x;
		for (int i = 0; i < fatCnt; i++) {
			res = res / factor[i][0] * (factor[i][0] - 1);	//欧拉函数的定义
		}

		cout << res << endl;
	}

	return 0;
}