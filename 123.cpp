#include <bits/stdc++.h>
using namespace std;
bool issafe (vector < vector <int> > visited , int arr[100][100] , int i , int j )
{ 
      if(!(i<12 && i>=0 && j>=0 && j<10))
{
 return false;
}
    if(visited[i][j] || !(arr[i][j]))
    {
        return false;
    }
    return true;
}
void findshort(int n , int m , int arr[100][100] ,int cans , int &ans , vector <vector <int> > &visited , int row , int col )
{ if(col==m-1)
{
    if(cans<ans)
    {
        ans = cans;
    }
    return ;
}

int rowmove [] ={1,0,0,-1};
int colmove [] ={0,-1,1,0};
   for(int i=0;i<4;i++)
   {  if(issafe(visited,arr,row+rowmove[i],col+colmove[i]))
   { visited[row+rowmove[i]][col+colmove[i]]=1;
     findshort(n , m , arr , cans+1, ans ,visited,row+rowmove[i],col+colmove[i]);
     visited[row+rowmove[i]][col+colmove[i]]=0; //backtrack
   }
   }
}
void find(int n , int m , int arr[100][100],int cans, int &ans , vector < vector <int> > visited)
{
  
for(int i=0;i<n;i++)
{
    if(arr[i][0]==1)
    {
        findshort(n , m , arr , cans ,ans ,visited, i , 0);
    }
}
return ;
}
int main()
{
    int n , m ;
    n=12;
    m=10;
    int temp[100][100] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };
    int ans= INT_MAX;
    int cans=0;
    int arr[100][100];
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<10;j++)
        {
            arr[i][j]=temp[i][j];
        }
    }
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(temp[i][j]==0)
            {
                if(i-1>=0)
                {
                    arr[i-1][j]=0;
                }
                if(j-1>=0)
                {
                    arr[i][j-1]=0;
                }
                if(i+1<12)
                {
                    arr[i+1][j]=0;
                }
                if(j+1<10)
                {
                    arr[i][j+1]=0;
                }
            }
        }
        
    }
    vector < vector <int> > visited(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            visited[i].push_back(0);
        }
    }
    find(n, m , arr ,cans,ans , visited );
    cout<<ans<<endl;

    return 0;
}