vector<long long int> l(105,-1);
vector<long long int> dp(105,-1);
vector<vector<long long int>> nck(105,vector<long long int>(105,-1));

long long int choose(long long int n,long long int k)
{
    if(k>n)
    {
        return 0;
    }
    if(n<=1)
    {
        return 1;
    }
    
    if(k==0)
    {
        return 1;
    }
    
    if(n==k)
    {
        return 1;
    }
    
    if(nck[n][k]!=-1)
    {
        return nck[n][k]%1000000007;
    }
    
    long long int ans = (choose(n-1,k)+choose(n-1,k-1))%1000000007;
    nck[n][k] =  ans%1000000007;
    //cout<<ans;
    
    
    return ans%1000000007;
}

long long int getleft(long long int n)
{
    if(n==1)
    {
        return 0;
    }
    long long int h = l[n];
    long long int num = (1<<h)%1000000007;
    long long int last = (n-((1<<h)-1))%1000000007;
    if(last>=num/2)
    {
        return ((1<<h)-1)%1000000007;
    }
    else
    {
        return ((1<<h)-1-(num/2-last))%1000000007;
    }
    
}

long long int number(long long int n)
{
    if(n<=1)
    {
        return 1;
    }
    long long int get = getleft(n);
    if(dp[n]!=-1)
    {
        return dp[n]%1000000007;
    }
    long long int ans = (choose(n-1,get)*number(get)*number(n-get-1))%1000000007;
    dp[n] = ans%1000000007;
    
    return ans%1000000007;
    
}




int Solution::solve(int A) {
    int curr1 = -1;
    int curr2 = 1;
    
    for(int i=1;i<=A;i++)
    {
         if(curr2==i)
         {
             curr1++;
             curr2 = curr2*2;
         }
        l[i] = curr1;
        
    }
    
    return number(A)%1000000007;
    
    //return curr1;
}
