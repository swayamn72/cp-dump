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
        vector<ll> even,odd;
        for(auto a : arr){
            if(a%2) odd.push_back(a);
            else even.push_back(a);
        }
        if(is_sorted(arr.begin(),arr.end())){
            cout << "YES" << "\n";
            continue; 
        }
        if(even.empty()||odd.empty()){
            cout << "NO" << "\n";
            continue;
        }
        ll evenmin = *min_element(even.begin(),even.end());
        ll evenmax = *max_element(even.begin(),even.end());
        ll oddmin = *min_element(odd.begin(),odd.end());
        ll oddmax = *max_element(odd.begin(),odd.end());

        ll prefmax = even[0];

        bool flag = true;

        for(ll i=1; i<even.size(); i++){
            prefmax = max(prefmax, even[i-1]);
            if(prefmax>even[i]){
                if(oddmin >= even[i] && oddmax <= prefmax){
                    flag = false;
                    break;
                }
            }
        }
        prefmax = odd[0];
        for(ll i=1; i<odd.size(); i++){
            prefmax = max(prefmax, odd[i-1]);
            if(prefmax > odd[i]){
                if(evenmin >= odd[i] && evenmax <= prefmax){
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
}