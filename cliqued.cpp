#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,int> ii;
typedef pair<int,ll> II;
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

vector<ii> edges[N];
ll dist[N];
//This code for Dijkstra is taken from Stanford's ACM Notebook.
void dijkstra(int s)
{
	priority_queue<ii, vector<ii>, greater<ii> > Q;
	while(!Q.empty())
		Q.pop();

	Q.push(make_pair(0, s));
	dist[s] = 0;
	while (!Q.empty()) {
		ii p = Q.top();
		Q.pop();

		int here = p.second;
		if (dist[here] != p.first) continue;

		for (vector<ii>::iterator it = edges[here].begin(); it != edges[here].end(); it++) {
			if (dist[here] + it->first < dist[it->second]) {
				dist[it->second] = dist[here] + it->first;
				Q.push(make_pair(dist[it->second], it->second));
			}
		}
	}
}

int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	int n,k,m,s;
  	ll x;
  	cin>>n>>k>>x>>m>>s;
  	
  	FOR(i,1,n)
  	{
  		dist[i]=INF;
  		edges[i].clear();
  	}


  	FOR(i,1,m)
  	{
  		int a,b;
  		ll c;
  		cin>>a>>b>>c;
  		edges[a].pb(mp(c,b));
  		edges[b].pb(mp(c,a));
  	}

  	if(s<=k)
  	{
  		FOR(i,1,k)
  		{
  			if(i==s)
  				continue;
  			if(sz(edges[i]))
  			{
  				edges[i].pb(mp(x,s));
  				edges[s].pb(mp(x,i));
  			}
  		}

  		dijkstra(s);
  		FOR(i,1,k)
  		dist[i]=min(x,dist[i]);
  	}
  	else
  	{
  		dijkstra(s);
  		int minv=0;
  		ll mind=INF;
  		FOR(i,1,k)
  		{	
  			if(dist[i]<mind)
  			{
  				mind=dist[i];
  				minv=i;
  			}
  		}

  		FOR(i,1,k)
  		{
  			if(i==minv)
  				continue;
  			if(sz(edges[i]))
  			{
  				edges[i].pb(mp(x,minv));
  				edges[minv].pb(mp(x,i));
  			}
  		}

  		FOR(i,1,n)
  		dist[i]=INF;

  		dijkstra(s);
  		FOR(i,1,k)
  		dist[i]=min(dist[i],mind+x);
  	}

  	FOR(i,1,n)
  	cout<<dist[i]<<" ";
  	cout<<endl;
  }
  return 0;
}