#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll p[2000005],v[2000005];
ll dp[1005][1005], n;
ll solve(ll pos, ll sum)
{
    if(sum>=n) return 0;
    if(pos>=n)  return 1e15;
    if(dp[pos][sum]!=-1) return dp[pos][sum];

    ll ret = p[pos]+solve(pos+1, sum+1+v[pos]);
    ret = min(ret, solve(pos+1, sum));

    return dp[pos][sum] = ret;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {

        memset(dp,-1,sizeof dp);
        cin >> n;
        for(ll i=0;i<n;i++){
            scanf("%lld%lld",&v[i],&p[i]);
        }

        ll ans = solve(0,0);
        printf("%lld\n",ans);


    }
}
