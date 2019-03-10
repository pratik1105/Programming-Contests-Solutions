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

int a[N];
int pos[2][N];
int main(){
  fast;
  int n;
  cin>>n;
 
  fill(pos,0);

  for(int i=1;i<=2*n;i++)
  {
  	cin>>a[i];
  	if(pos[0][a[i]]==0)
  	pos[0][a[i]]=i;
    else
    pos[1][a[i]]=i;
  }


  ll ans=0;
  for(int i=1;i<=n;i++)
  {
  	ans+=min(abs(pos[0][i-1]-pos[0][i])+abs(pos[1][i-1]-pos[1][i]),abs(pos[1][i-1]-pos[0][i])+abs(pos[0][i-1]-pos[1][i]));
  }

  cout<<ans-2<<endl;
  return 0;
}