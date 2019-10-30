/*
ID: andonov921
TASK: fact4
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

ifstream fin("fact4.in");
ofstream fout("fact4.out");

#define cin fin
#define cout fout

int n;

void read_input(){
    cin >> n; // 1 <= n <= 4220
}

void solve(){
    LL res = 1;
    for(int i=2;i<=n;i++){
        res = res*i;
        while(res % 10 == 0) res /= 10;
        res %= 1000000000;
    }

    cout << res % 10 << "\n";
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
