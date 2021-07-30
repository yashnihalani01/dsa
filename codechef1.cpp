#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define mod 1000000007
template < typename T >
class Graph{
public:
map < T , list <T> > l;
public:
void addedge(T x , T y)
{
    l[x].push_back(y);
    l[y].push_back(x);
}
int bfs(int src , vector <int> &ans , int n)
{
	vector <bool> visited(n);
		for(int i=0;i<n;i++)
		{
			visited [i]=false;
		} 
		queue < int > q;
		q.push(src-1);
		visited[src-1]=true;
		
		for(int i=0;i<n;i++)
		{
			ans.push_back(-1);
		}
		ans[src-1]=0;
		while(!q.empty())
		{
           int temp=q.front();
		   q.pop();

		   for(auto it:graph[temp])
		   {
			   if(!visited[it])
			   {
				   ans[it]=ans[temp]+1;
				   visited[it]=true;
				   q.push(it);
			   }
		   }
		   
		}
		
	}
}

};
int main()
{
		int t;
		cin>>t;
		while(t--)
		{
			Graph <int> g;
			int n,k,a;
			cin>>n>>k>>a;
			
			vector<int> special(k);
			for(int i=0;i<k;i++)
			{
				int inp;
				cin>>inp;
				special.push_back(inp-1);
			}
             int u , v;
			 int c=n;
             while(c--)
			 {
				 cin>>u>>v;
				 addedge(u-1,v-1);
			 }
			 vector <int> dist;

			 vector <int> minus(n);

			 g.bfs(a,dist ,n);
			 map <int , int> distance;
			 for(int i=0;i<special.size();i++)
			 {
                 distance[special[i]] = dist[special[i]];
			 }

			   int ans= INT_MAX;

			   map <int , pair <int , int> > code;
			 for(int i=0 ; i<n ;i++)
			 {    vector <int> vec;
				    g.bfs(i ,vec , n);
                for(int j=0;j<n;j++)
				{ 
					    if(vec[j]<mini)
				{
					for(int h=0;h<k;h++)
					{
						if(special[h]==vec[j])
						{
							flag=1;
							break;
						}
					}
					if(flag==1)
					{
					int temp = (distance[special[j]] - vec[j] );
					if(temp<ans)
					{
						ans = temp;
						code[i]={temp,j};
					}
					}
				}

				}
			 }


			 for(int i=0;i<n;i++)
			 {
				 code[i].first<<" ";
			 }
			 for(int i=0;i<n;i++)
			 {
				 code[i].second<<" ";
			 }
			 cout<<endl;



		}
	
	return 0;
}