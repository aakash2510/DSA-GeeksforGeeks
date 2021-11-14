#include<bits/stdc++.h>
using namespace std;

// Time : Theta((2^n)*n)
void printPowerSet(string str) {
	int n = str.length();
	int powSize = pow(2, n);
	for (int counter = 0; counter < powSize; counter++) {
		for (int j = 0; j < n; j++) {
			if ((counter & (1 << j)) != 0) {
				cout << str[j];
			}
		}
		cout << endl;
	}
}

int main()
{
	string s = "abc";
	printPowerSet(s);

	return 0;
}
