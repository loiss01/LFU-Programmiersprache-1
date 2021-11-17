//  Alois Stöckl - Hü 7 - Aufgabe 2

#include "iostream"

using namespace std;


int main(){
    cout << "a.)";

    int count = 0;
    while(count < 50){
        count = count + 2;

        cout << count << "\n";

    }

    cout << "b.)" << "\n";

    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    while(alphabet.length() != 0){
        cout << alphabet.back() << "\n";
        alphabet.pop_back();
    }

    return 0;
}
