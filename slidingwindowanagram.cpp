#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string p;
    cin>>p;
    map <char,int> m;
    
    for(int k=0;k<p.size();k++)
    {
    m[p[k]]++;
    }
    int j=0;
    int i=0;
    int count=m.size();
    int ans=0;

    while(j<s.size())
    {  
      if(m.count(s[j]))
       {
           m[s[j]]--;
       }

       if(m[s[j]]==0)
       {
           count--;
       }

        if(j-i+1<p.size())
       {
           j++;
           continue;
       }
        if(j-i+1==p.size())
       {
           if(count==0)
           {
              ans++;
              m[s[i]]++;
              i++;
              j++;
              count++;
           } 
           else{
               if(m.count(s[i]))
               {
                  m[s[i]]++;
                  i++;
                  j++;
               }
               else
               {
               	i++;
               	j++;
			   }
              
           }
       }

    }
    cout<<ans<<endl;
    return 0;
}