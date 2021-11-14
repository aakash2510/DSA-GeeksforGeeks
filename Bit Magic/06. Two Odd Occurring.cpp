#include<bits/stdc++.h>
using namespace std;

// Method 1 - Naive Solution
// Time :Theta(n^2)
void oddOccurring1(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j] == arr[i])
				cnt++;
		}
		if (cnt % 2 != 0) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}

// Method 2 - Efficient Solution
// Time : Theta(n)
void oddOccurring2(int arr[], int n) {
	int XOR = 0, res1 = 0, res2 = 0;
	for (int i = 0; i < n; i++) {
		XOR = XOR ^ arr[i];
	}
	int sn = XOR & (~(XOR - 1)); // rightmost set bit
	for (int i = 0; i < n; i++) {
		if ((arr[i]&sn) != 0) {
			res1 = res1 ^ arr[i];
		}
		else {
			res2 = res2 ^ arr[i];
		}
	}
	cout << res1 << " " << res2 << endl;
}

int main()
{
	int arr[] = {3, 4, 3, 4, 5, 4, 4, 6, 7, 7};
	int n = sizeof(arr) / sizeof(int);

	oddOccurring1(arr, n);
	oddOccurring2(arr, n);
	return 0;
}
