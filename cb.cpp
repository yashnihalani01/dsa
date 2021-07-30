#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
   int n ;
   cin>>n;
  map <int, bool > mp;
  for(int i=2;i<=n;i++)
   {
      mp[i]=false;
   }  
    int ans =1;
   for(int i=2;i<=n;i++)
   {
      if(i%2==0)
      {  mp[i]=true;
          continue;
      }
     else 
     {
         if(!mp[i])
         {   ans++;
             for(int j=i+1;j<=n;j++)
             {
                 if(j%3==0)
                 {
                     mp[j]=true;
                 }
             }
         }
     }
   }
   cout<<ans<<endl;  
  }
    
    return 0;
}