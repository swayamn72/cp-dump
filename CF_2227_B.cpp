#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        ll open = 0, close = 0;
        for(auto a : s){
            if(a=='(') open++;
            else close++;
        }
        if(open==close) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}