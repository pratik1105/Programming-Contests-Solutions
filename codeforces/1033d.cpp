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

map<ll,int> cnt;
map<ll,int> pp;
map<ll, int> done;
map<ll, ll> pp3;

bool isPrime[1000010];
vector<ll> primes;



int main(){
  fast;
  int n;
  cin>>n;

  cnt.clear();

  for(int i=1;i<=n;i++)
  {
  	ll a;
  	cin>>a;
  	cnt[a]++;
  	done[a]=0;
  }

  ll root = sqrt(2000010);
  for(int i=2;i<=1000009;i++)
  {
  	primes.push_back(i);
  	ll p3 = i;
  	p3 = p3*1LL*i;
  	p3= p3*1LL*i;998244353
  	pp3[p3]=i;

  	if(i<root)
  	{
  		for(int j=i*i;j<=1000009;j+=i)
  		{
  			isPrime[j]=false;
  		}
  	}
  }

  for(map<ll,int>::iterator it = cnt.begin();it != cnt.end(); it++)
  {
  	ll num = it->F;
  	ll mul =it->S;
  	ll root = sqrt(num);
  	ll root2 = sqrt(root);
  	if(root*root ==num and root2*root2 = root)
  	{
  		pp[root2]+=(4*mul);
  		done[num]=1;
  	}
  	else if(root*root ==num)
  	{
  		pp[root]+=(mul*2);
  		done[num]=1;
  	}

  	else if(pp3.count(num)==1)
  	{
  		pp[pp3[num]]+=(3*mul);
  	}

  }

  for(map<ll,int>::iterator it = cnt.begin();it != cnt.end(); it++)
  {

  		ll num = it->F;
  		ll mul = it->S;

  		if(done[num])
  		continue;

  		for(map<ll,int>::iterator it2 = cnt.begin();it2 != cnt.end(); it2++)
  		{
  			if(it==it2)
  				continue;
  			ll num2= it2->F;
  			ll mul2 = it2->S;
  			ll g = __gcd(num,num2);
  			if(g!=1)
  			{
  				pp[g]+=mul+mul2;
  				it->S = it->F/g;
  				it2->S=it2->F/g;
  			}
  		}
  }

  ll ans=1;
  for(map<ll,int>::iterator it = pp.begin(); it!= pp.end();it++)
  {
  	ll num =it->S;
  	ans=(ans*(1+num))%mod;
  	if(ans<0)
  		ans+=mod;
  }

  cout<<ans<<endl;
  return 0;
}