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
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;
        
        if(n==1){
            cout << min(a[0],b[0]) << "\n";
            continue;
        }
        ll left = 1, right = LLONG_MAX;
        ll res = 0;
        while(left<=right){
            ll mid = left + (right-left)/2;
            vi tempa = a, tempb = b;
            for(ll i=0; i<n; i++){
                if(a[i]<mid) tempa[i]=0;
                else tempa[i]=1;
                if(b[i]<mid) tempb[i]=0;
                else tempb[i]=1;
            }
            vi v;
            for(ll i=0; i<n; i++){
                if(tempa[i]==0 && tempb[i]==0) v.push_back(0);
                else if(tempa[i]==1 && tempb[i]==1) v.push_back(1);
            }
            if(v.empty()){
                right = mid-1; 
                continue;
            }
            ll count0 = 0, count1 = 0;
            ll prev = -1;
            for(ll i=0; i<v.size(); i++){
                if(v[i]==0 && prev!=0){
                    count0++;
                    prev = 0;
                }else if(v[i]==1){
                    count1++;
                    prev = 1;
                }
            }
            if(count1>count0){
                res = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        cout << res << "\n";
        
    }
}