#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x = 3, y = 6;
	// bitwise AND(&)
	cout << (x & y) << endl; // 2
	// bitwise OR(|)
	cout << (x | y) << endl; // 7
	// bitwise XOR(^)
	cout << (x ^ y) << endl; // 5

	// Left Shift Operator(<<)
	int a = 3, b = 4; // (x<<y) is equivalent to x*(2^y)
	cout << (x << 1) << endl; // 6
	cout << (x << 2) << endl; // 12
	int c = (a << b);
	cout << c << endl; // 48

	// Right Shift Operator(>>)
	int p = 33, q = 4; // (x>>y) is equivalent to floor[x/(2^y)]
	cout << (p >> 1) << endl; // 16
	cout << (p >> 2) << endl; // 8
	int r = (p >> q);
	cout << r << endl; // 2

	// bitwise NOT(~)
	unsigned int m = 1; // unsigned int Range : [0 to 2^32-1]
	cout << (~m) << endl; // 4294967294
	m = 5;
	cout << (~m) << endl; // 4294967290

	// 2's compliment of x in n bits representation = 2^n - x
	int n = 1; // signed int Range : [-2^31 to 2^31-1]
	cout << (~n) << endl; // -2
	n = 5;
	cout << (~n) << endl; // -6

	return 0;
}
