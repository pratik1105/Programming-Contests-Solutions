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
const int N = 1e5+10; 

char arr[2010][2010];
bool done[2010][2010];
int ans=0;
int x,y;
int n,m;
queue< pair< pair<int,int>, pair<int,int> > >q;

void bfs(int a, int b)
{
	q.push(mp(mp(a,b),mp(0,0)));

	while(!q.empty())
	{
		int sx = q.front().F.F;
		int sy = q.front().F.S;
		int l =  q.front().S.F;
		int r =  q.front().S.S;

		q.pop();

		if(done[sx][sy] or l>x or r>y)
			continue;
		
		done[sx][sy]=true;
		ans++;

		
		if(sx-1>0 and arr[sx-1][sy]!='*' and done[sx-1][sy]==false)
		q.push(mp(mp(sx-1,sy),mp(l,r)));
		if(sx+1<=n and arr[sx+1][sy]!='*' and done[sx+1][sy]==false)
		q.push(mp(mp(sx+1,sy),mp(l,r)));
		if(sy+1<=m and arr[sx][sy+1]!='*' and done[sx][sy+1]==false)
		q.push(mp(mp(sx,sy+1),mp(l,r+1)));
		if(sy-1>0 and arr[sx][sy-1]!='*' and done[sx][sy-1]==false)
		q.push(mp(mp(sx,sy-1),mp(l+1,r)));
	}
}

int main(){
  fast;
  
  cin>>n>>m;

  int r,c;
  cin>>r>>c;

  
  cin>>x>>y;

  while(!q.empty())
  	q.pop();
  fill(done,0);

  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  cin>>arr[i][j];
 
  bfs(r,c);
  cout<<ans<<endl;	
  return 0;
}