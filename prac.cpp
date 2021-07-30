#include <bits/stdc++.h>
using namespace std;
int longestsubarray(int arr[], int n)
{ unordered_map<int ,int> m;
int len=0;
int pre=0;

    for(int i=1;i<n;i++)
    {
       pre = arr[i] + pre;
       if(pre==0)
       {
           len= max(len,i+1);
       }
       else if(m.find(pre)!=m.end())
       {
           len=max(len , i - m[pre]);
       }
       else{
           m[pre]=i;
       }
    }
    return len;

   
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   cout<<longestsubarray(arr,n)<<endl;
}