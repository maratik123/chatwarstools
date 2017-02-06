#ifndef RANDOMHOLDER_H
#define RANDOMHOLDER_H

#include <random>

class RandomHolder
{
public:
    using MainEngineType = std::mt19937_64;

    static RandomHolder& getInstance();

    RandomHolder(const RandomHolder& c) = delete;
    void operator=(const RandomHolder& c) = delete;
    MainEngineType &mainEngine() { return _mainEngine; }

private:
    RandomHolder();
    std::seed_seq seq;
    MainEngineType _mainEngine;
};

#endif // RANDOMHOLDER_H
