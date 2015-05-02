#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init() {
}

// 変数を書く

ll n;

void input() {
  cin >> n;
}

ll rev(ll x) {
  string S = to_string(x);
  reverse(S.begin(), S.end());
  return stoll(S);
}

void output() {
  ll ans = 1;
  if (n%10 != 0 && rev(n) < n) {
    n = rev(n);
    ans++;
  }
  string S = to_string(n);
  string SS = S;
  for (unsigned i=(SS.size()+1)/2; i<SS.size(); i++) {
    SS[i] = '0';
  }
  SS[SS.size()-1] = '1';
  if (n < stoll(SS)) {
    SS = to_string(n-1);
    for (unsigned i=(SS.size()+1)/2; i<SS.size(); i++) {
      SS[i] = '0';
    }
    SS[SS.size()-1] = '1';
  }
  ans += n - stoll(SS);
  string SSS = SS;
  reverse(SS.begin(), SS.end());
  cerr << n << " " << SS << endl;
  n = stoll(SS);
  if (SSS != SS) {
    ans++;
  }
  while (n > 1) {
    S = to_string(n);
    SS = "";
    for (unsigned i=0; i<(S.size())/2; i++) {
      SS += '9';
    }
    for (unsigned i=(S.size())/2; i<S.size()-1; i++) {
      SS += '0';
    }
    SS[SS.size()-1] = '1';
    ans += n - stoll(SS);
    string SSS = SS;
    reverse(SS.begin(), SS.end());
    cerr << n << " " << SS << endl;
    n = stoll(SS);
    if (SSS != SS) {    
      ans++;
    }
  }
  cout << ans << endl;
}

int main() {
  init();
  int T;
  cin >> T;
  for (auto t=1; t<=T; t++) {
    cout << "Case #" << t << ": "; 
    input();
    output();
  }
}
