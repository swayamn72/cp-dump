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
        string s; cin >> s;        

        ll left = 0, right = n-1;
        ll total = 0;
        ll ones = 0, zeros = 0;
        for(ll i=0; i<n; i++){
            if(arr[i]==0){
                total += ones;
                zeros++;
            }else{
                ones++;
            }
        }
        while(left<n && arr[left]==0){
            left++; zeros--;
        } 
        while(right>=0 && arr[right]==1){
            right--; ones--;
        } 
        cout << total << " ";
        vi res(n,0);
        for(ll i=0; i<n; i++){
            if(right<=left) break;
            if(s[i]=='1'){
                total -= zeros;
                left++;
                ones--;
            }else{
                total -= ones;
                right--;
                zeros--;
            }
            res[i] = total;
            while(left<n && arr[left]==0){
                left++; zeros--;
            } 
            while(right>=0 && arr[right]==1){
                right--; ones--;
            } 
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
} 