#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    ll n; cin >> n;
    string res = "";
    for(ll i=n; i<=s.size()-(n+1); i++) res += s[i];
    cout << res;
}