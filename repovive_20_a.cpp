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
        ll n; cin >> n; n*=2;
        string s; cin >> s;
        ll res = 0, b = 0;
        ll left=0, right = n-1;
        while(left<right){
            while(left<n && s[left]!='R') left++;
            while(right>=0 && s[right]!='B') right--;
            if(left<right){
                res++;
                left++; right--;
            }else{
                break;
            }
        }
        cout << res << "\n";
    }
} 