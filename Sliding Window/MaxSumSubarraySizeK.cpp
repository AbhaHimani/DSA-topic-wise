long maximumSumSubarray(int K, vector<int> &arr, int N)
{

    int i = 0, j = 0;
    long sum = 0, mx = 0;

    while (j < N)
    {
        sum += arr[j];
        if (j - i + 1 < K)
        {
            j++;
        }
        else
        {
            mx = max(sum, mx);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return mx;
    // code here
}