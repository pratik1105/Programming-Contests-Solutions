#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 998244353;
const int N = 3e5+10; 

vi edges[N];
int done[N];
int w[N];
ll tempans=1;
int cnt=0;
void dfs(int s, int p , int ways, int pass)
{
	if(done[s]==pass)
		return;
	
	done[s]=pass;
	w[s]=ways;

	if(tempans==0)
		return;
	
	if(ways>1)
	{tempans=tempans*ways;
	while(tempans>=mod)
		tempans-=mod;}

	for(int i=0;i<edges[s].size();i++)
	{
		if(edges[s][i]==p)
			continue;
		if(done[edges[s][i]]==pass and w[edges[s][i]]!=w[s])
			continue;
		if(done[edges[s][i]]==pass and w[edges[s][i]]==w[s])
		{
			tempans=0;
			return;
		}

		if(tempans==0)
			return;
		dfs(edges[s][i],s,3-ways,pass);
		if(tempans==0)
			return;
	}

	return;
}

int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	int n,m;
  	cin>>n>>m;

  	for(int i=0;i<=n;i++)
  	{
  		done[i]=0;
  		w[i]=0;
  		edges[i].clear();
  	}

  	for(int i=1;i<=m;i++)
  	{
  		int u,v;
  		cin>>u>>v;
  		edges[u].pb(v);
  		edges[v].pb(u);
  	}

  	ll ans=1;
  	for(int i=1;i<=n;i++)
  	{
  		if(!done[i])
  		{
  			tempans=1;
  			dfs(i,0,1,1);
  			ll temp=tempans;
  
  			tempans=1;
  			dfs(i,0,2,2);
  			tempans=(temp+tempans)%mod;

  			if(tempans<0)
  			tempans+=mod;

  			ans=(ans*tempans)%mod;
  			if(ans<0)
  				ans+=mod;
  		}
  	}

  	cout<<ans<<endl;
  }

  return 0;
}