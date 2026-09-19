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
        string a,b; cin >> a >> b;
        if(a[0]!=b[0]){
            cout << "NO" << "\n";
            continue;
        }
        vi v1, v2;
        ll temp = 1;
        for(ll i=1; i<a.size(); i++){
            if(a[i]==a[i-1]){
                temp++;
            }else{
                v1.push_back(temp);
                temp = 1;
            }
        }        
        v1.push_back(temp);
        temp = 1;
        for(ll i=1; i<b.size(); i++){
            if(b[i]==b[i-1]){
                temp++;
            }else{
                v2.push_back(temp);
                temp=1;
            }
        }
        v2.push_back(temp);
        if(v1.size()!=v2.size()){
            cout << "NO" << "\n";
            continue;
        }
        bool flag = true;
        for(ll i=0; i<v1.size(); i++){
            if(v2[i]<v1[i]){
                flag = false;
                break;
            }
            if(v2[i]>2*v1[i]){
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << "\n"; 
    }
} 