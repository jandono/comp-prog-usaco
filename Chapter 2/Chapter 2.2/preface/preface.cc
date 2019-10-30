/*
ID: andonov921
TASK: preface
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

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename T >
ostream &operator << ( ostream & os, const unordered_set< T > &v ) {
    os << "[";
    typename unordered_set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << ": " << it -> second ;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const unordered_map< F, S > &v ) {
    os << "[";
    typename unordered_map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << ": " << it -> second ;
    }
    return os << "]";
}

#define debug(x) cerr << #x << " = " << x << endl;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VS> VVS;
typedef vector<VC> VVC;

ifstream fin("preface.in");
ofstream fout("preface.out");

int n;
unordered_map<char, int> symbol_to_count;
unordered_map<int, string> num_to_symbol = {
    {1000, "M"}, {900, "CM"}, {500, "D"},
    {400, "CD"}, {100, "C"}, {90, "XC"},
    {50, "L"}, {40, "XL"}, {10, "X"},
    {9, "IX"}, {5, "V"},  {4, "IV"},
    {1, "I"}, 
};

VI nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
VC symbols = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

void read_input(){
    fin >> n; // 1 < = n <= 3500
}

string convert_dec_to_roman(int x){
    string res = "";
    for(auto num : nums){
        while(x >= num){
            res += num_to_symbol[num];
            x -= num;
        }
    }
    return res;
}

void count(string roman){
    for(auto c : roman){
        symbol_to_count[c]++;
    }
}

void solve(){
    for(int i=1;i<=n;i++){
        string roman = convert_dec_to_roman(i);
        count(roman);
    }

    for(auto symb : symbols){
        if(!symbol_to_count.count(symb)) continue;
        fout << symb << " " << symbol_to_count[symb] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
