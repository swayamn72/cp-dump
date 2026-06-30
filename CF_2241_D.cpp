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
        bool flag = true;
        ll suma = 0, sumb = 0;
        for(ll i=0; i<n; i++){
            suma += a[i];
            sumb += b[i];
            if(suma>sumb){
                flag = false;
                break;
            }
            // if(a[i]<b[i]){
            //     if(i%2) bufferodd++;
            //     else buffereven++;
            // }else if(a[i]>b[i]){
            //     ll diff = a[i]-b[i];
            //     if(i%2==0){
            //         if(buffereven<diff){
            //             flag = false;
            //             break;
            //         }
            //     }else{
            //         if(bufferodd<diff){
            //             flag = false;
            //             break;
            //         }
            //     }
            // }
        }
        cout << (flag ? "YES" : "NO") << "\n"; 
    }
}
// 1 -1