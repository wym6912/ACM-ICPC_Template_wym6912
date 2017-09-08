## 树状数组

```cpp
#define SIZE_MM 50000
int bit[SIZE_MM + 1],n;
int sum(int i)
{
    int s = 0;
    while(i > 0)
    {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i,int x) // 求加法
{
    while(i <= n)
    {
        bit[i] += x;
        i += i & -i;
    }
}

void sub(int i,int x)
{
    while(i <= n)
    {
        bit[i] -= x;
        i += i & -i;
    }
}
```



