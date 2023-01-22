class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int count = 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int last = intervals[0][1];

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] < last)
            {
                count++;
            }
            else
            {
                last = intervals[i][1];
            }
        }
        return count;
    }
};