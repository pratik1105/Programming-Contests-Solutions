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

ll dp[5010];

char arr[5010];
int n;


int main(){
  fast;
  
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>arr[i];

  dp[n-1]=1;
  dp[n]=1;

  for(int i=n-2;i>=0;i--)
  {
    dp[i]=0;

    if(arr[i]=='s')
    dp[i]=dp[i+1];
    
    else
    {
      for(int j=i;j<n;j++)
      {
        if(arr[j]=='s')
        {
          dp[i]=(dp[i]+dp[j+1])%mod;
          if(dp[i]<0)
            dp[i]+=mod;
        }
      }
    }
  }

  cout<<dp[0]<<endl;
  return 0;
}