#include <bits/stdc++.h>
using namespace std;
// bool fn(const pair &x, const pair &y)
// {
//     if (x.first != y.first) {
//         return x.first < y.first;
//     }
 
//     return (x.second/x.first)<(y.second/y.first);
// }
int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
      int n , k;
      cin>>n>>k;
      vector <int> vec(n);
     for(int i=0;i<n;i++)
     {
         cin>>vec[i];
     }
     int ch=0;
     for(int i=0;i<n;i++)
     {
         if(i==0)
         {  if(i+1<n)
            { if(vec[i]==vec[i+1])
             {
               ch+=2;
             }
             else{
              ch+=1;
             }
            }
         }
         else if(i==n-2)
         {
             if(vec[i]==vec[i+1])
              ch+=2;
              else
              {
                  ch+=1;
              }
            
         }
         else{
             if(vec[i]==vec[i+1])
             {
                 ch+=2;
             }
             else{
                 ch+=1;
             }
            
         }
           cout<<i<<" "<<ch<<endl;
     }
    //  while(k--)
    //  {

    //  }
    // cout<<ch<<endl;
  }
    
    return 0;
}