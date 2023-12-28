#include <bits/stdc++.h>
using namespace std;

int w, l;
struct rect {
    int x1, x2, y1, y2;
    int area(){
        return ((y2 - y1)*(x2 - x1));
    }
};

int intersecct(rect a, rect b){
    w = max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
    l = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
    return w*l;
}

int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    rect a, b; 
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    int area = intersecct(a, b);

    //cases not accounted: if cow feed is entirely greater than lawnmower
    //
    if(w >= (a.x2 - a.x1) || l >= (a.y2 - a.y1)){
        cout << a.area() - area << endl;
        return 0;
    }

    cout << a.area() << endl;


}