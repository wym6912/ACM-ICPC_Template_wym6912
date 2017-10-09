## LCS
```cpp
const int maxn = 250010;
const int CHAR = 26;

struct SAM_node
{
	SAM_node *fa, *next[CHAR];
	int len;
	int id, pos;
	SAM_node(){}
	SAM_node(int __len__)
	{
		fa = 0;
		len = __len__;
		RESET(next);
	}
};

SAM_node SAM_NODE[maxn * 2], *SAM_root, *SAM_last;
int SAM_size;

SAM_node* newSAM_node(int len)
{
	SAM_NODE[SAM_size] = SAM_node(len);
	SAM_NODE[SAM_size].id = SAM_size;
	return & SAM_NODE[SAM_size ++];
}

SAM_node* newSAM_node(SAM_node *p)
{
	SAM_NODE[SAM_size] = *p;
	SAM_NODE[SAM_size].id = SAM_size;
	return & SAM_NODE[SAM_size ++];
}

void SAM_init()
{
	SAM_size = 0;
	SAM_root = SAM_last = newSAM_node(0);
	SAM_NODE[0].pos = 0;
}

void SAM_add(int x, int len)
{
	SAM_node *p = SAM_last, *np = newSAM_node(p -> len + 1);
	np -> pos = len;
	SAM_last = np;
	for(;p && ! p -> next[x];p = p -> fa)
		p -> next[x] = np;
	if(! p)
	{
		np -> fa = SAM_root;
		return ;
	}
	SAM_node *q = p -> next[x];
	if(q -> len == p -> len + 1)
	{
		np -> fa = q;
		return ;
	}
	SAM_node *nq = newSAM_node(q);
	nq -> len = p -> len + 1;
	q -> fa = nq;
	np -> fa = nq;
	for(;p && p -> next[x] == q;p = p -> fa)
		p -> next[x] = nq;
}

void SAM_build(char *s)
{
	SAM_init();
	int len = strlen(s);
	for(int i = 0;i < len;i ++)
		SAM_add(s[i] - 'a', i + 1);
}

// Topological Sort
char str[maxn], str2[maxn]; // STR is mode String, STR2 is test String
int topocnt[maxn];
SAM_node* topsam[maxn * 2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> str;
	int n = strlen(str);
	SAM_build(str);
	RESET(topocnt);
	for(int i = 0;i < SAM_size;i ++)
		topocnt[SAM_NODE[i].len] ++;
	for(int i = 1;i <= n;i ++)
		topocnt[i] += topocnt[i - 1];
	for(int i = 0;i < SAM_size;i ++)
		topsam[-- topocnt[SAM_NODE[i].len]] = &SAM_NODE[i];
	cin >> str2;
	int len = strlen(str2);
    SAM_node *tmp = SAM_root;
    int ans = 0;
    int t = 0;
    for(int i = 0;i < len;i++)
    {
        if(tmp -> next[str2[i] - 'a'])
        {
            tmp = tmp -> next[str2[i] - 'a'];
            t ++;
        }
        else
        {
            while(tmp && ! tmp -> next[str2[i] - 'a'])
                tmp = tmp -> fa;
            if(tmp == NULL)
            {
                tmp = SAM_root;
                t = 0;
            }
            else
            {
                t = tmp -> len + 1;
                tmp = tmp -> next[str2[i] - 'a'];
            }
        }
        ans = max(ans,t);
    }
	cout << ans << endl;
	return 0;
}
```