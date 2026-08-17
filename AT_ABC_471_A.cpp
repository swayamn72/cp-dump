#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a,b; cin >> a >> b;
    if(a+b==9 || a-b==9 || a*b==9 || (a/b==9 && a%b==0)){
        cout << "Nine";
    }else{
        cout << "Nein";
    }
}