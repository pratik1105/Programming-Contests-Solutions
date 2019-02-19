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
const int N = 2e5+10; 

ll b[N];
ll a[N];
int main(){
  fast;
  int n;
  fill(a,0);

  cin >>n;
  for(int i=1;i<=n/2;i++)
  	cin>>b[i];

  ll largest = INF;
  ll smallest = 0;
  for(int i=1;i<=n/2;i++)
  {
  	if(smallest+largest==b[i])
  	{
  		a[i]=smallest;
  		a[n-i+1]=largest;
  	}
  	else if(smallest+largest > b[i])
  	{
  		a[i]=smallest;
  		a[n-i+1]=b[i]-smallest;
  		largest=b[i]-smallest;
  	}

  	else if(smallest+largest < b[i])
  	{
  		a[n-i+1]=largest;
  		a[i]=b[i]-largest;
  		smallest=b[i]-largest;
  	}
  }

  for(int i=1;i<=n;i++)
  	cout<<a[i]<<" ";
  return 0;
}