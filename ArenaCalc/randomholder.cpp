#include "randomholder.h"

#include <chrono>

RandomHolder::RandomHolder() :
    seq({
        static_cast<long>(std::random_device()()),
        std::chrono::system_clock::now().time_since_epoch().count()
        }),
    _mainEngine(seq)
{}

RandomHolder &RandomHolder::getInstance()
{
    static RandomHolder instance;
    return instance;
}
