#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define ll long long

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

int main(){
    ll x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
    ll x3, y3, x4, y4; cin >> x3 >> y3 >> x4 >> y4;
    ll x5, y5, x6, y6; cin >> x5 >> y5 >> x6 >> y6;

    ll ogarea = (x2 - x1)*(y2-y1);

    ll width = min(x2, x4) - max(x1, x3);
    ll length = min(y2, y4) - max(y1, y3);
    ll area1 = width * length;
    if (width > 0 && length > 0) ogarea -= area1;

    ll w = min(x2, x6) - max(x1, x5);
    ll l = min(y2, y6) - max(y1, y5);
    ll area2 = w * l;
    if (w > 0 && l > 0) ogarea -= area2;

    ll overlapW = min({x2, x4, x6}) - max({x1, x3, x5});
    ll overlapL = min({y2, y4, y6}) - max({y1, y3, y5});
    ll overlapArea = overlapW * overlapL;
    if (overlapW > 0 && overlapL > 0) ogarea += overlapArea;

    cout << (ogarea > 0ll ? "YES\n" : "NO\n");
}
