#include <bits/stdc++.h>
using namespace std;
class Solution {
       public:
    int dp[1001];
public:
    int solve(vector <int> & vec , int i , bool check)
    {
        if(i>=vec.size())
        {
            return 0;
        }
        if(dp[i]!=-1 && i!=vec.size()-1)
        {
            return dp[i];
        }
        if(i==vec.size()-1)
        {
            if(check)
            {
                return 0;
            }
            else
            {
                // cout<<"yash";
                return vec [i];
            }
        }
        else if(i==0)
        {

            return dp[i]=max( vec[i]+solve(vec , i+2, true),solve(vec , i+1 , false) );
        }
        else
        {
            return dp[i]= max(solve(vec,i+1,check),vec[i]+(solve(vec,i+2,check)));
        }
    }
    int rob(vector<int>& vec) {
         bool check ;
        check=false;
        memset(dp , -1 , sizeof(dp));
        int ans =solve(vec , 0  ,check );
        // for(int i=0;i<vec.size();i++)
        // {
        //     cout<<dp[i]<<" ";
        // }
        // cout<<endl;
        return ans ;
    
    
    
}
};
int main()
{
    int n ;
    cin>>n;
    Solution ob;
    vector <int> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
  cout<<ob.rob(vec);
  return 0;

}