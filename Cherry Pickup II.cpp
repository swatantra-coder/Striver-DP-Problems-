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


//-------------------------------------------------------------------------------------------------------//
vector < int > (m, 0)));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        dp[n - 1][j1][j2] = grid[n - 1][j1];
      else
        dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += dp[i + 1][j1 + di][j2 + dj];

            maxi = max(ans, maxi);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }

  return dp[0][0][m - 1];

}
