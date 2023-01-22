class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        // 1 0 2
        // int left_kid=0;
        // int right_kid=1;
        // vector<int>left(ratings.size(),1);
        // vector<int>right(ratings.size(),1);
        // for(int i=0;i<ratings.size()-1;i++){
        //     right_kid= i+1;
        //     if(ratings[i]>ratings[left_kid]){
        //         ans[i]=ans[left_kid]+1;
        //     }
        //     if(ratings[i]>ratings[right_kid]){
        //         ans[i]=ans[right_kid]+1;
        //     }

        //     left_kid=i;

        // }
        // if(ratings[ratings.size()-1]>ratings[ratings.size()-2]){
        //     ans[ratings.size()-1]=ans[ratings.size()-2]+1;
        // }
        // int count=0;
        // for(int i=0;i<ans.size();i++){
        //     cout<<ans[i];
        //      count+=ans[i];
        // }
        // return count;
        vector<int> left(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
        }
        vector<int> right(ratings.size(), 1);
        for (int i = ratings.size() - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1])
            {
                right[i] = right[i + 1] + 1;
            }
        }
        int Total_candies = 0;
        for (int i = 0; i < ratings.size(); ++i)
        {
            Total_candies += max(right[i], left[i]);
        }
        return Total_candies;
    }
};