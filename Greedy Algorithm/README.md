# For greedy algorithm:


#### 1. We have Activity selection

###### here we sort all the activities according to their end time, in this we always pick the next activity whose finish time is the least among the remaining acitivites and the start time is more than or equal to the finish time of the previously selected activity.

##### Steps
###### For the best approach we can use priority queue (Min heap) 

Code:-

void SelectActivities(vector<int> s, vector<int> f)
{
    vector<pair<int, int> > ans;
 
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                   greater<pair<int, int> > >
        p;
 
    for (int i = 0; i < s.size(); i++) {
        p.push(make_pair(f[i], s[i]));
    }
 
    auto it = p.top();
    int start = it.second;
    int end = it.first;
    p.pop();
    ans.push_back(make_pair(start, end));
 
    while (!p.empty()) {
        auto itr = p.top();
        p.pop();
        if (itr.second >= end) {
            start = itr.second;
            end = itr.first;
            ans.push_back(make_pair(start, end));
        }
    }
    
}
 
#### 2. Job scheduling with Deadline & Profit

###### Here we have profit upon completion of each job, so we need to maximise the profit, and keep the deadlines in mind. So we first sort according to the deadlines, and start from the end, and choose the maximum profit
  
Code:
      vector<int> JobScheduling(Job arr[], int n)
    {
        priority_queue<int> pq;
        sort(arr, arr + n, myComp);
        // 2,3,4,1
  
        int count = 0;
        int profit = 0;
        // 2,3,4,1

      
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
  
  
 
  
