//  Alois Stöckl - Hü 9 - Aufgabe 3

#include "iostream"
#include "cctype"

using namespace std;

auto capitalize = [](auto& i) -> void {
    i = (char) i;
    i = toupper(i);
    //    string out;
//    for (char i : stg) {
//        if (islower(i)){
//            out = out + (char) toupper(i);
//        }else{
//            out = out + i;
//        }
//    }
//    return out;
};

auto noDigit = [](auto& i) -> void {
    i = (char) i;
    if (isdigit(i)){
        i = (char) 63;
    }
};


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

    string ich = "Alois Stöckl 12111607";

    apply(capitalize, ich);

    apply(noDigit, ich);


    return 0;
}
