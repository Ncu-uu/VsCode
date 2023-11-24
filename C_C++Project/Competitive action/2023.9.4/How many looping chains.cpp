#include <iostream>
using namespace std;

int find(int x, int* parent) {
  if (parent[x] != x) {
    parent[x] = find(parent[x], parent);
  }
  return parent[x]; 
}

void unite(int x, int y, int* parent) {
  x = find(x, parent);
  y = find(y, parent);
  if (x != y) {
    parent[y] = x;
  }
}

int main() {
  int n;
  cin >> n;
  
  int* parent = new int[n];
  for(int i = 0; i < n; i++) {
    parent[i] = i; 
  }
  
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    unite(i, a-1, parent);
  }
  
  int ret = 0;
  for(int i = 0; i < n; i++) {
    if(parent[i] == i) ret++; 
  }
  
  cout << ret << endl;
  
  delete[] parent;
  return 0;
}
