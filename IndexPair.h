#include <string>
using namespace std;

#ifndef IndexPair_h
#define IndexPair_h

class IndexPair {

private:
    int first;
    int second;

public:
    
    IndexPair(int _first, int _second) {
        first = _first;
        second = _second;
    }

    void setFirst(int in) {
        first = in;
    }
    void setSecond(int in) {
        second = in;
    }
    int getFirst() {
        return first;
    }
    int getSecond() {
        return second;
    }
    void printOut() {
        cout << "<" << first << ", " << second << ">";
    }

};

#endif