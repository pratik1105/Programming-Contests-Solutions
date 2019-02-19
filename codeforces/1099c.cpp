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
bool check1(int i)
{
	return (s[i]!='?');
}

bool check2(int i)
{
	return (s[i]!='*');
}

int main(){
  fast;
  cin>>s;
  int k;
  cin>>k;

  int f,c,st;
  f=c=st=0;
  
  int n=s.size();
  s=s+'a';

  for(int i=0;i<n;i++)
  {
  	if(check1(i) and check2(i) and check1(i+1) and check2(i+1))
	f++;
	else if(!check1(i))
	c++;
	else if(!check2(i))
	st++;
  }
  

  int mini,maxi;
  mini=f;
  if(st)
  maxi=202;
  else
  maxi=f+c;

  if(k<mini or k>maxi)
  {
  	cout<<"Impossible"<<endl;
  	return 0;
  }	

  string ans="";
  int extra = k-f;

  for(int i=0;i<n;i++)
  {
  	if(check1(i) and check2(i) and check1(i+1) and check2(i+1))
  	ans=ans+s[i];
  	else if(!check1(i) and extra)
  	{
  		ans=ans+s[i-1];
  		extra--;
  	}
  	else if(!check2(i) and extra)
  	{
  		while(extra)
  		{
  			ans=ans+s[i-1];
  			extra--;
  		}
  	}
  }
  
  cout<<ans<<endl;
  return 0;
}