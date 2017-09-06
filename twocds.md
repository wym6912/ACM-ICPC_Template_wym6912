```cpp
const int MAXN = 5010;
const int MAXM = 50010;

struct Edge 
{
	int to, next;
}edge[MAXM];

int head[MAXN], tot;

void init()
{
	tot = 0;
	memset(head, -1, sizeof(head));
}

void addedge(int u, int v)
{
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot ++;
}

int linker[MAXN];
bool used[MAXN];
int uN; // 只用初始化 uN，uN 是左边组边的点数

bool dfs(int u)
{
	for(int i = head[u];i != -1;i = edge[i].next)
	{
		int v = edge[i].to;
		if(! used[v])
		{
			used[v] = true;
			if(linker[v] == -1 || dfs(linker[v]))
			{
				linker[v] = u;
				return true;
			}
		}
	}
	return false;
}

int hungary()
{
	int res = 0;
	memset(linker, -1, sizeof(linker));
	for(int u = 0;u < uN;u ++)
	{
		memset(used, false, sizeof(used));
		if(dfs(u))
			res ++;
	}
	return res;
}
```
