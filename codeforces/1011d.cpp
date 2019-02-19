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
const int N = 5e5+10; 

ll maxi=1;
ll mini=1;
int main(){
  fast;
  int n;
  cin>>n;

  for(int i=0;i<n;i++)
  {
  	char c;
  	ll x,y;
  	cin>>c;
  	cin>>x>>y;

  	if(c=='+')
  	{
  		mini=max(mini,min(x,y));
  		maxi=max(maxi,max(x,y));
  	}

  	if(c=='?')
  	{
  		string ans = "NO";
  		if(x>=mini and y>=maxi)
  		ans="YES";
  		if(x>=maxi and y>=mini)
  		ans="YES";

  		cout<<ans<<endl;
  	}

  }

  return 0;
}