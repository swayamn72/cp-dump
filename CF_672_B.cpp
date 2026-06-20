#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    string s; cin >> s;
    if(n>26){
        cout << -1;
        return 0;
    }
    sort(s.begin(),s.end());
    ll res = 0;
    for(ll i=1; i<n; i++) if(s[i]==s[i-1]) res++;
    cout << res;
}