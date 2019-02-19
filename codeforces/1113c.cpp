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
const int N = 3e5+10; 

int a[N];
int cnt[3000010];
ll ans=0;
int main(){
  fast;
  int n;
  cin>>n;
  fill(cnt,0);

  for(int i=1;i<=n;i++)
  cin>>a[i];
	
  int xorval=0;
  for(int i=1;i<=n;i++)
  {
  	xorval=xorval^a[i];
  	if(i%2)
  	{
  		ans+=1LL*cnt[xorval];
  		cnt[xorval]++;
  				
  	}
  }

  fill(cnt,0);
  cnt[0]=1;
  xorval=0;
  for(int i=1;i<=n;i++)
  {
  	xorval=xorval^a[i];
  	if(i%2==0)
  	{
  		ans+=1LL*cnt[xorval];
  		cnt[xorval]++;
  		
  	}
  }

  cout<<ans<<endl;
  return 0;
}