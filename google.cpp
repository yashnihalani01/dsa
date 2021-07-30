#include <bits/stdc++.h>
using namespace std;

int t [1000001][1000001]={0};

int findans(int arr[], int n , int b)
{  if(n==0 || b<=0)
{
    return 0;
}
if(t[n-1][b]!=-1)
{
    return t[n-1][b];
}
int op1=0,op2=0;
if(b>=arr[n-1])
{
   op1 = 1 + findans(arr,n-1,b-arr[n-1]);
}
   op2 = findans(arr,n-1,b);
   
    return t[n-1][b]=max(op1,op2);
    
}
 int main()
 {
     int p;
     cin>>p;
     for(int x=1;x<=p;x++)
     {
         int n;
         cin>>n;
         int b;
         cin>>b;
         int arr[n];
         memset(t,-1,sizeof t);
         for(int i=0;i<n;i++)
         {
             cin>>arr[i];
         }
         
     cout<<"Case #"<<x<<": "<<findans(arr,n ,b)<<endl;
     
     memset(t,-1,sizeof(t));
     }
     return 0;
 }