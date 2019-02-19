#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e5+10; 

int n;
ll w[300010];
ll single[300010];
ll ans[300010];
vector<ll> sorter;

vector< pair<int,ll> > edges[300010];

void dfs(int s,int p)
{
	single[s]=w[s];
	ans[s]=w[s];

	
	for(int i=0;i<edges[s].size();i++)
	{
		if(edges[s][i].F==p)
			continue;
		dfs(edges[s][i].F,s);
		if(single[edges[s][i].F]-edges[s][i].S>=0)
		single[s]=max(single[s],single[edges[s][i].F]+w[s]-edges[s][i].S);
	}

	sorter.clear();
	for(int i=0;i<edges[s].size();i++)
	{
		if(edges[s][i].F==p)
			continue;
		if(single[edges[s][i].F]-edges[s][i].S>=0)
		{
			//cout<<"pushing "<<edges[s][i].F<<" for "<<s<<endl;
			sorter.push_back(single[edges[s][i].F]-edges[s][i].S);
		}
	}
	
	ans[s]=max(ans[s],single[s]);

	if(sorter.size()>1)
	{
		//cout<<"here "<<s<<endl;
		sort(sorter.begin(),sorter.end());
		reverse(sorter.begin(),sorter.end());
		ans[s]=max(ans[s],sorter[0]+sorter[1]+w[s]);
	}

	//cout<<s<<" "<<ans[s]<<endl;
	//cout<<s<<" "<<single[s]<<endl;
}

int main(){
  fast;
  
  cin>>n;
  for(int i=1;i<=n;i++)
  cin>>w[i];
  
  fill(ans,0);
  fill(single,0);

  for(int i=0;i<300010;i++)
  	edges[i].clear();

  for(int i=1;i<=n-1;i++)
  {
  	int u,v;
  	ll c;
  	cin>>u>>v>>c;
  	edges[u].pb(mp(v,c));
  	edges[v].pb(mp(u,c));
  }	

  dfs(1,0);

  ll final=0;
  for(int i=1;i<=n;i++)
  final=max(final,ans[i]);
	
  cout<<final<<endl;
  return 0;
}