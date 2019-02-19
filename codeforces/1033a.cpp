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
int n;
bool visited[1010][1010];
bool check(int ax, int ay, int bx, int by)
{
	if(ax==bx or ay==by)
		return false;
	if((bx-ax == by-ay) or (bx-ax)==(ay-by))
		return false;

	return true;
}

bool isValid(int ax,int ay)
{
	if(ax>=1 and ax<=n and ay>=1 and ay<=n and visited[ax][ay]==false)
		return true;
	return false;
}

bool bfs(int ax,int ay,int bx,int by, int cx,int cy)
{
	visited[bx][by]=true;
	//cout<<"POS "<<bx<<" "<<by<<endl;
	if(bx==cx and by==cy)
		return true;

	bool val= false;
	
	if(isValid(bx+1,by) and check(ax,ay,bx+1,by))
	val = val or bfs(ax,ay,bx+1,by,cx,cy);

	if(isValid(bx-1,by) and check(ax,ay,bx-1,by))
	val = val or bfs(ax,ay,bx-1,by,cx,cy);
	
	if(isValid(bx,by+1) and check(ax,ay,bx,by+1))
	val = val or bfs(ax,ay,bx,by+1,cx,cy);
	
	if(isValid(bx,by-1) and check(ax,ay,bx,by-1))
	val = val or bfs(ax,ay,bx,by-1,cx,cy);
	
	if(isValid(bx+1,by+1) and check(ax,ay,bx+1,by+1))
	val = val or bfs(ax,ay,bx+1,by+1,cx,cy);
	
	if(isValid(bx+1,by-1) and check(ax,ay,bx+1,by-1))
	val = val or bfs(ax,ay,bx+1,by-1,cx,cy);
	
	if(isValid(bx-1,by-1) and check(ax,ay,bx-1,by-1))
	val = val or bfs(ax,ay,bx-1,by-1,cx,cy);
	
	if(isValid(bx-1,by+1) and check(ax,ay,bx-1,by+1))
	val = val or bfs(ax,ay,bx-1,by+1,cx,cy);

	return val;
}

int main(){
  fast;
  
  fill(visited,0);	
  cin>>n;
  int ax, ay;
  cin>>ax>>ay;
  int bx,by;
  cin>>bx>>by;
  int cx,cy;
  cin>>cx>>cy;

  bool val = bfs(ax,ay,bx,by,cx,cy);

  
  if(val)
  	cout<<"YES"<<endl;
  else
  	cout<<"NO"<<endl;
  return 0;
}