#include <bits/stdc++.h >
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {   int c;
        cin>>c;
        int h=c;
        int bits=0;
        while(h>0)
        {   
            bits++;
            h=h/2;
        }
        cout<<bits<<endl;

    }
}