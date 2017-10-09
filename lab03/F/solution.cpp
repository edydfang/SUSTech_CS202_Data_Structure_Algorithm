#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class StringNode
{
private:
    string data;
    int lower_bound;
public:
    StringNode(string input, int lower_bound){
        this->data = input;
        this->lower_bound = lower_bound;
    }
    char lookup(int pos);
    StringNode* insert(char ch, int pos);
};

StringNode* StringNode::insert(char ch, int pos){
    this->data.insert(pos,string(1,ch));
    if(this->data.size()<this->lower_bound){
        return NULL;
    }else{
        string part2;
        strncpy(part2, this->data cpp lower_bound, this->data.size -)
        StringNode(this->data, this->lower_bound)
    }
}

char StringNode::lookup(int pos){
    return this->data[pos];
}

class LongString{
private:
    string* data;
    int total_size,lower_bound,upper_bound;

public:
    LongString(string longstr){
        this->total_size = longstr.size();
        lower_bound = (int) sqrt(this->total_size);

        int offset = 0;
        for(int i = 0 ;i<this->total_size;i++){
            
        }
        
    }
    char lookup(int pos);
    void insert(char ch, int pos);
};

char LongString::lookup(int pos){
    return 'x';
}
void LongString::insert(char ch, int pos){
    this->total_size++;
}

int main(){
    string input;
    cin >> input;
    StringNode* sn = new StringNode(input);
    cout<<sn->lookup(4)<<endl;
    return 0;
}