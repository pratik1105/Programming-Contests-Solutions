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

vector<int> edges[N];
int sizes[N];

void dfs(int s, int p)
{
	for(int i=0;i<edges[s].size();i++)
	{
		if(edges[s][i]==p)
			continue;
		dfs(edges[s][i],s);
		sizes[s]+=sizes[edges[s][i]];
	}

	if(sizes[s]==0)
		sizes[s]=1;
}

int main(){
  fast;
  int n;
  cin>>n;
  for(int i=0;i<=n;i++)
  	edges[i].clear();

  fill(sizes,0);

  for(int i=2;i<=n;i++)
  {
  	int p;
  	cin>>p;
  	edges[i].push_back(p);
  	edges[p].push_back(i);
  }

  dfs(1,0);
  sort(sizes+1,sizes+n+1);

  for(int i=1;i<=n;i++)
  	cout<<sizes[i]<<" ";

  return 0;
}