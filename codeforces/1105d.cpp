#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e3+10; 

queue<ii> leaves[15];
queue<pair<ii,int> > temp;
int arr[N][N];
int s[15];
int ans[15];
int n,m,p;

void bfs(int src)
{	
	while(temp.empty()==false)
	temp.pop();

	while(leaves[src].empty()==false)
	{
		int x = leaves[src].front().F;
		int y = leaves[src].front().S;
		leaves[src].pop();
		temp.push(mp(mp(x,y),s[src]));
	}

	while(temp.empty()==false)
	{
		int x = temp.front().F.F;
		int y = temp.front().F.S;
		int moves = temp.front().S;
		temp.pop();

		//cout<<x<<" "<<y<<" "<<" belongs to "<<src<<endl;
		if(moves==0)
		{
			leaves[src].push(mp(x,y));
			continue;
		}

		if(x+1<=n and y<=m and arr[x+1][y]==0)
		{
			arr[x+1][y]=src;
			temp.push(mp(mp(x+1,y),moves-1));
		}
		if(x-1>=1 and y<=m and arr[x-1][y]==0)
		{
			arr[x-1][y]=src;
			temp.push(mp(mp(x-1,y),moves-1));
		}
		if(x<=n and y+1<=m and arr[x][y+1]==0)
		{
			arr[x][y+1]=src;
			temp.push(mp(mp(x,y+1),moves-1));
		}
		if(x<=n and y-1>=1 and arr[x][y-1]==0)
		{
			arr[x][y-1]=src;
			temp.push(mp(mp(x,y-1),moves-1));
		}

	}
}

int main(){
  fast;
  
  
  cin>>n>>m>>p;

  for(int i=1;i<=p;i++)
  {
  	cin>>s[i];
  	while(leaves[i].empty()==false)
  	leaves[i].pop();
  }
  
  fill(ans,0);	
  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
  	char c;
  	cin>>c;

  	if(c=='.')
  	arr[i][j]=0;
  	else if(c=='#')
  	arr[i][j]=-1;
  	else
  	{
  		arr[i][j]= c-'0';
  		leaves[arr[i][j]].push(mp(i,j));
  	}
  }
  
  while(true)
  {
  	int cnt=0;
  	for(int i=1;i<=p;i++)
  	cnt+=(leaves[i].empty());

    if(cnt==p)
    break;
    
    for(int i=1;i<=p;i++)
    bfs(i);
    
  }
	
  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
  	if(arr[i][j]>0)
  	ans[arr[i][j]]++;
  }

  for(int i=1;i<=p;i++)
  cout<<ans[i]<<" ";

  return 0;
}