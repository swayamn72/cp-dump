#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n, d; 
        cin >> n >> d;
        vi arr(n); 
        for(auto &x : arr) cin >> x;
        sort(arr.begin(), arr.end());
        bool flag = false;
        
        if(n%2==0) {
            bool ok = true;
            for(int i=0; i<n; i+=2){
                if(arr[i+1]-arr[i] > d){
                    ok = false;
                    break;
                }
            }
            if(ok) flag = true;
        }else{
            for(int skip = 0; skip < n; skip++){
                vi temp;
                for(int i = 0; i < n; i++) {
                    if (i!=skip) temp.push_back(arr[i]);
                }
                bool ok = true;
                for(int i=0; i<n-1; i+=2) {
                    if(temp[i+1]-temp[i] > d){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    flag = true;
                    break;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
    return 0;
}