/*
ID: andonov921
TASK: ratios
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

ifstream fin("ratios.in");
ofstream fout("ratios.out");

#define cin fin
#define cout fout

VI goal(3);
VVI source(3, VI(3));

void read_input(){
    cin >> goal[0] >> goal[1] >> goal[2];
    for(int i=0;i<3;i++){
        cin >> source[i][0] >> source[i][1] >> source[i][2];
    }
}

int check(VI multipliers){

    VI tmp(3, 0);
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            tmp[j] += multipliers[i] * source[i][j];
        }
    }

    int goal_mul;
    for(int i=0;i<3;i++){
        if(goal[i] != 0){
            if(tmp[i] % goal[i])
                return 0;
            goal_mul = tmp[i] / goal[i];
        }else{
            if(goal[i] != tmp[i])
                return 0;
        }
    }

    if(goal_mul * goal[0] == tmp[0] && goal_mul * goal[1] == tmp[1] && goal_mul * goal[2] == tmp[2])
        return goal_mul;
    
    return 0;
}

void solve(){

    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            for(int k=0;k<=100;k++){
                int goal_mul = check({i, j, k});
                if(goal_mul){
                    cout << i << " " << j <<" " << k << " " << goal_mul << "\n"; 
                    return;
                }
            }
        }
    }

    cout << "NONE\n";
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    solve();
    return 0;
}
