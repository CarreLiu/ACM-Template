#include <iostream>
#include <cstring>
#include <climits>	//此头文件中有INT_MAX
#define MAXN 100000	//大于2^31开根号即可
#define MAXNN 1000000
using namespace std;
typedef long long ll;

ll prime[MAXN+1];
ll primes[MAXNN+1];
bool isPrime[MAXNN+1];

//初始化1--sqrt(2^31)之间的所有素数
void init_prime()
{
	prime[1] = 1;
	for (ll i = 2; i <= MAXN; i++) {
		if (!prime[i]) {
			prime[++prime[0]] = i;
		}
		for (ll j = 1; j <= prime[0] && i * prime[j] <= MAXN; j++) {
			prime[i * prime[j]] = 1;
			if (!(i % prime[j]))
				break;
		}
	}
}

//求出l--u之间的所有素数，存在下标为(该数-l)的数组primes中
void ask_prime(ll l, ll u)
{
	if (l == 1)	//1非素数，故若起始值为1，则可当起始值为2
		l = 2;
	//标记出l--u中的所有合数，存在(该数-l)的下标中,不减l会超出数组范围
	for (ll i = 1; i <= prime[0] && prime[i] * prime[i] <= u; i++) {	//素数到sqrt(u)即可
		ll b = (l - 1) /prime[i] + 1;	//b和e为当前检测的素数的倍数的起始值
		if (b == 1) {					//若l为2且prime[i]也为2时，则求出的b为1，此时b需从2开始；否则2会被当成合数
			b = 2;
		}
		ll e = u / prime[i];
		for (ll j = b; j <= e; j++) {	//素数乘以(b--e)均为合数，用true标记
			isPrime[prime[i] * j - l] = true;	//当前值减去l存储，否则会超出数组范围
		}
	}

	for (ll i = 0; i <= u - l; i++) {
		if (!isPrime[i])
			primes[++primes[0]] = i + l;//primes数组存储所有的素数，要还原减去的l 
	}
}

int main()
{
	memset(prime, 0, sizeof(prime));
	init_prime();
	ll l, u;
	while (cin >> l >> u) {
		memset(isPrime, false, sizeof(isPrime));
		memset(primes, 0, sizeof(primes));
		ask_prime(l, u);

		if (primes[0] < 2) {	//素数个数小于两个
			cout << "There are no adjacent primes." << endl;
			continue;
		}
		ll minB = 0, minE = INT_MAX;	//INT_MAX为头文件climits中的数
		ll maxB = 0, maxE = 0;
		for (ll i = 2; i <= primes[0]; i++) {	//暴力遍历
			if (primes[i] - primes[i-1] < minE - minB) {
				minE = primes[i];
				minB = primes[i-1];
			}
			if (primes[i] - primes[i-1] > maxE - maxB) {
				maxE = primes[i];
				maxB = primes[i-1];
			}
		}
		cout << minB << "," << minE << " are closest, "
		<< maxB << "," << maxE << " are most distant." << endl;
	}
	
	return 0;
}