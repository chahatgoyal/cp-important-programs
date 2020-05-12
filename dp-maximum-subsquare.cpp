#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findlargest(vector<vector<int>> A)
{
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> T(n+1,vector<int>(m+1,0));
    int maxm = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
          if(A[i-1][j-1]==1)
          {
              T[i][j] = 1+min(T[i-1][j],min(T[i][j-1],T[i-1][j-1]));
              //cout<<T[i][j];
          }
          else
          {
              T[i][j] = 0;
          }
          
          maxm = max(maxm,T[i][j]);
        }
    }
    
    cout<< maxm<<"\n";
    return 0;
}

int main() {
	//code
	//vector<vector<int>> A(2,vector<int>(2,1));
	int a;
	cin>>a;
	while(a--)
	{
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int>> A(n,vector<int>(m,0));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            cin>>A[i][j];
	        }
	    }
	    //cout<<A[n-1][m-1];
	    findlargest(A);
	}
	
	return 0;
}

