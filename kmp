const int N=1e5+5;
struct KMP{
    int longestPrefix[N]={};vector<int>ans;
    void calcPrefix(string patern)
    {
        int n=patern.size();
        for(int i=1,idx=0;i<n;i++)
        {
            while(idx>0&&patern[idx]!=patern[i])idx=longestPrefix[idx-1];
            if(patern[i]==patern[idx])idx++;
            longestPrefix[i]=idx;
        }
    }
    void kmp(string s,string pat)
    {
        int n=s.size(),m=pat.size();
        calcPrefix(pat);
        for(int i=0,idx=0;i<n;i++)
        {
            while(idx>0&&s[i]!=pat[idx])idx=longestPrefix[idx-1];
            if(s[i]==pat[idx])idx++;
            if(idx==m)ans.push_back(i-m+1),idx=longestPrefix[idx-1];
        }
    }
};
//////////////////////////////////////////////////

struct Hashing{
private:
    int mod1=1e9+7,mod2=2e9+11;
    ll base1,base2,h1,h2,inv1,inv2,*pw1,*pw2,len;
    deque<char>d;
    ll power(ll a,ll b,ll m)
    {
        ll ans=1;
        while(b>0)
        {
            if(b&1)
            {
                ans=(ans*a)%m;
            }
            a=(a*a)%m;
            b>>=1;
        }
        return ans;
    }
public:
    Hashing(int sz,ll x=31,ll y=37){
        base1=x;
        base2=y;
        h1=h2=len=0;
        inv1=power(x,mod1-2,mod1);
        inv2=power(y,mod2-2,mod2);
        pw1=new ll[sz+1];
        pw2=new ll[sz+1];
        pw1[0]=pw2[0]=1;
        for(int i=1;i<=sz;i++)
        {
            pw1[i]=(x*pw1[i-1])%mod1;
            pw2[i]=(y*pw2[i-1])%mod2;
        }
    }
    void push_back(char x)
    {
        x=x-'a'+1;
        h1=(h1*base1)%mod1;
        h1=(h1+x)%mod1;
        h2=(h2*base2)%mod2;
        h2=(h2+x)%mod2;
        len++;
        d.emplace_back(x);
    }
    void push_front(char x)
    {
        x=x-'a'+1;
        h1=(h1+(x*pw1[len])%mod1)%mod1;
        h2=(h2+(x*pw2[len])%mod2)%mod2;
        len++;
        d.emplace_front(x);
    }
    void pop_back()
    {
        if(len==0)return;
        char x=d.back();
        d.pop_back();
        h1=(h1-x+mod1)%mod1;
        h1=(h1*inv1)%mod1;
        h2=(h2-x+mod2)%mod2;
        h2=(h2*inv2)%mod2;
        len--;
    }
    void pop_front()
    {
        if(len==0)return;
        char x=d.front();
        d.pop_front();
        len--;
        h1=((h1-x*pw1[len]%mod1)+mod1)%mod1;
        h2=((h2-x*pw2[len]%mod2)+mod2)%mod2;
    }
    void clear()
    {
        h1=h2=len=0;
        d.clear();
    }
    bool operator==(const Hashing &H)const{
        return H.h1==h1&&H.h2==h2;
    }
    string GetString()
    {
        return string(d.begin(),d.end());
    }
    pair<int,int>GetHash()
    {
        return {h1,h2};
    }
};
/////////////////////////////////////////////////////////////////////
const int N=2e5+5;
int n,m,lowLink[N],dfn[N],timer,comp[N];
vector<int>adj[N];
vector<vector<int>>components;
stack<int>st;
bool in[N],vis[N];
void dfs(int node)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it);
        }
    }
}
void trajan(int node)
{
    lowLink[node]=dfn[node]=timer++;
    st.push(node);
    in[node]=1;
    for(auto it:adj[node])
    {
        if(dfn[it]==-1)
        {
            trajan(it);
            lowLink[node]=min(lowLink[node],lowLink[it]);
        }
        else if(in[it])
        {
            lowLink[node]=min(lowLink[node],dfn[it]);
        }
    }
    if(lowLink[node]==dfn[node])
    {
        vector<int>component={};
        int x=-1;
        while(x!=node)
        {
            x=st.top();
            st.pop();
            comp[x]=components.size();
            in[x]=0;
            component.push_back(x);
        }
        components.push_back(component);
    }
}
void init()
{
    memset(dfn,-1,sizeof dfn);
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]==-1)
        {
            trajan(i);
        }
    }
}
////////////////////////////////////////
void IS_BRIDGE(int v,int to); // some function to process the found bridge
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}
