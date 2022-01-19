//  Alois Stöckl - Hü 11 - Aufgabe 2


#include "iostream"
#include "vector"
#include "Bruch.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


using namespace std;

int main(){

    vector<Bruch> v;

    for (Bruch i; cin >> i; )
        v.push_back(i);

    cout << v.size() << "Brüche ausgelesen!";

    double sum = 0;
    for (Bruch i : v){
        sum = sum + (i.z / i.n);
    }

    cout << "Gesamtsumme: " << sum << endl;

    sort(v.begin(), v.end(), to_double);

    cout << "Größe Bruch: " << endl;
    cout << v.at(0);

    cout << "Kleinster Bruch: " << endl;
    cout << v.at(v.size() - 1);


    cout << "Brüche mit nenner 282:"
    cout << count(v, 282, &Bruch::n) << endl;






    /*

    cout << "a.)" << endl;
    cout << "Es konnten " << v.size() << " Brüche ausgelesen werden!" << endl;

    double sum = 0;
    Bruch max = 0,
        min = 0;
    for (Bruch bruch : v) {
        if (sum == 0){
            max = bruch;
            min = bruch;
        }

        sum = sum + to_double(bruch);

        if (to_double(max) < to_double(bruch)){
            max = bruch;
        }
        if (to_double(min) > to_double(bruch)){
            min = bruch;
        }
    }
    cout << "Gesamtsumme der Brüche: " << sum;

    cout << "b.)" << endl;
    cout << "Max:" << endl;
    cout << max;
    cout << endl;
    cout << "Min:" << endl;
    cout << min;
    cout << endl;

    cout << "c.)" << endl;

    int nenner = 0;
    for (Bruch bruch : v) {
        if (bruch.n == 282){
            nenner = nenner + 1;
        }
    }

    cout << "Nenner mit 282: " << nenner;
*/
    return 0;
}
