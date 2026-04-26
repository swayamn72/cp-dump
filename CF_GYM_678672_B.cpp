#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a,b; cin >> a >> b;
    ll c; cin >> c;
    if(!c) cout << a+b;
    else cout << a*b;
}