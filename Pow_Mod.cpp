#include<iostream>
#include<cstdio>
using namespace std;
long mod(long a,long b,long m)
{
     if(b==0)return 1;//边界处理
     if(b==1)return (a%m);//边界处理
     long ans=mod(a,b/2,m);//进入下一层
     ans=ans*ans%m;//返回值ans代表ab/2
     if(b%2==1)ans=ans*a%m;//奇数情况处理
     return ans;//返回ans代表a/b mod m
}
int main()
{
    long long a,b,m;
    cin>>a>>b>>m;
    cout<<mod(a,b,m);
    return 0;
}     
