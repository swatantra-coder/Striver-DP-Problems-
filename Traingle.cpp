    int solve(vector<vector<int>>& t,int i,int j,vector<vector<int>>& dp)
    {
       if(i==t.size()-1)
           return t[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mx=INT_MAX;
        mx=t[i][j]+min(solve(t,i+1,j,dp),solve(t,i+1,j+1,dp));
        return dp[i][j]=mx;
    }
    int minimumTotal(vector<vector<int>>& t) 
    {
        int n=t.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<vector<int>> dp1(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            dp1[n-1][i]=t[n-1][i];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<t[i].size();j++)
            {
                int low=t[i][j]+dp1[i+1][j];
                int how=t[i][j]+dp1[i+1][j+1];
                
                dp1[i][j]=min(low,how);
            }
        }
        
        //return dp1[0][0];
        return solve(t,0,0,dp);
    }
