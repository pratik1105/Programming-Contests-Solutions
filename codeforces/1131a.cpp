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
  ll w1,w2,h1,h2;
  cin>>w1>>h1>>w2>>h2;

  ll ans=0;
  ans+=(w1+2)*(h1+2);
  ans+=(w2+2)*(h2+2);
  ans-=w1*h1;
  ans-=w2*h2;
  ans-=min(w1,w2)+2;
  ans-=min(w1,w2)+2;

  cout<<ans<<endl;
  return 0;
}