#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll dp[101];
bool  solve(vector <ll> & vec , int n , inw w , int i , vector <ll> &ans , int  sum  , int &count)
{   if(count==n-1)
{
    return false;
}
    if(ans.size()==n)
    {
        return true;
    }

    if(sum + vec[i]==w)
    {   count +++;
        int temp=vec[i];
        vec.erase(vec.begin()+i);
        vec.push_back(temp);
        return solve(vec, n , w , i ,  ans , sum );
    }

    vector <ll> help= ans ;
    help.push_back(vec[i]);
    return solve(vec , n , w , i+1, help , sum+vec[i]);
}
int main()
{ ll t;
 cin>>t;
 while(t--)
 {
     ll n,w;
     cin>>n>>w;
     vector <ll> vec(n);
     memset(dp,-1,sizeof(dp));
     for(int i=0;i<n;i++)
     {
         cin>>vec[i];
     }
     vector <ll> ans ;
     if(solve(vec, n , w , 0 ,ans , 0 , 0))
     {
         cout<<"YES"<<endl;
         for(int i=0;i<n;i++)
         {
             cout<<ans[i]<<" ";
         }
         cout<<endl;
     }
     else{
         cout<<"NO"<<endl;
     }
 }
return 0;
}