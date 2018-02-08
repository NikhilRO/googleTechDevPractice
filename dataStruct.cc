#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <deque>
#include <stack>
#include <queue> 
#include <fstream>
#include <string>

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
d.push_back();
d.push_front();
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
        d.push_back();
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

    return 0;
}




// Wesley's code:
// template <typename T>
// void test(vector<T> &v) {
//     for (T a : v) {
//         cout << a + "." << endl;
//     }
// }




