#include "science.h"
#include <bits/stdc++.h>
using namespace std;
 
const int N = 1<<12;
 
void trinity() {
  mark(0, 0); 
}
 
void neo() {
  int x = 0, y = 0; 
  for (int i = 0; i < N; i++) if (numColumn(i) > 0) {
    x = i;
    break;
  }
  for (int j = 0; j < N; j++) if (numRow(j) > 0) {
    y = j;
    break;
  }
  found(x, y);
}

