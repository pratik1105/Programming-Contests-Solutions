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
const int N = 3e4+10; 

int a[N];
int b[N];

int dst[5010][5010];
int tot[5010][5010];
int can[5010];
int mini[5010];
int ans[5010];
int main(){
  fast;
  int n,m;
  cin>>n>>m;
  
  fill(dst,0);
  fill(can,0);
  fill(tot,0);
  fill(ans,0);

  for(int i=1;i<=m;i++)
  {
  	cin>>a[i]>>b[i];
  	can[a[i]]++;
  }
  
  for(int i=1;i<=n;i++)
  {
  	mini[i]=n;
  	int dist=0;
  	for(int j=i+1;j<=n;j++)
  	{
  		dst[i][j]=dist+1;
  		//cout<<"dist "<<i<<" "<<j<<" "<<dst[i][j]<<endl;
  		dist++;
  	}
  	for(int j=1;j<i;j++)
  	{
  		dst[i][j]=dist+1;
  		//cout<<"dist "<<i<<" "<<j<<" "<<dst[i][j]<<endl;
  		dist++;
  	}

  }

  for(int i=1;i<=m;i++)
  mini[a[i]]=min(mini[a[i]],dst[a[i]][b[i]]);
 

  for(int st=1;st<=n;st++)
  {
  	 for(int i=1;i<=n;i++)
  	 {
  	 	if(can[i]==0)
  	 	{
  	 		tot[st][i]=0;
  	 		continue;
  	 	}
  	 	tot[st][i]=dst[st][i];
  	 	tot[st][i]+=((can[i]-1)*(n));
  	 	tot[st][i]+=mini[i];
  	 	ans[st]=max(ans[st],tot[st][i]);	
  	 } 	
  }		

  for(int i=1;i<=n;i++)
  cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}