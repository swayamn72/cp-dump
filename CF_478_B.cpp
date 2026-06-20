#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m; cin >> n >> m;
    
    // max
    ll max = ((n-m+1)*(n-m))/2;

    // min
    ll rem = n%m; // 0
    ll eachgroup = n/m; // 2
    ll biggroups = rem; // 0
    ll smallgroups = m-rem; // 3
    ll min = (smallgroups) * (eachgroup*(eachgroup-1))/2;
    min += (biggroups)* (((eachgroup+1)*(eachgroup))/2);

    cout << min << " " << max;
}