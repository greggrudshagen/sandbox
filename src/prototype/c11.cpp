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
        FizzBuzz(int32_t const start, int32_t const finish) : begin(start), end(finish)
        {
            
        }
        
        int32_t ByMask()
        {
            std::cout << ClassName() << "::" << __FUNCTION__ << ":[" << __LINE__ << "]" << std::endl;

            int32_t const rc = 0;

            uint32_t const NONE     = 0;
            uint32_t const FIZZ     = 1;
            uint32_t const BUZZ     = 2;
            uint32_t const FIZZBUZZ = 3;

            for (int32_t i = begin; i < end; i++)
            {
                uint32_t mask = 0;

                mask |= ((i % 3) == 0 ? FIZZ : 0x0);
                mask |= ((i % 5) == 0 ? BUZZ : 0x0);

                switch (mask)
                {
                    case NONE:
                        std::cout << "i = " << i << std::endl;
                        break;
                    case FIZZ:
                        std::cout << FizzName() << std::endl;
                        break;
                    case BUZZ:
                        std::cout << BuzzName() << std::endl;
                        break;
                    case FIZZBUZZ:
                        std::cout << FizzName() << BuzzName() << std::endl;
                        break;
                    default:
                        break;
                } // switch
            } // for
            
            return rc;
        } // ByMask

        int32_t ByString()
        {
            std::cout << ClassName() << "::" << __FUNCTION__ << ":[" << __LINE__ << "]" << std::endl;

            int32_t const rc = 0;
            std::ostringstream oss;
            for (int32_t i = begin; i < end; i++)
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
            
            return rc;
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

        int32_t const begin;
        int32_t const end;
}; // FizzBuzz

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
        static const int32_t sec_per_min = 60;

        std::string hello;

        //Object(Object const&);                // Disable Copy constructor
        //Object& operator=(Object const&);     // Disable Assignment operator
}; // Object

void PassByPointer( FizzBuzz *fb)
{
    std::cout << __FUNCTION__ << ":[" << __LINE__ << "]" << std::endl;

    fb->ByMask();
    std::cout << __FUNCTION__ << ":[" << __LINE__ << "]" << std::endl;
}

void PassByReference( FizzBuzz &fb)
{
    std::cout << __FUNCTION__ << ":[" << __LINE__ << "]" << std::endl;

    fb.ByString();
    std::cout << __FUNCTION__ << ":[" << __LINE__ << "]" << std::endl;
}


int32_t main()
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
#if 1
        { // C++14
            std::cout << "C++14" << std::endl;
            auto fb = std::make_unique<FizzBuzz>(1, 16);
            fb->ByString();
            if (fb.get())
            {
                PassByPointer(fb.get());    // pass raw pointer to object FizzBuzz.
                PassByReference(*fb.get()); // pass raw reference to object FizzBuzz.
            }
        }
#endif
    }
    return 0;
} // main
