#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
      long long  int a , b;
       cin>>a>>b;

       long long int temp=a*b;
       cout<<"YES"<<endl;
      if((temp/a)<=2)
      {
          temp= temp*3;
      }

      int help=temp/a;
      
      long long int x=a;
      long long int y=(a-1)*a;
      long long int z=temp;
      cout<<x<<" "<<y<<" "<<temp<<endl;

    }
    return 0;
}