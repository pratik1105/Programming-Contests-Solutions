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


vector<pair<int,int> > pt;
bool done[1010][1010];
void go_from(int x1,int y1, int x2,int y2,int marker)
{
	if(marker==1)
	{
		for(int i=min(x1,x2);i<=max(x2,x1);i++)
		if(!done[i][y1])
		{
			cout<<i<<" "<<y1<<endl;
			done[i][y1]=true;
		}
	}

	if(marker==2)
	{
		for(int i=min(y1,y2);i<=max(y2,y1);i++)
		if(!done[x1][i])
		{
			cout<<x1<<" "<<i<<endl;
			done[x1][i]=true;
		}
	}
}

int main(){
  fast;

  fill(done,0);
  pt.clear();
  pt.push_back(make_pair(-1,-1));
  for(int i=1;i<=3;i++)
  {
  	int x,y;
  	cin>>x>>y;
  	pt.push_back(make_pair(x,y));
  }
  
  sort(pt.begin(),pt.end());

  int ans1 = abs(pt[1].F-pt[2].F)+1+abs(pt[1].S-pt[2].S);
  // /cout<<"ans1 "<<ans1<<endl;
  int ans2 = 1000090;
  for(int i=min(pt[1].S,pt[2].S);i<=max(pt[1].S,pt[2].S);i++)
  {
  	ans2=min(ans2,abs(pt[2].F-pt[3].F)+abs(i-pt[3].S));
  }
  //cout<<"ans2 "<<ans2<<endl;

  int ans3 = abs(pt[3].F-pt[2].F)+1+abs(pt[3].S-pt[2].S);
  //cout<<"ans3 "<<ans3<<endl;
  int ans4 = 1000090;
  for(int i=min(pt[3].S,pt[2].S);i<=max(pt[3].S,pt[2].S);i++)
  {
  	ans4=min(ans4,abs(pt[2].F-pt[1].F)+abs(i-pt[1].S));
  }	  
  //cout<<"ans4 "<<ans4<<endl;
  if(ans1+ans2<=ans3+ans4)
  {
  	cout<<ans1+ans2<<endl;
  	//cout<<pt[1].F<<" "<<pt[1].S<<endl;
  	go_from(pt[1].F,pt[1].S,pt[2].F,pt[1].S,1);
  	go_from(pt[2].F,pt[1].S,pt[2].F,pt[2].S,2);

  	for(int i=min(pt[1].S,pt[2].S);i<=max(pt[1].S,pt[2].S);i++)
  	{
  		if(ans2 == abs(pt[2].F-pt[3].F)+abs(i-pt[3].S))
  		{
  			go_from(pt[2].F,i,pt[3].F,i,1);
  			go_from(pt[3].F,i,pt[3].F,pt[3].S,2);	
  			break;
  		}
  	}

  }
  else
  {
  	cout<<ans3+ans4<<endl;
  	//cout<<pt[3].F<<" "<<pt[3].S<<endl;
  	go_from(pt[3].F,pt[3].S,pt[2].F,pt[3].S,1);
  	go_from(pt[2].F,pt[3].S,pt[2].F,pt[2].S,2);

  	for(int i=min(pt[3].S,pt[2].S);i<=max(pt[3].S,pt[2].S);i++)
  	{
  		if(ans4 == abs(pt[2].F-pt[1].F)+abs(i-pt[1].S))
  		{
  			go_from(pt[2].F,i,pt[1].F,i,1);
  			go_from(pt[1].F,i,pt[1].F,pt[1].S,2);	
  			break;
  		}
  	}
  }

  //cout<<ans<<endl;
  return 0;
}