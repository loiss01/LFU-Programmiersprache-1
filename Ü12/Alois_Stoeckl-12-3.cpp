#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

struct LV {
    string name;
    double h, ects;
    friend ostream& operator<<(ostream& os, const LV& lv)
    {
        os << lv.name << "\nECTS: " << lv.ects << "\nStunden:" << lv.h;
        return os;
    }
};

struct Pruefung {
    LV lv;
    int note;


    friend ostream& operator<<(ostream& os, const Pruefung& pruefung){
        os << pruefung.lv.name << ":" << endl << "Note:" << pruefung.note;
        return os;
    }
};

struct Student {
    string name, matrikel;
    vector<Pruefung> pruefungen{};

    void pruefung(const LV& lv, int note){   // eine Pruefung abgelegt
        Pruefung nP{lv, note};
        pruefungen.push_back(nP);
    }

    double ects() const{            // meine erreichten ECTS
      /* bitte ausfuellen */

      return std::accumulate(pruefungen.begin(), pruefungen.end(), 0.0, [](auto sum, const Pruefung& pruefung){
          if (pruefung.note < 5){
              return sum + pruefung.lv.ects;
          }else {
              return sum;
          }});
    }

    friend ostream& operator<<(ostream& os, const Student& s)
    {   os << s.matrikel << "  " << s.name << ':';
        for (auto& p: s.pruefungen)
            os << "\n\t" << p;
        return os << '\n';
    }
};

int main()
{   LV math1_vo{"VO Mathematik 1", 4., 5.},
            math1_ue{"UE Mathematik 1", 2., 2.5},
            prog1_vo{"VO Programmiersprache 1", 1., 1.5},
            prog1_ue{"UE Programmiersprache 1", 2., 3.};

    cout << math1_vo << '\n' << math1_ue << '\n' << prog1_vo << '\n'
         << prog1_ue << '\n';

    Student ich{"Reinhard Stix", "07515337"};
    ich.pruefung(math1_vo, 4);
    ich.pruefung(math1_ue, 3);
    ich.pruefung(prog1_vo, 1);
    ich.pruefung(prog1_ue, 1);

    cout << "---" << endl;

    cout << ich;
    cout << ich.ects() << '\n';

}


    