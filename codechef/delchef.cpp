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

int a[110];
int d[110];

int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	int n;
  	cin>>n;
  	for(int i=1;i<=n;i++)
  	cin>>a[i];
  	for(int i=1;i<=n;i++)
  	cin>>d[i];

  	int ans=-1;

  	if(a[2]+a[n]<d[1])
  	ans=max(ans,d[1]);
  	if(a[1]+a[n-1]<d[n])
  	ans=max(ans,d[n]);

  	for(int i=2;i<n;i++)
  	{
  		if(a[i-1]+a[i+1]<d[i])
  		ans=max(ans,d[i]);
  	}
  	cout<<ans<<endl;
  }
  return 0;
}