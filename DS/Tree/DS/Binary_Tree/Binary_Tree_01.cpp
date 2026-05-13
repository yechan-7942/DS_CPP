#include <iostream>
using namespace std;

class node{
    public:
    string name;
    double score;
    node *left, *right;
    void set_data(string name, double score);
};

void node :: set_data(string s, double n){
    name =s;
    score = n;
}

class my_tree{
    public :
    int node_count;
    node *root;
    my_tree();
    int insert_root(node t);

};

my_tree :: my_tree(){
    node_count =0;
    root = NULL;
}



int main(){

}


