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

vector<int> primes;
vector<int> semiPrimes;
bool isPrime[210];
bool isSemiPrime[210];

bool semiPrimeChecker(int n)
{
	for(int i=0;i<primes.size();i++)
	{
		if(n != primes[i] and n != primes[i]*primes[i] and n%primes[i]==0 and isPrime[n/primes[i]])
		{
			semiPrimes.pb(n);
			return true;
		}
	}
	return false;
} 

string YesOrNo(int n)
{
	for(int i=0;i<semiPrimes.size();i++)
	{
		if(semiPrimes[i] < n and isSemiPrime[n-semiPrimes[i]])
			return "YES";
	}
	return "NO";
}
	
int main(){
  fast;
  
  int t;
  cin>>t;

  fill(isPrime,1);
  fill(isSemiPrime,0);

  primes.clear();
  semiPrimes.clear();

  for(int i=2;i<210;i++)
  {
  	if(isPrime[i])
  		primes.push_back(i);

  	for(int j=i*i;j<210;j+=i)
  	{
  		isPrime[j]=false;
  	}
  }

  for(int i=2;i<210;i++)
  {
  	isSemiPrime[i]=semiPrimeChecker(i);
  	
  }


  while(t--)
  {
  	 int n;
  	 cin>>n;
  	 cout<<YesOrNo(n)<<endl;
  }

  return 0;
}