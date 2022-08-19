bool comp(string& a,string& b)
{
    return a.size()<b.size();
}

bool compare(string &a,string &b)
    {
        int n1=a.size();
        int n2=b.size();
        
        if(n1-n2!=1)
            return false;
        
        int i=0,j=0;
        
        while(i<n1)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        
        if(i==n1 and j==n2)
            return true;
        return false;
        
        
    }
    int longestStrChain(vector<string>& words) 
    {
        int n=words.size();
        
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),comp);
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(compare(words[i],words[j]) and dp[i]<1+dp[j])
                {
                    dp[i]=1+dp[j];
                }
            }
            ans=max(ans,dp[i]);
        }
        
        
        return ans;
    }
