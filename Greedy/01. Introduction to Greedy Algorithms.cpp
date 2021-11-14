// Problem link : https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/

// video link : https://www.youtube.com/watch?v=mVg9CfJvayM&ab_channel=takeUforward

// --> Greedy Algorithms - mainly useful for optimisation problems.
// --> Greedy algorithms may not work always.

// --> Applications of Greedy algorithm :-

// 1. Finding optimal solutions
// - Activity Selection
// - Fractional Knapsack
// - Job Sequencing
// - Prim's Algorithms
// - Kurskal's Algorithms
// - Dijkstra's Algorithms
// - Huffman Coding

// 2. Finding close to optimal solutions for NP Hard Problems
//    like Travelling salesman problem.

// --> General Structure of Greedy Algorithms :-

// getOptimal(Item arr[], int n)
// (1) Initialize : result = 0
// (2) while(All items are not considered)
//     {
//       	i = selectAnItem()
//          if(feasible(i))
//             result += i
//     }
// (3) return result

#include<bits/stdc++.h>
using namespace std;

int minimumCoins(int coins[], int n, int amount)
{
	// Sort the coins array in descending order
	sort(coins, coins + n, greater<int>());

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		if (coins[i] <= amount)
		{
			int count = floor(amount / coins[i]);
			result += count;
			amount -= count * coins[i];
			if (amount == 0)
			{
				break;
			}
		}
	}
	return result;
}

int main()
{
	int amount = 57;
	int coins[] = {5, 10, 2, 1};
	int n = sizeof(coins) / sizeof(int);

	cout << minimumCoins(coins, n, amount); // 7
	return 0;
}
