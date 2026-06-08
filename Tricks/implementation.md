unique vector
v.erase(unique(v.begin(), v.end()), v.end());

<<<<<-------------------------------------------------------------------------------------------------------->>>>>

void Prefex_2D()
{
vector<vector<ll>>a(n+2,vector<ll>(m+2));
int n,m;cin>>n>>m;
for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)a[i][j] += a[i ][j- 1];
for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)a[i][j] += a[i-1 ][j];
int x1,y1,x2,y2;
cin>>x1>>y1>>x2>>y2;
cout<<a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1]<<"\n";
}
_____________________________________________________________________________
void partial_2D()
{
int x1,x2,y1,y2;
ans[x1- 1][y1- 1]++;
ans[x2][y1- 1]--;
ans[x1- 1][y2]--;
ans[x2][y2]++;
}
<<<<<-------------------------------------------------------------------------------------------------------->>>>>

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>
