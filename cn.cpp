#include <bits/stdc++.h>
using namespace std;
bool find(int i , vector <string> &vec , int a , int b , int c )
{   if(i==vec.size())
{
    if(a==0 && b==0 && c==0)
    {
        return true;
    }
    return false;
}
bool help=false;
    
     for(int k=0;k<vec[i].size();k++)
     {
         if(vec[j][k]=='O')
         {
          help = help ||  find (i+1,vec,a-1,b ,c );
         }
         else if(vec[j][k]=='V')
         {
           help = help ||  find (i+1,vec,a,b-1,c );
         }
         else{
            help = help || find (i+1,vec,a-1,b,c-1 );
         }

    }
    return help;
}
int main() {

	int n;
    cin>>n;
   vector<string>arr;
    for(int i=0;i<n;i++)
    {
       
            string s;
            cin>>s;
            arr.push_back(s);
        
    }
    int q;
    cin>>q;
    map<char,int>mp;
    vector<string>vec;
    while(q--)
    {
        string s;
        cin>>s;
        vec.push_back(s);
      
    }
    for(int i=0;i<n;i++)
    {
        string aa="",bb="",cc="";
        int a,b,c;
        int j=0;
        int k=0;
        for(k=0;arr[i][k]!='-';k++,j++)
        {
            aa+=arr[i][k];
        }
        j++;
        for(k=j;arr[i][k]!='-';k++,j++)
        {
            bb+=arr[i][k];
        }
        
        j++;
        for( k=j;arr[i][k]!='\0';k++,j++)
        {
            cc+=arr[i][k];
        }
        a=stoi(aa);
        b=stoi(bb);
        c=stoi(cc);
        // cout<<a<<b<<c;
       bool key=find(0,vec,a,b,c);
        if(key)
            cout<<"DA"<<endl;
        else cout<<"NE"<<endl;
    }
}