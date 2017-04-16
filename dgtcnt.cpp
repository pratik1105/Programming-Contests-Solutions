
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

int a[10];
ll ncr[25][25];
ll pows[15][20];
int digits[20];
bool check[10];

void pre()
{
	fill(ncr,0);
	FOR(i,0,20)
	ncr[i][0]=1;

	ncr[1][1]=1;

	FOR(i,2,20)
	FOR(j,1,i)
	ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];

	FOR(i,1,10)
	{
		pows[i][0]=1;
		FOR(j,1,18)
		pows[i][j]=pows[i][j-1]*i;
	}
}

ll func(ll n)
{
	ll ans=0;
	FOR(i,1,1023)
	{
		FOR(j,0,9)
		check[j]=false;

		int cnt=0;
		ll sums=0;
		FOR(j,0,9)
		{
			if(i&(1<<j))
			{
				cnt++;
				check[j]=true;
				sums+=a[j];
			}
		}
		if(sums<=n)
		{
			ll temp=1;
			ll num=n;
			FOR(j,0,9)
			{
				if(check[j])
				{
					temp*=ncr[num][a[j]];
					num-=a[j];
				}
			}
			temp*=pows[10-cnt][n-sums];
			if(cnt%2)
				ans+=temp;
			else
				ans-=temp;
		}
	}
	return ans;
}

ll helper(int pos,bool start)
{
	if(pos==0)
	return func(0);
	

	ll ans=0;
	
	int	lim=digits[pos]-1;
	FOR(i,0,lim)
	{
		if(i==0 and start)
			continue;
		a[i]--;
		//cout<<"setting "<<i<<" at position "<<pos<<endl;
		//cout<<"answer received is "<<func(pos-1)<<endl;
		ans+=func(pos-1);
		a[i]++;
	}
	a[lim+1]--;
	//cout<<"setting "<<lim+1<<" at position "<<pos<<endl;
	ans+=helper(pos-1,false);
	a[lim+1]++;
	return ans;
}

ll ansfor(ll n)
{
	int dig=0;
	ll val=n;
	while(val>0)
	{
		dig++;
		digits[dig]=val%10;
		val/=10;
	}

	ll ans=0;
	ans+=helper(dig,true);
	
	NFOR(k,dig-1,1)
	{
		ans+=func(k);
		a[0]--;
		ans-=func(k-1);
		a[0]++;
	}	
	return ans;
}

int main(){
  fast;
  pre();
  int t;
  cin>>t;
  while(t--)
  {
  	ll l,r;
  	cin>>l>>r;
  	FOR(i,0,9)
  	cin>>a[i];

  	cout<<(r-l+1)-ansfor(r)+ansfor(l-1)<<endl;
  }

  return 0;
}