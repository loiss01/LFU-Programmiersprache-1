//  Alois Stöckl - Hü 11 - Aufgabe 2

#include <fstream>
#include <sstream>
#include "iostream"
#include "vector"
#include "Bruch.hpp"

using namespace std;

vector<string> splitString(string in){
    vector<string> out;

    istringstream iss(in);
    for(std::string s; iss >> s; )
        out.push_back(s);

    return out;
}


int main(){

    vector<Bruch> v;

    fstream datei;
    datei.open("data", ios::in);

    if (datei.is_open()){
        string line;
        int c = 0;
        while (getline(datei, line)){
            c++;
            if (c == 1) continue;

            vector<string> splitArray = splitString(line);

            for (int i = 0; i < splitArray.size() / 2; ++i) {


                Bruch bru{
                        stoi(splitArray.at(0 + (2*i)) ),
                        stoi(splitArray.at(1 + (2*i)) ),
                };

                v.push_back(bru);
            }


            splitArray.clear();
        }
        cout << c << " Zeilen ausgewertet!" << endl;
        datei.close();
    }else cout << "Fehler beim öffnen der Datei!";

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

    return 0;
}
