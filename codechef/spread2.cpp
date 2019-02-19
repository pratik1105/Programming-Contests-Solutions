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

ll prefixSums[N];
ll a[N];

int main(){
  fast;
  
  int t;
  cin>>t;
  while(t--)
  {
  	ll n;
  	cin>>n;

  	prefixSums[0]=0;
  	for(int i=1;i<=n;i++)
  	{
  		cin>>a[i];
  		prefixSums[i]=prefixSums[i-1]+a[i];
  	}

  	ll cnt=1;
  	ll ans=n;
  	ll day;
  	for(day=1;day<=n;day++)
  	{
  		cnt=cnt+prefixSums[cnt];
  		if(cnt>=n)
  		{
  			ans = day;
  			break;
  		}
  	}

  	cout<<ans<<endl;
  }

  return 0;
}