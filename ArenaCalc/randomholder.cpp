#include "randomholder.h"

#include <chrono>

namespace {
using seq_init_t = std::chrono::system_clock::rep;
}

RandomHolder::RandomHolder() :
    seq({
        static_cast<seq_init_t>(std::random_device()()),
        std::chrono::system_clock::now().time_since_epoch().count()
        }),
    _mainEngine(seq)
{}

RandomHolder &RandomHolder::getInstance()
{
    static RandomHolder instance;
    return instance;
}
