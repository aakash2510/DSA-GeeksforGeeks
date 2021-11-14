// Problem link : https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

// Video link : https://www.youtube.com/watch?v=II6ziNnub1Q&t=98s&ab_channel=takeUforward

#include<bits/stdc++.h>
using namespace std;

bool myCmp(pair<int, int> a, pair<int, int> b) {
	return (a.second < b.second);
}

// Time Complexity : O(nlogn)
int maximumActivities(pair<int, int> arr[], int n)
{
	sort(arr, arr + n, myCmp);

	int prev = 0;
	int res = 1;

	for (int curr = 1; curr < n; curr++)
	{
		if (arr[curr].first >= arr[prev].second)
		{
			res++;
			prev = curr;
		}
	}
	return res;
}

int main()
{
	pair<int, int> arr[] = {make_pair(12, 25), make_pair(10, 20), make_pair(20, 30)};
	int n = 3;

	cout << maximumActivities(arr, n); // 2
	return 0;
}
