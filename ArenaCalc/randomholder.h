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
    MainEngineType _mainEngine;
    std::random_device randomDevice;
};

#endif // RANDOMHOLDER_H
