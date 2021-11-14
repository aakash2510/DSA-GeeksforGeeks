// Problem link : https://www.geeksforgeeks.org/job-sequencing-problem/

// Video link : https://www.youtube.com/watch?v=LjPx4wQaRIs&ab_channel=takeUforward

/*
1. sort all the jobs in decreasing order of profit
2. initialize the result as first job in the sorted list.
   assign the latest possible slot.
3. Do the following for the remaining (n-1) jobs
   (a) if this job cannot added, ignore it.
   (b) else add it to the latest possible slot.
*/

// Time Complexity : O(nlogn)

// Program to find the maximum profit job sequence from a given array of jobs with deadlines and profits
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// A structure to represent a job
struct Job
{
	char id;     // Job Id
	int dead;    // Deadline of job
	int profit;  // Profit if job is over before or on deadline
};

class Solution {
public:
	static bool cmp(Job a, Job b) {
		return (a.profit > b.profit);
	}
	//Function to find the maximum profit and the number of jobs done.
	vector<int> JobScheduling(Job arr[], int n)
	{
		// your code here
		// Sort all jobs according to decreasing order of profit
		sort(arr, arr + n, cmp);

		int result[n]; // To store result (Sequence of jobs)
		bool slot[n];  // To keep track of free time slots

		// Initialize all slots to be free
		for (int i = 0; i < n; i++)
			slot[i] = false;
		int countjobs = 0, jobprofit = 0;
		// Iterate through all given jobs
		for (int i = 0; i < n; i++)
		{
			// Find a free slot for this job (Note that we start
			// from the last possible slot)
			for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
			{
				// Free slot found
				if (slot[j] == false)
				{
					result[j] = i;  // Add this job to result
					countjobs++;
					jobprofit += arr[i].profit;
					slot[j] = true; // Make this slot occupied
					break;
				}
			}
		}
		vector<int> v;
		v.push_back(countjobs);
		v.push_back(jobprofit);
		return v;
	}
};

int main()
{
	int t;
	//testcases
	cin >> t;

	while (t--) {
		int n;

		//size of array
		cin >> n;
		Job arr[n];

		//adding id, deadline, profit
		for (int i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			arr[i].id = x;
			arr[i].dead = y;
			arr[i].profit = z;
		}
		Solution ob;
		//function call
		vector<int> ans = ob.JobScheduling(arr, n);
		cout << ans[0] << " " << ans[1] << endl;
	}
	return 0;
}

// Input : 1
//         4
//         1 4 20 2 1 10 3 1 40 4 1 30
// Output : 2 60
