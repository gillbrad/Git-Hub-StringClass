
#include <iostream>
#include <string>
#include "stringclass.h"


int main( [[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
    
    

    try {
        //char str[] {"hello world"};
        //StringClass s(str);
        StringClass s("hello world");
        StringClass s2;
        
        print_stringclass_data(s);

        s2 = s;
        std::cout << "\n**Print s2**" << std::endl;
        print_stringclass_data(s2);
        char str2[] {"!!"};
        char str3[] {"$$"};
        char str4[] {" goodbye world"};
        char str5[] {" the end"};
        StringClass s3(str4);
        StringClass s4(str5);
        StringClass s5 = s3 + s4;
        std::cout << "\nPrint s5 = s3 + s4" << std::endl;
        s5.print_string( );

        s.append(str2);
        print_stringclass_data(s);

        s.append(str3);
        std::cout << "print s3" << std::endl;
        print_stringclass_data(s);

        s.append(str4);
        std::cout << "print s4" << std::endl;
        //print_stringclass_data(s);
        
        s.append(str5);
        std::cout << "print s5" << std::endl;
        print_stringclass_data(s);
        
        
        //print_stringclass_data(s2);
        std::cout << "main completed" << std::endl;
    }
    
    catch(...) {
        std::cout << "Unexpected Exception" << std::endl;
        // Unexpected Exception exit with error condition 3
        exit(3);   
    }


    return 0;
}
