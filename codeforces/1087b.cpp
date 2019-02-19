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
  int n,k;
  cin>>n>>k;
  ll ans;
  for(int i=1;i<=n;i++)
  {
  	if(n%i==0)
  	{
  		int rem=n/i;
  		if(rem<k)
  		{
  			ans=(1LL*i)*k;
  			ans+=rem;
  			break;
  		}
  	}	
  }

  cout<<ans<<endl;
  return 0;
}