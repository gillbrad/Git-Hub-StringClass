#include "stringclass.h"

//  Copy Constructor for StringClass
StringClass::StringClass( const StringClass &source ) : strSize{source.strSize}, cap{source.cap}
{
    str = new char[cap];
    std::strcpy( str, source.str );
}

//  Move Constructor for StringClass
StringClass::StringClass( StringClass &&moveSC ) : str{moveSC.str}, strSize{moveSC.strSize}, cap{moveSC.cap}    
{
    moveSC.str = nullptr;
}

// No args constructor for StringClass
StringClass::StringClass( ) : strSize{0}, cap{STR_INC} 
{
    std::cout << "no args constructor" << std::endl;
    str = new char[cap];
    *str = '\0';
}

// Single arg (char *) constructor for StringClass
StringClass::StringClass( const char *newStr ) : strSize{strlen(newStr)}, cap{( ( strSize / STR_INC ) + 1 ) * STR_INC}
{
    str = new char[cap];
    std::strcpy( str, newStr );
}

// StringClass Destructor
StringClass::~StringClass( )
{
    std::cout << "StringClass distructor" << std::endl;
    delete[] str;
}

//  StringClass Method clear
//      Will delete string and allocate new string
//      Will set string to empty string
//      Will init strSize and cap
void StringClass::clear( ) 
{
    cap = STR_INC; 
    strSize = 0; 
    delete[] str;
    str = new char[cap];
    *str = '\0';
}

//  StringClass Method print_string
//      Will print out string pointed to by
//      Private member str
//          if string is empty will print
//          empty string 
void StringClass::print_string( ) const 
{ 
    std::cout << "print string" << std::endl;
    if ( strSize == 0 || str == nullptr )
    {
        std::cout << "empty string" << std::endl;
        return;
    }
    std::cout << str << std::endl; 
}

//  StringClass Method append
//  Will append new string to string pointed to by str
void StringClass::append( char *newStr )
{ 
    std::cout << "\n**Append** " << newStr << std::endl;
    size_t length = std::strlen( newStr );
    if ( ( length + strSize  ) >= cap )
    {
        cap = ( ( ( length + strSize + 1 ) / STR_INC ) + 1 ) * STR_INC;
        char *tempStr = new char[cap];
        std::strcpy( tempStr, str );
        delete[] str;
        str = tempStr;
    }
    std::strcpy(&str[strSize], newStr ); 
    strSize+=length;
    std::cout << "\nappend complete\n" << std::endl;
}

void print_stringclass_data( StringClass s )
{
    std::cout << "size = " << s.size( ) << std::endl;
    std::cout << "capacity = " << s.capacity( ) << std::endl;
    s.print_string( );
}

