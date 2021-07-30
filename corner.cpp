#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
  int n ;
  cin>>n;
  int dp[n+1];
  for(int i=0;i<=n;i++)
  {
    dp[i]=10000000;
  }
  
  dp[0]=0;
  for(int i=0;i<=n;i++)
  {
    for(int j=1;j<=9;j++)
    {
      if(i-j>=0)
      {
        dp[i]=min(dp[i],dp[i-j]+1);
      }
    }

  }
  cout<<dp[n]<<endl;
      return 0;
}