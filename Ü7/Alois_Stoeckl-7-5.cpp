//  Alois Stöckl - Hü 7 - Aufgabe 5

#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> v;
    for (int i = 1000, step = 1; i > -1000; step++) {
        v.push_back(i);
        //cout << i << endl;
        i -= step;
    }

    vector<int> v3, v6, rest;

    for (int i: v) {
        if (i % 3 == 0 && i % 6){
            v3.push_back(i);
            continue;
        }
        if (i % 6 == 0){
            v6.push_back(i);
            continue;
        }
        rest.push_back(i);
    }

    cout << "v3: " << endl;
    for (int i: v3){
        cout << i << ", ";
    }
    cout << endl;

    cout << "v6: " << endl;
    for (int i: v6){
        cout << i << ", ";
    }
    cout << endl;

    cout << "rest: " << endl;
    for (int i: rest){
        cout << i << ", ";
    }
    cout << endl;
}
