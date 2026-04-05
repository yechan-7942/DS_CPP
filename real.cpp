#include<iostream>
using namespace std;

class node{
    public:
    string name;
    double score;
    node *link;
    void set_data(string name, double score);
};

void node::set_data(string n, double s){
    name = n;
    score =s;
}

class my_list{
    node *head;
    public:
    my_list();
    void add_to_head(node t);
    double score_sum();
    int count_high_scores();
    double get_score(string t_name);
    void show_all();
    int num_node();

};
my_list :: my_list(){
    head =NULL;
}

void my_list :: add_to_head(node t){
    node *p;
    p = new node;
    *p = t;
    p->link =head;
    head = p;
}

double my_list :: score_sum(){
    node *p;
    double sum=0.0;
    for(p=head ; p!= NULL; p= p->link){
        sum += p->score;
    }
    return sum;
}

int my_list :: count_high_scores(){
    node *p;
    int count =0;
    for(p = head; p != NULL; p= p->link){
        if(p->score >= 80){
            count ++;
        }
    }
    return count;
}

double my_list :: get_score(string t_name){
    node *p;
    for(p=head ; p!= NULL ; p = p->link){
        if(p->name == t_name){
            return p->score;
        }
    }
    return -1.0;

}
void my_list :: show_all(){
    node *p;
    for(p=head ; p != NULL ; p= p->link){
        cout << p ->name << ":" << p->score << endl;
    }
}
int my_list :: num_node(){
    node *p;
    int count =0;
    for(p= head ; p != NULL; p= p->link){
        count ++;
    }
    return count;
}

int main(){
    node tmp;
    my_list a;

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

        double average = a.score_sum() / a.num_node();

        cout << "The Number of Nodes :" << a.num_node() <<endl;
        cout << "The Average : " <<  average << endl;
        cout << "The number of hight scores (highter than 80)" << a.count_high_scores() << endl;
        cout << "choi's score:" << a.get_score("Choi") << endl;
        return 0;
}