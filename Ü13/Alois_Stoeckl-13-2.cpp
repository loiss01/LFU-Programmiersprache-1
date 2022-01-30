//  Alois Stöckl - Hü 11 - Aufgabe 1

#include <fstream>
#include <sstream>
#include "iostream"
#include "vector"

using namespace std;

struct Konto{
    int anfachs_saldo;
    vector<int> buchungen;

    void saldo(){
        int calc = anfachs_saldo + 0;
        for (int i : buchungen) {
            calc = calc + i;
        }
        cout << "Aktueller Kontostand: " << calc << endl;

    }

    void operator+=(int i){
        buchungen.push_back(i);
    }

    friend ostream& operator<<(ostream& os, Konto c);
};


ostream& operator<<(ostream& os, Konto c) {
    os << "Anfangs Saldo: " << c.anfachs_saldo << endl;
    os << "Buchungen: " << c.buchungen.size() << endl;

    reverse(c.buchungen.begin(), c.buchungen.end());

    for (int i : c.buchungen) {
        os << "Buchung: " << i << endl;
    }


    return os;
}


int main(){

    Konto k{3};

    k += 20;
    k += -3;
    k += 19;

    cout << k << endl;
    return 0;
}
