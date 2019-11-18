#include "operatory.h"
#include "tstring.h"
#include <string>
using namespace std;

std::ostream& operator<<(std::ostream& strumien, const TString& s) {
    return strumien << (s.ptr ? s.ptr : "pusty");
}

std::istream& operator>>(std::istream& strumien, TString& s) {
    string tmp;
    getline(strumien,tmp);
    delete [] s.ptr; //usunac stara zawartosc
    s.len = tmp.size();
    if (s.len > 0) {
        s.ptr = new char[s.len+1];
        strcpy(s.ptr,tmp.c_str()); //c_str() zwraca const char*
    } else {
        s.ptr = nullptr;
    }
    return strumien;
}

