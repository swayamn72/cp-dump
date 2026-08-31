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
        ll n,k; cin >> n >> k;
        ll minv = n, maxv = n+n-1;
        if(k<minv || k>maxv){
            cout << "NO" << "\n";
            continue;
        }        
        cout << "YES" << "\n";

        ll buffer = k-n;
        ll b = buffer; // 0 to n-1
        if(buffer==0){
            for(ll i=1; i<=n; i++){
                cout << i << " " << i << " ";
            }
            cout << "\n";
            continue;
        }
        vi res = {1,2};
        ll temp = 3, temp2 = 1;
        while(buffer>1){
            res.push_back(temp++);
            res.push_back(temp2++);
            buffer--;
        }
        res.push_back(temp2);
        res.push_back(temp2+1);
        ll val = n-b-1;
        ll ptr = n;
        while(val!=0){
            res.push_back(ptr);
            res.push_back(ptr--);
            val--;
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
} 