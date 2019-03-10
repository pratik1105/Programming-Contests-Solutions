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
const int N = 5e5+10; 

string s;
string t;
string ans;
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
  
  cin>>s>>t;
  ans="";

  int sOnes=0;
  int sZero=0;
  int tOnes=0;
  int tZero=0;
  for(int i=0;i<s.size();i++)
  {
  	sOnes+=(s[i]=='1');
  	sZero+=(s[i]=='0');
  }

  for(int i=0;i<t.size();i++)
  {
  	tOnes+=(t[i]=='1');
  	tZero+=(t[i]=='0');
  }

  ZAlgorithm(t);
  if(sOnes<tOnes or sZero<tZero)
  {
  	cout<<s<<endl;
  	return 0;
  }

  sOnes-=tOnes;
  sZero-=tZero;

  int maxprefix=0;
  for(int i=1;i<t.size();i++)
  {
  	if(z[i]==t.size()-i)
  	{
  		maxprefix=t.size()-i;
  		break;
  	}
  }

  string temp=t.substr(maxprefix,(int)t.size()-maxprefix);
  tOnes=0;
  tZero=0;
  for(int i=0;i<temp.size();i++)
  {
  	tOnes+=(temp[i]=='1');
  	tZero+=(temp[i]=='0');
  }

  int cnt=0;
  while(sOnes>=tOnes and sZero>=tZero)
  {
  	cnt++;
  	sOnes-=tOnes;
  	sZero-=tZero;
  }

  cout<<t;
  for(int i=0;i<cnt;i++)
  cout<<temp;
  for(int i=0;i<sOnes;i++)
  cout<<1;
  for(int i=0;i<sZero;i++)
  cout<<0;

  
  return 0;
}