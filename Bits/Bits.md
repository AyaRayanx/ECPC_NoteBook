```
// __builtin_popcountll(n) -> number of set bits  
// __builtin_clzll(n) -> leading zeros  
// __builtin_ctzll(n) -> trailing zeros
```
```
// ================= BIT MANIPULATION TEMPLATE =================

using ll = long long;

// convert to binary (print)
string toBinary(ll n) {
    string s = "";
    while (n) {
        s += (n & 1) + '0';
        n >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}

// count ones (Brian Kernighan)
int countOnes(int n) {
    int c = 0;
    while (n) {
        n &= (n - 1);
        c++;
    }
    return c;
}

// set bit to 1
ll setBit(ll n, int id) {
    return n | (1LL << id);
}

// set bit to 0
ll clearBit(ll n, int id) {
    return n & ~(1LL << id);
}

// toggle bit
ll toggleBit(ll n, int id) {
    return n ^ (1LL << id);
}

// get bit
int getBit(ll n, int id) {
    return (n >> id) & 1;
}

// check power of 2
bool isPowerOfTwo(ll n) {
    return n && !(n & (n - 1));
}

// lowest set bit (LSB)
ll lowestBit(ll n) {
    return n & -n;
}

// remove lowest set bit
ll removeLowestBit(ll n) {
    return n & (n - 1);
}

// highest set bit position
int highestBit(ll n) {
    return 63 - __builtin_clzll(n);
}

// count bits (built-in)
int bitCount(ll n) {
    return __builtin_popcountll(n);
}
## 4. turn off last bit مباشرة
n = n & (n - 1);
## 5. get rightmost bit

ll x = n & -n;

```
```
for (int mask = 0; mask < (1 << n); mask++) {
    // كل subset
    for (int sub = mask; sub; sub = (sub - 1) & mask) {
    // submask من mask
}
}

```