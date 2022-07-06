int maax(int index,vector<int>& nums,vector<int>& dp)
    {
        if(index==0)
            return nums[index];
        if(index<0)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int pick=nums[index]+maax(index-2,nums,dp);
        int notpick=maax(index-1,nums,dp);
        
        return dp[index]=max(pick,notpick);
    }
    int rob(vector<int>& nums) 
    {
        vector<int> dp(nums.size()+1,-1);
        dp[0]=nums[0];
        int neg=0;
        for(int i=1;i<nums.size();i++)
        {
            int take=nums[i];
            if(i>1)
                take+=dp[i-2];
            int nottake=dp[i-1];
            dp[i]=max(take,nottake);
        }
       // return maax(nums.size()-1,nums,dp);
        return dp[nums.size()-1];
    }
