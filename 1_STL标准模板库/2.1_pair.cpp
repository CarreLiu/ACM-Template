#include <iostream>
#include <utility>
using namespace std;

int main()
{
	pair<int, int> x;
	x = make_pair(1, 2);

	cout << x.first << endl;
	cout << x.second << endl;

	return 0;
}