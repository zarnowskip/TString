#ifndef OPERATORY_H
#define OPERATORY_H
#include<iostream>
#include<fstream>
class TString;

    friend std::ostream& std::ostream& operator<<(std::ostream& strumien, const TString& s);
    friend std::istream& operator>>(std::istream& strumien, TString& s);

#endif