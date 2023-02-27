#include <bits/stdc++.h>

using namespace std;
int wt[] = {3,2,2};
double val[] = {1.8,1,1};
int dp[3][5];
int knapsack(int ind,int cap)
{
         
    if(ind == 0){
        if(wt[0] <=cap) 
          return dp[0][cap] =val[0];
        else 
		  return dp[0][cap] =0;
    }
    
    if(dp[ind][cap]!=-1)
        return dp[ind][cap];
        
    int notinclude = 0 + knapsack(ind-1,cap);
    int include = INT_MIN;
    if(wt[ind] <= cap)
        include = val[ind] + knapsack(ind-1,cap-wt[ind]);
    return dp[ind][cap] = include>notinclude?include:notinclude;
}

int main() {

  int cap=4;
  int n = 3;

 for(int i=0;i<n;i++)
   for(int j=0;j<cap+1;j++)
      dp[i][j]=-1;
  
                                 
  cout<<"The Maximum value of items is " <<knapsack(n-1,cap);
}