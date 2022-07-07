int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,1));
        dp[0][0]=grid[0][0];
        int mn=INT_MAX;
        for(int i=1;i<m;i++)
        {
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1;i<n;i++)
        {
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
        
        
    }



// <h1>Space optimized code---------</h1>



int minSumPath(vector<vector<int>> &grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m,0);
    for(int i=0;i<n;i++)
    {
        vector<int> temp(m,0);
        for(int j=0;j<m;j++)
        {
            if(i==0 and j==0)
                temp[j]=grid[i][j];
            else
            {
                int left=grid[i][j];
                int up=grid[i][j];
                if(i>0)
                    up+=prev[j];
                else
                    up=1e9;
                if(j>0)
                    left+=temp[j-1];
                else
                    left=1e9;
                temp[j]=min(left,up);
            }
        }
        prev=temp;
    }
    return prev[m-1];
}
