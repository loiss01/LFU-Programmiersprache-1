//  Alois Stöckl - Hü 7 - Aufgabe 6

#include <iostream>

using namespace std;

int sum35(int arg){
    int out = 0;

    for (int i = 1; i < arg+1; ++i) {
        if (i % 3 == 0){
            out = out + i;
        }else if (i % 5 == 0){
            out = out + i;
        }
    }

    return out;
}

int main() {
    cout << "sum35(10): " << sum35(10) << endl << "sum35(1000): " << sum35(1000);
}