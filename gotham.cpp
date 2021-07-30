#include <bits/stdc++.h>
using namespace std; 
class graph{
    public:
    map <int , int > m;
    map<int , int> cap;

    public:
    void addedge(int x , int y , int capacity)
    {
        m[x]=y;
        cap[x]=capacity;
    }

    int solve(int city , int drop , vector <int> & parent)
    {
        if(cap[parent[city]]>=drop)
        {
            cap[parent[city]] = cap[parent[city]] - drop;
            return 0;
        }
        int count =0;
        for(int i=parent[city];i<n && drop !=0 ;i++)
        {  if(drop<=cap[i])
        {
            cap[i]=cap[i]-drop;
            parent [city]=i;
        }  
        else{
            count = count + drop- cap[i];
            drop = drop - cap[i];
            cap[i]=0;
        }
        }
         


    }

    

}
int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    graph <int> g;
    int i=0;
    for(int i=0;i<=n-2;i++)
    {
        g.addedge(i,i+1, arr[i]);
    }
      int q;
      cin>>q;
      int ans=0;
      vector <int> parent(n);
      for(int i=0;i<n;i++)
      {
          parent[i]=i;
      }
      while(q--)
      {
          int city,int drop;
          cin>>city>>drop;
         ans += g.solve(city,drop);
      }

      cout<<ans;
}