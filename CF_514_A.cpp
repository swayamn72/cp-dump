#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    string res = "";
    while(n>0){
        ll digit = n%10;
        if(digit>4) digit = 9-digit;
        res += digit+'0';
        n/=10;
    }
    reverse(res.begin(),res.end());
    for(auto &a : res){
        if(a=='0') a='9';
        break;
    }
    cout << res;
}