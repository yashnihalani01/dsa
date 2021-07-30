#include<bits/stdc++.h>
#include <string.h>
#include <stdlib.h>
#define M 1000000007
#define ll long long int
#define ul unsigned long long int
//aditya sharotri 
using namespace std;

void answer(int **array, int rowlower, int rowupper, int collower, int colupper)
{   int i,j,k,t;
	i=rowlower;
	while(i<=rowupper){
		j=collower;
		while(j<colupper){
			k=collower;
			while(k<=colupper-j-1){
				if(array[i][k]>array[i][k+1])
				{
				t=array[i][k];
				array[i][k]=array[i][k+1];
				array[i][k+1]=t;	
				}
				k++;
			}
			j++;
		}
		i++;
	}
	
	i=rowlower;
	while(i<=rowupper){
		j=collower;
		while(j<=colupper){
			k=rowlower;
			while(k<=rowupper-i-1){
			if(array[k][j]>array[k+1][j])
				{
					t=array[k][j];
					array[k][j]=array[k+1][j];
					array[k+1][j]=t;
				}
				k++;	
			}
			j++;
		}
		i++;
	}
}
 void apply_sort(int **array, int rowlower, int rowupper, int collower, int colupper)
{   
     int mergerow,mergecol;
	if(rowlower<rowupper || collower<colupper)
	{
		mergerow=(rowlower+rowupper)/2;
		mergecol=(collower+colupper)/2;
		apply_sort(array,rowlower,mergerow,collower,mergecol);
		apply_sort(array,mergerow+1,rowupper,mergecol+1,colupper);
		apply_sort(array,rowlower,mergerow,mergecol+1,colupper);
		apply_sort(array,mergerow+1,rowupper,collower,mergecol);
		answer(array,rowlower,rowupper,collower,colupper);
	}
}


int main()
{  

    int row,col,i,j; 
	//define row and col 
	cin>>row>>col;
	
	int** array = new int*[row];
	for(i=0; i<row; i++)
        array[i] = new int[col];
    //input
	for(int i=0; i<row; i++)
         for(int j=0; j<col; j++)
             cin >> array[i][j];
                
  apply_sort(array,0,row-1,0,col-1);//funcution call
  
  //output
	for(i=0;i<row;i++)
	{
		j=0;
		while(j<col){
			cout<<array[i][j]<<" ";
			j++;
		}
	}
}