## Cantor 展开

```cpp
int maxc = 10;
ll fac[] = {1,1,2,6,24,120,720,5040,40320};  //注意 fac[n] = n! 

ll Cantor(ll n, ll a[]) // 注意 a[] 从 0 开始存
{
    ll i, j, t, CantorValue;
    CantorValue = 0;
    for(i = 0; i < n ; i ++)
    {
        t = 0;
        for(j = i + 1; j < n; ++ j)
            if(a[i] > a[j])
                ++ t;
        CantorValue += t * fac[n - i - 1];
    }
    return CantorValue;
}

void CantorReverse(ll n, ll CantorValue, ll e[]) //注意返回值是存储在 e[] 里
{
    int i, j, t, vst[maxc] = {0};
    for (i = 0; i < n; i ++)
    {
        t = CantorValue / fac[n - i - 1];
        for (j = 1;j <= n;j ++)
            if (! vst[j])
            {
                if (t == 0) break;
                -- t;
            }
        e[i] = j;
        vst[j] = 1;
        CantorValue %= fac[n - i - 1];
    }
}
```



