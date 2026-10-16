#include <bits/stdc++.h>
#include <memory>
using namespace std;
using ll = long long;

enum class ValueType{
    INTEGER, 
    STRING
};

struct Value{
    ValueType type;
    ll intval;
    string strval;
};

Value createint(ll v){
    Value val;
    val.type = ValueType::INTEGER;
    val.intval = v;
    val.strval = "";
    return val;
}

Value createstring(string v){
    Value val;
    val.type = ValueType::STRING;
    val.strval = v;
    val.intval = 0;
    return val;
}

using Row = unordered_map<string, Value>;

class Node{
    virtual ~Node() = default;
    virtual bool evaluate(const Row &row) const = 0;
    virtual void addChild(unique_ptr<Node> child) {}
};

class CondNode : public Node{
    private:
        string column;
        string op;
        Value targetval;
    public:
        CondNode(string col, string o, Value val){
            column = col;
            op = o;
            targetval = val;
        }
        bool evaluate(const Row &row) const override{
            auto it = row.find(column);
            if(it==row.end()) return false;
            
        }
};

int main() {
    
}