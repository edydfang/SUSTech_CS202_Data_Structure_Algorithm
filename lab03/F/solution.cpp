#include <iostream>

using namespace std;

class StringNode
{
private:
    string data;
    int size;
public:
    StringNode(string input){
        this->data = input;
    }
    char lookup(int pos);
    void insert(char ch, int pos);
};

void StringNode::insert(char ch, int pos){
    this->data.insert(pos,string(1,ch));
}

char StringNode::lookup(int pos){
    return this->data[pos];
}

class LongString{
private:
    string[] data[];
    int total_size;

public:
    LongString(string longstr){
        this->total_size = longstr.size();
    }
    char lookup(int pos);
    void insert(char ch, int pos);
}

int main(){
    string input;
    cin >> input;
    StringNode* sn = new StringNode(input);
    cout<<sn->lookup(4)<<endl;
    return 0;
}