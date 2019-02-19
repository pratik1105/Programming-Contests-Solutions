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

int main(){
  fast;
  double tscore=0;
  double tcredit=0;
  double credit, grade;
  cout<<"This is a cpi calculator "<<endl;
  cout<<"Keep entering the course credit followed by the grade equivalent number. When you are done, enter -1 -1."<<endl;
  cin>>credit>>grade;
  
  while( credit!=-1 or grade!=-1)
  {
  	tscore+=grade*credit;
  	tcredit+=credit;
  	cin>>credit>>grade;
  }

  if(tcredit==0)
  	cout<<"No input provided"<<endl;
  else
  	cout<<"Your cpi is "<<tscore/tcredit<<endl;

  cout<<"Total credits "<<tcredit<<endl;
  	return 0;
}