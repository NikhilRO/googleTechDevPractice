#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <iterator>
#include <sstream>
#include <random>
#include <unordered_set>

using namespace std; //only used for convenience here

/*
[Y] Random colour 
[Y] Empty tags / Self-closing tags in HTML 5
*/

unordered_set<string> emptyTags = {"area", "base", "br", "col", "embed", "hr", "img", "input", "keygen", "link", "meta", "param", "source", "track", "wbr"};

bool isEmptyTag(const string &text, string tag){
    return emptyTags.count(tag);
}

string whatTag(const string &text, int pos){
    string tag;
    while(text[pos] != '>'){
        tag += text[pos];
        pos++;
    }
    return tag;
}

int randomFFFFFF(){
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,16777215);
    return dist(rng);
}

string randomColor(){
    int num = randomFFFFFF();
    stringstream sstream;
    sstream << "\\color[" << std::hex << num << "]"; 
    string result = sstream.str();    
    return result;
}

string getFileName(){
    string filename;
    cout << "Please enter in the name of the file you'd like to open: ";
    cin >> filename;
    return filename;
}

string fileToString(ifstream& file, string filename){
    file.open(filename);
    string text(istreambuf_iterator<char>(file), {}); //String construction taking in first, last
    file.close();
    return text;
}

void appendColors(string& text){
    stack<string> colors;

    bool sameCommand = false;
    for(int i = 0; i < text.size(); ++i) {
        if(text[i] == '<'){
            if(text[i+1] == '/'){
                if(!sameCommand){
                    text.insert(i, colors.top());
                    i += colors.top().length() + 1;
                }
                colors.pop(); //Idea - this step can be used to check if the tags are "balanced"
                sameCommand = false;
            } else {
                string random = randomColor();
                text.insert(i, random);
                i += random.length() + 1;
                string tag = whatTag(text, i);
                i += tag.length();
                if(!isEmptyTag(text, tag)){
                    sameCommand = true;
                    colors.push(random);
                } else {
                    if(sameCommand){
                        i++;
                        text.insert(i, colors.top());
                        i += colors.top().length() + 1;
                    }
                }
            }
        }
    }
    return;
}

void outputString(string& text, string filename){
    string outName = filename.substr(0, filename.find_last_of('.')) + "_escSequences" + filename.substr(filename.find_last_of('.'));
    ofstream out(outName);
    out << text;
    out.close();
    return;
}

int main(int argc, char **argv){
    string filename = getFileName();
    ifstream file;
    string text = fileToString(file, filename);
    cout << text << endl; 
    appendColors(text);
    cout << text << endl; 
    outputString(text, filename);
    return 0;
}