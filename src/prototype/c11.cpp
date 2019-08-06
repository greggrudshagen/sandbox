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
        
        int ByMask()
        {
            std::cout << ClassName() << "::" << __FUNCTION__ << ":[" << __LINE__ << "]" << std::endl;

            int const rc = 0;   
            for (int i = begin; i < end; i++)
            {
                uint32_t mask = 0;

                mask |= ((i % 3) == 0 ? 0x01 : 0x0);
                mask |= ((i % 5) == 0 ? 0x02 : 0x0);

                switch (mask)
                {
                    case 0:
                        std::cout << "i = " << i << std::endl;
                        break;
                    case 1:
                        std::cout << FizzName() << std::endl;
                        break;
                    case 2:
                        std::cout << BuzzName() << std::endl;
                        break;
                    case 3:
                        std::cout << FizzName() << BuzzName() << std::endl;
                        break;
                    default:
                        break;
                } // switch
            } // for
            
            return 0;
        } // ByMask

        int ByString()
        {
            std::cout << ClassName() << "::" << __FUNCTION__ << ":[" << __LINE__ << "]" << std::endl;

            int const rc = 0;   
            std::ostringstream oss;
            for (int i = begin; i < end; i++)
            {
                oss.str(""); // empty string
                oss.clear(); // reset error flags
                
                if (i % 3 == 0)
                {
                    oss << FizzName();
                }
                if (i % 5 == 0)
                {
                    oss << BuzzName();
                }
                if (oss.str().empty())
                {
                   oss << "i = " << i; 
                }
                
                std::cout << oss.str() << std::endl; 
            } // for
            
            return 0;
        } // ByString

    protected:

    private:
        char const * FizzName() const
        {
            return "Fizz";
        }

        char const * BuzzName() const
        {
            return "Buzz";
        }

        char const * ClassName() const
        {
            return "FizzBuzz";
        }

        int const begin;
        int const end;
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
        {
            FizzBuzz fb(1, 16);
            fb.ByString();
        }

        {
            std::unique_ptr<FizzBuzz> fb(new FizzBuzz(1, 16));
            fb->ByMask();
        }
#if 0
        { // C++14
            auto fb = std::make_unique<FizzBuzz>(1, 16);
            fb->ByString();
        }
#endif
    }


    return 0;
} // main
