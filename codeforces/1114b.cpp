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
const int N = 2e5+10; 

ll a[N],b[N];
map<int,int> c;
vector<int> ans;
int main(){
  fast;
  int n,m,k;
  cin>>n>>m>>k;
  
  c.clear();
  ans.clear();
  for(int i=0;i<n;i++)
  {
  	cin>>a[i];
  	b[i]=a[i];
  }
	
  sort(a,a+n);
  reverse(a,a+n);

  int x=m*k;
  ll sum=0;
  for(int i=0;i<x;i++)
  {
  	sum+=a[i];
  	c[a[i]]++;
  }	  
 	
  int cnt=0;	
  for(int i=0;i<n;i++)
  {
  	if(c[b[i]])
  	{
  		cnt++;
  		c[b[i]]--;
  	}
  	if(cnt==m)
  	{
  		ans.push_back(i+1);
  		cnt=0;
  		if(ans.size()==k-1)
  		break;
  	}  	
  }
  cout<<sum<<endl;
  for(int i=0;i<ans.size();i++)
  cout<<ans[i]<<" ";
  return 0;
}