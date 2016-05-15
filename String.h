#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <iostream>
using namespace std ;
namespace name{enum enumration{left,right,Justify};}


class String
{
private :

    char * arr ;
    int SIZE=0;

public :
    void setarr(char*);
    void setSIZE(int);
    char* getarr();
    int getsize();
    String ();
    int str_length();
    int Find (String);
    bool Isempty () ;
    String replacing(String,String);
    void ToLower();
    void ToUpper();
    String append(String);
    String substring(int , int);
    void showjustify(name::enumration);
    void Reverse();
    void Erase(int ,int);
    int Compare(String);
    char getat (int) ;
    ~String() ;


    friend istream &operator >> (istream & in , String &x) ;
    friend ostream &operator << (ostream & out , String &x );


    friend void Sort (String * arr , int x) ;
    friend void Swap (String &z , String &s) ;


    void operator = (const String &x);
    void operator = (const char *x);

};

#endif // STRING_H_INCLUDED
