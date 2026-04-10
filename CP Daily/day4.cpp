#include<bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n + 1, 0);
    int l = 0, r = 0;
    for (int i = 2; i <= n; i++) {
      if (s[i - 2] == '<') a[i] = --l;
      else a[i] = ++r;
    }
    for (int i = 1; i <= n; i++) a[i] += 1 - l;
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
  }
  return 0;
}
