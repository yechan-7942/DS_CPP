#include<iostream>
using namespace std;


class node{
    public:
    string name;
    double score;
    node *link;
    void set_data(string name, double score);
};

void node :: set_data(string n, double s){
    name = n;
    score = s;
}

class my_list{
    node *head;
    public:
    my_list();
    void add_to_head(node t);
    int remove_a_node(string t_name);
    void insert_a_node(string t_name, node t);
    void show_all_data();
};

my_list :: my_list(){
    head = NULL;
}

void my_list :: add_to_head(node t){
    node *p;
     p = new node;
    *p= t;
    p->link = head;
    head =p;

}

int my_list :: remove_a_node(string t_name){
    node *p , *prev;
    p =NULL;
    prev = NULL;
    while (p!=NULL){
        if(p->name == t_name){
            if(prev == NULL){
                head = p->link;
            }
            else prev ->link = p ->link;
        }
        delete p;
        return 1;
    }
    return 0;
}

void my_list :: insert_a_node(string t_name, node t){
    node *p;
    p= head;
    while (p!=NULL){
        if(p->name == t_name){
            node *new_node = new node;
            *new_node =t;
            new_node ->link = p->link;
            p->link = new node;
            return ;
        }
        p= p->link;
    }
}

void my_list :: show_all_data(){
    node *p;
    for(p=head; p!= NULL ; p= p->link){
        cout << p->name << ":" << p->score << endl;
    }
}

int main(){
    my_list a;
    node tmp;
            tmp.set_data("Kim", 83.5);
        a.add_to_head(tmp);
        tmp.set_data("Lee", 58.2);
        a.add_to_head(tmp);
        tmp.set_data("Park", 91.3);
        a.add_to_head(tmp);
        tmp.set_data("Choi", 55.1);
        a.add_to_head(tmp);
        tmp.set_data("Ryu", 77.1);
        a.add_to_head(tmp);
        tmp.set_data("Yang", 41.3);
        a.add_to_head(tmp);
        tmp.set_data("Hong", 78.2);
        a.add_to_head(tmp);

        cout << "\nThe list before the test \n";
        a.show_all_data();

        a.remove_a_node("Ryu");

        cout << "\nThe list after the removal\n";

        a.show_all_data();

        tmp.set_data("Jeong", 97.5);
        a.insert_a_node("Choi", tmp);

        tmp.set_data("Cho", 85.5);
        a.insert_a_node("Kang", tmp);

        cout << "\nThe list after the insertions\n";
        a.show_all_data();

        return 0;

}