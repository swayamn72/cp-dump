#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;
    bool flag = true;
    for(auto a : arr){
        if(a>=0) flag = false;
    }
    cout << (flag ? "Yes" : "No");
}