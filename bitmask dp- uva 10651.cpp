#include<bits/stdc++.h>
using namespace std;
int dp[(1<<12)+10];
int Set(int n, int bit)
{
    return n=n|(1<<bit);
}
int reset(int n,int bit)
{
    return n=n&~(1<<bit);
}
bool check(int n, int bit)
{
    return (bool) (n&(1<<bit));
}
int solve(int mask)
{
    if(dp[mask]!=-1)
        return dp[mask];
    int mn= (1<<15),cnt=0;
    for(int i=0;i<12;i++)
    {
        if(i>=2&&!check(mask,i)&&check(mask,i-1)&&check(mask,i-2))
        {
            int tmp = mask;
            mask = Set(mask,i);
            mask = reset(mask,i-1);
            mask = reset(mask,i-2);
            mn = min(mn,solve(mask));
            mask = tmp;

        }
        if(i<10&&!check(mask,i)&&check(mask,i+1)&&check(mask,i+2))
        {
            mask = Set(mask,i);
            mask = reset(mask,i+1);
            mask = reset(mask,i+2);
            mn = min(mn,solve(mask));
        }
    }
    for(int i=0;i<12;i++)
    {
        if(check(mask,i))
            cnt++;
    }
    return dp[mask] = min(mn,cnt);
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        memset(dp,-1,sizeof dp);
        string s;
        cin >> s;
        int  mask=0;
        for(int j=0;j<12;j++)
        {
            if(s[j]=='o')
              mask= Set(mask,j);
        }

        int ans = solve(mask);
        printf("%d\n",ans);
    }
}

