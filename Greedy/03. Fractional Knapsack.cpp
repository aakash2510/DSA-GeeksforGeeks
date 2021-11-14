// Problem link : https://www.geeksforgeeks.org/fractional-knapsack-problem/

// Video link : https://www.youtube.com/watch?v=F_DDzYnxO14&ab_channel=takeUforward

// 1. Calculate ratio(value/weight) for every item.
// 2. sort all item in decreasing order of ratio.
// 3. initialize : res = 0 , curr_cap = given_cap,
// 4. Do following for every item I in sorted order
//    (a.) if(I.weight<=curr_cap){
// 	curr_cap -= I.weight;
// 	res += I.value;
//    }
//    (b.) else{
// 	res += (I.value)*(curr_cap/I.weight);
// 	return res;
//    }
// 5. return res;

#include<bits/stdc++.h>
using namespace std;

bool myCmp(pair<int, int> a, pair<int, int>b) {
	double r1 = (double)a.first / a.second;
	double r2 = (double)b.first / b.second;
	return r1 > r2;
}

// Time Complexity : O(nlogn)
double fractionalKnapsack(int w, pair<int, int> arr[], int n)
{
	// sorting all items according to value per weight in decreasing order
	sort(arr, arr + n, myCmp);

	double res = 0.0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].second <= w)
		{
			res += arr[i].first;
			w = w - arr[i].second;
		}
		else
		{
			res += arr[i].first * ((double)w / arr[i].second);
			break;
		}
	}
	return res;
}

int main()
{
	pair<int, int> arr[] = {make_pair(120, 30), make_pair(100, 20), make_pair(60, 10)};
	int n = 3;
	int w = 50;

	cout << fractionalKnapsack(w, arr, n); // 240
	return 0;
}
