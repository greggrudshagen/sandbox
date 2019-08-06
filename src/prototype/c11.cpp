/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <memory>
#include <sstream>
#include <string>


class FizzBuzz
{
    public:
        FizzBuzz(int const start, int const finish) : begin(start), end(finish)
        {
            
        }
        
        int Walk()
        {
        
            return 0;
        }
        
        int Display()
        {
            
            return 0;
        }
    protected:
    private:
        int begin;
        int end;
};

class Object
{
    public:
        char const * ClassName() const
        {
            return "Object";
        }

        Object() : hello{"Hello"}
        {
        }

        Object(Object const&) = delete;                 // Disable Copy constructor
        Object& operator=(Object const&) = delete;      // Disable Assignment operator
        
    protected:

    private:
        static const int sec_per_min = 60;

        std::string hello;

        //Object(Object const&);                // Disable Copy constructor
        //Object& operator=(Object const&);     // Disable Assignment operator
}; // Object


int FizzBuzz(int const begin, int const end);

int main()
{
    std::cout << "Hello World" << std::endl;

    {
        {
            Object obj;
            std::cout << obj.ClassName() << std::endl;
        }

        { // C++11
            std::unique_ptr<Object> obj(new Object);
            std::cout << obj->ClassName() << std::endl;
        }

#if 0
        { // C++14
            auto obj = std::make_unique<Object>();
            std::cout << obj->ClassName() << std::endl;
        }
#endif
    }

    { // Fizz Buzz routine
        int const rc = FizzBuzz(1, 16);
        if (rc != 0)
        {
            std::cout << "FizzBuzz Error!" << std::endl;
        }
    } // Fizz Buzz routine

    return 0;
} // main



int FizzBuzz(int const begin, int const end)
{
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
 
    int const rc = 0;   
    std::ostringstream oss;
    for (int i = begin; i < end; i++)
    {
        oss.str(""); // empty string
        oss.clear(); // reset error flags
        
        if (i % 3 == 0)
        {
            oss << "Fizz";
        }
        if (i % 5 == 0)
        {
            oss << "Buzz";
        }
        if (oss.str().empty())
        {
           oss << "i = " << i; 
        }
        
        std::cout << oss.str() << std::endl; 
    } // for
    
    return rc;
}
