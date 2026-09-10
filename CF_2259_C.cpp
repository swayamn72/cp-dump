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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll idx = -1;
        for(ll i=0; i<n; i++){
            if(arr[i]==-1 || arr[i]==1){
                idx = i;
                break;
            }
        }        
        if(idx==-1){
            for(auto &a : arr) if(a==-1)a = 1;
            for(auto a : arr) cout << a << " ";
            cout << "\n";
            continue;
        }
        ll len = 0;
        ll resl = -1, resr = -1;
        ll curl = idx, curr = -1;
        for(ll i=idx+1; i<n; i++){
            if(arr[i]==1){
                curr = i;
                if(curr-curl+1 > len){
                    len = curr-curl+1;
                    resl = curl; resr = curr;
                }
                curl = i; curr = -1;
            }else if(arr[i]==0){
                
            }else{
                curr = i;
                if(curr-curl+1 > len){
                    len = curr-curl+1;
                    resl = curl; resr = curr;
                }
            }
        }
        if(resr==-1){
            for(auto &a : arr) if(a==-1) a = 1;
            for(auto a : arr) cout << a << " ";
            cout << "\n";
            continue;
        }
        for(ll i=resl+1; i<=resr-1; i++){
            arr[i] = 0;
        }
        arr[resl] = 1; arr[resr] = 1;
        // cout << curl << " " << curr << "\n";
        for(auto &a : arr) if(a==-1) a = 1;
        for(auto a : arr) cout << a << " ";
        cout << "\n"; 
    }
} 