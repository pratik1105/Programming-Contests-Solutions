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


const int SZ=110;
int actualSize;

ll add(ll a, ll b)
{
	ll ret = a + b;
	while(ret >= mod)
		ret=ret-mod;
	return ret;
}

ll mult(ll a, ll b)
{
	ll ret = a;
	ret *= b;
	if(ret >= mod)
		return ret % mod;
	return ret;
}

struct matrix
{
	ll arr[SZ][SZ];

	void makezeros()
	{
		for(int i=0;i<SZ;i++)
		for(int j=0;j<SZ;j++)
		arr[i][j]=0;
	}

	void base()
	{
		makezeros();
		arr[0][0] = 1;
		arr[0][actualSize-1] = 1;
		for(int i=1;i<actualSize;i++)
		arr[i][i-1] = 1;
	}

	void makeiden()
	{
		makezeros();
		for(int i=0;i<SZ;i++)
		{
			arr[i][i] = 1;
		}
	}

	int answer(){
		ll ans = 0;
		for(int i=0;i<actualSize;i++)
		ans+=arr[0][i];

		return add(ans,0);
	}

	matrix operator + (const matrix &o) const
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
			}
		}
		return res;
	}

	matrix operator * (const matrix &o) const
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = 0;
				for(int k=0;k<SZ;k++)
				{
					res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
				}
			}
		}
		return res;
	}
};

matrix power(matrix a, ll b)
{
	matrix ret;
	ret.makeiden();

	if(b<=0)
	return ret;

	while(b)
	{
		if(b & 1)
		{
			ret = ret * a;
		}
		a = a * a;
		b >>= 1;
	}
	return ret;
}


int main(){
  fast;
  
  ll n;
  cin>>n>>actualSize;

  matrix mat;
  
  mat.base();
  mat = power(mat,n-actualSize+1);
  cout<<mat.answer()<<endl;

  return 0;
}