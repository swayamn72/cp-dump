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
        ll n,q; cin >> n >> q;
        vi arr(n); for(auto &x : arr) cin >> x;
        
        set<ll> s1 = {0,3,5,6,9,10,12,15};
        set<ll> s2 = {1,2,4,7,8,11,13,14};
        ll res = 0;
        for(auto a : arr){
            if(s1.count(a)) res++;
        }
        cout << res << " ";
        while(q--){
            ll p,x; cin >> p >> x;
            p--;
            ll a = arr[p], b = x;
            if(!s1.count(a) && s1.count(b)){
                res++;
            }else if(s1.count(a) && !s1.count(b)){
                res--;
            }
            arr[p] = b;
            cout << res << " ";
        }
        cout << "\n";
    }
}