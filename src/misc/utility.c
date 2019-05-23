#include <utility.h>


int IsEven(unsigned int const v)
{
    return ((v & 0x01) ? 0 : 1);
}


// EOF
