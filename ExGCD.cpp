#include <iostream>
#include <cstdio>
using namespace std;

int x,y,q;
void extend_Eulid(int a,int b)
 {
     if(b == 0){
          x = 1;y = 0;q = a;
     }else{
         extend_Eulid(b,a%b);
         int temp = x;
         x = y;
         y = temp - a/b*y;
     }
}
int main()
{
     int a,b;
     cin>>a>>b;
     extend_Eulid(a,b);
     if(x<=0)x+=b;
     printf("%d\n",x);
     return 0;
}