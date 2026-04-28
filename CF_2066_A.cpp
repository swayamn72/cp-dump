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
        vector<ll> arr(n); for(auto &x : arr) cin >> x;
        bool ispermutation = true; 
        set<ll> s; for(auto a : arr) s.insert(a);
        ll num = -1;
        for(ll i=1; i<=n; i++){
            if(s.find(i)==s.end()){
                ispermutation = false;
                num = i;
                break;
            }
        }
        if(!ispermutation){
            ll res;
            if(num==1){
                cout << "? " << num << " 2" << endl;
                cin >> res;
            }else{
                cout << "? " << num << " 1" << endl;
                cin >> res;
            }
            if(res==0){
                cout << "! A" << endl;
            }else{
                cout << "! B" << endl;
            }
        }else{
            ll res1,res2;
            ll u,v; 
            for(ll i=0; i<n; i++){
                if(arr[i]==1) u = i+1;
                if(arr[i]==n) v = i+1;
            }
            cout << "? " << u << " " << v << endl;
            cin >> res1;
            cout << "? " << v << " " << u << endl;
            cin >> res2;
            if(res1<n-1){
                cout << "! A" << endl;
            }else{
                if(res1==res2) cout << "! B" << endl;
                else cout << "! A" << endl;
            }
        }
    }
}