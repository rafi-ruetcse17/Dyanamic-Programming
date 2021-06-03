#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[35][35];
ll nCr(ll n,ll r)
{
    if(n==r)
        return 1;
    if(r==1)
        return n;
    if(dp[n][r]!=-1)
        return dp[n][r];
    dp[n][r]= nCr(n-1,r)+nCr(n-1,r-1);
    return dp[n][r];
}
int main()
{
    int t,cs=0;
    cin >> t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        ll ans=1;
        memset(dp,-1,sizeof(dp));
        if(k>n)
        {
            printf("Case %d: 0\n",++cs);
            continue;
        }
        if(k==0)
        {
            printf("Case %d: 1\n",++cs);
            continue;
        }

        ans*= nCr(n,k);
        for(int i=1;i<=k;i++)
        {
            ans*=n;
            n--;
        }
        printf("Case %d: %lld\n",++cs,ans);
    }
}
