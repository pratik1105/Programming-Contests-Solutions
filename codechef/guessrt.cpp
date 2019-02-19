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

ll n,m,k;
ll num,den,temp;
ll mul(ll a, ll b)
{
	ll ret = a*b;
	ret = ret%mod;
	if(ret<0)
		ret+=mod;

	return ret;
}

ll add(ll a, ll b)
{
	ll ret = a+b;
	ret = ret%mod;
	if(ret<0)
		ret+=mod;

	return ret;
}


ll powmod(ll a, ll b)
{
	if(a==1 or b==0)
	return 1;
	
	ll ret = powmod(a,b/2);

	ret = mul(ret,ret);
	if(b%2)
	ret = mul(ret,a);

	return ret;
}

ll func(ll factor)
{
	num=powmod(n,m);
	num=mul(num,factor);
	den=num;
	temp=powmod(n-1,m);
	temp=mul(temp,max(1LL,factor-1));
	num=add(num,-1LL*temp);
	den=powmod(den,mod-2);
}

int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	
  	cin>>n>>k>>m;

  	
  	if(m%2==0)
  	{
  		m=m/2;
  		func(n+k);
  	}
  	else
  	{
  		m=(m+1)/2;
  		func(1LL);
  	}

  	cout<<mul(num,den)<<endl;
  }
  return 0;
}