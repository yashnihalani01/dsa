#include <bits/stdc++.h>
using namespace std;
priority_queue < int , vector <int> , greater <int> > rh;
priority_queue <int> lh;
void balanceheap()
{
    if(lh.size()<rh.size())
    {
        lh.push(rh.top());
        rh.pop();
    }
    else{
        rh.push(lh.top());
        lh.pop();
    }
}
double getmedian ()
{
    if(lh.size()==rh.size())
    {
      return ((lh.top()+rh.top())/2.0 );
    }
    else if(lh.size()>rh.size())
    {
       return lh.top();
    }
    else{
      return rh.top();
    }
}

vector <double> solve (int arr[], int n)
{
    
vector <double> ans;

    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            lh.push(arr[i]);
        }
        else
        {
            if(arr[i]<getmedian())
            {
                 if(lh.size()>rh.size())
                 {
                     balanceheap();
                     lh.push(arr[i]);
                 }
                 else{
                     lh.push(arr[i]);
                 }                
            }
            else if(arr[i]>getmedian())
            {
                 if(lh.size()<rh.size())
                 {
                     balanceheap();
                     rh.push(arr[i]);
                 }
                 else{
                     rh.push(arr[i]);
                 }         

            }
            else if(arr[i]==getmedian())
            {
                if(rh.size()<lh.size())
                {
                    rh.push(arr[i]);
                }
                else{
                    lh.push(arr[i]);
                }
            }
        }
       ans.push_back(getmedian());
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        vector <double> ans = solve (arr,n);
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        lh = priority_queue <int> ();
        rh = priority_queue <int , vector <int> , greater <int> > ();
    }
}