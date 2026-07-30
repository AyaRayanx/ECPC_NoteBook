// Next Element :
    vector<int> next(n+2, 0);
    stack<int> st;
    for (int i = 1; i <= n+1; i++) {
        while (!st.empty() && v[i] > v[st.top()]) {
            next[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

<<<<<-------------------------------------------------------------------------------------------------------->>>>>
vector<int> compress(vector<int>& v) {

   vector<int> tmp = v;

   sort(tmp.begin(), tmp.end());

   tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

  

   vector<int> res(v.size());

   for (int i = 0; i < v.size(); i++) {

       res[i] = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();

   }

   return res;
<<<<<-------------------------------------------------------------------------------------------------------->>>>>

   /* ================= MERGE INTERVALS ================= */

vector<pii> merge_intervals(vector<pii>& v) {

   if (v.empty()) return {};

   sort(v.begin(), v.end());

  

   vector<pii> res;

   res.push_back(v[0]);

  

   for (int i = 1; i < v.size(); i++) {

       if (v[i].first <= res.back().second) {

           res.back().second = max(res.back().second, v[i].second);

       } else {

           res.push_back(v[i]);

       }

   }

   return res;

}
