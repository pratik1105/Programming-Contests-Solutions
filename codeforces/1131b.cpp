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
const int N = 1e4+10; 

ll a[N];
ll b[N];

int main(){
  fast;
  int n;
  cin>>n;

  a[0]=0;
  b[0]=0;

  ll ans=1;

  for(int i=1;i<=n;i++)
  cin>>a[i]>>b[i];
  
  
  for(int i=1;i<=n;i++)
  {
  	ll maxi=max(a[i-1],b[i-1]);
  	ll mini=min(a[i],b[i]);

  	if(mini>=maxi)
  	ans+=(mini-maxi+1);
  	
  	if(a[i-1]==b[i-1])
  	ans--;
  }	

  cout<<ans<<endl;
  return 0;
}