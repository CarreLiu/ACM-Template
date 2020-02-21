#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> L;
	for (int i = 0; i < 10; i++)
		L.push_back(i);

	vector<int>::iterator min_it = min_element(L.begin(), L.end());
	vector<int>::iterator max_it = max_element(L.begin(), L.end());
	cout << "Min is " << *min_it << endl;
	cout << "Max is " << *max_it << endl;


	return 0;
}