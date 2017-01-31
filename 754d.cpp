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
const int N = 3e5+10; 

ll l[N];
ll r[N];
vector<ll> s;
vector<ll> e;
ll dummy[N];
vi ans;
int n,k;
bool check(ll lt,ll rt)
{
	if(lt>rt)
		return false;

	 int count=0;
     FOR(i,1,n)
     {
         if(lt>=l[i] and rt<=r[i])
         count++;

         if(count==k)
         return true;  
     }
     return false;
}

int main(){
  fast;
  
  cin>>n>>k;
  FOR(i,1,n)
  {
     cin>>l[i]>>r[i];
     e.pb(r[i]);
  }
  sort(e.begin(),e.end());
  
  int temp=0;
  int lt=0,rt=n-1;
  FOR(i,1,n)
 {
  //cout<<"h"<<endl;
  lt=temp;
  while(e[lt]<l[i])
  	lt++;
  temp=lt;

  while((rt-lt)>1)
  {
      int mid=(lt+rt)/2;
      if(check(l[i],e[mid]))
      lt=mid;
      else
      rt=mid;
  }

  dummy[i]=0;
  if(check(l[i],e[rt]))
  	dummy[i]=e[rt]-l[i]+1;
  else if(check(l[i],e[lt]))
  	dummy[i]=e[lt]-l[i]+1;

 }
  
  ll maxi=0;
  ll ans1=0,ans2=0;
  FOR(i,1,n)
  {
  	if(dummy[i]>maxi)
  	{
  		maxi=dummy[i];
  		ans1=l[i];
  		ans2=dummy[i]+l[i]-1;
  	}
  }
  
  cout<<maxi<<endl;
  if(maxi==0)
  {
  	FOR(i,1,k) 
  	cout<<i<<" ";
    return 0;
  }

  FOR(i,1,n)
  {
  	if(ans1>=l[i] and ans2<=r[i])
      ans.pb(i); 
  }
  FOR(i,0,k-1)
  cout<<ans[i]<<" ";
  return 0;
}