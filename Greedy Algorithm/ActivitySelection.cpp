void SelectActivities(vector s, vector f)
{
    vector<pair<int, int>> ans;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        p;

    for (int i = 0; i < s.size(); i++)
    {
        p.push(make_pair(f[i], s[i]));
    }

    auto it = p.top();
    int start = it.second;
    int end = it.first;
    p.pop();
    ans.push_back(make_pair(start, end));

    while (!p.empty())
    {
        auto itr = p.top();
        p.pop();
        if (itr.second >= end)
        {
            start = itr.second;
            end = itr.first;
            ans.push_back(make_pair(start, end));
        }
    }