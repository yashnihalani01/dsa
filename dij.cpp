#include <bits/stdc++.h>
using namespace std;
template < typename T >
class Graph{

public:

unordered_map < T , list < pair < T , int > > > m;

public:

void addedge(T u , T v , int dist , bool bidir=true )
{
    m[u].push_back(make_pair(v,dist));
    if(bidir)
    {
        m[v].push_back(make_pair(u,dist));
    }
}

void dijkstra(T src)
{
  unordered_map < T, int > dist;
  set < pair < int , T > > s;
  for(auto j:m)
  {
      dist[j.first]=INT_MAX;
  }
  s.insert(make_pair(0,src));
  dist[src]=0;
while(!s.empty())
{   
   auto help= *(s.begin());
   T node = help.second;
   s.erase(s.begin());

      for(auto childpair:m[node])
      { 
        if(dist[node] + childpair.second < dist[childpair.first])
        {
            auto f= s.find(make_pair(dist[childpair.first] , childpair.first));
            if(f!=s.end())
            {
                s.erase(f);
                
            }
            dist[childpair.first]=dist[node]+childpair.second;
            s.insert(make_pair(dist[childpair.first],childpair.first));
        }
        
      }
  }
  for(auto d:dist)
  {
      if(d.first!=src)
      {
          cout<<d.first<<"->>"<<d.second<<endl;
      }
  }
}

};
int main()
{
    Graph <int> g;

    g.addedge(1,2,1);
    g.addedge(1,3,4);
    g.addedge(2,3,1);
    g.addedge(3,4,2);
    g.addedge(1,3,7);
    g.dijkstra(1);
    return 0;

}