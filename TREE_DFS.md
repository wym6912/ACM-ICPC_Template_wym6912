## 求树的 DFS 序

```cpp
int n;
int idx;
int to[2000000],next[2000000],head[1000001],
    q[1000001],fa[1000001],size[1000001],
    dfs[1000001],zz[1000001];  
//size[] 表示树的子树大小 
//dfs[] 表示树的 DFS 序 
void add(int x,int y)
{
    to[++idx]=y;
    next[idx]=head[x];
    head[x]=idx;
    to[++idx]=x;
    next[idx]=head[y];
    head[y]=idx;
    return ;
}
void bfs()
{
    int l=0,r=0;
    q[r++]=1;
    while(l!=r)
    {
        int x=q[l++];
        size[x]=1;
        for(int i=head[x];i;i=next[i])
            if(to[i]!=fa[x])
            {
                fa[to[i]]=x;
                q[r++]=to[i];
            }
    }
    for(int i=n-1;i>=0;--i)
        size[fa[q[i]]]+=size[q[i]];
    return ;
}
int main()
{
    n=read();
    for(int i=1;i<n;++i)
    {
        int a=read(),b=read();
        add(a,b);
    }
    bfs();
    dfs[1]=1;
    zz[1]=2;
    int last;
    for(int i=1;i<n;++i)
    {
        if(fa[q[i]]!=fa[q[i-1]])
            last=zz[fa[q[i]]];
        else
            (last+=size[q[i-1]]);
        dfs[last]=q[i];
        zz[q[i]]=last+1;
    }
 }
```

