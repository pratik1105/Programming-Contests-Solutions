#include <bits/stdc++.h>
using namespace std;

#define INF 10000000

typedef long long ll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef map<string, int> msi;

#define all(x) x.begin(), x.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define spresent(c,x) ((c).find(x) != (c).end())  // for set,map
#define present(c,x) (find(all(c),x) != (c).end())  // for vector
#define F first
#define S second
#define loop(i,a,b) for(int i=int(a);i<=int(b);++i)
#define nloop(i,a,b) for(int i= int(a);i>=int(b);--i)

int dp[501][501];
int present[501]= {0};
vector<ll> ans;
vi temp;


int main()
{
	int n;
	cin>>n;
	loop(i,1,n)
	{
		loop(j,1,n)
		cin>>dp[i][j];
	}
	
	loop(i,0,n-1)
	{
		int t;
		cin>>t;
		temp.pb(t);
	}
	
	nloop(k,n-1,0)
	{
	  present[temp[k]]=1;
	  loop(i,1,n)
	  loop(j,1,n)
	  {
 	  	 dp[i][j]=min(dp[i][j],dp[i][temp[k]]+dp[temp[k]][j]);
	  }
	  
	  ll Tans=0;
	  loop(i,1,n)
	  loop(j,1,n)
	  {
	  	if(present[i] && present[j])
	  	Tans+=dp[i][j];
	  }
	  
	  ans.pb(Tans);
    }
    
    nloop(k,n-1,0)
    {
    	cout<<ans[k]<<" ";
	}
	
	return 0;
}
