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

ll a[N];
vector<ll> pos;
int n,k,A,B;
int srch(int val)
{
	int l=0;
	int r=pos.size()-1;
	while(r-l>1)
	{
		int mid = (l+r)/2;
		if(pos[mid]>val)
		r=mid;
		else
		l=mid;
	}

	if(pos[r]<=val)
	return r+1;
	if(pos[l]<=val)
	return l+1;
	
	return 0;
}

ll solve(int st,int ed)
{
	if(ed<st)
	return 0;
	
	if(srch(ed)-srch(st-1)==0)
	return 1LL*A;

	if(st==ed)
	{
		int tot=srch(ed)-srch(ed-1);
		if(tot==0)
		return 1LL*A;
		else
		return (1LL*tot)*B;
	}

	int mid =(st+ed)/2;
	int tot = srch(ed)-srch(st-1);
	ll cur;
	if(tot==0)
	cur=1LL*A;
	else
	{
		cur=B*1LL;
		cur=cur*tot;
		cur=cur*(ed-st+1);
	}

	return min(cur,solve(st,mid)+solve(mid+1,ed));
}
int main(){
  fast;
  
  cin>>n>>k>>A>>B;
  
  pos.clear();
  for(int i=1;i<=k;i++)
  {
  	cin>>a[i];
  	pos.push_back(a[i]);
  }
  
  sort(pos.begin(),pos.end());	
  
  int last=1;
  for(int i=1;i<=n;i++)
  last=2*last;
  
  cout<<solve(1,last);

  return 0;
}