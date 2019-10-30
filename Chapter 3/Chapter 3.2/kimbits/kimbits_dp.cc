/*
ID: andonov921
TASK: kimbits
LANG: C++                 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <sstream>
#include <climits>
#include <fstream>
#include <cmath>

using namespace std;

/// ********* debug template by Bidhan Roy *********

template <typename F, typename S>
ostream &operator<<(ostream &os, const pair<F, S> &p){
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v){
    
    os << "{";
    typename vector<T>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++){
        if (it != v.begin())
            os << ", ";
        os << *it;
    }
    return os << "}";
}

template <typename T>
ostream &operator<<(ostream &os, const set<T> &v){
    
    os << "[";
    typename set<T>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++){
        if (it != v.begin())
            os << ", ";
        os << *it;
    }
    return os << "]";
}

template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &v){

    os << "[";
    typename unordered_set<T>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++){
        if (it != v.begin())
            os << ", ";
        os << *it;
    }
    return os << "]";
}

template <typename F, typename S>
ostream &operator<<(ostream &os, const map<F, S> &v){

    os << "[";
    typename map<F, S>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++){
        if (it != v.begin())
            os << ", ";
        os << it->first << ": " << it->second;
    }
    return os << "]";
}

template <typename F, typename S>
ostream &operator<<(ostream &os, const unordered_map<F, S> &v){

    os << "[";
    typename unordered_map<F, S>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++){
        if (it != v.begin())
            os << ", ";
        os << it->first << ": " << it->second;
    }
    return os << "]";
}

#define debug(x) cerr << #x << " = " << x << endl;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VB> VVB;
typedef vector<VI> VVI;
typedef vector<VC> VVC;
typedef vector<VLL> VVLL;
typedef vector<VD> VVD;
typedef vector<VS> VVS;

ifstream fin("kimbits.in");
ofstream fout("kimbits.out");

#define cin fin
#define cout fout

LL N, L, I;
VVLL szs;

void read_input(){
    cin >> N >> L >> I;
}

void init_szs(){

    szs.resize(N+1, VLL(L+1, 1));

    for(int i=1;i<=N;i++){
        for(int j=1;j<=L;j++){
            szs[i][j] = szs[i-1][j] + szs[i-1][j-1];
        }
    }
}

void gen_number(int n, int l, int i){

    if(!n) return;

    LL m = szs[n-1][l];
    if(m <= i){
        cout << "1";
        gen_number(n-1, l-1, i-m);
    }else{
        cout << "0";
        gen_number(n-1, l, i);
    }
}

void solve(){
    init_szs();
    gen_number(N, L, I-1);
    cout << "\n";
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
