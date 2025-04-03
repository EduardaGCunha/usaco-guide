#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    vector<ll> divisors;
    vector<ll> primes;
    ll n; cin >> n;
    vector<ll> crivo(1000001, 0);
    ll aux = n;
    for(ll i = 2; i*i<=n; i++) {
        if(!(aux%i)){
            primes.push_back(i);
            while(aux % i == 0) {
                aux /= i;
            }
        }
    }

    if(aux > 1) primes.push_back(aux);

    cout << (1LL << primes.size()) - 1 - primes.size() << endl;
}