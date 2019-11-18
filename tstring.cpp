#include <iostream>
#include <stdexcept>
#include "tstring.h"
using namespace std;

TString::TString(const char* s) {
    if ( s != nullptr ) {
        len = strlen(s);
        ptr = new char[len+1]; // \0 też się musi zmieścić
        strcpy(ptr,s);
    }
    #ifdef DEBUG
        cout << "TString c-tor " << len << " - " << (ptr?ptr:"pusty") << endl;
    #endif
}

TString::~TString() {
    #ifdef DEBUG
        cout << "TString d-tor " << len << " - " << (ptr?ptr:"pusty") << endl;
    #endif
    delete [] ptr;
}

TString::TString(const TString& s) : len(s.len) {
    if (len>0) {
        ptr = new char[len+1];
        strcpy(ptr,s.ptr);
    }
    #ifdef DEBUG
        cout << "TString cc-tor " << len << " - " << (ptr?ptr:"pusty") << endl;
    #endif
}

TString& TString::operator=(const TString& s) {
    if ( this != &s ) { // if ( *this != s )
        delete [] ptr;
        ptr = nullptr;
        len = s.len;
        if (len>0) {
            ptr = new char[len+1];
            strcpy(ptr,s.ptr);
        }
    }
    #ifdef DEBUG
        cout << "TString copy operator= " << len << " - " << (ptr?ptr:"pusty") << endl;
    #endif    
    return *this;
}

TString::TString(TString&& s) : ptr(s.ptr), len(s.len) {
    s.ptr = nullptr;
    s.len = 0;
    #ifdef DEBUG
        cout << "TString mvc-tor " << len << " - " << (ptr?ptr:"pusty") << endl;
    #endif
}

TString& TString::operator=(TString&& s) {
    if ( this != &s ) {
        delete [] ptr;
        ptr = s.ptr;
        len = s.len;
        s.ptr = nullptr;
        s.len = 0;
    }
    #ifdef DEBUG
        cout << "TString move operator= " << len << " - " << (ptr?ptr:"pusty") << endl;
    #endif    
    return *this;
}

char& TString::operator[](size_t n) {
    if (!ptr) throw "pusty obiekt";
    if ( n < len ) return ptr[n];
    throw out_of_range("W klasie TString argument operatora[] poza zakresem");
}

const char& TString::operator[](size_t n) const {
    if (!ptr) throw "pusty obiekt";
    if ( n < len ) return ptr[n];
    throw out_of_range("W klasie TString argument operatora[] poza zakresem");
}

char* TString::insert(size_t pos, const char* c) {
    if (pos <= len) {
        size_t oldlen = len;
        len = len + strlen(c);
        char* tmp = new char[len+1];
        strcpy(tmp,ptr);
        for (size_t i=pos; i<pos+strlen(c); ++i) {
            tmp[i] = c[i-pos];
        }
        for (size_t i=pos; i<oldlen; ++i) {
            tmp[i+strlen(c)] = ptr[i];
        }
        delete [] ptr;
        ptr = tmp;
        return ptr+pos;
    } else {
        throw out_of_range("zly argument");
    }
    return ptr;
}