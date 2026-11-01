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
        ll n,m; cin >> n >> m;
        vi freq(26,0);  
        string a,b; cin >> a >> b;
        for(auto x : a) freq[x-'a']++;
        for(auto x : b) freq[x-'a']--;
        bool flag = true;
        for(ll i=0; i<26; i++){
            if(i+'a'!='i' && i+'a'!='s' && i+'a'!='x'){
                if(freq[i]!=0){
                    flag = false;
                    break;
                }
            }else if(i+'a'=='i' || i+'a'=='s' || i+'a'=='x'){
                if(freq[i]!=1){
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
}