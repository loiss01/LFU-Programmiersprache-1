//  Alois Stöckl - Hü 10 - Aufgabe 4

#include <fstream>
#include "random"
#include "iostream"

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


int main(){

    mt19937_64 g;
    normal_distribution<double> nv{5.,3.};

    SimpleStat s;
    SimpleStat getuerkte_NV;

    ofstream myfile;
    myfile.open("stat.txt");
    for (int i = 0; i < 1000000; ++i) {
        double h = nv(g);
        myfile << h << endl;
        s += h;
        if (h > 1){
            getuerkte_NV += h;
        }
    }
    myfile.close();

    cout << s << endl;
    cout  << getuerkte_NV << endl;

    return 0;
}
