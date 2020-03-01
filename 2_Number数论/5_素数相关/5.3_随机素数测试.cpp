/*
	完成此题需要有欧拉函数的基础
	HDU2138即是该类型的题目，不过输出不同
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;	//此处需要使用long long型，因为数可能有32位

ll pow_mod(ll a, ll m, ll n)	//快速幂，即求(a ^ m) % n
{
	ll ans = 1;
	ll k = a;
	while (m > 0) {
		if (m & 1)
			ans = ans * k % n;
		m >>= 1;	
		k = k * k % n;
	}

	return ans;
}

bool miller_rabin(ll n, int s = 10)	//miller-rabin随机算法检测n是否为素数，s为测试的迭代次数
{
	if (n == 2)
		return true;
	if (n < 2 || !(n & 1))
		return false;
	ll m = n - 1;
	int q = 0;	//n - 1 = (2 ^ q) * m
	while (!(m & 1)) {
		m >>= 1;
		q++;
	}
	ll x, y;
	srand(time(NULL));
	for (int i = 0; i < s; i++) {
		ll a = rand() % (n - 1) + 1;	//0<a<n，此处不要用模板中的RAND_MAX，否则生成的a太大，不好操作
		x = pow_mod(a, m, n);			//自a ^ m % n开始，每次做平方，直至a ^ ((2 ^ q) * m) % n
		for (int j = 0; j < q; j++) {	//引理2，二次探测定理
			y = x * x % n;
			if (y == 1 && x != 1 && x != n - 1)	//此行解释见解释1.jpg
				return false;
			x = y;
		}
		if (y != 1)	//引理1，费马小定理，判断顶部的a ^ ((2 ^ q) * m) % n是否为1，即a^(n-1) % n 是否为1，见图 解释1.jpg
			return false;
	}
	return true;
}

int main()
{
	ll n;
	while (cin >> n) {
		if (miller_rabin(n))
			cout << "prime number" << endl;
		else
			cout << "not prime number" << endl;
	}

	return 0;
}