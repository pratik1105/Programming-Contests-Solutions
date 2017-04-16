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

int arr[N];
int closest[N];
vi nums[10*N];

int check(int val,int pos)
{
	if(pos==0 or !sz(nums[val]))
		return 0;

	int l=0;
	int r=sz(nums[val])-1;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(nums[val][mid]>pos)
			r=mid;
		else
			l=mid;
	}
	if(nums[val][r]<=pos)
		return r+1;
	else if(nums[val][l]<=pos)
		return l+1;

	return 0;
}

int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	FOR(i,1,10*N-1)
  	nums[i].clear();

  	int n,q;
  	int last,now;
  	cin>>n>>q;
  	last=0;
  	arr[0]=0;
  	FOR(i,1,n)
  	{
  		cin>>now;
  		if(now==last)
  		{
  			arr[i]=arr[i-1]+1;
  			nums[arr[i]].pb(i);
  		}
  		else
  		{
  			arr[i]=1;
  			nums[1].pb(i);
  			last=now;
  		}
  	}

  	closest[n]=mod;

  	NFOR(i,n-1,1)
  	{
  		if(arr[i+1]==1)
  		closest[i]=i+1;
  		else
  		closest[i]=closest[i+1];
  	}

  	FOR(i,1,q)
  	{
  		int l,r,k;
  		cin>>l>>r>>k;
  		int ans=check(k,r)-check(k,l-1);

  		if(arr[l]>k and min(closest[l],r+1)-l>=k)
  		ans++;
  		
  		if(arr[l]<=k and arr[min(closest[l]-1,r)]>=k and min(closest[l],r+1)-l<k)
  		ans--;

  		cout<<max(ans,0)<<endl;
  	}

  }
  return 0;
}