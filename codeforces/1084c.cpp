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

string s;
int prevs[100010];
int cnta[100010];
ll dp[100010];

int main(){
  fast;
  cin>>s;

  fill(prevs,-1);
  fill(cnta,0);
  fill(dp,0);

  int last =-1;
  int lasta =0;
  int n=s.size();

  for(int i=0;i<n;i++)
  {
  	if(s[i]=='a')
  	{
  		prevs[i]=last;
  		lasta++;
  	}

  	if(s[i]=='b')
  	{
  		prevs[i]=last;
  		cnta[i]=lasta;
  		last=i;
  	}

  	cnta[i]=lasta;
  }

  ll ans=0;
  for(int i=0;i<n;i++)
  {
  	if(s[i]=='a')
  	{
  		if(prevs[i]!=-1)
  		dp[i]=dp[prevs[i]];

  		dp[i]++;

  		dp[i]%=mod;	
  		if(dp[i]<0)
  			dp[i]+=mod;

  		ans=(ans+dp[i])%mod;
  		if(ans<0)
  			ans+=mod;
  	}

  	if(s[i]=='b')
  	{
  		dp[i]=ans;
  	}
  	
  }

  cout<<ans<<endl;

  return 0;
}