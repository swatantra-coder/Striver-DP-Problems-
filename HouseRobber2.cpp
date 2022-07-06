int rob(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> dp(nums.size(),0),dp1(nums.size(),0);
        if(n==1)
            return nums[0];
        else if(n==2)
            return max(nums[1],nums[0]);
        dp[0]=nums[0];
        for(int i=1;i<nums.size()-1;i++)
        {
            int take=nums[i];
            if(i>1)
                take+=dp[i-2];
            int nottake=dp[i-1];
            dp[i]=max(take,nottake);
        }
        
        dp1[1]=nums[1];
        dp1[2]=nums[2];
        for(int i=2;i<nums.size();i++)
        {
            int take=nums[i]+dp1[i-2];
            int nottake=dp1[i-1];
            dp1[i]=max(take,nottake);
        }
        return max(dp[n-2],dp1[n-1]);
    }
