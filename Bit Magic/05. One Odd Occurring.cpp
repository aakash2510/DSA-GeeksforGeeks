#include<bits/stdc++.h>
using namespace std;

// Method 1 - Naive Solution
// Time : O(n^2)
void oneOdd1(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j] == arr[i])
				count++;
		}
		if (count % 2 != 0) {
			cout << arr[i];
		}
	}
	cout << endl;
}

// Method 2 - Efficient Method
// Time : O(n), Aux. Space : O(1)
int oneOdd2(int arr[], int n) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		res = res ^ arr[i];
	}
	return res;
}

// Variation Problem : Given an array of n number that has values in range [1...n+1].
// Every no. appears exactly once hence one no. is missing. Find the missing no.
int missingNumber(int arr[], int n) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		res = res ^ arr[i];
	}
	for (int i = 1; i <= n + 1; i++) {
		res = res ^ i;
	}
	return res;
}

int main()
{
	int arr[] = {4, 3, 4, 4, 4, 5, 5};
	int n = sizeof(arr) / sizeof(int);
	oneOdd1(arr, n);
	cout << oneOdd2(arr, n) << endl; // 3

	int arr1[] = {1, 5, 3, 2};
	int m = sizeof(arr1) / sizeof(int);
	cout << missingNumber(arr1, m) << endl; // 4

	return 0;
}
