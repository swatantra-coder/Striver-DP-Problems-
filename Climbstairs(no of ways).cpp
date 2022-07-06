int inf = 1e9+7;
    //Function to count number of ways to reach the nth stair.
    int solve(int n,vector<int>& dp)
    {
        if(n==0)
           return 0;
        if(n==1 or n==2)
           return n;
        if(dp[n]!=-1)
           return dp[n];
           
        return dp[n]=((solve(n-1,dp)%inf)+(solve(n-2,dp)%inf))%inf;

    }
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n+1,-1);
        
        
        
        return solve(n,dp);
    }
