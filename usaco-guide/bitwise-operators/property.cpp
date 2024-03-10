#include <iostream>
using namespace std;

int main(){
    int a, b, c, d; cin >> a >> b;
    c = a^b;
    d = a&b;
    cout << 2*d + c << endl;
    return 0;
}