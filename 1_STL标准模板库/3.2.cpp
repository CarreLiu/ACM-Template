#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	set<int>::iterator iter;
	for (int i = 1; i <= 5; i++) {
		s.insert(i);
	}

	for (iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	pair<set<int>::const_iterator, set<int>::const_iterator> pr;
	pr = s.equal_range(3);
	cout << *pr.first << endl;
	cout << *pr.second << endl;

	return 0;
}