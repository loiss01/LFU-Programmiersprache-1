//  Alois Stöckl - Hü 11 - Aufgabe 1

#include <fstream>
#include <sstream>
#include "iostream"
#include "vector"

using namespace std;

void test(int x){
    cout << (x % 2 == 0 ? "x ist gerade" : "x ist ungerade");
    cout << endl;
}

void test(double x){
    if (x == 0){
        cout << "x ist Null" << endl;
    }else{
        if (x > 0){
            cout << "x ist postiv" << endl;
        }else cout << "x ist negativ" << endl;
    }
}

int main(){
    test(2);

    //c.)
    test(1);
    test(1.0);
    test('1');
    test(1.0f);
    //test(1L);
    //test("eins");




    return 0;
}
