#include "science.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 4096;

int x, y;
int Time = 0, aTime = 0;
int f[N][N];
int cntRow[N], cntCol[N];
pair<int, int> marks[10004];

void mark(int i, int j) {
    if (!(i >= 0 && i < N && j >= 0 && j < N)) {
      cout << "Trinity marks an invalid cell\n";
      exit(1);
    }
    if (++Time > 10000) {
      cout << "Trinity calls more than 10000 times\n";
      exit(1);
    }
    marks[Time] = {(i + x) % N, (j + y) % N};
}

void neoCall() {
    if (++Time > 10000) {
      cout << "Neo calls more than 10000 times\n";
      exit(1);
    }
    if (Time > aTime) return;
    cntRow[marks[Time].second]++;
    cntCol[marks[Time].first]++;
}

int numRow(int j) { return neoCall(), cntRow[j]; } 
int numColumn(int i) { return neoCall(), cntCol[i]; }

void found(int i, int j) {
    assert(i == x && j == y);
    cout << max(Time, aTime) << endl;
    exit(0);
}

int main() {
    cin >> x >> y;
    trinity(); aTime = Time; Time = 0;
    neo(); 
}

