```cpp
int Cantor(int n,status a)
{
    int i, j, t, CantorValue;
    CantorValue = 0;
    for(i = 0; i < n ; i ++)
    {
        t = 0;
        for(j = i + 1; j < n; ++ j)
            if(a.num[i] > a.num[j])
                ++ t;
        CantorValue += t * fac[n - i - 1];
    }
    return CantorValue;
}
 
void CantorReverse(int n, int CantorValue, status e)
{
    int i, j, t, vst[8] = {0};
    for (i = 0; i < n; i ++)
    {
        t = CantorValue / fac[n - i - 1];
        for (j = 1;j <= n;j ++)
            if (! vst[j])
            {
                if (t == 0) break;
                -- t;
            }
        e.num[i] = j;
        vst[j] = 1;
        CantorValue %= fac[n - i - 1];
    }
}
```