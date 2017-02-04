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
const ll inf = 1e18;
const ll mod = 1e9+7;
const int N = 3e5+10;

ll a[N];
ll b[250];
ll dp[N][250];
ll sums[N];
int main()
{
  fast;
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    FOR(i,1,n)
    cin>>a[i];
    FOR(i,1,m)
    cin>>b[i];

    sums[0]=0;
    FOR(i,1,n)
    sums[i]=sums[i-1]+a[i];

    FOR(i,1,n-b[1]+1)
    dp[i][1]=sums[i+b[1]-1]-sums[i-1];

    FOR(i,n-b[1]+2,n)
    dp[i][1]=inf;

    FOR(j,2,m)
    {
      FOR(i,1,j-1)
      dp[i][j]=inf;

      FOR(i,j,n-j-b[j]+2)
      {
        if(j%2==0)
        {
          int left=max((ll)1,i+1+b[j]-b[j-1]);
          int right=i-1;
          ll maxi=-inf;
          FOR(k,left,right)
          {
            if(dp[k][j-1]!=inf)
            maxi=max(maxi,dp[k][j-1]);
          }
          ll val=sums[i+b[j]-1]-sums[i-1];
          if(maxi==-inf)
          dp[i][j]=inf;
          else
          dp[i][j]=maxi-val;
          cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
        else
        {
          int left=max((ll)1,i+1+b[j]-b[j-1]);
          int right=i-1;
          ll mini=inf;
          FOR(k,left,right)
          {
            if(dp[k][j-1]!=inf)
            mini=min(mini,dp[k][j-1]);
          }
          ll val=sums[i+b[j]-1]-sums[i-1];
          if(mini==inf)
          dp[i][j]=inf;
          else
          dp[i][j]=mini+val;
          cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
      }

      FOR(i,n-j-b[j]+3,n)
      dp[i][j]=inf;

    }

    if(n%2)
    {
      ll maxi=-inf;
      FOR(i,1,m)
      {
        if(dp[i][m]!=inf)
        maxi=max(maxi,dp[i][m]);
      }
      cout<<maxi<<endl;
    }
    else
    {
      ll mini=inf;
      FOR(i,1,m)
      {
        if(dp[i][m]!=inf)
        mini=min(mini,dp[i][m]);
      }
      cout<<mini<<endl;
    }

  }
  return 0;
}
