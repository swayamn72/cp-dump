#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct Basis{
    ll b[60] = {0}; ll v[60] = {0};
    ll sz = 0;
    bool insert(ll x){
        bool flag = false;
        for(ll i=59; i>=0; i--){
            if((x>>i)&1LL){
                if(!b[i]){
                    b[i] = x; sz++;
                    flag = true;
                }
                x^=b[i];
            }
        }
        return flag;
    }
    void reduce(){
        for(ll i=59; i>=0; i--){
            if(b[i]){
                for(ll j=59; j>i; j--){
                    if(b[j] && ((b[j]>>i)&1LL)){
                        b[j] ^= b[i];
                    }
                }
            }
        }
        ll idx = 0;
        for(ll i=0; i<=59; i++){
            if(b[i]){
                v[idx++] = b[i];
            }
        }
    }
    ll kth(ll k){
        ll total = (1LL << sz);
        if(k > total) return -1;
        k--; ll res = 0;
        for(ll i=0; i<sz; i++){
            if((k>>i)&1LL){
                res ^= v[i];
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        string s; cin >> s;
        Basis basis;
        bool flag = true;

        for(ll i=n-1; i>=0; i--){
            if(s[i]=='1'){
                bool f = basis.insert(arr[i]);
                if(f==true){
                    flag = false;
                    break;
                }
            }else{
                bool f = basis.insert(arr[i]);
            }
        }

        cout << (flag ? 0 : 1) << "\n";
    }
}