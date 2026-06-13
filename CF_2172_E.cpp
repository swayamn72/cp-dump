#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        int n,i,j; cin >> n >> i >> j;
        i--; j--;
        string a = to_string(n);
        string b = a;
        while(i--) next_permutation(a.begin(),a.end());
        while(j--) next_permutation(b.begin(),b.end());
        int res1 = 0, res2 = 0;
        for(ll i=0; i<a.size(); i++){
            if(a[i]==b[i]) res1++; else res2++;
        } 
        cout << res1 << "A" << res2 << "B" << "\n";
    }
}