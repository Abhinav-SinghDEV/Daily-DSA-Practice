#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    } return a;
}

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

void solve() {
    long long n, k;
    cin >> n >> k;
    
    long long l = 1LL << k;
    long long g = gcd(n, l);
    long long m = n / g;
    
    if (m % 3 == 0) {
        long long exp = g * k;
        cout << power(4, exp) <<endl;
    } else cout << 1 <<endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
