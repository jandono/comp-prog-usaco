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

unsigned int N, L, I;

void read_input(){
    cin >> N; // 1 <= N <= 31
    cin >> L; // 1 <= L <= N
    cin >> I; // 1 <= I <= 2^32-1
}

int count_bits(int x){
    int cnt = 0;
    for(int i=0;i<N;i++){
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

string to_binary(int x){
    vector<char> bits;
    for(int i=0;i<N;i++){
        bits.push_back((int)(x & 1) + '0');
        x >>= 1;
    }
    return string(bits.rbegin(), bits.rend());
}

void solve(){

    int limit = (N == 31) ? INT_MAX : (1 << (N + 1)) - 1;
    int smallest_l = (L == 31) ? INT_MAX : (1 << (L + 1)) - 1;

    if(L == N || smallest_l >= I){
        cout << to_binary(I-1) << "\n";
        return;
    }

    int cnt = smallest_l, res = 0;
    for(int i=smallest_l;i<=limit;i++){
  
        int num_bits = count_bits(i);
        int lsb = (i | (i-1)) ^ (i-1);
        
        if(num_bits > L){
            i += lsb - 1;
            continue;
        }

        cnt++;
        
        if(cnt == I){
            res = i;
            break;
        }

        int lsb0 = (i+1 | i) ^ i;
        if(I - cnt > lsb0 - 1){
            i += lsb0 - 1;
            cnt += lsb0 - 1;
        }
    }

    cout << to_binary(res) << "\n";
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
