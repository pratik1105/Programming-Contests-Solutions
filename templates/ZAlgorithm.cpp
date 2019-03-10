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


// z[i]=length of longest substring that starts at i
// and is also a prefix of the string.

int z[N];

void ZAlgorithm(const string& s)
{
	int n=s.size();
	int l=0,r=0;
	z[0]=n;

	for(int i=1;i<n;i++)
	{
		z[i]=0;
		if(i>r)
		{
			l=r=i;
			while(r<n and s[r-l] == s[r])
			r++;
			
			z[i]=r-l;
			r--;
		}
		else if(z[i-l] < r-i+1 )
		z[i]=z[i-l];
		else
		{
			l=i;
			while(r<n and s[r-l]==s[r])
			r++;

			z[i]=r-l;
			r--;
		}
	}
}


int main(){
  fast;
  
  return 0;
}