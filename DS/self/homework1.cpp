#include<iostream>
using namespace std;

/*
- class(weight) 정의

-  member함수 set_weight, get_weight, is_heavy, add_grams

- 일반 함수(nonmember 함수) add_weight
*/

class weight{
    public:
    int kg, g;
    public:
    void set_weight(int k, int gr){
        kg =k;
        g= gr;
    }

  int get_weight() {
    return kg * 1000 + g;
  }

    bool is_heavy() { 
    return (kg*1000 + g) >= 10000; 
}

    void add_grams(int gr){
        g += gr; 
        kg += g/1000;
        g %= 1000;
    }
};

weight add_weight (weight a, weight b) {
    weight res;
    int total = (a.kg*1000 + a.g) + (b.kg*1000 + b.g);
    res.kg = total / 1000; res.g = total % 1000;
    return res;
}


int main(){

weight  w1, w2, w3;  // weight라는 class object 3개 생성

    w1.set_weight(12, 800);  // w1을 12kg 800 g으로

    if ( w1.is_heavy() )       //  w1이 10 kg 이상의 값인가 check

        cout << "Heavy. \n";  // 10 이상의 값이므로 Heavy 출력

    else

        cout << "Light. \n";

    w2.set_weight(2, 900);  // w2을 2kg 900 g으로

    w2.add_grams(500);   // gram 값에 500을 더함, w2값이 3kg 400 gram으로 변화

    w3 = add_weight(w1, w2); // w1과 w2을 더하여 w3에 à w3는 16kg 200g

    cout <<  w3.get_weight() << " grams\n"; // w3의 값 ‘16200 grams’ 출력

    return 0;

}
