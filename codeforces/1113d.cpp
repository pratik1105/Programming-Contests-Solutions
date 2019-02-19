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
const int N = 5e3+10; 

string s;
bool ispalin[N][N];
string t;

bool palin()
{
	int st=0;
	int ed=t.size()-1;
	while(ed>st)
	{
		if(t[st]!=t[ed])
			return false;
		st++;
		ed--;
	}
	return true;
}

int main(){
  fast;
  fill(ispalin,0);

  cin>>s;
  int n=s.size();

  for(int i=0;i<n;i++)
  ispalin[i][i]=true;
  for(int i=0;i<n-1;i++)
  {
  	if(s[i]==s[i+1])
  	ispalin[i][i+1]=true;
    else
    ispalin[i][i+1]=false;
  }
  
  
  for(int len=3;len<=n;len++)
  {
  	for(int i=0;i<=n-len;i++)
  	{
  		if(s[i]==s[i+len-1] and ispalin[i+1][i+len-2]==true)
  		ispalin[i][i+len-1]=true;
  	    else
  	    ispalin[i][i+len-1]=false;
  	}
  }


 
  	int ans=-1;
  	
  	for(int i=1;i<n/2;i++)
    if(s[i]!=s[i-1])
   	ans=0;
  
    if(ans==-1)
    {
    	cout<<"Impossible"<<endl;
    	return 0;
    }

   for(int i=n-1;i>=1;i--)
  	{
  		t=s.substr(i,n-i);
  		t=t+s.substr(0,i);
  		if(palin() and s!=t)
  		{
  			cout<<1<<endl;
  			return 0;
  		}
  	}
  	
  	
  	cout<<2<<endl;
  	return 0;
}