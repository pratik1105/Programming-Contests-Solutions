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
//const int N = 2e5+10; 

#define LOGSZ 18

ll tree[(1<<LOGSZ)+1];
const int N = (1<<LOGSZ);

int p[N];
int lft[N];
int rght[N];

// add v to value at x
void settree(int x, ll v) {
  while(x <= N) {
    tree[x] += v;
    x += (x & -x);
  }
}

// get cumulative sum up to and including x
ll gettree(int x) {
  ll res = 0;
  while(x) {
    res += tree[x];
    x -= (x & -x);
  }
  return res;
}

ll powermod(ll a, ll b, ll m)
{
	ll ret = 1;
	while (b)
	{
		if (b & 1) 
		{
			ret = (ret*a)%m;
			if(ret<0)
				ret+=m;
		}
		a = (a*a)%m;
		if(a<0)
		a+=m;
		b >>= 1;
	}
	return ret;
}

int main(){
  fast;
  
  int n;
  cin>>n;
  fill(tree,0);

  lft[0]=0;

  for(int i=1;i<=n;i++)
  {
  	cin>>p[i];
  	if(p[i]==-1)
  	lft[i]=lft[i-1]+1;
  	else
  	lft[i]=lft[i-1];
  }
  
  ll ans=0;
  //inversions between 2 knowns
  for(int i=1;i<=n;i++)
  {
  	rght[i]=lft[n]-lft[i];
  	if(p[i]!=-1)
  	{
  		ans+=gettree(n)-gettree(p[i]);
  		settree(p[i],1);
  	}
  }	

  ans%=mod;
  if(ans<0)
  ans+=mod;
  
  //cout<<ans<<endl;

  //inversions between 2 unknowns	
  ll facn=1;
  ll facn1=1;
  for(int i=1;i<lft[n];i++)
  {
  	facn1=(facn1*i)%mod;
  	if(facn1<0)
  	facn1+=mod;
  }

  facn=max(1LL,(facn1*lft[n])%mod);
  if(facn<0)
  facn+=mod;

  ll temp = (facn*lft[n])%mod;
  temp=(temp*(lft[n]-1))%mod;
  temp=(temp*((mod+1)/2))%mod;
  temp=(temp*((mod+1)/2))%mod;

  while(temp<0)
  temp+=mod;
  
  ans=(ans*facn)%mod;
  if(ans<0)
  ans+=mod; 	  
  ans=(ans+temp)%mod;
  if(ans<0)
  ans+=mod;
  
  //cout<<ans<<endl;

  //inversions between known and unknown
  temp=0;	
  for(int i=1;i<=n;i++)
  {
  	 if(p[i]!=-1)
  	 {
  	 	temp = (temp + (lft[i]* (n-p[i]-gettree(n)+gettree(p[i])))%mod)%mod;
  	 	temp = (temp + (rght[i]*(p[i]-gettree(p[i])))%mod)%mod;
  	 	if(temp<0)
  	 	temp+=mod;
  	 }
  }

  temp=(temp*facn1)%mod;
  if(temp<0)
  temp+=mod;	
  
  ans = (ans+temp)%mod;
  if(ans<0)
  ans+=mod;
  
  //cout<<ans<<endl;

  ans = (ans*powermod(facn,mod-2,mod))%mod;
  if(ans<0)
  ans+=mod;

  cout<<ans<<endl;
  return 0;
}