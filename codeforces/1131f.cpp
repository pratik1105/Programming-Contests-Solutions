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


int p[N];
int nxt[N];
int last[N];

int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

bool unite(int x, int y) 
{
    int xp = find(x), yp = find(y);
    if (xp == yp) return false;
    if (p[xp] > p[yp]) swap(xp,yp);
  	nxt[yp]=last[xp];
  	last[xp]=last[yp];
    p[xp] += p[yp], p[yp] = xp;
    return true; 
}

int main(){
  fast;
  int n;
  cin>>n;

  for(int i=1;i<=n;i++)
  {
  	p[i]=nxt[i]=-1;
  	last[i]=i;
  }
  

  for(int i=0;i<n-1;i++)
  {
  	int x,y;
  	cin>>x>>y;
  	unite(x,y);
  }

  int a=find(1);
  int st=last[a];

  int cnt=0;
  while(cnt<n)
  {
  	cout<<st<<" ";
  	cnt++;
  	st=nxt[st];
  }


  return 0;
}