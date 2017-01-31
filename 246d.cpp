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

int C[N];
set<int> Q[N];
int main(){
  fast;
  int n,m;
 
  cin>>n>>m;
  
  FOR(i,1,N-1)
  Q[i].clear();

  int mini=N;
  FOR(i,1,n)
  {
  	cin>>C[i];
  	mini=min(mini,C[i]);
  }
  	
  

  FOR(i,1,m)
  {
  	int u,v;
  	cin>>u>>v;
  	if(C[u]-C[v])
  	{
  		Q[C[u]].insert(C[v]);
  		Q[C[v]].insert(C[u]);
  	}

  }
  
  int maxi=0;
  int ans=mini;
  FOR(i,1,N-1)
  {
  	//if(i<6)
  	//cout<<i<<" "<<sz(Q[i])<<endl;
     if(sz(Q[i])>maxi)
     {
     	maxi=sz(Q[i]);
     	ans=i;
     }
  }
  
  cout<<ans;
  return 0;
}