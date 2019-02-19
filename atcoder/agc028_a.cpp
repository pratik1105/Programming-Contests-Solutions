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

int main(){
  fast;
  ll n,m;
  string s;
  string t;
  cin>>n>>m;
  cin>>s;
  cin>>t;


  ll g = __gcd(n,m);
  ll ans = (m*n)/g;

  ll m1 = ans/n;
  ll n1 = ans/m;

  for(ll i=0;i<=n;i++)
  {
  	ll k1 = i*n1;
  	ll k2 = i*m1;

  	if(k1>n-1 or k2>m-1)
  		break;

  	if(s[k1]!=t[k2])
  	{
  		ans=-1;
  		break;
  	}
  }

  cout<<ans<<endl;	
  return 0;
}