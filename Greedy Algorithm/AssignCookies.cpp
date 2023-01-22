class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        // 1,2,3
        // 1,1
        sort(g.begin(), g.end());
        // 1,2,3
        sort(s.begin(), s.end());
        // 1,1
        int j = 0;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (j < g.size())
            {
                if (s[i] >= g[j])
                {
                    count++;
                    j++;
                }
            }
        }

        return count;
    }
};