#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    set<ll> s;
    ll p = 1;
    for(ll i=1; i<n; i++){
        if(gcd(i,n)!=1) continue;
        p = (p*i)%n;
        s.insert(i);
    }
    if(p!=1) s.erase(p);
    cout << s.size() << "\n";
    for(auto a : s) cout << a << " ";
}