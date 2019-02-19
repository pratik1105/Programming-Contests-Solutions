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
const ll mod = 1e9+7;
const int N = 1e5+10; 

int parent[N];
int state[N];
int teeth[N];
int siz[N];
bool damaged[N];
vi edges[N];

void dfs(int s, int p, int st)
{
	state[s]=st;
	for(int i=0;i<sz(edges[s]);i++)
	{
		if(edges[s][i]==p)continue;
		dfs(edges[s][i],s,1-st);
	}
}

int find(int x) { return (parent[x] == x) ? x : parent[x] = find(parent[x]); }
bool connected(int x,int y)
{
	return find(x)==find(y);
}

void join(int x, int y)
{
	edges[x].pb(y);
	edges[y].pb(x);

	int px = find(x);
	int py = find(y);

	if(damaged[px] or damaged[py])
	{	
		damaged[py]=true;
		parent[px]=py;
		damaged[px]=true;
	}

	else
	{
		if(px==py)
		{
			if(state[x]==state[y])
			{
				damaged[px]=true;
			}
		}

		else
		{
			
			if(state[x]==state[y])
			{
				if(siz[px]<siz[py])
				dfs(x,y,1-state[x]);
				else
				dfs(y,x,1-state[y]);
			}
			
			parent[px]=py;
			siz[py]+=siz[px];
		}
	}

}


int main(){
  fast;
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
  	cin>>teeth[i];
  }

  for(int i=1;i<=n;i++)
  {
  	edges[i].clear();
  	parent[i]=i;
  	siz[i]=1;
  	state[i]=0;
  	damaged[i]=false;
  }

  for(int i=0;i<m;i++)
  {
  	int t;
  	cin>>t;
  	if(t==1)
  	{
  		int x,c;
  		cin>>x>>c;
  		teeth[x]=c;
  	}

  	if(t==2)
  	{
  		int x,y;
  		cin>>x>>y;

  		join(x,y);
  	}

  	if(t==3)
  	{
  		int x,y,v;
  		cin>>x>>y>>v;

  		if(connected(x,y) and !damaged[find(y)])
  		{
  			ll num = (1LL*teeth[x])*v;
  			ll den = teeth[y];
  			ll g = __gcd(num,den);
  			num = num/g;
  			den=den/g;
  			
  			if(state[x]==state[y])
  			{
  				cout<<1LL*num<<"/"<<den<<endl;
  			}
  			
  			else
  			{
  				cout<<-1*num<<"/"<<den<<endl;
  			}
  		}

  		else
  			cout<<0<<endl;
  	}
  }

  return 0;
}