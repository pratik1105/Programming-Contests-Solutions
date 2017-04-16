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
const int N = 1e2+10; 
 
bool ball[N][N];
int weight[N][N];
int moves[5][4010];
int sum[N];
int main()
{
  fast;
  int t;
  cin>>t;
 
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    fill(ball,0);
    fill(weight,0);
 
    FOR(i,1,m)
    {
      int x,y,z;
      cin>>x>>y>>z;
      ball[x][y]=1;
      weight[x][y]=z;
    }
 
    int cnt=0;
 
    FOR(i,0,n)
    {
      sum[i]=weight[i][i];
      int maxi=sum[i];
      int hit=i;
      FOR(j,i+1,n)
      {
        sum[j]=sum[j-1]+weight[i][j];
        if(sum[j]>maxi)
        {
          maxi=sum[j];
          hit=j;
        }
      }

      if(maxi>1 and hit>i)
      {
        moves[0][cnt]=i;
        moves[1][cnt]=hit;
        moves[2][cnt]=0;
        moves[3][cnt]=-1;
        moves[4][cnt]=hit-i;
        cnt++;
        FOR(j,i+1,hit)
        ball[i][j]=weight[i][j]=0;
        
        ball[i][i]=1;
        weight[i][i]+=maxi;
      }

      //if(hit==n)
       // continue;

      sum[i]=weight[i][i];
      maxi=sum[i];
      hit=i;

      NFOR(j,i-1,0)
      {
        sum[j]=sum[j+1]+weight[i][j];
        if(sum[j]>maxi)
        {
          maxi=sum[j];
          hit=j;
        }
      }

      if(maxi>1 and hit<i)
      {
        moves[0][cnt]=i;
        moves[1][cnt]=hit;
        moves[2][cnt]=0;
        moves[3][cnt]=1;
        moves[4][cnt]=i-hit;
        cnt++;
        FOR(j,hit,i-1)
        ball[i][j]=weight[i][j]=0;
        
        ball[i][i]=1;
        weight[i][i]+=maxi; 
      }
    }
    
    FOR(j,0,n)
    {
      sum[j]=weight[j][j];
      int maxi=sum[j];
      int hit=j;
      FOR(i,j+1,n)
      {
        sum[i]=sum[i-1]+weight[i][j];
        if(sum[i]>maxi)
        {
          maxi=sum[i];
          hit=i;
        }
      }

      if(maxi>1 and hit>j)
      {
        moves[0][cnt]=hit;
        moves[1][cnt]=j;
        moves[2][cnt]=-1;
        moves[3][cnt]=0;
        moves[4][cnt]=hit-j;
        cnt++;

        FOR(i,j+1,hit)
        ball[i][j]=weight[i][j]=0;
        
        ball[j][j]=1;
        weight[j][j]+=maxi;
      }

      //if(hit==n)
       // continue;

      sum[j]=weight[j][j];
      maxi=sum[j];
      hit=j;

      NFOR(i,j-1,0)
      {
        sum[i]=sum[i+1]+weight[i][j];
        if(sum[i]>maxi)
        {
          maxi=sum[i];
          hit=i;
        }
      }

      if(maxi>1 and hit<j)
      {
        moves[0][cnt]=hit;
        moves[1][cnt]=j;
        moves[2][cnt]=1;
        moves[3][cnt]=0;
        moves[4][cnt]=j-hit;
        cnt++;
        FOR(i,hit,i-1)
        ball[i][j]=weight[i][j]=0;
        
        ball[j][j]=1;
        weight[j][j]+=maxi; 
      }
    }  

    int hit=-1;
    sum[0]=weight[0][0];
    int maxi=sum[0];
    FOR(i,1,n)
    {
        sum[i]=sum[i-1]+weight[i][i];
        if(sum[i]>maxi)
        {
          maxi=sum[i];
          hit=i;
        }
    }
   
    if(hit!=-1)
    {
            if(ball[hit][hit])
            {
              moves[0][cnt]=hit;
              moves[1][cnt]=hit;
              moves[2][cnt]=-1;
              moves[3][cnt]=-1;
              moves[4][cnt]=hit+1;
              cnt++;
            }

            FOR(i,0,hit)
            {
              ball[i][i]=0;
              weight[i][i]=0;
            }
    }

    hit=n+1;
    sum[n]=weight[n][n];
    maxi=sum[n];
    NFOR(i,n-1,0)
    {
        sum[i]=sum[i+1]+weight[i][i];
        if(sum[i]>maxi)
        {
          maxi=sum[i];
          hit=i;
        } 
    }

    if(hit!=(n+1))
    {
            if(ball[hit][hit])
            {
              moves[0][cnt]=hit;
              moves[1][cnt]=hit;
              moves[2][cnt]=1;
              moves[3][cnt]=1;
              moves[4][cnt]=n-hit+1;
              cnt++;
            }

            FOR(i,hit,n)
            ball[i][i]=weight[i][i]=0;
    }

    cout<<cnt<<endl;
    FOR(i,0,cnt-1)
    cout<<moves[0][i]<<" "<<moves[1][i]<<" "<<moves[2][i]<<" "<<moves[3][i]<<" "<<moves[4][i]<<endl;
    
  }
  return 0;
} 