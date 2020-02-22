/*
	素数筛选，notprime是一张表
	false表示是素数，true表示不是
 */
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN = 40000000;
bool notprime[MAXN];

int main()
{
	int mid_MAXN = sqrt(MAXN);
	memset(notprime, false, sizeof(notprime));
	notprime[0] = notprime[1] = true;
	for (int i = 2; i <= mid_MAXN; i++) {
		if (!notprime[i]) {
			for (int j = i * i; j < MAXN; j += i) {
				notprime[j] = true;
			}
		}
	}

	cout << notprime[39999931] << endl;


	return 0;
}
