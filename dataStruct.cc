#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <deque>
#include <stack>
#include <queue> 
#include <fstream>
#include <string>
#include <list>

using namespace std;


/* Vector Functions
v.push_back(val);
v.pop_back();
v.begin(); - Pointer to start
v.end();   - Pointer to end
v.data();  - Pointer to start and capable of pointer arithmetic
v.front(); - Value at start
v.back();  - Value at back
v.insert(pos pointer, value); 
v.size();
v.clear();  - Clear entire vector
v.empty();
*/
vector<string> tokenizeToVector(string filename){
    ifstream file;
    file.open(filename);
    string s;
    vector<string> tokens;
    while(file >> s) tokens.push_back(s);
    file.close();
    return tokens;
}
 
/* Stack Functions
s.empty(); - returns true if empty
s.size();  - returns size (is actually constant time in C++)
s.top();  
s.push(val);
s.pop();
*/
stack<string> tokenizeToStack(string filename){
    ifstream file;
    file.open(filename);
    string s;
    stack<string> tokens;
    while(file >> s) tokens.push(s);
    file.close();
    return tokens;
}

/* Queue Functions
q.empty();
q.size();
q.front();
q.back(); - Eww, this is queue. I shouldn't be able to access it. 
q.push(val);
q.pop();
*/
queue<string>  tokenizeToQueue(string filename){
    ifstream file;
    file.open(filename);
    string s;
    queue<string> tokens;
    while(file >> s) tokens.push(s);
    file.close();
    return tokens;
}

/* Deque Functions
d.push_back(val);
d.push_front(val);
d.pop_back();
d.push_front();
d.insert(pos, val);
d.erase(pos);
d.clear();
d[index];
d.front(); - Returns value
d.begin(); - Returns iterator
d.back();  - Returns value
d.end();   - Returns iterator
d.size();
d.empty();
*/
deque<string> tokenizeToDeque(string filename){
    ifstream file;
    file.open(filename);
    string s;
    deque<string> tokens;
    while (file >> s) tokens.push_back(s);
    file.close();
    return tokens;
}

/* List functions 
l.push_back(val);
l.pop_back();
l.push_front(val);
l.pop_front();
l.insert(pos, val);
l.erase(pos);
l.clear();
l.splice(pos,theSecondList);    - result is a combined list with second beginning at pos of l
l.remove(val);                  - O(n) but it needs to be sorted
l.unique();                     - O(n)
l.merge(theSecondList);         - second list becomes empty; complexity is O(n); useful in merge sort;
l.sort();                       - O(nlogn) 
l.reverse();                    - O(n)
l.front();                      - Gets value
l.back();
l.begin();                      - Gets iterator: NOTE Iterators can be used to traverse the list by ++i or i++
l.end();
l.empty();
l.size();
*/
list<string> tokenizeToList(string filename){
    ifstream file;
    file.open(filename);
    string s;
    list<string> tokens;
    while(file >> s) tokens.push_back(s);
    file.close();
    return tokens;
}

/* Unordered Map Functions
um.insert( {{key, val}, {key, val}} );   - To insert many keys
um["key"] = val;                         - It can add a new key if it doesn't exist or it will reassign the value at key.
um.size();
um.erase(iterator or key);                     
um.begin();                              - Iterator to the beginning
um.end();                                - Iterator to the end
um.empty();
um.count(key);                           - Returns the count for a key
um.find(key);                            - Returns the pointer/iterator for a key
um.clear();
*/
unordered_map<string, int> tokenizeToMap(string filename){
    ifstream file;
    file.open(filename);
    string s;
    unordered_map<string, int> tokens;
    while(file >> s) tokens[s]++;
    file.close();
    return tokens;
}

/* Unordered Set Functions
us.empty();
us.size();
us.begin();
us.find(key);                           -  Returns an iterator./pointer for the key
us.count(key);                          -  Returns 0 or 1
us = {"" , " "};                       
us.insert({key});
us.erase(key);
us.clear();
*/
unordered_set<string> tokenizeToSet(string filename){
    ifstream file;
    file.open(filename);
    string s;
    unordered_set<string> tokens;
    while(file >> s) tokens.insert({s});
    file.close();
    return tokens;
}

void printVector(vector<auto> &v){ // Prints forward
    for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
    v.clear();
    cout << endl;
    return;
}

void printVector2(vector<auto> &v){ //Prints reverse
    while(!v.empty()){
        cout << v.back() << endl;
        v.pop_back();
    }
    cout << endl;
    return;
}

void printStack(stack<auto> &s){ //Prints reverse
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
    return;
}

void printQueue(queue<auto> &q){ //Prints forward
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    cout << endl;
    return;
}

void printDeque(deque<auto> &d){ //Prints forward
    while(!d.empty()){
        cout << d.front() << endl;
        d.pop_front();
    }
    cout << endl;
    return;
}

void printDeque2(deque<auto> &d){ //Prints reverse
    while(!d.empty()){
        cout << d.back() << endl;
        d.pop_back();
    }
    cout << endl;
    return;
}

void printList(list<auto> &l){ //Prints forward
    while(!l.empty()){
        cout << l.front() << endl;
        l.pop_front();
    }
    cout << endl;
    return;
}

void printList2(list<auto> &l){ //Prints Reverse
    while(!l.empty()){
        cout << l.back() << endl;
        l.pop_back();
    }
    cout << endl;
    return;
}

void printMap(unordered_map<auto, int> &um){
    cout << um.size() << endl;
    while(!um.empty()){
        cout << um.begin()->first << " : " << um.begin()->second << endl;
        um.erase(um.begin());
    }
    cout << endl;
    return;
}

void printSet(unordered_set<auto> &us){
    cout << us.size() << endl;
    while(!us.empty()){
        cout << *us.begin() << " : " << us.count(*us.begin()) << endl;
        us.erase(us.begin());
    }
    cout << endl;
    return;
}


int main(int argc, char ** argv){
    char arr[] = {'a', 5, 5, 43, 120}; // auto 
    int arrSize = sizeof(arr)/sizeof(*arr);

    string filename= "in1.txt";
    
    vector<string> v;// (arr, arr+arrSize);
    v = tokenizeToVector(filename);
    printVector(v);

    stack<string> s;
    s = tokenizeToStack(filename);
    printStack(s);

    queue<string> q;
    q = tokenizeToQueue(filename);
    printQueue(q);

    deque<string> d;
    d = tokenizeToDeque(filename);
    printDeque(d);

    list<string> l;
    l = tokenizeToList(filename);
    printList(l);

    unordered_map<string, int> um;
    um = tokenizeToMap(filename);
    printMap(um);

    unordered_set<string> us;
    us = tokenizeToSet(filename);
    printSet(us);


    return 0;
}




// Wesley's code:
// template <typename T>
// void test(vector<T> &v) {
//     for (T a : v) {
//         cout << a + "." << endl;
//     }
// }




