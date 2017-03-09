FOR(j,2,m)
    {
      FOR(i,1,j-1)
      dp[i][j]=inf;

      FOR(i,j,n-j-b[j]+2)
      {
        if(j%2==0)
        {
          int left=max((ll)1,i+1+b[j]-b[j-1]);
          int right=i-1;
          ll maxi=-inf;
          FOR(k,left,right)
          {
            if(dp[k][j-1]!=inf)
            maxi=max(maxi,dp[k][j-1]);
          }
          ll val=sums[i+b[j]-1]-sums[i-1];
          if(maxi==-inf)
          dp[i][j]=inf;
          else
          dp[i][j]=maxi-val;
          cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
        else
        {
          int left=max((ll)1,i+1+b[j]-b[j-1]);
          int right=i-1;
          ll mini=inf;
          FOR(k,left,right)
          {
            if(dp[k][j-1]!=inf)
            mini=min(mini,dp[k][j-1]);
          }
          ll val=sums[i+b[j]-1]-sums[i-1];
          if(mini==inf)
          dp[i][j]=inf;
          else
          dp[i][j]=mini+val;
          cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
      }

      FOR(i,n-j-b[j]+3,n)
      dp[i][j]=inf;

    }

    if(m%2)
    {
      ll maxi=-inf;
      FOR(i,1,m)
      {
        if(dp[i][m]!=inf)
        maxi=max(maxi,dp[i][m]);
      }
      cout<<maxi<<endl;
    }
    else
    {
      ll mini=inf;
      FOR(i,1,m)
      {
        if(dp[i][m]!=inf)
        mini=min(mini,dp[i][m]);
      }
      cout<<mini<<endl;
    }