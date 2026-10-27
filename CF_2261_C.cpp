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
        ll sum = accumulate(arr.begin(),arr.end(),0LL);
        if(sum%2==0 || n==1){
            cout << "Moggity" << "\n";
            continue;
        }        
        ll even = 0, odd = 0;
        for(auto a : arr){
            if(a%2) odd++;
            else even++;
        }
        // losing pos - 3 odd, 1 even 1 odd
        if(odd==3 && even==0){
            cout << "Larpity" << "\n";
            continue;
        }
        if(odd==1){
            if(even==1){
                cout << "Larpity" << "\n";
                continue;
            }else{
                cout << "Moggity" << "\n";
                continue;
            }
        }
        // odd>=3 but odd is odd
        cout << "Moggity" << "\n";
    }
}