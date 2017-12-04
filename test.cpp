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
const int N = 8200+10;

vi edges[5010];
ll val[8200][5010];
ll query[200010];
int h[5010];
int hw[5010];
ll whole=0;
int maxh;
void dfs(int s,int p,int r)
{
  val[r][s]=val[r-1][s];
  if(p==0)
    h[s]=0;
  else
    h[s]=1+h[p];

  maxh=max(maxh,h[s]);
  FOR(i,0,sz(edges[s])-1)
  {
    if(edges[s][i]==p)
      continue;

    dfs(edges[s][i],s,r);
    val[r][s]=val[r][s]^val[r][edges[s][i]];
  }
  hw[h[s]]^=val[r][s];
}

void print(int s,int p,int r)
{
  
  cout<<s<<" "<<val[r][s]<<endl;
  whole=whole^val[r][s];
  FOR(i,0,sz(edges[s])-1)
  {
    if(edges[s][i]==p)
      continue;

    print(edges[s][i],s,r);
  }
}

int main(){
  fast;
  int n,q;
  cin>>n>>q;
  fill(h,0);

  FOR(i,1,n-1)
  {
    int u,v;
    cin>>u>>v;
    edges[u+1].pb(v+1);
    edges[v+1].pb(u+1);
  }

  FOR(i,1,n)
  cin>>val[0][i];
  
  /*FOR(i,1,q)
  cin>>query[i];*/

  maxh=0;
  dfs(1,0,1);
  cout<<"round 1"<<endl;
  FOR(j,0,maxh)
  cout<<"Height "<<j<<" "<<hw[j]<<endl;
  
  ll rem=1;
  FOR(i,0,12)
  {
    int v1=(1<<i);
    int v2=(1<<(i+1));
    if(maxh>=v1 and maxh<v2)
    {
      rem=v2;
      break;
    }
  }

  FOR(i,2,rem)
  {
    fill(hw,0);
    dfs(1,0,i);
    whole=0;

    cout<<"round "<<i<<endl;
    //print(1,0,i);
    //cout<<"Rest is "<< (whole ^ val[i][1]) <<endl;
    FOR(j,0,maxh)
    cout<<"Height "<<j<<" "<<hw[j]<<endl;
  }

  
  

  /*FOR(i,1,q)
  {
    query[i]%=rem;
    if(query[i]<0)
      query[i]+=rem;

    cout<<val[query[i]][1]<<endl;
  }*/

  return 0;
}