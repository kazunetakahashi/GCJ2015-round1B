#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int C = 1000010;

int N[1000010];
int from[1000010];

void init() {
  fill(N, N+1000010, 0);
  N[1] = 1;
  queue<pair<int, int>> Q; // 数字、回数
  Q.push(make_pair(1, 1));
  while (!Q.empty()) {
    int num = Q.front().first;
    int times = Q.front().second;
    Q.pop();
    string S = to_string(num);
    reverse(S.begin(), S.end());
    int next[2] = {num+1, stoi(S)};
    for (auto i=0; i<2; i++) {
      if (next[i] < C && N[next[i]] == 0) {
        N[next[i]] = times+1;
        from[next[i]] = num;
        Q.push(make_pair(next[i], times+1));
      }
    }
  }
  cerr << "READY" << endl;
}

// 変数を書く

void disp(int x) {
  int f = x;
  while(f != 1) {
    cerr << f << " <- ";
    f = from[f];
  }
  cerr << 1 << endl;
}

int n;

void disp_neg(int x) {
  cout << "target = " << n << endl;
  int f = x;
  while(f != 1) {
    if (f-from[f] > 1) {
      cout << f << " <- " << from[f] << endl;
    }
    f = from[f];
  }
}

void input() {
  cin >> n;
}

void output() {
  cout << N[n] << endl;
  disp_neg(n);
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
