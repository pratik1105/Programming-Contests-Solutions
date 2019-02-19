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

ll amb[N];

string s;
ll dp[N][4];

int indexOf(int i)
{
  if(s[i]=='h')return 1;
  if(s[i]=='a')return 2;
  if(s[i]=='r')return 3;
  if(s[i]=='d')return 4;
  return 5;
}

int main(){
  fast;
  int n;
  cin>>n;

  cin>>s;
  s='z'+s;
  for(int i=1;i<=n;i++)
  cin>>amb[i];

  for(int j=0;j<4;j++)
  dp[0][j]=INF;
  dp[0][0]=0;
  
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<4;j++)
    {
      if(indexOf(i)<j || indexOf(i)>j+1)
      dp[i][j]=dp[i-1][j];
      if(indexOf(i)==j)
      dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]);
      if(indexOf(i)==j+1)
      dp[i][j]=dp[i-1][j]+amb[i];
    }
  }

  cout<<min(min(dp[n][0],dp[n][1]),min(dp[n][2],dp[n][3]))<<endl;
  return 0;
}