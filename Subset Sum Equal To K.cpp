bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
    dp[0][arr[0]]=1;
    for(int i=1;i<n;i++)
    {
        for(int tar=1;tar<=k;tar++)
        {
            int notake=dp[i-1][tar];
            int take=0;
            if(arr[i]<=tar)
                take=dp[i-1][tar-arr[i]];
            dp[i][tar]=take or notake;
        }
    }
    
    return dp[n-1][k];
}
