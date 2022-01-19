//  Alois Stöckl - Hü 11 - Aufgabe 2


#include "iostream"
#include "random"

using namespace std;


struct SimpleStat {
    string title;
    int n{};
    double sum{};
    double sum2{};
    double varianz;
};

void operator+=(SimpleStat& s, double x){   /* bitte programmieren */
    s.n = s.n + 1;
    s.sum = s.sum + x;
    s.sum2 = pow(x,2);
}

double calcVarianz(SimpleStat s){
    double var = 0;
    var = s.sum2 - (s.n - (s.n - pow((s.sum/s.n), 2)));
    var = var / (s.n - 1);
    s.varianz = var;
    return var;
}

ostream& operator<<(ostream& os, const SimpleStat& s){
    os << s.title << ":" << endl;
    os << "Anzahl der Stichproben: " << s.n << endl;
    if (s.n > 0){
        os << "Mittelwert der Stichproben: " << s.sum/s.n << endl;
    }
    if (s.n > 1){
        os << "Varianz: " << calcVarianz(s) << endl;
        os << "Standartabweichung: " << sqrt(s.varianz) << endl;
    }

    return os;
}


int multipleChoic(){
   int punkte = 0;

    default_random_engine generator(4);
    binomial_distribution<int> bin{4,0.8};

    for (int i = 0; i < 12; ++i) {
        int a = bin(generator);

        switch (a) {
            case 3: punkte = punkte + 1;
            case 4: punkte = punkte + 3;
            default:;
        }
    }


   return punkte;
}


int main(){
    SimpleStat stat;

    for (int i = 0; i < 10000; ++i) {
        stat+= multipleChoic();
    }
    cout << stat;

    return 0;
}
