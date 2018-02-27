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

// Global unordered_set for empty tags in HTML
unordered_set<string> emptyTags = {"area", "base", "br", "col", "embed", "hr", "img", "input", "keygen", "link", "meta", "param", "source", "track", "wbr"};

// Checks if the tag in consideration is empty
bool isEmptyTag(const string &text, string tag){
    return emptyTags.count(tag);
}

// Extracts the tag in consideration
string whatTag(const string &text, int pos){
    string tag;
    while(text[pos] != ' ' && text[pos] != '>'){
        tag += text[pos];
        pos++;
    }
    return tag;
}

string whatCommand(const string &text, int pos){
    string tag;
    while(text[pos] != '>'){
        tag += text[pos];
        pos++;
    }
    return tag;
}


//Returns a random number between 1 and FFFFFF
int randomFFFFFF(){
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,16777215);
    return dist(rng);
}

//Generates the escape sequence to be put before a tag
string randomColor(){
    int num = randomFFFFFF();
    stringstream sstream;
    sstream << "\\color[" << std::hex << num << "]"; 
    string result = sstream.str();    
    return result;
}

// Asks user for the filename
string getFileName(){
    string filename;
    cout << "Please enter in the name of the file you'd like to open: ";
    cin >> filename;
    return filename;
}

//Moves entire file to string
string fileToString(ifstream& file, string filename){
    file.open(filename);
    string text(istreambuf_iterator<char>(file), {});                       //String construction taking in [first, last)
    file.close();
    return text;
}

//Iterates through the string of the file and inputs color escape sequences where needed
void appendColors(string& text){
    stack<string> colors;

    bool sameCommand = false;                                               //To avoid writing the tag twice for the same tag continued
    for(int i = 0; i < text.size(); ++i) {
        if(text[i] == '<'){                                                 //Tag detected
            if(text[i+1] == '/'){                                           //Closing tag
                if(!sameCommand){                                           //Not same line/continued tag
                    text.insert(i, colors.top());                           //Inserts the tag into the string file
                    i += colors.top().length() + 1;                         //Moves the iterator to avoid seeing '<' again and being stuck in a loop
                }
                colors.pop();                                               //Idea - this step can be used to check if the tags are "balanced"
                sameCommand = false;                                        
            } else {                                                        //Opening tag
                string random = randomColor();                              //Acquires a escape sequence with random colour
                text.insert(i, random);                                     //Inserts the tag into the string file
                i += random.length() + 1;                                   //Moves the iterator to avoid seeing '<' again and being stuck in a loop
                string tag = whatTag(text, i);
                string command = whatCommand(text, i);
                i += command.length();                                          
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

//Outputs a file with the same extension as input file
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