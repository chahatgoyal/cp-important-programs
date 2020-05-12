#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

pair<int,int> game(vector<int> A)
{
    vector<vector<pair<int,int>>> T(A.size(),(vector<pair<int,int>>(A.size(),make_pair(0,0))));
    for(int i=0;i<A.size();i++)
    {
        T[i][i].first=A[i];
        T[i][i].second=0;
    }
   int n = A.size();
    for(int l=1;l<n;l++)
    {
        int i=0;
        int j = i+l;
        while(i<n && j<n)
        {
            if(A[i]+T[i+1][j].second>A[j]+T[i][j-1].second)
            {
                T[i][j].first = A[i]+T[i+1][j].second;
                T[i][j].second = T[i+1][j].first;
            }
            else
            {
                T[i][j].first = A[j]+T[i][j-1].second;
                T[i][j].second = T[i][j-1].first;
            }
            i++;
            j++;
        }
    }
    
    
    return T[0][n-1];
}

int main() {
	int a;
	int n;
    cout<<"enter no of test cases";
	cin>>a;
	vector<int> A;
	while(a--)
	{
        cout<<"enter array size";
	  cin>>n;
	  while(n--)
	  {  cout<<"enter element in order";
          int x;
	      
	      cin>> x;
	      A.push_back(x);
	      //cout<<n;
	      
	  }
	  //cout<<A[3];
	  pair<int,int> m = game(A);
	cout<<m.first<<"\n";
	A.clear();
	  
	}
	
	
	
	return 0;
}

