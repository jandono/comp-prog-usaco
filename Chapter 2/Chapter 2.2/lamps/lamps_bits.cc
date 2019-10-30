/*
ID: andonov921
TASK: lamps
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
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<string> VS;
typedef vector<VB> VVB;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VS> VVS;

ifstream fin("lamps.in");
ofstream fout("lamps.out");

int num_lamps, buttons_pressed;
const int CYCLE_SIZE = 6;
int init_conf = (1 << CYCLE_SIZE) - 1;
int ison = 0, known = 0;
int x;
bool solved = false;

int MASK_ALL = 0x3F;
int MASK_ODD = 0x2A;
int MASK_EVEN = 0x15;
int MASK_K = 0x09;

int flip[4] = {
    MASK_ALL,
    MASK_ODD,
    MASK_EVEN,
    MASK_K
};

string to_binary(int x){
    string s(num_lamps, ' ');
    for(int i=0;i<num_lamps;i++){
        int bit = 1 << (i % CYCLE_SIZE);
        if(x & bit)
            s[i] = '1';
        else
            s[i] = '0';
    }
    return s;
}

void read_input(){
    
    fin >> num_lamps;
    fin >> buttons_pressed;

    while(fin >> x && x != -1){
        x--;
        int bit = 1 << (x % CYCLE_SIZE);
        ison |= bit;
        known |= bit;
    }

    while(fin >> x && x != -1){
        x--;
        int bit = 1 << (x % CYCLE_SIZE);

        if(ison & bit){
            fout << "IMPOSSIBLE\n";
            solved = true;
            return;
        }
        known |= bit;
    }
}

bool check(int conf){

    for(int i=0;i<CYCLE_SIZE;i++){
        int bit = 1 << i;
        
        if(!(known & bit)) continue; // bit can be whatever if not known

        // Return false if conf has set bit and its not set in final_conf
        if((conf & bit) && !(ison & bit))
            return false;
        
        // Return false if conf has not set bit and final_conf has it set
        if(!(conf & bit) && (ison & bit))
            return false;
    }

    return true;
}

void solve(){
    if(solved)
        return;

    set<string> solution;
    int limit = 1 << 4;
    for(int i=0;i<limit;i++){

        int tmp_conf = init_conf;
        int ones = 0;
        for(int j=0;j<4;j++){
            if(i & (1 << j)){
                ones++;
                tmp_conf = tmp_conf ^ flip[j];
            }
        }

        if(buttons_pressed == 0 && ones != 0) continue;
        if(buttons_pressed == 1 && ones != 1) continue;

        if(check(tmp_conf))
            solution.insert(to_binary(tmp_conf));
    }

    if(!solution.size()){
        fout << "IMPOSSIBLE\n";
        return;
    }

    for(auto sol : solution){
        fout << sol << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
