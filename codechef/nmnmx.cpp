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

ll arr[5010];
ll nck[5010][5010];

ll modpow(ll num,ll p)
{
	if(p==0 or num==1)
		return 1;

	if(p==1)
		return num;

	ll temp = modpow(num,p/2);
	temp = (temp*temp)%mod;
	while(temp<0)
		temp+=mod;
	
	if(p%2)
	{
		temp=(temp*num)%mod;
		while(temp<0)
			temp+=mod;
	}

	return temp;
}


int main(){
  fast;
  int t;
  cin>>t;
  
  fill(nck,0);

  for(int i=0;i<=5002;i++)
  	nck[i][0]=1;

  for(int i=1;i<=5002;i++)
  {
  	for(int j=1;j<=i;j++)
  	{
  		nck[i][j]=(nck[i-1][j]+nck[i-1][j-1])%(mod-1);
  		if(nck[i][j]<0)
  			nck[i][j]+=(mod-1);
  	}
  }

  while(t--)
  {
  	int n,k;
  	cin>>n>>k;
  	for(int i=1;i<=n;i++)
  		cin>>arr[i];

  	sort(arr+1,arr+n+1);

  	ll prod = 1;
  	ll temp = 0;
  	for(int i=1;i<=n;i++)
  	{
  		temp = nck[n-1][k-1];
  		
  		if(i>=k)
  		temp -= nck[i-1][k-1];

  		if((n-i)>=(k-1))
  		temp -= nck[n-i][k-1];	

  		while(temp<0)
  			temp+=(mod-1);

  		temp = modpow(arr[i],temp);
  		prod = (prod*temp)%mod;
  		while(prod<0)
  			prod+=mod;
  	}

  	cout<<prod<<endl;
  }
  return 0;
}