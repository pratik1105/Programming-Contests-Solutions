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
int main(){
  fast;
  
  int n;
  cin>>n;

  int ans=0;
  int cur=0;
  int maxi=-1;
  
  for(int i=0;i<n;i++)
  cin>>arr[i];
  
  int i=0;
  while(i<n)
  {
  	if(arr[i]>maxi)
  	{
  		ans=0;
  		maxi=arr[i];
  		int j=i;
  		while(j<n and arr[j]==maxi)
  		{
  			//cout<<j<<endl;
  			ans++;
  			j++;
  		}

  		i=j;
  		continue;
  	}
  	else if(arr[i]==maxi)
  	{
  		cur=0;
  		int j=i;
  		while(j<n and arr[j]==maxi)
  		{
  			//cout<<j<<endl;
  			cur++;
  			j++;
  		}

  		ans=max(ans,cur);
  		i=j;
  		continue;
  	}

  	i++;
  }

  cout<<ans<<endl;

  
  return 0;
}