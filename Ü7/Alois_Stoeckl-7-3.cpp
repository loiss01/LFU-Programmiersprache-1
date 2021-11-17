//  Alois Stöckl - Hü 7 - Aufgabe 3

#include "iostream"

using namespace std;

int main(){

    cout << "a.)" << "\n";

    for (int i = 0; i < 51; i = i + 2) {
        cout << i << "\n";
    }

    cout << "b.)" << "\n";

    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    int len = alphabet.length();
    for (int i = 0; i < len; ++i) {
       cout << alphabet.back() << "\n";
       alphabet.pop_back();
    }

    return 0;
}