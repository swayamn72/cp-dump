#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    string s1 = "", s2 = "";
    for(ll i=0; i<n; i++){
        ll a; cin >> a;
        s1 += (a+'0'-1);
    }
    for(ll i=0; i<n; i++){
        ll a; cin >> a;
        s2 += (a+'0'-1);
    }
    if(s2<=s1){
        cout << 0;
        return 0;
    }
    // cout << s1 << "\n" << s2 << "\n";
    ll res = 0;
    string s = s1;
    while(true){
        next_permutation(s.begin(),s.end());
        if(s==s2) break;
        res++;
    }
    cout << res;
}