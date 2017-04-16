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
const int N = 1e6+10; 

int sp[N];
ll ans=0;
vi primes;
priority_queue<ll, vector<ll>, greater<ll> > Q;
vi sp2[N];

void sieve()
{
	fill(sp,0);
	primes.pb(2);
	for(int i=2;i<N;i+=2)
		sp[i]=2;

	int root=sqrt(N);
	for(int i=3;i<N;i+=2)
	{
		if(!sp[i])
		{
			sp[i]=i;
			primes.pb(i);

			if(i<=root)
			for(int j=i;(j*i)<N;j+=2)
			if(!sp[j*i])
			sp[j*i]=i;
		}
	}
}

void work(ll prod)
{
	ans+=prod;
	while(!Q.empty())
	{	
		ll val=-Q.top();
		Q.pop();

		//cout<<val<<endl;
		prod=(prod/val)*(val-1);

		if(prod>1)
		ans+=prod;
		
		if(val>2)
		Q.push(-(val-1));
	}
}

int main(){
  fast;
  sieve();
  ll a,b;
  cin>>a>>b; 

  FOR(i,0,sz(primes)-1)
  {
  	ll val=a/primes[i];
  	for(ll j=val-1;(j*primes[i])<=b;j++)
  	{
  		if((j*primes[i])>=a)
  		sp2[(j*primes[i])-a].pb(primes[i]);
  	}	
  }

  for(ll i=a;i<=b;i++)
  {
  	ll val=i;
  	ll prod=1;
  
  	if(sz(sp2[i-a])==0)
  	{
  		Q.push(-2);
  		prod*=2;
  		val=1;
  	}

  	FOR(j,0,sz(sp2[i-a])-1)
  	{
  		int cnt=0;
  		while(val%sp2[i-a][j]==0)
  		{
  			cnt++;
  			val/=sp2[i-a][j];
  		}
  		if(cnt)
  			Q.push(-(1+cnt));
  		prod*=(1+cnt);
  	}

  	if(val>1)
  	{
  		Q.push(-2);
  		prod*=2;
  	}

  	work(prod);
  }

  if(a==1)
  cout<<ans-2;
  else
  cout<<ans;
  
  return 0;
}