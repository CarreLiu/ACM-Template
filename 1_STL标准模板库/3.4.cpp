#include <iostream>
#include <set>
using namespace std;

int main()
{
	multiset<int> s;
	s.insert(1);
	s.insert(5);
	s.insert(4);
	s.insert(1);

	multiset<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << " ";

	return 0;
}