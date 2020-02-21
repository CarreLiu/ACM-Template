#include <iostream>
#include <map>
using namespace std;

typedef map<int, string, greater<int> > M_TYPE;
typedef M_TYPE::iterator M_IT;
typedef M_TYPE::const_iterator M_CIT;

int main()
{
	M_TYPE myTestMap;

	myTestMap[3] = "No.3";
	myTestMap[5] = "No.5";
	myTestMap[1] = "No.1";
	myTestMap[2] = "No.2";
	myTestMap[4] = "No.4";

	M_IT itStop = myTestMap.find(2);

	cout << "myTestMap[2] = " << itStop->second << endl;

	for (M_CIT it = myTestMap.begin(); it != myTestMap.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}


	return 0;
}