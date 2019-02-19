#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

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

bool special[N];
vector<pair<ll, ii> > edges;
vector<pair<ll, ii> > ret;
vector<ii> edges2[N];
int cnt[N];
int n,m,k;
ll ans=0;

struct union_find {
    vi p; union_find(int n) : p(n+1, -1) { }
    int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
    bool unite(int x, int y) {
        int xp = find(x), yp = find(y);
        if (xp == yp) return false;
        if (p[xp] > p[yp]) swap(xp,yp);
        p[xp] += p[yp], p[yp] = xp;
        return true; }
    int size(int x) { return -p[find(x)]; } };

vector<pair<ll, ii> > mst(int n, vector<pair<ll, ii> > edges) {
    union_find uf(n);
    sort(edges.begin(), edges.end());
    vector<pair<ll, ii> > res;
    for(int i=0;i<edges.size();i++)
        if (uf.find(edges[i].second.first) !=
                uf.find(edges[i].second.second)) {
            res.push_back(edges[i]);
            uf.unite(edges[i].second.first, edges[i].second.second);
        }
    return res;
}

void dfs(int s,int p)
{
	if(special[s])
		cnt[s]=1;

	for(int i=0;i<edges2[s].size();i++)
	{
		if(edges2[s][i].F==p)
			continue;

		dfs(edges2[s][i].F,s);
		if(cnt[edges2[s][i].F]!=k and cnt[edges2[s][i].F]!=0)
		ans=max(ans,edges2[s][i].S);
		cnt[s]+=cnt[edges2[s][i].F];
	}
}

int main(){
  fast;
  cin>>n>>m>>k;
  fill(special,false);
  edges.clear();
  ret.clear();
  fill(cnt,0);

  for(int i=0;i<=n;i++)
  	edges2[i].clear();

  for(int i=1;i<=k;i++)
  {
  	int s;
  	cin>>s;
  	special[s]=true;
  }

  for(int i=1;i<=m;i++)
  {
  	int u,v;
  	ll w;
  	cin>>u>>v>>w;
  	edges.push_back(mp(w,mp(u,v)));
  	edges.push_back(mp(w,mp(v,u)));
  }

  ret = mst(n,edges);
  for(int i=0;i<ret.size();i++)
  {
  	edges2[ret[i].S.F].pb(mp(ret[i].S.S,ret[i].F));
  	edges2[ret[i].S.S].pb(mp(ret[i].S.F,ret[i].F));
  }

  dfs(1,0);
  for(int i=1;i<=k;i++)
  	cout<<ans<<" ";
  return 0;
}