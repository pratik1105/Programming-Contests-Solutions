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
const int N = 510; 

int dp[N][N];
bool done[N];
ll ans[N];
int order[N];
int main(){
  fast;
  int n;
  cin>>n;
  fill(done,0);

  FOR(i,1,n)
  FOR(j,1,n)
  cin>>dp[i][j];
  
  FOR(i,1,n)
  cin>>order[i];

  NFOR(k,n,1)
  {
     done[order[k]]=true;
     FOR(i,1,n)
     FOR(j,1,n)
     dp[i][j]=min(dp[i][j],dp[i][order[k]]+dp[order[k]][j]);

     ll temp=0;
     FOR(i,1,n)
     FOR(j,1,n)
     if(done[i] and done[j])
     	temp+=dp[i][j];

     ans[k]=temp;
  }
  
  FOR(i,1,n)
  cout<<ans[i]<<" ";

  return 0;
}