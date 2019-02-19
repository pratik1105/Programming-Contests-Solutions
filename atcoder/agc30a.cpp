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
  ll a,b,c;
  cin>>a>>b>>c;

  ll ans=0;
  ans= min(b,c);
  b-=ans;
  c-=ans;
  ans*=2;

  if(c==0)
  {
  	ans+=b;
  	cout<<ans<<endl;
  	return 0;
  }
  else
  {
  	ans+=min(a,c);
  	c-=min(a,c);
  	if(c)
  	ans++;
  	cout<<ans<<endl;
  	return 0;
  }
  return 0;
}