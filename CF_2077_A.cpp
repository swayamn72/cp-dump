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
        vi arr(2*n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        set<ll> s;
        for(auto a : arr) s.insert(a);
        ll sum1 = 0;
        for(ll i=0; i<n; i++) sum1 += arr[i];
        
        ll sum2 = 0;
        for(ll i=n; i<2*n; i++) sum2 += arr[i];

        ll val = sum2 - sum1;
        vi v;
        v.push_back(val);
        ll ptr1 = 0, ptr2 = n;
        for(ll i=0; i<n; i++){
            v.push_back(arr[ptr2++]);
            v.push_back(arr[ptr1++]);
        }
        ll ptr = 2*n;
        while(s.count(val)){
            ll idx1 = ptr-1, idx2 = ptr;
            val -= 2*v[idx1];
            val += 2*v[idx2];
            swap(v[idx1],v[idx2]);
            if(val>0 && !s.count(val)){
                v[0] = val;
                break;
            }
            ptr-=2;
        }
        
        for(auto a : v) cout << a << " ";
        cout << "\n";
    }
}