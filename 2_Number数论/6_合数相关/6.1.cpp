/**
 * 合数的分解需要先进行素数的筛选
 * factor[i][0]存放分解的素数
 * factor[i][1]存放对应素数出现的次数
 * fatCnt存放合数分解出的素数个数(相同的素数只算一次)
 */
#include <iostream>
#include <cstring>
#define MAXN 10000
using namespace std;

int prime[MAXN+1];
int factor[100][2];
int fatCnt;

//欧拉筛选法获取素数表
void getPrime()
{
	for (int i = 2; i <= MAXN; i++) {
		if (!prime[i]) {
			prime[++prime[0]] = i;
		}
		for (int j = 1; j <= prime[0] && i * prime[j] <= MAXN; j++) {
			prime[i * prime[j]] = 1;
			if (!(i % prime[j]))
				break;
		}
	}
}

//合数分解
int getFactors(int x)
{
	fatCnt = 0;
	for (int i = 1; i <= prime[0] && prime[i] * prime[i] <= x; i++) {
		if (!(x % prime[i])) {
			factor[fatCnt][0] = prime[i];
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
		memset(factor, 0, sizeof(factor));
		int len = getFactors(x);
		for (int i = 0; i < len; i++)
			cout << factor[i][0] << " ";
		cout << endl;
	}

	return 0;
}