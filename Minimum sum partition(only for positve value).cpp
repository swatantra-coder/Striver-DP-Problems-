int minDifference(int arr[], int n)  
	{ 
	    // Your code goes here
	    int sum=0;
        //int n=nums.size();
        for(int i=0;i<n;i++)
            sum+=arr[i];
       vector<vector<int>> dp(n,vector<int>(sum+1,0));
       for(int i=0;i<n;i++) 
        {
            dp[i][0]=true;
            
        }
        if(arr[0]<=sum)
            dp[0][arr[0]]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                int nottake=dp[i-1][j];
                int take=0;
                if(arr[i]<=j)
                    take=dp[i-1][j-arr[i]];
                
                dp[i][j]=take or nottake;
                
            }
        }
        int mn=INT_MAX;
        for(int i=0;i<=sum;i++)
        {
            if(dp[n-1][i])
            {
                int sum2=sum-i;
                mn=min(mn,abs(sum2-i));
                
            }
        }
        return mn;
        
	} 
