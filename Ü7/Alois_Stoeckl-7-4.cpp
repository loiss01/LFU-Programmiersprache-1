//  Alois Stöckl - Hü 7 - Aufgabe 4

#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> v;
    for(int i = 1000, step = 1; i > -1000; step++){
        v.push_back(i);
        //cout << i << endl;
        i -= step;
    }

    //a.)
    cout << "a.)" << endl << "Gerade Zahlen:" << endl;
    for(int i : v){
        if(i%2 == 0){
            cout << i << ", ";
        }
    }
    cout << endl;

    //b.)
    cout << "b.)" << endl << "Zahlen im Intervall [-50,50]:" << endl;
    for(int i : v){
        if (-50 <= i && i <= 50){
            cout << i << ", ";
        }
    }
    cout << endl;

    //c.)
    cout << "c.)" << endl << "Vielfache von 7 oder 11:" << endl;
    for(int i : v){
        if (i % 7 == 0 || i % 11 == 0){
            cout << i << ", ";
        }
    }
    cout << endl;


    return 0;
}