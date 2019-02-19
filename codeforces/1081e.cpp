#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e5+10; 

ll x[N];
vector<pair<ll,ll> > ret[2*N];
ll xmax=2*N-20;
int main(){
  fast;
  int n;
  cin>>n;
  fill(x,0);
  for(int i=1;i<2*N;i++)
  ret[i].clear();

  for(int i=2;i<=n;i+=2)
  cin>>x[i];

  for(int i=1;i<=xmax;i++)
  {
  	ll a=i;
  	for(int j=i+1;j<=xmax;j++)
  	{
  		ll b=j;
  		if(b*b-a*a>xmax)
  		break;
  		ret[b*b-a*a].pb(mp(a,b));
  	}
  }

  ll sum=0;
  for(int i=2;i<=n;i+=2)
  {
  	for(int j=0;j<ret[x[i]].size();j++)
  	{
  		ll a=ret[x[i]][j].F;
  		if(a*a>sum)
  		{
  			x[i-1]=a*a-sum;
  			sum=ret[x[i]][j].S;
  			sum*=sum;
  			break;
  		}
  	}
  	if(x[i-1]==0)
  	{
  		cout<<"No"<<endl;
  		return 0;
  	}
  }

 cout<<"Yes"<<endl;
 for(int i=1;i<=n;i++)
 	cout<<x[i]<<" ";
  	
  return 0;
}