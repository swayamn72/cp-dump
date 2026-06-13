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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi even, odd;
        for(auto a : arr){
            if(a%2) odd.push_back(a);
            else even.push_back(a);
        }        
        sort(even.rbegin(),even.rend());
        sort(odd.rbegin(),odd.rend());
        if(odd.size()==0){
            vi res(n,0);
            for(auto a : res) cout << a << " ";
            cout << "\n";
            continue;
        }
        if(even.size()==0){
            vi res(n,0);
            for(ll i=0; i<n; i+=2){
                res[i] = odd[0];
            }
            for(auto a : res) cout << a << " ";
            cout << "\n";
            continue;
        }
        vi res(n);
        res[0] = odd[0];
        for(ll i=1; i<even.size()+1; i++){
            res[i] = res[i-1] + even[i-1];
        }
        for(ll i=even.size()+1; i<n; i++) res[i] = res[i-2];
        if(accumulate(arr.begin(),arr.end(),0)%2==0) res[n-1] = 0;
        for(auto a : res) cout << a << " ";

        cout << "\n";

    }
}