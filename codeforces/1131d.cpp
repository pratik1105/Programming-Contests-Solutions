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
#define rep(i,a,b) for(int i = a; i<b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e3+10; 

char arr[N][N];

int p[2010];
int pos[2010];
int find(int x) { 
  return p[x] < 0 ? x : p[x] = find(p[x]); 
}

bool unite(int x, int y) 
{
    int xp = find(x), yp = find(y);
    if (xp == yp) return false;
    if (p[xp] > p[yp]) swap(xp,yp);
    p[xp] += p[yp], p[yp] = xp;
    return true; 
}

int w[2010][2010];

typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;

typedef vector<int> VI;
typedef vector<VI> VVI;

VI order;
bool TopologicalSort (int sum){
  int n=sum;
  VI parents (n+1);
  queue<int> q;
  order.clear();
  
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++)
      if (w[j][i]) parents[i]++;
      if (parents[i] == 0) 
        {
          q.push (i);
        }
  }
  
  while (q.size() > 0){
    int i = q.front();
    
    q.pop();
    order.push_back (i);
    for (int j = 1; j <= n; j++) if (w[i][j]){
      parents[j]--;
      if (parents[j] == 0) 
        {
          q.push (j);
        }
    }
  }
  
  return (order.size() == n);
}

int main(){
  fast;
  int n,m;
  cin>>n>>m;
  
  fill(w,0);
  for(int i=0;i<=n+m;i++)
  p[i]=-1;
  

  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
    cin>>arr[i][j];
  }
  
  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
  	if(arr[i][j]=='=')
  	unite(i,n+j);
  }
  
  for(int i=1;i<=n+m;i++)
  {
    if(p[i]<0)
    p[i]=i;
  }

  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
  	if(arr[i][j]=='<')
  	{
      w[p[i]][p[n+j]]=1;
    }
    if(arr[i][j]=='>')
    {
      w[p[n+j]][p[i]]=1;
    }
  }
  
  if(TopologicalSort(n+m))
  {
    cout<<"Yes"<<endl;
    pos[order[0]]=1;
    for(int i=1;i<order.size();i++)
    {
      pos[order[i]]=1;
      for(int j=i-1;j>=0;j--)
      {
        if(w[p[order[j]]][p[order[i]]])
        {
          pos[order[i]]=max(pos[order[j]]+1,pos[order[i]]);
          break;
        }
      }
    }

    for(int i=1;i<=n;i++)
    cout<<pos[p[i]]<<" ";
    cout<<endl;
    for(int i=n+1;i<=n+m;i++)
    cout<<pos[p[i]]<<" ";
    cout<<endl;
  }
  else
  cout<<"No"<<endl;
  return 0;
}