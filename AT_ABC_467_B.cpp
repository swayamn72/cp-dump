#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vi a(n), b(n);
    vector<string> s(n);
    for(ll i=0; i<n; i++) cin >> a[i] >> b[i] >> s[i];
    ll res = 0;
    for(ll i=0; i<n; i++){
        if(s[i][0]=='k'){
            res += (b[i]-a[i]);
        }
    }
    cout << res;
}