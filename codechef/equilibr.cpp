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

ll modpow(ll num,ll p)
{
	if(p==0 or num==1)
		return 1;

	if(p==1)
		return num;

	ll temp = modpow(num,p/2);
	temp = (temp*temp)%mod;
	if(temp<0)
		temp+=mod;
	
	if(p%2)
	{
		temp=(temp*num)%mod;
		if(temp<0)
			temp+=mod;
	}

	return temp;
}

int main(){
  fast;
  ll n;
  cin>>n;
  int k;
  cin>>k;

  ll v1 = modpow(2,n-1);
  ll v2 = modpow(v1,mod-2);

  v1 = (v1-n)%mod;
  if(v1<0)
  	v1+=mod;

  ll ans = (v1*v2)%mod;
  if(ans<0)
  	ans+=mod;

  cout<<ans<<endl;
  return 0;
}