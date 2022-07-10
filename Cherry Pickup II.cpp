int maxichoco(int i,int j1,int j2,int r,int c,vector<vector<int>> &grid,vector<vector<vector<int>>>& dp)
{   
    // base case outoff bound cases
    if(j1<0 or j2<0 or j1>=c or j2>=c)
        return -1e8;
    
   // check weather the value is present in dp matrix or not
    if(dp[i][j1][j2]!=-1)
        return dp[i][j1][j2];
    
    //at the final destination check and store the value accordingaly
    if(i==r-1)
    {
        if(j1==j2)
           return dp[i][j1][j2]=grid[i][j1];
        else
            return dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
    }
    
    // explore the different path across grid and store value in dp matrix
    int maxxi=INT_MIN;
    for(int d1=-1;d1<=1;d1++)
    {
        for(int d2=-1;d2<=1;d2++)
        {
            
            int value=0;
            if(j1==j2)
                value=grid[i][j1];
            if(j1!=j2)
                value=grid[i][j1]+grid[i][j2];
            value+=maxichoco(i+1,j1+d1,j2+d2,r,c,grid,dp);
            maxxi=max(maxxi,value);
           
                
        }
    }
    return  dp[i][j1][j2]=maxxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) 
{
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
  
    return maxichoco(0,0,c-1,r,c,grid,dp);
    
}
