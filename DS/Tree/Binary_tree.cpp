#include<iostream>
using namespace std;

class node{
    public : 
    string name;
    double score;
    node *left , *right;
    void set_data(string s, double n);

};
void node :: set_data(string s, double n){
    name = s;
    score = n;
}



