#include <iostream>
#include <string>

using namespace std;

class node{
    public :
    string name;
    double score;

    node *link;
    void set_data(string s, double d);
};

void node :: set_data(string s , double d){
    name = s;
    score =d;
}

class my_list{
    node *head, *tail;
    public :
    void add_to_head(node t);
    node delete_fropm_head();
void invert();

};

my_list :: my_list(){
    head = NULL;
    tail = NULL;
}

void my_list :: add_to_head(node t){
    node *p;
    p = new node;
    p ->link = head;
    head =p;
    if(tail == NULL){
        tail =p;
    }
    
}

node my_list:: delete_fropm_head() {
    node temp;
    node *t;
    t = head;
    temp = *head;
    head = head->link;
    delete t;
    if (head == NULL) // 삭제 후 empty가 되면, tail값도 조정
        tail = NULL;
    return temp;
}