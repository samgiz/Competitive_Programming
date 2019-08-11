#include <message.h>
#include <bits/stdc++.h>
#include "more.h"

unordered map<long long, long long>M;
unordered_set<long long>S;

long long int get_number(long long index) {
  int responsible_node = (index - 1) * NumberOfNodes() / GetN();
  PutLL(responsible_node, index);
  Send(responsible_node);
  Receive(responsible_node);
  return GetLL(responsible_node);
}

long long int calculate(long long int index) {
  if (index < 1 + MyNodeId() * GetN() / NumberOfNodes()) {
    return get_number(index);
  }
  if (index < 3) return 1LL;
  if(S.count(index))return M[index];
  long long ans = (calculate(index - 1) + GetM() * calculate(index - 2) + calculate(index / 3) + GetA(index))% GetP();
  S.insert(index);
  M[index] = ans;
  return ans;
}

int main() {
  if (MyNodeId() < NumberOfNodes() - 1) {
    while (true) {
      int questioner = Receive(-1);
      long long index = GetLL(questioner);
      if (index == 0) return 0;
      PutLL(questioner, calculate(index));
      Send(questioner);
    }
  } else {
    printf("%lld\n", calculate(GetN()));
    for (int node = 0; node < NumberOfNodes() - 2; ++node) {
      PutLL(node, 0);
      Send(node);
    }
    return 0;
  }
}