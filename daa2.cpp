#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n , m ;
    cin>>n>>m;
   vector <vector < int> > vec(n , vector <int> (m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>vec[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        sort(vec[i].begin(),vec[i].end());
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i>j)
            {
                swap(vec[i][j],vec[j][i]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        sort(vec[i].begin(),vec[i].end());
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i>j)
            {
                swap(vec[i][j],vec[j][i]);
            }
        }
    }
     for(int i=0;i<n;i++)
    {
        sort(vec[i].begin(),vec[i].end());
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i>j)
            {
                swap(vec[i][j],vec[j][i]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<vec[i][j]<<" ";
        }
    }

    return 0;
}