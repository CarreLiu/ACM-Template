#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	vector<int> s;
	s.push_back(1);
	s.push_back(2);
	s.push_back(3);
	s.push_back(4);
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}