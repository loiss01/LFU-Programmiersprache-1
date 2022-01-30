#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <random>

using namespace std;

struct Druckjob {
    std::string datei;
    std::string user;
    int seiten;
    bool doppelseitig = true;


    Druckjob(string file, string u, int to){
        datei = file;
        user = u;
        seiten = to;
    }

    friend ostream& operator<<(ostream& os, const Druckjob& dj){
        //Druckjob(User: stix, File: "..." Seiten: 13 doppelseitig)
        os << "Druckjob(User: " << dj.user << ", File: \""
            <<  dj.datei << "\" Seiten: " << dj.seiten << " " << dj.doppelseitig ? "doppelseitig" : "einseitig";
        return os;
    }
};

class Printer {
private:
    std::string name;
    int papier_vorrat;
    int papier_verbraucht;
    int seiten_gedruckt;
    int stoerungen;
    std::vector<Druckjob> log;

public:
    Printer(std::string n){      // sinnvoller Konstruktor fehlt
        name = n;
        papier_vorrat = 1000;
        papier_verbraucht = 0;
        stoerungen = 0;
    }

    void print_log(ostream& os = std::cout) const   // fehlt
    {
    }

    void reload_paper()
    {   papier_vorrat = papier_verbraucht + 1000; }

    void print_job(const Druckjob& pj){

        if (papier_vorrat < ((pj.seiten % 2 == 0 ? pj.seiten / 2: (pj.seiten / 2) + 1) + papier_verbraucht)){
            throw runtime_error(name + ": Kein Papier!");
        }

        cout << papier_verbraucht << endl;

        if (pj.doppelseitig){
            if (pj.seiten % 2 == 0){
                papier_verbraucht = papier_verbraucht + (pj.seiten / 2);
            }else {
                papier_verbraucht += (pj.seiten / 2) + 1;
            }
        }else {
            papier_verbraucht += pj.seiten;
        }
        seiten_gedruckt += pj.seiten;


    }

    friend ostream& operator<<(ostream& os, const Printer& p){
        return os << "Drucker: " << p.name << endl
            << "Seiten gedruckt: " << p.seiten_gedruckt << endl
            << "Papier verbraucht: " << p.papier_verbraucht << endl
            << "Papiervorrat: " << p.papier_vorrat - p.papier_verbraucht << endl
            << "Anzahl Druckjobs: " << p.log.size() << endl
            << "Stoerungen: " << p.stoerungen << endl;
    }
};

////////////////////////////////////////////////////////////////// alles darunter ist ok

Printer lan_printer{"Laserjet"};

void submit_job(const Druckjob& dj)
{
    try {
        lan_printer.print_job(dj);
    }catch(exception& e) {
        cout << e.what() << endl;
        lan_printer.reload_paper();
        lan_printer.print_job(dj);
    }

}

void user(std::string name, int jobs, int from, int to, double p_ds){
    uniform_int_distribution<int> seiten{from, to};
    bernoulli_distribution ds{p_ds};

    for (int i{}; i < jobs; ++i)
        submit_job({"sinnloser Text", name, to-from});
}


int main()
{
    user("jud", 100, 5, 25, 0.1);
    user("steixner", 150, 1, 10, 0.5);
    user("stix", 200, 5, 13, 0.9);
}