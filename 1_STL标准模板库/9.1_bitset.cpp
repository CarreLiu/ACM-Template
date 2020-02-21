#include <iostream>
#include <bitset>
using namespace std;
const int MAXN = 32;

int main()
{
	bitset<MAXN> bt(0x3f3f3f3f);
	cout << bt << endl;
	cout << bt.any() << endl;
	cout << bt.none() << endl;
	cout << bt.flip() << endl;
	cout << bt[7] << endl;

	return 0;
}