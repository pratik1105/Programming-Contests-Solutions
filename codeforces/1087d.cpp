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

int deg[N];
int main()
{
  fast;
  fill(deg,0);
  int n,s;
  cin>>n>>s;

  for(int i=1;i<=n-1;i++)
  {
  	int u,v;
  	cin>>u>>v;
  	deg[u]++;
  	deg[v]++;
  }

  int leaves=0;
  for(int i=1;i<=n;i++)
  if(deg[i]==1)
  leaves++;

  double ans = 2.0*s;
  ans = ans/leaves;

  cout<<setprecision(20);
  cout<<ans<<endl;	  	
  return 0;
}