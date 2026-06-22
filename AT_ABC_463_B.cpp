#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; char x; cin >> n >> x;
    ll index = 0;
    if(x=='B') index=1;
    else if(x=='C') index=2;
    else if(x=='D') index=3;
    else if(x=='E') index=4;
    vector<string> arr(n); for(auto &a : arr) cin >> a;
    bool flag = false;
    for(auto a : arr){
        if(a[index]=='o'){
            flag = true; break;
        }
    }
    cout << (flag ? "Yes" : "No");
}