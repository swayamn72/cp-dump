#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi freq(101,0);
        for(auto a : arr) freq[a]++;
        vi res;
        while(true){
            bool found = false;
            for(ll i=100; i>=1; i--){
                if(freq[i]>0){
                    freq[i]--;
                    res.push_back(i);
                    found = true;
                }
            }
            if(!found) break;
        }       
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}