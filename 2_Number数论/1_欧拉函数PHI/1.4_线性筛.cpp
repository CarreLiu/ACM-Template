/**
 * 时间复杂度为线性
 * 同时得到欧拉函数和素数表
 */
#include <iostream>
#include <cstring>
#define MAXN 10000
using namespace std;
int prime[MAXN+1];
int phi[MAXN+1];

//本质是欧拉筛选法
void getPhi()
{
	phi[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
		if (!prime[i]) {
			prime[++prime[0]] = i;	//prime[0]存放的是素数的个数
			phi[i] = i - 1;	//当i是素数时 phi[i] = i - 1 
		}
		for (int j = 1; j <= prime[0] && i * prime[j] <= MAXN; j++) {
			prime[i * prime[j]] = 1;
			if (!(i % prime[j])) {
				phi[i * prime[j]] = phi[i] * prime[j];	//p为质数，如果i mod p = 0,那么phi(i * p) = phi(i) * p
				break;
			}
			else {
				phi[i * prime[j]] = phi[i] * phi[prime[j]]; //p为质数，如果i mod p ≠0,那么phi(i * p)=phi(i) * phi(p)
				//phi(p) = p - 1，因为p为素数
			}
		}
	}
}

int main()
{
	getPhi();

	for (int i = 1; i <= 20; i++) {
		cout << phi[i] << " ";
		if (!(i % 5))
			cout << endl;
	}

	return 0;
}