#include<bits/stdc++.h>
#define ll  long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pi 3.1415926535
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define zer(x) memset(x,0,sizeof x)
#define pii pair<ll,ll>
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
int main()
{	
	ll t;
	cin>>t;
	while(t--)
	{
		ll i,j,k,l,m,n;
		cin>>n>>k;
		vector<ll>arr(n);
		for(i=0;i<n;i++)
        cin>>arr[i];
		ll ans=0;
		
		vector<ll>brr=arr;
		sort(all(brr));
		{
			ll inx1=n+1,inx2=0;
			
			for(i=1;i<=n;i++)
			{
				if(arr[i-1]!=i)
				{
					inx1=i;break;
				}
			}
			
			for(i=n;i>=1;i--)
			{
				if(arr[i-1]!=i)
				{
					inx2=i;break;
				}
			}
			if(inx2>=inx1)
			{
				ll diff=(inx2-inx1+1);
				if(diff<=k)
				{
					ans=1;
				}
				else
				{
					ll rem=diff%k;
					ll cnt=0;map<ll,ll>mp;
					for(i=inx1;i<inx1+k;i++)
					{
						if(arr[i-1]>=inx1&&arr[i-1]<=inx1+rem-1)
						{
							if(!mp[arr[i-1]])mp[arr[i-1]]=1,cnt++;
						}
					}
					if(cnt>=rem)ans=2;
					else
					{
						cnt=0;map<ll,ll>mp2;
						for(i=inx2;i>inx2-k;i--)
						{
							if(arr[i-1]>inx2-rem&&arr[i-1]<=inx2)
							{
								if(!mp2[arr[i-1]])mp2[arr[i-1]]=1,cnt++;
							}
						}
						if(cnt>=rem)ans=2;else ans=3;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
