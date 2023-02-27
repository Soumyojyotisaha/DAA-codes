#include<iostream>
#include<string>
using namespace std;
int comp(string s1,string s2)
{
int m=s1.size();
int n=s2.size();
if(m==0 || n==0)
return 0;
if(s1.at(m-1)==s2.at(n-1))
return 1+comp(s1.substr(0,m-1),s2.substr(0,n-1));
else
{
    int first=comp(s1,s2.substr(0,n-1));
    int second=comp(s1.substr(0,m-1),s2);
    return first>second?first:second;
}
}

main()
{
    string s1="speedy",s2="steady";
    cout<<comp(s1,s2);
}