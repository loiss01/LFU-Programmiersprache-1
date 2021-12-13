//  Alois Stöckl - Hü 9 - Aufgabe 4

#include "iostream"

using namespace std;


auto hide_chars(int from, int to) {
    return [=](auto& x) -> void{
        for (int i = from; i <= to; ++i) {
            if (x==i){
                x =  (char) 63;
            }
        }
    };
}

/**
 * <b>Apply lambda which i could NOT fetch from lecture to du server outage!</b>
 * So i made my one!
 *
 * @param lamb lamb is the function you want to apply
 * @param in inbut Object to use
 */
auto apply = [](auto lamb, auto in){
    for_each(begin(in), end(in), lamb);
    cout << in << endl;
};

int main(){

    string ich = "Alois Stoeckl 12111607";

    apply(hide_chars(int('0'), int('9')), ich);
    apply(hide_chars(int('A'), int('Z')), ich);
    apply(hide_chars(int('a'), int('z')), ich);
    apply(hide_chars(0, 0), ich);
    apply(hide_chars(0, 100000), ich);
    return 0;
}
