/*
ID: andonov921
TASK: humble
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
ostream &operator<<(ostream &os, const pair<F, S> &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "{";
    typename vector<T>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        if (it != v.begin())
            os << ", ";
        os << *it;
    }
    return os << "}";
}

template <typename T>
ostream &operator<<(ostream &os, const set<T> &v)
{
    os << "[";
    typename set<T>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        if (it != v.begin())
            os << ", ";
        os << *it;
    }
    return os << "]";
}

template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &v)
{
    os << "[";
    typename unordered_set<T>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        if (it != v.begin())
            os << ", ";
        os << *it;
    }
    return os << "]";
}

template <typename F, typename S>
ostream &operator<<(ostream &os, const map<F, S> &v)
{
    os << "[";
    typename map<F, S>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        if (it != v.begin())
            os << ", ";
        os << it->first << ": " << it->second;
    }
    return os << "]";
}

template <typename F, typename S>
ostream &operator<<(ostream &os, const unordered_map<F, S> &v)
{
    os << "[";
    typename unordered_map<F, S>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
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

ifstream fin("humble.in");
ofstream fout("humble.out");

#define cin fin
#define cout fout

int k, n;
VLL primes;
set<LL> humbles;

void read_input(){
    
    cin >> k; // 1 <= k <= 100
    cin >> n; // 1 <= n <= 100 000
    primes.resize(k);
    for (int i = 0; i < k; i++){

        cin >> primes[i];
        humbles.insert(primes[i]);
    }
}

void solve(){

    for (int i = 0; i < k; i++){

        set<LL>::iterator it = humbles.begin();
        while (1){

            LL tmp = primes[i] * (*it);
            if(tmp > INT_MAX) break;

            humbles.insert(tmp);
            if (humbles.size() > n){

                humbles.erase(--humbles.end());
                if (tmp >= *(--humbles.end()))
                    break;
            }
            it++;
        }
    }

    cout << *(--humbles.end()) << "\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
