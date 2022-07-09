#define ll long long
    int minFallingPathSum(vector<vector<int>>& p) 
    {
        int n=p.size(),m=p[0].size();
        ll mx=INT_MAX,index;
        vector<vector<ll>> dp(n,vector<ll>(m,0));
        for(int j=0;j<m;j++)
        {
            dp[0][j]=p[0][j];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int up=p[i][j]+dp[i-1][j];
                
                int leftDiagonal= p[i][j];
                if(j-1>=0) 
                    leftDiagonal += dp[i-1][j-1];
                else 
                    leftDiagonal += +1e9;
            
                int rightDiagonal = p[i][j];
                if(j+1<m) 
                    rightDiagonal += dp[i-1][j+1];
                else 
                    rightDiagonal += +1e9;
                
                 dp[i][j] = min(up, min(leftDiagonal,rightDiagonal));   
            }
        }
        
        for(int j=0;j<p[n-1].size();j++)
        {
            
            mx=min(mx,dp[n-1][j]);
        }
        
        
        return mx;
        
        
    }
