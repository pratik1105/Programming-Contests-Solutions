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

ll a[N];
ll pref[N];
int main(){
  fast;
  int n,k,m;
  cin>>n>>k>>m;
  for(int i=0;i<n;i++)
  cin>>a[i];
  
  sort(a,a+n);  
  reverse(a,a+n);

  pref[0]=a[0];
  for(int i=1;i<n;i++)
  pref[i]=pref[i-1]+a[i];
  
  double ans=0; 
  for(int i=n-1;i>=0;i--)
  {
    ll sum=pref[i];
    ll rem = m - (n-i)+1;
    if(rem<0)
      continue;
    ll temp = min((1LL*k)*(i+1),rem);

    sum = sum+temp;
    double avg = 1.0*sum;
    avg = avg/(i+1);
    ans=max(ans,avg);
  }

  cout<<setprecision(20);
  cout<<ans<<endl;
  return 0;
}