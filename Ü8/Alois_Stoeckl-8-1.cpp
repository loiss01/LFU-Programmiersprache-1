//  Alois Stöckl - Hü 8 - Aufgabe 1

#include "iostream"

using namespace std;


/**
 * Summirt alle ungraden Zahlen
 * @param n Alle zahlen von 0 < n  werden druchgegangen
 * @return an int
 */
int sum_odd(int n){
    int s = 0;

    for (int i = 0; i <= n; ++i) {

        if ( i % 2 != 0){
            s += i;
        }
    }

    return s;
}

/**
 * Multiplizirt alle Interger von 0 bis n
 * @param n grenze
 * @return  long long number
 */
long long factorial(int n){
    long long s = 0;

    for (int i = 0; i <= n; ++i) {
        s = s*i;
    }

    return s;
}


int main(){
    cout << "c.)" << endl;
    for (int i = 1; i < 31; ++i) {
        cout << "summ_odd(" << i << ") = " << sum_odd(i) << endl;
    }


    cout << "d.)" << endl;

    for (int i = 1; i < 31; ++i) {
        cout << "factorial(" << i << ") = " << factorial(i) << endl;
    }


    return 0;
}
