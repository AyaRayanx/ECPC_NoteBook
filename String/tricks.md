//to split string into words
vector<string> split(const string &s) {
    stringstream ss(s);
    vector<string> v;
    string x;
    while (ss >> x)
        v.push_back(x);
    return v;
}
