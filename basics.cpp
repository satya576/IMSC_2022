#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int a,b;
    int n;
    vector<int> v;
    v.push_back(5);
    v.push_back(89);
    v.push_back(78);
    for(auto i : v)
        cout<<i<<"\n";
    vector<char> c;
    vector<int> u[5]; 
    u[0].push_back(6);
    u[1].push_back(71);
    u[0].push_back(32);
    for(auto i : u[0])
        cout<<i<<"\n";

    
   vector<int> w={2, 5, 43, 6};

   for(auto i : w)
        cout<<i<<"\t";
    
    for(int i = 0 ;i < w.size(); i++){
        cout<<w[i]<<"\t";
    }

    /////////////// PAIRS /////////
    pair<int, int> p(5,6); //(p.first,p.second)
    vector< pair<int,int> > q;
    q.push_back(make_pair(5,3));
    q.push_back(make_pair(15,88));
    cout<<q[0].first<<"\n";
    cout<<q[0].second<<"\n";

    /////// STACK //////
    stack<int> s; //push, top, pop
    s.push(5);
    s.push(787);
    s.push(88); // 5, 787, 88
    cout<<s.top()<<"\n"; // 88
    s.pop(); // 88 get out
    cout<<s.top()<<"\n"; // 787

    ////// DEQUE /////
    deque<int> d;
    d.push_back(5); // [5]
    d.push_back(98); // [5, 98]
    d.push_front(31); // [31, 5, 98]
    d.pop_back(); // [31,5]
    d.pop_front(); //[5]

    //// Queue /////
    queue<int> q1;
    q1.push(54); // [54]
    q1.push(23); // [23, 54]
    q1.push(76); // [76, 23, 54]
    cout<<q1.front(); // 54
    q1.pop();
    cout<<q1.front(); // 23

    // SET, MAP, Bitset, Priority queue

// cin>>n;
    // for(int i = 1; i<=n; i++){
    //     cin>>a>>b;
    //     cout<<a+b<<"\n";
    // }
    // cout<<"Welcome"<<"\n";
}