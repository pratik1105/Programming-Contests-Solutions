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
  ll n;
  int m;
  cin>>n>>m;

  ll ans=0;
  for(int i=1;i<=m;i++)
  for(int j=1;j<=m;j++)
  {
  	int rem = i*i;
  	rem+=j*j;

  	if(rem%m==0)
  	{
  		ll f=n/m;
  		if(n%m >=i)
  		f++;
  		ll s=n/m;
  		if(n%m >=j)
  		s++;

  		ans+=f*s;
  	}
  }

  cout<<ans<<endl;
  return 0;
}