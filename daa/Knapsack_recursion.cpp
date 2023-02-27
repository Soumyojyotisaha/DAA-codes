#include<iostream>
using namespace std;
int cap=4;
int wt[]={3,2,2};
double val[]={1.8,1,1};
int n=3;
int find(int ind,int cap)
{
	if(ind==0)
	{
		if(wt[0]<=cap)
		  return val[0];
		return 0;
	}
   int notinc=0+find(ind-1,cap);
   int inc=INT_MIN;
   if(wt[ind]<=cap)
     inc=val[ind]+find(ind-1,cap-wt[ind]);
   return (inc>notinc?inc:notinc);
}
int main()
{
	cout<<find(n-1,cap);
}