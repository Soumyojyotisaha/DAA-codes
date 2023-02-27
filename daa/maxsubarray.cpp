#include <iostream>
using namespace std;


int maxSum(int arr[],int n)
{
    int maxEnding=arr[0];
    int res=arr[0];
    
    for(int i=0;i<n;i++)
    {
        maxEnding=max(maxEnding+arr[i],arr[i]);
        res=max(res,maxEnding);
    }
    
    return res;
}

int main() {
	int arr[]={-6,77,-2,15,-55,2};
	int n=6;
	
	int res=maxSum(arr,n);
	cout<<res<<"\n";
	return 0;
}