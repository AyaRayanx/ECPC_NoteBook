Diameter

ll mx;
int far = 0;
void dfs(int node, int parent, long long dist)
{

	if (dist > mx){
		mx = dist;
		far = node;
	}

	for (auto [child, w] : gg[node]){
		if (child == parent)
			continue;
		dfs(child, node, dist + w);
	}
}
void solve()
{
	mx = -1;
	dfs(1, -1, 0);

	mx = -1;
	dfs(far, -1, 0);
	
	cout << mx;
}

<<<<<-------------------------------------------------------------------------------------------------------->>>>>
bipartite 

int bfs(int i)
{
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    col[i] = 0;
    int c1 = 1, c2 = 0;
    bool b = 1;

    while (!q.empty())
    {
        int u = q.front();
        q
            .pop();
        for (int v : gg[u])
        {
            if (col[v] == -1)
            {
                col[v] = 1 - col[u];
                if (col[v] == 0)
                    c1++;
                else
                    c2++;
                vis[v] = 1;
                q.push(v);
            }
            else if (col[v] == col[u])
            {
                b = 0;
            }
        }
    }

    if (b)
        return max(c1, c2);
        return 0;
}

<<<<<-------------------------------------------------------------------------------------------------------->>>>>
floyed

int d[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j]=INF;
            if(i==j)
                d[i][j]=0;
        }
    }

for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}

<<<<<-------------------------------------------------------------------------------------------------------->>>>>
dijkastra  1

int dij(int st, int ed, int n)
{
    vector<int> dis(n+1, INT_MAX); 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dis[st] = 0;
    pq.push({0, st});

    while(!pq.empty())
    {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(u == ed) return cost; 
        if(cost > dis[u]) continue; 

        for(auto [v, w] : gg[u])
        {
            if(dis[v] > cost + w)
            {
                dis[v] = cost + w;
                pq.push({dis[v], v});
            }
        }
    }
    return INT_MAX;
}

<<<<<-------------------------------------------------------------------------------------------------------->>>>>
dijkastra 2

int dij(int st, int ed)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, st});

	while (!pq.empty())
	{
		int p = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (dis[p])
			continue;

		vis[p] = 1;
		dis[p] = cost;
		for (auto [a, b] : gg[p])
		{
			if (!vis[a])
			{
				pq.push({cost + b, a});
			}
			if (vis[ed])
				return 0;
		}
	}
	return 0;
}

<<<<<-------------------------------------------------------------------------------------------------------->>>>>
dijkastra ans
int dij(int st, int ed, int k)
{
	priority_queue<
		pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
		pq;
	
			dis = vector<int>(n + 1, 1e9);
dis[st] = 0;
	pq.push({0, st});
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (u == ed)
			return cost;

		if (cost > dis[u])
			continue;

		for (auto [v, w] : gg[u])
		{
			if (dis[v] > cost + w.first && k >= w.second)
			{
				dis[v] = cost + w.first;
				pq.push({dis[v], v});
			}
		}
	}
	return 1e9;
}

<<<<<-------------------------------------------------------------------------------------------------------->>>>>

bfs min loxg

void bfs(int s, int t)
{
	vector<int> vis(305, 0), par(305, -1);
	queue<int> q;

	q.push(s);
	vis[s] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		vector<int> neigh = gg[cur];
		sort(neigh.begin(), neigh.end());

		for (auto it : neigh)
		{
			if (!vis[it])
			{
				vis[it] = 1;
				par[it] = cur;
				q.push(it);
			}
		}
	}

	if (!vis[t])
	{
		cout << "connection impossible\n";
		return;
	}

	vector<int> path;
	for (int v = t; v != -1; v = par[v])
		path.push_back(v);

	reverse(path.begin(), path.end());

	for (auto v : path)
	{
		cout << v;
		if (v != t)
			cout << ' ';
	}
	cout << endl;
}
