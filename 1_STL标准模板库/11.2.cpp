#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(vector<int> &L)
{
	for (vector<int>::iterator it = L.begin(); it != L.end(); it++)
		cout << *it << " ";

	cout << endl;
}

int main()
{
	vector<int> L;
	for (int i = 0; i < 5; i++)
		L.push_back(i);

	for (int i = 9; i >= 5; i--)
		L.push_back(i);

	Print(L);

	sort(L.begin(), L.end());
	Print(L);

	sort(L.begin(), L.end(), greater<int>());
	Print(L);


	return 0;
}