#include "LinkedList.hpp"
#include <string>

int main() {

    LinkedList<string> list;

    //using append
    list.append("It");
    list.append("can't");
    list.append("come");
    list.append("quickly");
    list.append("enough");

    //replace valid
    try {
        list.replace(1, "can");
    }
    catch( string &e ) {
        cerr << e << endl;
    }

    //replace invalid
    try {
        list.replace(100, "hello");
    }
    catch(string &e) {
        cerr << e << endl;
    }

    cout << list;

    cout << endl;

    //insert valid
    try {
        list.insert(1, "really");
    }
    catch(string &e) {
        cerr << e << endl;
    }

    //insert invalid
    try {
        list.insert(-1, "null");
    }
    catch(string &e) {
        cerr << e << endl;
    }

    cout << list;

    cout << endl;

    //remove valid
    try {
        list.remove(5);
    }
    catch(string &e) {
        cerr << e << endl;
    }

    //remove invalid
    try {
        list.remove(10);
    }
    catch(string &e) {
        cerr << e << endl;
    }

    cout << list;

    cout << endl;

    //copy
    LinkedList<string> second;

    second = list;

    cout << second;

    cout << endl;

    

}