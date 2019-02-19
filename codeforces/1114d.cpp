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
const int N = 5e3+10; 

int c[N];
int dp[2][N][N];
int main(){
  fast;
  int n;
  cin>>n;

  for(int i=1;i<=n;i++)
  cin>>c[i];
  
  for(int i=1;i<=n;i++)
  dp[0][i][i]=dp[1][i][i]=0;

  for(int sz=2;sz<=n;sz++)
  {
  	for(int i=1;i<=n-sz+1;i++)
  	{
  		dp[0][i][i+sz-1]=min((c[i]!=c[i+sz-1])+dp[1][i+1][i+sz-1],(c[i]!=c[i+1])+dp[0][i+1][i+sz-1]);
  		dp[1][i][i+sz-1]=min((c[i]!=c[i+sz-1])+dp[0][i][i+sz-2], (c[i+sz-1]!=c[i+sz-2])+dp[1][i][i+sz-2]);
  	}	
  }

  cout<<min(dp[0][1][n],dp[1][1][n])<<endl;
  return 0;
}