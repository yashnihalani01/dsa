#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int bfs(vector < vector <int> > graph , int n)
{
    queue <int> q;
    q.push(0);
    bool *visited = new bool [n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    visited[0]=true;
    int dist [n] ;
    for(int i=0; i<n;i++)
    {
        dist[i]=0;
    }
    dist [0]=0;
    while(!q.empty())
    {
        int parent=q.front();
        q.pop();
        for(int i:graph[parent])
        {   if(!visited[i])
           { dist[i]=dist[parent] + 1;
            q.push(i);
            visited[i]=true;
           }
        }
    }
    int ans = dist[n-1];
    delete visited;
   return ans;
}
int main ()
{
    int t ;
    cin>>t;
    while(t--)
    {
        int n, l, s;
        cin>>n>>l>>s;
        vector < vector <int> > vec(n);
        int ladder[n]={0};
        while(l--)
        {
         int x, y;
         cin>>x>>y;
         ladder[x-1]=y-x;
        }
        int snake[n]={0};
        while(s--)
        {
            int x,y;
            cin>>x>>y;
            snake[y-1]=y-x;
        }
      for(int i=0;i<n;i++)
      {
          for(int dice=1;dice<=6;dice++)
          {
              vec[i].push_back(i+dice+ladder[i+dice]-snake[i+dice]);
          }
      }
      int ans = bfs(vec, n);
      cout<<ans<<endl;
    
    }
}