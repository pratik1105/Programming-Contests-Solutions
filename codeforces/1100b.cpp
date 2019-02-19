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

int dif[N];
set<int> nums;
int cnt[N];
int ans[N];
int main(){
  fast;
  int n,m;
  cin>>n>>m;
  fill(ans,0);
  fill(cnt,0);
  nums.clear();

  for(int i=1;i<=m;i++)
  cin>>dif[i];

  for(int i=1;i<=m;i++)
  {
  	nums.insert(dif[i]);
  	cnt[dif[i]]++;
  	if(nums.size()==n)
  	{
  		ans[i]=1;
  		nums.clear();
  		for(int j=1;j<=n;j++)
  		{
  			if(cnt[j]>=2)
  			{
  				cnt[j]--;
  				nums.insert(j);
  			}
  			else
  			cnt[j]=0;
  	  	}

  	}
  }

  for(int i=1;i<=m;i++)
  cout<<ans[i];
  cout<<endl;	
  return 0;
}