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
ll sv[N];
ll a[N];

ll mini[N];
bool ans=true;
void dfs(int s)
{
	if(sv[s]==-1)
	mini[s]=INF;
	else
	mini[s]=sv[s];

	for(int i=0;i<edges[s].size();i++)
	{
		dfs(edges[s][i]);
		mini[s]=min(mini[s],mini[edges[s][i]]);
	}

	if(mini[s]<sv[s])
	ans=false;
}

void func(int s,int p)
{
	if(sv[s]==-1)
	{
		sv[s]=mini[s];
		if(sv[s]==INF)
		sv[s]=sv[p];	
		a[s]=sv[s]-sv[p];
	}
	else
	{
		a[s]=sv[s]-sv[p];
	}
	for(int i=0;i<edges[s].size();i++)
	func(edges[s][i],s);
}

int main(){
  fast;
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  edges[i].clear();

  for(int i=2;i<=n;i++)
  {
  	int p;
  	cin>>p;
  	edges[p].push_back(i);
  }
  
  sv[0]=0;

  for(int i=1;i<=n;i++)
  {
  	cin>>sv[i];
  }
	
  dfs(1);
  if(!ans)
  {
  	cout<<-1<<endl;
  	return 0;
  }
  
  func(1,0);
  ll sum=0;
  for(int i=1;i<=n;i++)
  sum+=a[i];
  
  cout<<sum<<endl;
  return 0;
}