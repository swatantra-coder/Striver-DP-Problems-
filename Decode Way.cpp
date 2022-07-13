int numDecodings(string s) 
    {
        int count=1;
        int n=s.size();
        vector<int> dp(n+1,0);
        /*dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!='0')
                dp[i]+=dp[i+1];
            if(i+1<s.size() and (s[i]=='1' || s[i]=='2' and s[i+1]<='6'))
                dp[i]+=dp[i+2];
        }*/
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(s[i-1]!='0')
                dp[i]+=dp[i-1];
            if((s[i-2]=='1'||s[i-2]=='2' and s[i-1]<='6'))
                dp[i]+=dp[i-2];
        }
       
        return dp[n];
    }
