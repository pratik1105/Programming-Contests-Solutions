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
const int N = 1e6+10; 

int x[N],y[N],a[N],b[N];
int main(){
  fast;
  int n;
  cin>>n;

  for(int i=0;i<n;i++)
  cin>>x[i]>>y[i]; 	
  
  for(int i=0;i<n;i++)
  cin>>a[i]>>b[i];
  
  sort(x,x+n);
  sort(y,y+n);
  sort(a,a+n);
  sort(b,b+n);

  cout<<x[0]+a[n-1]<<" "<<y[0]+b[n-1]<<endl;
  return 0;
}