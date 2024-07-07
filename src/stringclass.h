#ifndef STRINGCLASS_H
#define STRINGCLASS_H
#include <cstring>
#include <iostream>

#define STR_INC 10   // BAD
const int strInc = 10; // medium
constexpr int strInc = 10;  // better

class StringClass {
    static constexpr int strInc = 10; // best
    static const int strInc = 10; // pretty good 

    private:
        char *str;
        size_t strSize;
        size_t cap;
    public:
        // Constructors
        StringClass( const StringClass &source );
        StringClass( StringClass &&moveSC );
        StringClass( );
        StringClass( const char *newStr );
        // Destructors
        ~StringClass( );
        // Methods
        int size( ) const { return strSize; }
        int capacity( ) const { return cap; }
        void print_string( ) const;
        char* c_str( ) const { return str; } 
        void clear( );
        void append( char *str );
        // Operator overloads
        StringClass& operator= ( const StringClass &rStr)
        {
            if( this != &rStr ) {
                delete[] str;
                str = new char[rStr.capacity()];
                std::strcpy(str, rStr.str);
                cap = rStr.capacity();
                strSize = rStr.size();
            }
            return *this; 
        }

        StringClass operator+ ( const StringClass &rStr )
        {
            StringClass tempStrClass( c_str( ) ); 
            tempStrClass.append(rStr.c_str( ) );
            return tempStrClass;  
        }
        /*
        StringClass& operator+=( const StringClass &other)
        {
            //   std::string s{"hello"}
            //   
        }*/
        // A c_str() function like std::string has.
};
/*
void old_c_function( char* str )
{
    printf("%s\n", str)
}

void brads_function()
{
    std::string s{"hello"};
    s += " world!";

    old_c_function(  somehow get my 's' string passed in  );
}
*/
void print_stringclass_data( StringClass s );

#endif // #ifndef STRINGCLASS_H