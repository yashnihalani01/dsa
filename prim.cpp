#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void dfshelper( vector < vector <int > > vec , vector <int> & visited, int src)
{
    visited[src]=1;
    for(int nbr : vec[src])
    {   if(!visited[nbr])
        dfshelper(vec,visited,nbr);
    }
}
int dfs( vector < vector <int> > vec , int n)
{
   vector<int> visited(n);
   for(int j=0;j<n;j++)
   {
       visited[j]=0;
   }
   int count =0;
   for(int i=0;i<vec.size();i++)
   {
     if(!visited[i])
     {   count ++;
         dfshelper(vec, visited ,i);
     }
   }
   return count;
   
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n , m , a , b;
		cin>>n>>m>>a>>b;
		vector < vector <int> > graph(n);
        ll int pls=m;
         ll int ans;
		while(m--)
		{
			int u ,v;
			cin>>u>>v;
			graph[u-1].push_back(v-1);
			graph[v-1].push_back(u-1);
		}
		if(a>b)
		{
           ans =dfs(graph, n);
           ans *=a;
           ans += b*pls;
		}
		else
		{
            ans = a*n;
		}
        cout<<ans<<endl;
	}

}