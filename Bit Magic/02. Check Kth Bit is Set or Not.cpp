#include<bits/stdc++.h>
using namespace std;

// Method 1 - Using Left Shift Operator
void KthBit(int n, int k) {
	if (n & (1 << (k - 1)) != 0) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	cout << endl;
}

// Method 2 - Using Right Shift Operator
void kthbit(int n, int k) {
	if (((n >> (k - 1)) & 1) == 1) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	cout << endl;
}

int main()
{
	int n1 = 5, k1 = 3;
	KthBit(n1, k1);

	int n2 = 13, k2 = 3;
	kthbit(n2, k2);

	return 0;
}
