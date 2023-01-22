vector<int> Solution::solve(vector<int> &arr, int B)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (B == 0)
            break;
        if (arr[i] != n - i)
        {
            int x = arr[i];

            arr[i] = n - i;

            B--;

            arr[mp[n - i]] = x;

            int k = mp[n - i];

            mp[n - i] = i;

            mp[x] = k;
        }
    }
    return arr;
}