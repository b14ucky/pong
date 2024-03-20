#pragma once

#include <random>

class RandomNumberGenerator
{
private:
    std::mt19937 gen;
    std::uniform_int_distribution<unsigned> dist;

public:
    RandomNumberGenerator();
    RandomNumberGenerator(size_t min, size_t max);

    size_t operator()();
};