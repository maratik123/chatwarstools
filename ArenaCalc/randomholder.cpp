#include "randomholder.h"

#include <chrono>

RandomHolder::RandomHolder() :
    _mainEngine(std::chrono::system_clock::now().time_since_epoch().count())
{}

RandomHolder &RandomHolder::getInstance()
{
    static RandomHolder instance;
    return instance;
}
