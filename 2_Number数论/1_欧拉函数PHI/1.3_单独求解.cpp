/**
 * 本质是定义式的应用，即分解质因数法，φ(x) = x * ∏ (1-1/xi)，其中xi为x的非重复质因数
 */
#include <iostream>
using namespace std;

int euler(int x)
{
	int res = x;
	for (int i = 2; i * i <= x; i++) {
		if (!(x % i)) {
			res = res / i * (i - 1);	//求欧拉函数的定义式
			while (!(x % i)) {
				x /= i;
			}
		}
	}

	if (x != 1) {						//最后还剩一个因子
		res  = res / x * (x - 1);
	}

	return res;
}

int main()
{
	int x;
	while (cin >> x) {
		cout << euler(x) << endl;
	}


	return 0;
}