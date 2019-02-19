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

string s;
int freq[30];
vector<int> helper;

int check(int n)
{
	int sum=0;
	int extra=0;
	helper.clear();

	if(26*n < s.size())
	return s.size();
   
	for(int i=0;i<26;i++)
	{
		if(freq[i]>n)		
		extra+=freq[i]-n;
		else
		{
			sum+=freq[i];
			helper.push_back(freq[i]);
		}
	}

	sort(helper.begin(),helper.end());
	reverse(helper.begin(),helper.end());

	int cnt = (sum+extra)/n;
	int cur = 0;
	for(int i=0;i<cnt;i++)
	cur+=helper[i];
	
	return sum+extra-cur;
}

int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	cin>>s;
  	for(int i=0;i<26;i++)
  	freq[i]=0;

  	for(int i=0;i<s.size();i++)
  	freq[s[i]-'A']++;
  	
  	int n=s.size();
  	int root = sqrt(n);
  	int ans = n;

  	for(int i=1;i<=root+5;i++)
  	{
  		if(n%i==0)
  		{
  			ans = min(ans,check(i));
  			ans = min(ans,check(n/i));
  		}
  	}

  	cout<<ans<<endl;

  }

  return 0;
}