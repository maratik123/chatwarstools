#include "randomholder.h"

RandomHolder::RandomHolder() :
    _mainEngine(randomDevice())
{
}

RandomHolder &RandomHolder::getInstance()
{
    static RandomHolder instance;
    return instance;
}
