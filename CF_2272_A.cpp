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
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        if(is_sorted(arr.begin(),arr.end())){
            cout << -1 << "\n";
            continue;
        }
        vi mexarr(n);
        ll mex = 0;
        set<ll> s;
        for(ll i=0; i<n; i++){
            s.insert(arr[i]);
            while(s.count(mex)) mex++;
            mexarr[i] = mex;
        }
        // for(auto a : mexarr) cout << a << " ";
        // cout << "\n";
        // ll m = n-k;
        // // cout << mexarr[m] << "\n";
        // vi pos(n);
        // for(ll i=0; i<n; i++) pos[arr[i]] = i;

        // ll idx1 = pos[mexarr[m]];
        // ll idx2;
        // for(ll i=0; i<=m; i++){
        //     if(arr[i]>mexarr[m]){
        //         idx2 = i;
        //         break;
        //     }
        // }
        // if(idx1>idx2) swap(idx1,idx2);
        // cout << idx1+1 << " " << idx2+1 << "\n";
        sort(mexarr.rbegin(),mexarr.rend());
        ll val = mexarr[k-1];
        ll res1=-1, res2=-1;
        for(ll i=0; i<n; i++){
            for(ll j=i+1; j<n; j++){
                swap(arr[i],arr[j]);
                
                vi temp(n,0);
                ll mex2 = 0;
                set<ll> s2;
                for(ll k=0; k<n; k++){
                    s2.insert(arr[k]);
                    while(s2.count(mex2)) mex2++;
                    temp[k] = mex2;
                }
                sort(temp.rbegin(),temp.rend());
                if(temp[k-1]>val){
                    val = temp[k-1];
                    res1 = i+1; res2 = j+1;
                }
                swap(arr[i],arr[j]);
            }
        }
        if(res1==-1){
            cout << -1 << "\n";
            continue;
        }
        cout << res1 << " " << res2 << "\n";
    }
}