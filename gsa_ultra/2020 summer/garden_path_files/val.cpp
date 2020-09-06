#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]){
    registerValidation(argc, argv);
    int N, M, K;
    N = inf.readInt(1, 1e9);
    inf.readSpace();
    M = inf.readInt(1, 7);
    inf.readSpace();
    K = inf.readInt(0, 1000);
    inf.readEoln();
    set<pair<int, int>>S;
    for(int i=0; i<K; i++){
        int a, b;
        a = inf.readInt(0, N-1);
        inf.readSpace();
        b = inf.readInt(0, M-1);
        inf.readEoln();
        ensuref(S.count({a, b}) == 0, "hole appears twice");
    }
    inf.readEof();
}