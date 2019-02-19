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

ll v[1010];
int n;
ll s;

bool check(ll mid)
{
	bool val = true;
	ll tot = 0;
  	for(int i=1;i<=n;i++)
  	{
  		if(v[i]<mid)
  		{
  			val=false;
  			break;
  		}
  		tot += v[i]-mid;
  	}
  	if(tot<s)
  		val=false;

  	return val;
}


int main(){
  fast;
  
  cin>>n>>s;

  for(int i=1;i<=n;i++)
  	cin>>v[i];

  ll l=0;
  ll r=mod-7;

  while(r-l>1)
  {
  	ll mid =(l+r)/2;
  	bool val=check(mid);
  	if(val)
  	l=mid;
  	else
  	r=mid;
  }

  if(check(r))
  	cout<<r<<endl;
  else if(check(l))
  	cout<<l<<endl;
  else
  	cout<<-1<<endl;



  return 0;
}