#include <bits/stdc++.h>
using namespace std;

struct rect {
    int x1, x2, y1, y2;
    int area(){
        return ((y2 - y1) * (x2 - x1));
    }
};


int intersect(rect i, rect t){
    int w = max(0, min(i.x2, t.x2) - max(i.x1, t.x1));
    int l = max(0, min(i.y2, t.y2) - max(i.y1, t.y1));
    return w * l;
}

int main(){
    freopen("billboard.in", "r", stdin);
    rect a, b, t;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
    freopen("billboard.out", "w", stdout);
    cout << a.area() + b.area() - intersect(a, t) - intersect(b, t) << endl;

}