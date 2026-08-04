#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,d,r; cin >> n >> d >> r;
    ll div = n/d;
    ll rem = n%d;
    if(rem>=r) div++;
    cout << div;
}