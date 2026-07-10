
const int N = 200005;
const int LOG = 20;

int n;
int arr[N];
int T[N][LOG];
int lg[N + 1];

int marge(int a, int b)
{
	return min(a, b);
}
void precompute()
{
	// precompute logs
	lg[1] = 0;
	for (int i = 2; i <= N; i++)
		lg[i] = lg[i / 2] + 1;
}
void build()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < LOG; j++)
		{
			T[i][j] = 2e5; // قيمة أكبر من أي Input ممكن
		}
	}
	// initialize level 0
	for (int i = 0; i < n; i++)
		T[i][0] = arr[i];

	// build table
	for (int j = 1; j < LOG; j++)
	{
		for (int i = 0; i + (1 << j) <= n; i++)
		{
			T[i][j] = marge(T[i][j - 1], T[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l, int r)
{
	int j = lg[r - l + 1];
	return marge(T[l][j], T[r - (1 << j) + 1][j]);
}

void solve()
{
	int q, l, r;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	precompute();
	build();
	cin >> q;
  // l,r include
	while (q--)
	{
		cin >> l >> r;
		cout << query(l, r) << endl;
	}
}
