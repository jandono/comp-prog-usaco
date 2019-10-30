/*
ID: andonov921
TASK: contact
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

ifstream fin("contact.in");
ofstream fout("contact.out");

#define cin fin
#define cout fout

int a, b, n;
string s;

void read_input(){
    cin >> a >> b; // 1 <= a <= b <= 12
    cin >> n; // 1 <= n <= 50

    string tmp;
    while(cin >> tmp){
        s += tmp;
    }
}

unordered_map<string, int> m;

void solve(){

    for(int i=0;i<s.size();i++){
        for(int j=a;j<=b;j++){
            if(i + j <= s.size())
                m[s.substr(i, j)]++;
        }
    }

    auto comp = [](pair<int, string> &lhs, pair<int, string> &rhs){
        
        if(lhs.first == rhs.first){
            
            if(lhs.second.size() == rhs.second.size())
                return lhs.second > rhs.second;
            
            return lhs.second.size() > rhs.second.size();
        }

        return lhs.first < rhs.first;
    };

    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);
    for(auto kv : m){
        pq.push({kv.second, kv.first});
    }

    int freq;
    string pattern;
    for(int i=0;i<n;i++){
        tie(freq, pattern) = pq.top(); pq.pop();
        cout << freq << "\n" << pattern;
        int per_line = 1;
        while(!pq.empty() && freq == pq.top().first){
            tie(freq, pattern) = pq.top(); pq.pop();
            if(per_line == 0)
                cout << pattern;
            else
                cout << " " << pattern;
            
            per_line++;
            if(per_line % 6 == 0){
                cout << "\n";
                per_line = 0;
            }
        }
        if(per_line != 0)
            cout << "\n";

        if(pq.empty())
            break;
    }
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
