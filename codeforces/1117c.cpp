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

ll dir[6][N];
int x11;
int y11;
int x22;
int y22;
char moves[N];
map<char,int> m;
int n1,n2;
int n;

bool check(ll x)
{
	ll k1=x/n;
	ll k2=x%n;

	if(k2<0)
	k2+=n;
	
	ll u1=k1*dir[n1][n]+1LL*dir[n1][k2];
	ll l1=k1*dir[n2][n]+1LL*dir[n2][k2];
	ll u2=k1*dir[1-n1][n]+1LL*dir[1-n1][k2];
	ll l2=k1*dir[5-n2][n]+1LL*dir[5-n2][k2];

	ll uf=u1-u2;
	ll lf=l1-l2;

	uf=abs(x22-uf);
	lf=abs(y22-lf);

	return (x-uf-lf>=0);
}

int main(){
  fast;
  	
  cin>>x11>>y11;
  cin>>x22>>y22;

  x22=x22-x11;
  y22=y22-y11;
  
  m.clear();
  m['R']=0;
  m['L']=1;
  m['U']=2;
  m['D']=3;

  cin>>n;
  for(int i=0;i<4;i++)
  dir[i][0]=0;

  for(int i=1;i<=n;i++)
  {
  	cin>>moves[i];
  	
  	for(int j=0;j<4;j++)
  	dir[j][i]=dir[j][i-1];

    dir[m[moves[i]]][i]++;
  }
  
  if(x22>=0)
  n1=0;
  else
  n1=1;
 
  if(y22>=0)
  n2=2;
  else
  n2=3;

  
  x22=abs(x22);
  y22=abs(y22);

  ll l=1;
  ll r=INF;
  while(r-l>1)
  {
  	ll mid=(l+r)/2;
  	if(check(mid))
  	r=mid;
  	else
  	l=mid;
  }

  if(check(l))
  cout<<l<<endl;
  else if(check(r))
  cout<<r<<endl;
  else
  cout<<-1<<endl;
  return 0;
}