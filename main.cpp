#include <iostream>
#include "tstring.h"
using namespace std;

auto fun(const char* s) {
    return TString(s);
}

int main() {
    TString s1;
    TString s2("dzien dobry");
    TString s3 = move(s2);
    s1 = fun("drugi obiekt");   // move(s3);
    for ( auto& c : s1 ) cout << (c=toupper(c)) << "-";
    cout << endl;
    for ( auto c : s1 ) cout << c << "=";
    cout << endl;
    for ( size_t i = 0; i < s1.size(); ++i ) cout << s1[i] << "#";
    cout << endl;
    cout << "----------------" << endl;
}