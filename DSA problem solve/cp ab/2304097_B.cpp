#include <iostream>
using namespace std;
typedef long long ll;

ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll inverseMod(ll n, ll p) {
    return power(n, p - 2, p);
}

ll solve() {
    ll n, p;
    cout<<"Type N and P : "<<endl;
    if (!(cin >> n >> p)) return -1;
    
    if (n >= p) return 0; 

    if (p - n <= 1000000) {
        ll res = p - 1;
        for (ll i = n + 1; i < p; ++i) {
            res = (res * inverseMod(i, p)) % p;
        }
        return res;
    } else {
        ll res = 1;
        for (ll i = 1; i <= n; ++i) {
            res = (res * i) % p;
        }
        return res;
    }
}

int main() {
    ll result;
    while ((result = solve()) != -1) {
        cout << result << endl;
    }
    return 0;
}

