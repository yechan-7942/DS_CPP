#include<iostream>
using namespace std;

class node{
    public:

    string name;
    double score;
    node *link;
    
    void set_data(string name, double score);
};

void node :: set_data(string s, double n){
    name = s;
    score = n;
}

class my_list{
    node *head, *tail;

    public:
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();
    double sum_score();
    double get_score(string t_name);
    int remove_a_node(string t_name);

};

my_list :: my_list(){
    head =NULL;
    tail = NULL;
}

void my_list :: add_to_head(node t){
    node *p;
    p= new node;
    (*p) = t;
    p->link = head;
    head = p;
    if(tail ==NULL)
    tail = p;
}

void my_list :: add_to_tail(node t){
    node *p ; 
    p = new node;
    (*p) =t;
    p->link = NULL;
    if(tail!= NULL){
        tail ->link = p;
    }
    else
        head=p;

        tail=p;
}

node my_list :: delete_from_head(){
    node temp;
    node *p;
    p = head;
    temp = *head;
    head = head ->link;
    delete p;
    if(head ==NULL){
        tail = NULL;
    }
    return temp;
}

int my_list :: num_nodes(){
    node *p;
    int count =0;

    for(p=head; p!=NULL; p= p->link){
        count ++;
    }
    return count;

}

bool my_list :: list_empty(){
    if(head ==NULL){
        return true;
    }
    else 
    return false;
}
double my_list :: sum_score(){
    node *p;
    double sum =0;
    for(p=head; p!= NULL ; p= p->link){
         sum += p->score;
    }
    return sum;
}

int my_list::remove_a_node(string t_name){
    node *p = head;
    node *prev = NULL;
    while(p != NULL){
        if(p->name == t_name){
            if(prev == NULL) head = p->link;
            else prev->link = p->link;
            if(p == tail) tail = prev;
            delete p;
            return 1; // 삭제 성공
        }
        prev = p;
        p = p->link;
    }
    return 0; // 못 찾음
}
double my_list::get_score(string t_name){
    node *p = head;
    while(p != NULL){
        if(p->name == t_name) return p->score;
        p = p->link;
    }
    return -1.0; // 못 찾으면 -1 반환
}


int main(){
    my_list a;
    node tmp;

tmp.set_data("Kim", 83.5);
a.add_to_head(tmp);
tmp.set_data("Lee", 78.2);
a.add_to_head(tmp); // head 위치로 2개의 원소 추가
cout << a.num_nodes() << " : " << a.sum_score() << "\n"; // 1단계 점검
tmp.set_data("Park", 91.3);
a.add_to_tail(tmp); 
cout << a.num_nodes() << " : " << a.sum_score() << "\n"; 
tmp = a.delete_from_head();
cout << tmp.name << " is deleted.\n"; 
tmp.set_data("Choi", 85.1);
a.add_to_tail(tmp);
tmp.set_data("Ryu", 94.3);
a.add_to_head(tmp); // 2개의 원소 추가
cout << a.num_nodes()<< " : "  << a.sum_score() << "\n";
cout << "Park's score : " << a.get_score("Park") << endl;
if ( a.remove_a_node("Kim") == 1)
cout << "Kim is deleted from the list.\n";
cout << a.num_nodes()<< " : " << a.sum_score() << "\n"; 
return 0;

}