// Fast Power                                                                                                         O(log n)
ll fpow(ll x, ll n) {
    if (n == 0) return 1 % mod;
    if (n == 1) return x % mod;
    ll ans = fpow(x, n / 2);
    ans = ans * ans % mod;
    if (n & 1) ans = ans * x % mod;
    return ans;
}

// -----------------------------------------------------------------------------------------------------------------
// Sum of Powers: 1 + x + x^2 + ... + x^n                                                                   O(log n)
ll sumpow(ll x, ll n) {
    if (n == 1) return x % mod;
    ll p = sumpow(x, n / 2);
    ll ans = p + (p * fpow(x, n / 2)) % mod;
    ans %= mod;
    if (n & 1) ans = (ans + fpow(x, n)) % mod;
    return ans;
}

// ------------------------------------------------------------------------------------------------------------------
// Sieve                                                                                                               O(n log log n)
vector<int> prime;
vector<bool> isprime;

void sieve(ll n) {
    isprime = vector<bool>(n + 1, true);
    isprime[0] = isprime[1] = false;
    for (ll i = 4; i <= n; i += 2) isprime[i] = false;
    for (ll i = 3; i * i <= n; i += 2) {
        if (!isprime[i]) continue;
        for (ll j = i * i; j <= n; j += i + i) {
            isprime[j] = false;
        }
    }
    for (ll i = 2; i <= n; i++) {
        if (isprime[i]) prime.push_back(i);
    }
}

// ---------------------------------------------------------------------------------------------------------------
// Prime Factorization                                                                                           O(sqrt(n))
vector<pair<int, int>> primefact(ll n) {
    vector<pair<int, int>> ret;
    if (n <= (ll)isprime.size() - 1 && isprime[n]) {
        ret.push_back({n, 1});
        return ret;
    }
    for (auto& it : prime) {
        if (it * it > n) break;
        int cnt = 0;
        while (n % it == 0) {
            cnt++;
            n /= it;
        }
        if (cnt) ret.push_back({it, cnt});
    }
    if (n > 1) ret.push_back({n, 1});
    return ret;
}

// ---------------------------------------------------------------------------------------------------------------


const int N = 1e6 + 1;
int divCount[N];
int startIdx[N];
vector<int> divi;

void buildDivisors()
{
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            divCount[j]++;

    startIdx[0] = 0;
    for (int i = 1; i < N; i++)
        startIdx[i] = startIdx[i - 1] + divCount[i - 1];

    int total = startIdx[N - 1] + divCount[N - 1];
    divi.resize(total);

    vector<int> pos(startIdx, startIdx + N);
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            divi[pos[j]++] = i;
}

void solve()
{
    int x = 12;
    for (int i = startIdx[x];i < startIdx[x] + divCount[x]; i++)
    {
        cout << divi[i] << " ";
    }
}

// ---------------------------------------------------------------------------------------------------------------
هو هو الللي فوق لو جاب تايم ده هات اللي فوق												 
const int N = 1e6 + 1;
vector<vector<int> > divi(N);

void divisors() {
    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divi[j].emplace_back(i);
        }
    }
}

// ---------------------------------------------------------------------------------------------------------------
// GCD and LCM                                                                                         O(log min(a, b))
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

// ----------------------------------------------------------------------------------------------------------
// Modular Inverse                                                                                              O(log k)
int power(int x, int k) {
    int ret = 1;
    while (k) {
        if (k & 1) ret = (ret * 1LL * x) % MOD;
        k >>= 1;
        x = (x * 1LL * x) % MOD;
    }
    return ret;
}

int modInverse(int a, int m) {
    return power(a, m - 2);
}

// Call Example:
// ll ans = (p * modInverse(q, mod)) % mod;
// ---------------------------------------------------------------------------------------------------------------
spf
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int spf[N];

void build_spf() {
    for (int i = 1; i < N; i++) spf[i] = i;

    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

vector<int> prime_factors(int x) {
    vector<int> factors;
    while (x != 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}

int main() {
    build_spf();
    // مهمممممممممممممممممممممممممممممممممممممممممممممممممممممم

    int x;
    cin >> x;

    vector<int> f = prime_factors(x);

    for (auto i : f)
        cout << i << ' ';
}
// ---------------------------------------------------------------------------------------------------------------
typedef unsigned long long ull;

// nCr = n!/((n-r)! * r!)
// nCr(n,r) = nCr(n,n-r)
// nPr = n!/(n-r)!
// nPr_circle = nPr/r
// nCr(n,r) = pascal[n][r]
// catalan[n] = nCr(2n,n)/(n+1)

ull nCr(int n, int r) {
	if (r > n)
		return 0;
	r = max(r, n - r);
	ull ans = 1, div = 1, i = r + 1;
	while (i <= n) {
		ans *= i++;
		ans /= div++;
	}
	return ans;
}

ull nPr(int n, int r) {
	if (r > n)
		return 0;
	ull p = 1, i = n - r + 1;
	while (i <= n)
		p *= i++;
	return p;
}

vector<vector<ull>> pascalTriangle(int n) {
	vector<vector<ull>> pascal(n + 1, vector<ull>(n + 1));
	for (int i = 0; i <= n; i++) {
		pascal[i][i] = pascal[i][0] = 1;
		for (int j = 1; j < n; j++)
			pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
	}
	return pascal;
}

// return catalan number n-th using dp O(n^2)//max = 35 then overflow
vector<ull> catalanNumber(int n) {
	vector<ull> catalan(n + 1);
	catalan[0] = catalan[1] = 1;
	for (int i = 2; i <= n; i++) {
		ull &rt = catalan[i];
		for (int j = 0; j < n; j++)
			rt += catalan[j] * catalan[n - j - 1];
	}
	return catalan;
}

// count number of paths in matrix n*m 
// go to right or down only
ull countNumberOfPaths(int n, int m) {
	return nCr(n + m - 2, n - 1);
}

const int N = 1e5 + 100;
const int MOD = 1e9 + 7;
ll fact[N];
ll inv[N]; //mod inverse for i
ll invfact[N]; //mod inverse for i!
void factInverse() {
	fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
	for (long long i = 2; i < N; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
		inv[i] = MOD - (inv[MOD % i] * (MOD / i) % MOD);
		invfact[i] = (inv[i] * invfact[i - 1]) % MOD;
	}
}

ll nCr(int n, int r) {
	if (r > n)
		return 0;
	return (((fact[n] * invfact[r]) % MOD) * invfact[n - r]) % MOD;
}
// ---------------------------------------------------------------------------------------------------------------
class Pollard {
    public:
        using ul = uint64_t;
        using db = long double;
        map<ul, int> cnt_primes;
        vector<ul> primes, divisors;

        ul modMul(ul a, ul b, const ul mod) {
            ll ret = a * b - mod * (ul) ((db) a * b / mod);
            return ret + ((ret < 0) - (ret >= (ll) mod)) * mod;
        }

        ul modPow(ul a, ul b, const ul mod) {
            if (b == 0) return 1;
            ul res = modPow(a, b / 2, mod);
            res = modMul(res, res, mod);
            return b & 1 ? modMul(res, a, mod) : res;
        }

        bool rabin_miller(ul n) {
            // not ll!
            if (n < 2 || n % 6 % 4 != 1) return n - 2 < 2;
            ul A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
                    s = __builtin_ctzll(n - 1), d = n >> s;
            for (auto a: A) {
                // ^ count trailing zeroes
                ul p = modPow(a, d, n), i = s;
                while (p != 1 && p != n - 1 && a % n && i--) p = modMul(p, p, n);
                if (p != n - 1 && i != s) return 0;
            }
            return 1;
        }

        ul pollard(ul n) {
            // return some nontrivial factor of n
            auto f = [n, this](ul x) { return modMul(x, x, n) + 1; };
            ul x = 0, y = 0, t = 30, prd = 2, i = 1, q;
            while (t++ % 40 ||
                   __gcd(prd, n) == 1) {
                /// speedup: don't take gcd every it
                if (x == y) x = ++i, y = f(x);
                if ((q = modMul(prd, max(x, y) - min(x, y), n))) prd = q;
                x = f(x), y = f(f(y));
            }
            return __gcd(prd, n);
        }

        void factor_rec(ul n, map<ul, int> &cnt) {
            if (n == 1) return;
            if (rabin_miller(n)) {
                ++cnt[n];
                return;
            }
            ul u = pollard(n);
            factor_rec(u, cnt), factor_rec(n / u, cnt);
        }

        void calcDivisorsRec(ul cur, int i) {
            if (i >= primes.size()) {
                divisors.push_back(cur);
                return;
            }
            int r = cnt_primes[primes[i]];
            for (int j = 0; j <= r; j++) {
                calcDivisorsRec(cur, i + 1);
                cur = cur * primes[i];
            }
        }

        void calcDivisors(ul x) {
            cnt_primes.clear();
            primes.clear();
            divisors.clear();
            factor_rec(x, cnt_primes);
            for (auto &u: cnt_primes) {
                primes.push_back(u.first);
            }
            calcDivisorsRec(1, 0);
        }
    } P;
// ---------------------------------------------------------------------------------------------------------------

<<<<<-------------------------------------------------------------------------------------------------------->>>>>

ll r = cbrt(a);
	// خد بالك لو عايز تستخدمه كذا مره اعلمه ف متغير وماتستخدموش كذا مره عشلان التايم مهم فششخ


