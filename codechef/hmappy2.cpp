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
  int t;
  cin>>t;
  while(t--)
  {
  	ll n,k,a,b;
  	cin>>n>>a>>b>>k;

  	ll c = a*b;
  	c = c/__gcd(a,b);

  	if(n/a + n/b - 2*(n/c) >=k)
  	cout<<"Win"<<endl;
 	else
 	cout<<"Lose"<<endl; 
  }
  return 0;
}