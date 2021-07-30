#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string ans;
  stack <char> st;
  int oc=0;
    for(int i=0;i<s.size();i++)
    {
            if(oc==0 && s[i]!='(')
    {
        ans=ans+s[i];
    }
         else if(s[i]==')')
        {
            string help;
         while(st.top()!='(')
         { 
             help=help+st.top();
             st.pop();
         }
         st.pop();
         oc--;
         if(oc==0)
         {
             ans= ans + help;
             
         }
         else
         {
             int i=0;
         while(i<help.size())
         {
             st.push(help[i]);
             i++;
         }
        }
        }
        else
        {
            if(s[i]=='(')
             oc++;
           st.push(s[i]);
        }
    }

   
    cout<<ans;
    cout<<endl;
    return 0;
}