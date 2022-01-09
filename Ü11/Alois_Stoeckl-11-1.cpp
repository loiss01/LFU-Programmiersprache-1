//  Alois Stöckl - Hü 11 - Aufgabe 1

#include <fstream>
#include <sstream>
#include "iostream"
#include "vector"

using namespace std;

struct StatData{
    int J1981,
        J1991,
        J2001,
        J2011,
        J2021;
    string bezirk;
    string gemeinde;
};

vector<string> splitString(string in){
    vector<string> out;

    istringstream iss(in);
    for(std::string s; iss >> s; )
        out.push_back(s);

    return out;
}


int main(){
    vector<StatData> stats;

    fstream datei;
    datei.open("Gemeinden.dat", ios::in);

    int test = 0;

    if (datei.is_open()){
        string line;
        int c = 0;
        while (getline(datei, line)){
            c++;

            vector<string> splitArray = splitString(line);

            if (test == 0){
                cout << splitArray.at(0) << endl;
                cout << splitArray.at(1) << endl;
                cout << splitArray.at(2) << endl;
                cout << splitArray.at(3) << endl;
                cout << splitArray.at(4) << endl;
                cout << splitArray.at(5) << endl;
                cout << splitArray.at(6) << endl;
                test = 1;
            }


            StatData i{
                    stoi(splitArray.at(2)),
                    stoi(splitArray.at(3)),
                    stoi(splitArray.at(4)),
                    stoi(splitArray.at(5)),
                    stoi(splitArray.at(6)),
                    splitArray.at(1),
                    splitArray.at(0),
            };

            stats.push_back(i);
            splitArray.clear();
        }
        cout << c << " Zeilen ausgewertet!" << endl;
        datei.close();
    }else cout << "Fehler beim öffnen der Datei!";


    cout << "a.)" << endl;


    int J1981 = 0,
        J1991 = 0,
        J2001 = 0,
        J2011 = 0,
        J2021 = 0;


    cout << stats.size() << endl;
    for (StatData& i : stats){
        J1981 = J1981 + i.J1981;
        J1991 = J1991 + i.J1991;
        J2001 = J2001 + i.J2001;
        J2011 = J2011 + i.J2011;
        J2021 = J2021 + i.J2021;
    }

    cout << "Gesamtanzahl in Tirol:" << endl
            << "1981: " << J1981 << endl
            << "1991: " << J1991 << endl
            << "2001: " << J2001 << endl
            << "2011: " << J2011 << endl
            << "2021: " << J2021 << endl;

    cout << "b.)" << endl;

    int reutte = 0;
    for (StatData& i : stats){
        if (i.bezirk == "Reutte"){
            reutte = reutte + 1;
        }
    }

    cout << "Im Bezirk Reutte gibt es " << reutte << " Gemeinden!" << endl;

    cout << "c.)" << endl;

    int zuwachs = 0;
    for (StatData& i : stats){
        if (i.bezirk == "Reutte"){
            if (i.J2001 < i.J2021){
                zuwachs = zuwachs + 1;
            }
        }
    }

    cout << "Im Bezirk Reutte gibt es " << zuwachs << " Gemeinden die ihre Einwohneranzahl in den letzten 20 Jahren gesteigert haben." << endl;


    return 0;
}
