#include<iostream>
#include<cstdio>
using namespace std;
long mod(long a,long b,long m)
{
     if(b==0)return 1;//�߽紦��
     if(b==1)return (a%m);//�߽紦��
     long ans=mod(a,b/2,m);//������һ��
     ans=ans*ans%m;//����ֵans����ab/2
     if(b%2==1)ans=ans*a%m;//�����������
     return ans;//����ans����a/b mod m
}
int main()
{
    long long a,b,m;
    cin>>a>>b>>m;
    cout<<mod(a,b,m);
    return 0;
}     
