#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
int a[105],dp[10005];
int main()
{
    int t,cs=0;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        for(int i=1;i<=n;i++)
            cin>> a[i];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(a[i]<=j)
                {
                    dp[j]= (dp[j]%mod+(dp[j-a[i]])%mod)%mod;
                }
            }
        }

        printf("Case %d: %d\n",++cs,dp[k]);
    }
}
