/**
 * 时间复杂度为n^2
 */
#include <iostream>
#include <cstring>
#define MAXN 100
using namespace std;
int phi[MAXN+1];

void euler()
{
	phi[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
		phi[i] = i;
	}
	for (int i = 2; i <= MAXN; i++) {
		if (phi[i] == i) {	//当为素数时
			for (int j = i; j <= MAXN; j += i) {
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

int main()
{
	memset(phi, 0, sizeof(phi));
	euler();
	for (int i = 1; i <= MAXN; i++) {
		cout << phi[i] << " ";
		if (!(i % 10))
			cout << endl;
	}

	return 0;
}