#include <ctime>
#include <iostream>
#include <string>
#include "hash_map.h"
using namespace std;

int main() {
    HashMap<string, int> randomHashMap;
    srand(time(nullptr));
    for (char c = 'a'; c <= 'z'; c++) {
        int randNumber = rand();
        string s(1, c);
        cout << "Number putting in " << c << ": " << randNumber << endl;
        randomHashMap.put(s, randNumber);
    }
    for (char c = 'a'; c <= 'z'; c++) {
        string s(1, c);
        cout << "Printing number in HashMap " << c << ": ";
        cout << randomHashMap.get(s) << endl;
    }
    return 0;
}