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

ll arr[N];

int main(){
  fast;
  int n;
  ll m,k;
  cin>>n>>m>>k;

  for(int i=0;i<n;i++)
  cin>>arr[i];

  sort(arr,arr+n);
  reverse(arr,arr+n);

  ll ans=0;
  if(arr[0]==arr[1])
  {
  	ans=m*arr[0];
  }
  else
  {
  	ll temp = m/(k+1);
  	ll temp2 = k*arr[0]+arr[1];
  	ans= temp*temp2;

    temp = m%(k+1);
    if(temp<0)
    temp+=(k+1);

    ans= ans+ temp*arr[0];
  }

  cout<<ans<<endl;
  return 0;
}