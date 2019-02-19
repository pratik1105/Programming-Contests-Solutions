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
  cin>>n;

  if(n==1)
  {
  	cout<<2<<endl;
  	return 0;
  }
  if(n==2)
  {
  	cout<<3<<endl;
  	return 0;
  }

  
  ll inc=2;	
  ll cur=2;
  ll ans=3;

  while(true)
  {
  	if(cur>=n)
  	{
  		cout<<ans<<endl;
  		return 0;
  	}
  	ans++;	
  	cur=cur+inc;
  	if(cur>=n)
  	{
  		cout<<ans<<endl;
  		return 0;
  	}
  	ans++;
  	cur=cur+inc;
  	inc++;
  }	
  return 0;
}