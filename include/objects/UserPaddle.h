#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "Paddle.h"

class UserPaddle : public Paddle
{
public:
    // constructor
    UserPaddle();

    // methods
    void handleMovement(float windowSizeY) override;
};