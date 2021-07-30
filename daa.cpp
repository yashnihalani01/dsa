#include <bits/stdc++.h>
using namespace std;
bool fn(const pair &x, const pair &y)
{
    if (x.first != y.first) {
        return x.first < y.first;
    }
 
    return (x.second/x.first)<(y.second/y.first);
}
int main()
{
    int m , s , n;
    vector <int> vec;
    for(int i=0;i<s;i++)
    {
        int inp;
        cin>>inp;
        vec.push_back(inp);
    }
    vector < pair <int , int> > help;
    for(int i=0;i<n;i++)
    {
        int mx,sub;
        cin>>mx>>sub;
        help.push_back({sub,max});
    }
   
   sort(help.begin(), help.end(),fn);

   for(auto i:help)
   {
       cout<<i.fisrt<<" "<<i.second<<" "<<endl;
   }
    return 0;
}