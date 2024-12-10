#include "die.h"

int Die::roll()
{
   int result = std::rand() % sides + 1;
   return result;
}