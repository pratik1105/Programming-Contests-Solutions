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
const int N = 5e5+10; 

string s,t;
ll dp[N];
int main(){
  fast;
  int n;
  ll k;
  cin>>n>>k;

  cin>>s;
  cin>>t;
  s='1'+s;
  t='1'+t;
  
  dp[0]=1;

  ll possible = 2; //This would be 26 if we had all lowercase letters.
  char highest = 'b'; //This would be 'z' if we had all lowercase letters.
  char lowest = 'a';

  ll ans=0;

  for(int i=1;i<=n;i++)
  {
  	if(dp[i-1]>2)
  	{
  		dp[i]=(dp[i-1]-2)*possible;
  		dp[i-1]=2;
  	}
  	else
  	dp[i]=0;

  	if(dp[i-1]==2)
  	{
  		dp[i]+=highest-s[i]+1;
  		dp[i]+=t[i]-lowest+1;
  	}

  	if(dp[i-1]==1)
  	{
  		dp[i]+=t[i]-s[i]+1;
  	}
  	
  	if(dp[i]>=mod-7)
    dp[i]=mod-7;
    		
  	ans+=min(dp[i],k);
  }

  cout<<ans<<endl;
  return 0;
}