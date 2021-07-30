#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll int power(ll int x, ll int y) {
   ll int i,power=1;
   if(y == 0)
   return 1;
   for(ll i=1;i<=y;i++)
   power=power*x;
   return power;
}

int main()
{
	long long int t;
	cin>>t;
	while(t--)
{
	long long int n,k;
	cin>>n>>k;
	long long int maxsum=(power(2,k-1)*(n-1)%(1000000007)+ power( 2 , k-2 )%(1000000007) ) %(1000000007);
	cout<<maxsum<<endl;

	
	
}
	
	return 0;
}