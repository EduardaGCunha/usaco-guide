void solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> numbers;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        numbers.push_back({x,i});
    }
    sort(all(numbers));
    tuple<int,int,int> ans = {-1,-1,-1};
    int best = -1;
    for (int i = 1; i < n; i++){
        auto &[a, idxa] = numbers[i];
        auto &[b, idxb] = numbers[i-1];
 
        int x = a ^ ((1<<k) - 1);
        int e = (a^x)&(b^x);
        if (e > best){
            best = e;
            ans = {x, idxa, idxb};
        }
    }
    auto &[u,v,w] = ans;
    if (v > w) swap(v,w);
    cout << v << " " << w << " " << u << " " << endl;
}