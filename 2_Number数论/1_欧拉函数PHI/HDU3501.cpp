/**
 * 计算小于n且与其不互质的数的和
 * 此处使用1---n-1的和 减去 小于n并与其互质的数的和来做
 * 此处使用到的公式：n大于1时，小于n，且与n互质的所有数字的和是 φ(n) * n / 2
 */
#include <iostream>
#define MODULE 1000000007
using namespace std;

typedef long long ll;

ll sumPhi;

ll getPhi(ll n)
{
	ll res = n;
	for (ll i = 2; i * i <= n; i++) {
		if (!(n % i)) {
			res = res / i * (i - 1);
			while (!(n % i))
				n /= i;
		}
	}
	if (n != 1) {
		res = res / n * (n - 1);
	}

	return res;
}

int main()
{
	ll n, sum, result;
	while (cin >> n && n) {
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		sumPhi = getPhi(n) * n / 2;
		sum = (1 + n - 1) * (n - 1) / 2;
		result = (sum - sumPhi) % MODULE;
		cout << result << endl;
	}

	return 0;
}