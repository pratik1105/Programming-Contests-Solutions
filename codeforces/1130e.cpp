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
  ll k;
  cin>>k;

  ll ans=-1;
  int len=2000;
  ll div = k/1999;
  ll rem = k%1999;

  ll s=len-rem-1;
  ll x=div+s+1;

  cout<<len<<endl;
  for(int i=1;i<=len-2;i++)
  cout<<-1*(s/(len-1))<<" ";
  
  ll done = (s/(len-1))*(len-2);
  rem=s-done;
  cout<<-1*rem<<" ";
  
  cout<<x<<endl;

  return 0;
}