/**
 * 不需要判断x和y的大小关系；如果x比y小的话，一次for之后自动会交换
 * 当for循环遇到逗号运算符：中间一项，用逗号分开的表达式的值分别结算，但整个表达式的值是最后一个表达式的值
 * https://blog.csdn.net/hurmishine/article/details/75172761
 */
#include <iostream>
using namespace std;

int gcd(int x, int y)
{
	if (!x || !y)
		return x > y ? x : y;
	for (int t; t = x % y, t; x = y, y = t) ;	//中间一项的值为最右项t的值，即t为0时终止循环，不要漏了最外面的分号

	return y;
}

int main()
{
	int x, y;
	while (cin >> x >> y) {
		cout << gcd(x, y) << endl;
	}

	return 0;
}