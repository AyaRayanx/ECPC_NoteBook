```cpp
int const  lg=30;
vector<array<int, 4>> op;
struct trie{
    struct Node{
        Node* ch[2];
        int cnt=0;
        Node(){
            memset(ch,0,sizeof(ch));
            cnt=0;
        }
    };
    Node* root=new Node();
    void insert(int x){
        Node* cur = root;
        for(int i = 30; i >= 0; i--){
            int bit = (x >> i) & 1;
            if(cur->ch[bit] == 0)
                cur->ch[bit] = new Node();
            cur = cur->ch[bit];
            cur->cnt++;
        }
    }
   void erase(int& x){
        Node* cur=root;
       for(int i = 30; i >= 0; i--) {
           int bit = (x >> i) & 1;
           cur = cur->ch[bit];
           cur->cnt--;
       }
    }
    void del

    ll mx_xor(int x){
        Node* cur=root;
        ll ans=0;
        for(int i = 30; i >= 0; i--) {
            int bit = 1^((x >> i) & 1);
            if(cur->ch[bit] && cur->ch[bit]->cnt>0) cur=cur->ch[bit],ans|=(1LL<<i);
            else cur=cur->ch[bit^1];
        }
        return ans;
    }
     bool SearchWord(string &s)
    {
        Node*cur=root;
        for(auto it:s)
        {
            int idx=it-'a';
            if(cur->child[idx]==0)return 0;
            cur=cur->child[idx];
        }
        return cur->IsEnd;
    }
    int CountWord(string &s)
    {
        Node*cur=root;
        for(auto it:s)
        {
            int idx=it-'a';
            if(cur->child[idx]==0)return 0;
            cur=cur->child[idx];
        }
        return cur->IsEnd;
    }
    int CountPrefix(string &s)
    {
        Node*cur=root;
        for(auto it:s)
        {
            int idx=it-'a';
            if(cur->child[idx]==0)return 0;
            cur=cur->child[idx];
        }
        return cur->Prefix;
    }
    
    

};
```