#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll h,w; cin >> h >> w;
    double ht = h/100.0;
    cout << (400*w>=h*h ? "Yes" : "No");
}