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
ll sums[5010];

char arr[5010];
int n;

int main(){
  fast;
  cin>>n;

  for(int i=0;i<n;i++)
  	cin>>arr[i];

  dp[0]=sums[0]=1;
  for(int i=1;i<n;i++)
  {
  	dp[i]=1;
  	sums[i]=sums[i-1]+dp[i];
  }
  
  for(int i=n-2;i>=0;i--)
  {
  	for(int j=0;j<=i;j++)
  	{
  		if(arr[i]=='f')
  		{
  			dp[j]=(sums[j+1]-sums[j])%mod;
  			if(dp[j]<0)
  				dp[j]+=mod;
  		}

  		else
  		{
  			dp[j]=sums[j];
  		}
  	}

  	sums[0]=dp[0];
  	for(int j=1;j<=i;j++)
  	{
  		sums[j]=(sums[j-1]+dp[j])%mod;
  		if(sums[j]<0)
  			sums[j]+=mod;
  	}
  }

  cout<<dp[0]<<endl;
  return 0;
}