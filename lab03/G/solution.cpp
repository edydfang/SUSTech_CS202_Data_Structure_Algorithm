#include <bits/stdc++.h>
using namespace std;

int a[5010], b[5010], nxt[5010], bef[5010], h[100010];

int main()
{
	// freopen("test.in",  "r",  stdin);
    // freopen("test.ans",  "w",  stdout); 
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(h, 0, sizeof(h));
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &a[i]);
			b[i] = a[i];
			bef[i] = i - 1;
			nxt[i] = i + 1;
		}
		nxt[0] = 1;
		bef[n + 1] = n;
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; ++i)
			h[b[i]] = i;
		
		int p(n / 2 + 1);
		vector<int > v;
		v.push_back(b[p]);
		
		for (int i = n; i >= 1; --i)
			if (i % 2 == 0)
			{
				int p1 = h[a[i]], p2 = h[a[i + 1]];
				nxt[bef[p1]] = nxt[p1];
				bef[nxt[p1]] = bef[p1];
				nxt[bef[p2]] = nxt[p2];
				bef[nxt[p2]] = bef[p2];
				if (a[i] >= b[p] && a[i + 1] >= b[p])
				{
					p = bef[p];
					v.push_back(b[p]);
				}
				else
					if (a[i] <= b[p] && a[i + 1] <= b[p])
					{
						p = nxt[p];
						v.push_back(b[p]);
					}
					else
						v.push_back(b[p]);
			}
		for (int i = v.size() - 1; i >= 0; --i)
			printf("%d ", v[i]);
		putchar('\n');
	}
	
	return 0;
}
