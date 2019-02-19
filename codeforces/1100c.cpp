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

double PI = 3.14159265;

int main(){
  fast;
  int n;
  double r;
  cin>>n>>r;

  double theta1=2*PI;
  theta1=theta1/n;
  double theta2= (n-2)*PI;
  theta2=theta2/n;
  theta2=theta2/2;


  double val1= sin(theta1);
  

  double val2 = sin(theta2);
  val2 = 2.0*val2;
  val2 = val2 - val1;

  val1=val1*r;

  cout<<setprecision(20);
  cout<<val1/val2<<endl;
  return 0;
}