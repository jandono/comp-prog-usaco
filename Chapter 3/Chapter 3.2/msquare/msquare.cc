/*
ID: andonov921
TASK: msquare
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

ifstream fin("msquare.in");
ofstream fout("msquare.out");

#define cin fin
#define cout fout

VVI conf = {{1,2,3,4}, {8, 7, 6, 5}};
VVI target(2, VI(4));
VC op2char = {'A', 'B', 'C'};

void read_input(){
    for(int i=0;i<8;i++){
        if(i<4){
            cin >> target[0][i];
        }else{
            cin >> target[1][7-i];
        }
    }
}

VVI A(VVI curr){
    swap(curr[0], curr[1]);
    return curr;
}

VVI B(VVI curr){

    for(int i=0;i<2;i++){
        int tmp = curr[i][3];
        for(int j=0;j<3;j++)
            curr[i][3 - j] = curr[i][3 - j - 1];
        curr[i][0] = tmp;
    }
    return curr;
}

VVI C(VVI curr){

    swap(curr[0][2], curr[0][1]);
    swap(curr[0][1], curr[1][1]);
    swap(curr[1][1], curr[1][2]);
    return curr;
}

VVI transform(VVI &curr, int t){
    
    if(t == 0)
        return A(curr);

    if(t == 1)
        return B(curr);
    
    return C(curr);
}

int to_int(const VVI &curr){
    int sol = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            sol = sol*10 + curr[i][j];
        }
    }

    return sol;
}

class Node{
  public:
    VVI conf;
    VC transforms;
    
    Node(VVI conf, VC transforms){
        this->conf = conf;
        this->transforms = transforms;
    }
};

VC bfs(){

    queue<Node> q;
    unordered_set<int> visited;
    q.push(Node(conf, {}));
    while(!q.empty()){
        Node curr = q.front(); q.pop();

        if(curr.conf == target){
            return curr.transforms;
        }

        for(int i=0;i<3;i++){
            Node new_node = Node(transform(curr.conf, i), curr.transforms);
            new_node.transforms.push_back(op2char[i]);
            if(!visited.count(to_int(new_node.conf))){
                visited.insert(to_int(new_node.conf));
                q.push(new_node);
            }
        }
    }

    return {};
}

void solve(){
    
    VC solution = bfs();
    cout << solution.size() << "\n";
    for(int i=0;i<solution.size();i++){
        if(i != 0 && i % 60 == 0){
            cout << "\n" << solution[i];
        }else{
            cout << solution[i];
        }
    }
    cout << "\n";
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    solve();
    return 0;
}
