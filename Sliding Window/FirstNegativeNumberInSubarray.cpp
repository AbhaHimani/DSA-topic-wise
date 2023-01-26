vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    vector<long long> res;
    vector<long long> ans;
    long long int i = 0, j = 0;
    while (j < N)
    {
        if (A[j] < 0)
        {
            ans.push_back(A[j]);
        }

        if (j - i + 1 < K)
        {
            j++;
        }
        else
        {
            if (ans.size() == 0)
            {
                res.push_back(0);
            }

            else
            {
                res.push_back(ans[0]);
                if (ans[0] == A[i])
                {
                    ans.erase(ans.begin());
                }
            }

            i++;
            j++;
        }
    }
    return res;
}