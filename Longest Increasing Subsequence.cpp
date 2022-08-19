/*int function(int i,int previ,vector<int>& nums,vector<vector<int>>& dp)
    {
       if(i==nums.size())
           return 0;
       
       if(dp[i][previ+1]!=-1)
           return dp[i][previ+1];
        int len=0+function(i+1,previ,nums,dp);
       if(previ==-1 || nums[i]>nums[previ])
       {
           len=max(len,1+function(i+1,i,nums,dp));
       }
        
        return dp[i][previ+1]=len;
    }*/
    int lengthOfLIS(vector<int>& nums) 
    {
        //int ans=1;
        int n=nums.size();
       // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        
        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
            }
        }
        
        return ans;*/
        
       // return function(0,-1,nums,dp);
        vector<int> dp(n,1);
        int ans=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(1+dp[j],dp[i]);
                }
            }
            ans=max(dp[i],ans);
        }
        
       
        
        
        return ans;
    }
