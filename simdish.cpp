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

string s[5];
map<string,bool> present;
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	present.clear();
  	FOR(i,0,3)
  	{
  		cin>>s[i];
  		present[s[i]]=true;
  	}
  	int cnt=0;
  	FOR(i,0,3)
  	{
  		cin>>s[i];
  		if(present[s[i]])
  			cnt++;
  	}
  	if(cnt>1)
  		cout<<"similar"<<endl;
  	else
  		cout<<"dissimilar"<<endl;
  }
  return 0;
}