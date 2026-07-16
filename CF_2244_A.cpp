#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        ll temp = 0;
        ll maxl = 0;
        for(auto a : s){
            if(a=='#'){
                temp++;
            }else{
                maxl = max(maxl,temp);
                temp = 0;
            }
        }
        maxl = max(maxl,temp);
        cout << (maxl+1)/2 << "\n";
    }
}