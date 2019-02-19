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
const int N = 1e5+10; 

string s;

int main(){
  fast;
  int n;
  cin>>n;
  cin>>s;

  ll k1=0;
  ll k2=0;

  for(int i=0;i<n;i++)
  if(s[i]==s[0])
  k1++;
  else
  break;

  for(int i=n-1;i>=0;i--)
  if(s[i]==s[n-1])
  k2++;
  else
  break;
	
  ll ans = k1+k2+1;
  if(s[0]==s[n-1])
  ans+= k1*k2;

  ans%=mod;
  if(ans<0)
  	ans+=mod;

  cout<<ans<<endl;
  return 0;
}