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
        if(n==1){
            cout << 3 << "\n";
            cout << "1 1 1" << "\n";
            continue;
        }
        
        ll k = 1;
        while(k<=n) k*=2;
        k--;
        cout << k*2+1 << "\n";
        
        ll b = __builtin_popcount(k);
        b--;
        ll temp = (1<<b);
        temp--;
        vi res(k*2+1);
        res[0] = temp;
        res[1] = 0;
        ll curxor = temp;
        ll i = 2;
        while(true){
            temp--;
            res[i] = curxor^temp;
            if(temp==0){
                i++;
                break;
            } 
            curxor = temp;
            res[i+1] = 0;
            i+=2;
        }
        temp = (1<<b);
        curxor = 0;
        while(i<k*2+1){
            res[i] = curxor^temp;
            if(i+1<=2*k)res[i+1] = 0;
            curxor = temp++;
            i+=2;
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
        
    }
}