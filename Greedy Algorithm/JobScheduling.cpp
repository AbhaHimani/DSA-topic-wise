//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
    static bool myComp(Job a, Job b)
    {
        return a.dead < b.dead;
    }
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        priority_queue<int> pq;
        sort(arr, arr + n, myComp);
        // 2,3,4,1
        vector<int> ans;
        int count = 0;
        int profit = 0;
        // 2,3,4,1

        vector<int> check;
        int tot = arr[n - 1].dead;
        // 4
        int idx = n - 1;
        while (tot > 0)
        {
            while (idx >= 0)
            {
                if (tot == arr[idx].dead)
                {
                    pq.push(arr[idx].profit);
                    idx--;
                }
                else
                {
                    break;
                }
            }
            if (pq.empty() == false)
            {
                count++;
                profit += pq.top();
                pq.pop();
            }
            tot--;
        }

        return {count, profit};

        // first we should sort this on the basis of deadline and then check the profit

        // your code here
    }
};

//{ Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends