#include<bits/stdc++.h>
using namespace std;

// Method 1 - Naive Solution
// Time : Theta(total bits in binary representation of n)
int CountSetBits1(int n) {
	int res = 0;
	while (n > 0) {
		if (n % 2 != 0) // if((n&1)==1) or res = res+(n&1)
			res++;   //    res++;
		n = n / 2; // or n = n>>1
	}
	return res;
}

// Method 2 - Brian and Kerningham Algorithm
// Time : Theta(Set Bit Count)
int CountSetBits2(int n) {
	int res = 0;
	while (n > 0) {
		n = (n & (n - 1));
		res++;
	}
	return res;
}

// Method 3 - Lookup Table Method for 32 bit numbers
// Time : Theta(1)
int table[256];
void initialize() {
	table[0] = 0;
	for (int i = 1; i < 256; i++) {
		table[i] = (i & 1) + table[i / 2];
	}
}

int CountSetBits3(int n) {
	int res = table[n & 0xff];
	n = n >> 8;
	res = res + table[n & 0xff];
	n = n >> 8;
	res = res + table[n & 0xff];
	n = n >> 8;
	res = res + table[n & 0xff];
	return res;
	// OR return (table[n & 0xff] + table[(n >> 8) & 0xff] + table[(n >> 16) & 0xff] + table[(n >> 24)]);
}

int main()
{
	int n = 40;
	cout << CountSetBits1(n) << endl;
	cout << CountSetBits2(n) << endl;
	initialize();
	cout << CountSetBits3(n) << endl;

	return 0;
}
