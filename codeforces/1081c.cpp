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
const ll mod = 998244353;
const int N = 1e5+10; 

ll NCR[2010][2010];
int main(){
  fast;
  ll n,m,k;
  cin>>n>>m>>k;

  fill(NCR,0);

  if(k==0)
  {
  	cout<<m<<endl;
  	return 0;
  }
  if(k and m==1)
  {
  	cout<<0<<endl;
  	return 0;
  }

  for(int i=0;i<=n;i++)
  NCR[i][0]=1;
	
  for(int i=1;i<=n-1;i++)
  for(int j=1;j<=i;j++)
  {
  	NCR[i][j]=(NCR[i-1][j-1]+NCR[i-1][j])%mod;
  	if(NCR[i][j]<0)
  		NCR[i][j]+=mod;
  }  

  ll ans=m;
  for(int i=1;i<=k;i++)
  {
  	ans=(ans*(m-1))%mod;
  	if(ans<0)
  		ans+=mod;
  }

  ans=(ans*NCR[n-1][k])%mod;
  if(ans<0)
  	ans+=mod;

  cout<<ans<<endl;

  return 0;
}