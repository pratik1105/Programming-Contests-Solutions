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
const int N = 5e4+10; 

int arr[N];
ll sum=0;
int main(){
  fast;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
  	cin>>arr[i];
  	sum+=arr[i];
  }

  sort(arr,arr+n);

  int small=arr[0];

  ll mini=0;
  ll temp=0;
  for(int i=1;i<n;i++)
  {
  	for(int j=2;j<=arr[i];j++)
  	{
 		if(arr[i]%j==0)
 		{
 			temp=1LL*small-(arr[i]/j);
 			temp=temp*(j-1);
 			mini=min(mini,temp);
 		}
  	}
  }

  cout<<sum+mini<<endl;
  return 0;
}