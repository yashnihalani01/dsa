#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x[n];
    int y[n];
    unordered_map <string,int> m;
    
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<n;i++)
    {   int count1=0;
        int count2=0;

        string s=to_string(x[i])<<"_"<<to_string(y[i]);
        for(j=0;j<n;j++)
        {    
            if(x[j]==x[i] && y[j]!=y[i])
            {
                count1++;
            }
        }
        for(j=0;j<n;j++)
        {    
            if(x[j]!=x[i] && y[j]==y[i])
            {
                count2++;
            }
        }

        map[s]=(count1-1)*(count2-1);

    }
    int sum=0;
    for(auto p::m)
    {
      sum = sum + p.second;
    }

    cout<<sum<<endl;
    return 0;
}