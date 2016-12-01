#ifndef TORNADO_EXCEPTION_H
#define TORNADO_EXCEPTION_H
#include <string>
using namespace std;

class tornadoException {
    public:
        string what() const;
        tornadoException(int m);
        tornadoException();
    private:
        string err;
};

#endif