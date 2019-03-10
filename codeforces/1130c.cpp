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

char arr[60][60];
bool src[2][60][60];
bool vis[60][60];

bool valid(int r,int c,int n)
{
	//cout<<n<<endl;
	//cout<<r<<" "<<c<<" "<<n<<endl;
	if(r>=1 and r<=n and c>=1 and c<=n and arr[r][c]=='0' and vis[r][c]==false)
	{
		return true;
	}

	return false;
}

void dfs(int idx,int r,int c,int n)
{
	//cout<<n<<endl;
	vis[r][c]=true;
	src[idx][r][c]=true;
	
	if(valid(r+1,c,n))
	dfs(idx,r+1,c,n);

    if(valid(r,c+1,n))
    dfs(idx,r,c+1,n);

    if(valid(r-1,c,n))
    dfs(idx,r-1,c,n);

    if(valid(r,c-1,n))
    dfs(idx,r,c-1,n);

	//cout<<r<<" "<<c<<endl;
}

int main(){
  fast;
  int n;
  cin>>n;

  int r1,c1;
  int r2,c2;

  cin>>r1>>c1;
  cin>>r2>>c2;

  
  
  fill(src,0);
  fill(vis,0);

  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  cin>>arr[i][j];
   
  dfs(0,r1,c1,n);
  fill(vis,0);
  dfs(1,r2,c2,n);
  
  if(src[0][r2][c2])
  {
  	cout<<0<<endl;
  	return 0;
  }

  ll ans=INF;
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  {
  	if(src[0][i][j])
  	{
  		for(int k=1;k<=n;k++)
  		{
  			for(int l=1;l<=n;l++)
  			{
  				if(src[1][k][l])
  				{
  					ll temp;
  					temp=i-k;
  					temp=temp*(i-k);
  					ll temp2;
  					temp2=j-l;
  					temp2=temp2*(j-l);

  					ans=min(ans,temp+temp2);
  				}
  			}
  		}
  	}
  }

  cout<<ans<<endl;
  return 0;
}