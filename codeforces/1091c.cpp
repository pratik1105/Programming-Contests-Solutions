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

vector<int> divs;
vector<ll> ans;
int main(){
  fast;
  
  divs.clear();
  ans.clear();
  int n;
  cin>>n;

  int root = sqrt(n);
  for(int i=1;i<=root+3;i++)
  {
  	if(n%i==0)
  	{
  		divs.pb(i);
  		divs.pb(n/i);
  	}
  }

  for(int i=0;i<divs.size();i++)
  {
  	ll d = 1LL*divs[i];
  	ll k = (n-1)/d;
  	ll num = (2+(k*d))*(k+1);
  	num/=2;
  	ans.push_back(num);
  }

  sort(ans.begin(),ans.end());

  for(int i=0;i<ans.size();i++)
  {
  	if(i==0 or ans[i]!=ans[i-1])
  	cout<<ans[i]<<" ";
  }

  return 0;
}