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

bool isPrime[1000010];
vector<int> primes;

bool check(ll num)
{
	for(int i=0;i<primes.size();i++)
	{
		if(num==primes[i])
			return true;
		
		if(num%primes[i]==0)
			return false;
	}
	return true;
}

int main(){
  fast;
  int t;
  fill(isPrime,1);
  primes.clear();

  int root = sqrt(2000010);
  for(int i=2;i<=1000009;i++)
  {
  	primes.push_back(i);
  	if(i<root)
  	{
  		for(int j=i*i;j<=1000009;j+=i)
  		{
  			isPrime[j]=false;
  		}
  	}
  }

  cin>>t;
  while(t--)
  {
  	ll a, b;
  	cin>>a>>b;
  	if(a-b==1 and check(a+b))
  		cout<<"YES"<<endl;
  	else
  		cout<<"NO"<<endl;
  }

  return 0;
}