#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll n,m;
		cin >> n >> m;
		string a,b;
		cin >> a >> b;
		ll dp[n+1][m+1];
		for(ll i=0;i<m+1;i++)
			dp[0][i] = 0 ;
		for(ll i=0;i<n+1;i++)
			dp[i][0] = 0;
		for(ll i=1;i<n+1;i++)
		{
			for(ll j=1;j<m+1;j++)
			{
				if(a[i-1] == b[j-1])
					dp[i][j] = 1 + dp[i-1][j-1];
				else
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout << dp[n][m] <<endl;
	}
}
