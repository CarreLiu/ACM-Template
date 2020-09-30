#include <iostream>
#include <set>
using namespace std;

int main()
{
	int a[] = {4, 6, 2, 3};
	set<int> s(a, a+4);
	set<int>::const_iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	if ((iter = s.find(3)) != s.end())
		cout << *iter << endl;

	return 0;
}