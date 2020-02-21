#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> L;
	int x;
	while (cin >> x) {
		L.push_back(x);
	}
	for (int i = L.size()-1; i >= 0; i--) {
		cout << L[i] << " ";
	}
	cout << endl;


	return 0;
}