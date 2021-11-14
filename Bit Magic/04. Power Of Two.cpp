#include<bits/stdc++.h>
using namespace std;

// Method 1 - Naive Solution
bool isPow2(int n) {
	if (n == 0) {
		return false;
	}
	while (n != 1) {
		if (n % 2 != 0) {
			return false;
		}
		n = n / 2;
	}
	return true;
}

// Method 2 - Efficient - using count set bits by brian and kerningham algorithm
// Time : Theta(1) as in power of 2 there will be only 1 set bit.

bool IsPow2(int n) {
	if (n == 0)
		return false;
	return ((n & (n - 1)) == 0); // or return (n!=0)&&((n&(n-1))==0);
}

int main()
{
	int n = 6, m = 32;
	if (isPow2(n))
		cout << n << " is power of 2" << endl;
	else
		cout << n << " is not a power of 2" << endl;

	if (isPow2(m))
		cout << m << " is power of 2" << endl;
	else
		cout << m << " is not a power of 2" << endl;

	if (IsPow2(n))
		cout << n << " is power of 2" << endl;
	else
		cout << n << " is not a power of 2" << endl;

	if (IsPow2(m))
		cout << m << " is power of 2" << endl;
	else
		cout << m << " is not a power of 2" << endl;

	return 0;
}
