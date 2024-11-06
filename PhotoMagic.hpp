// Copyright 2024 Wilson Van

#ifndef PHOTOMAGIC_H
#define PHOTOMAGIC_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"

namespace PhotoMagic {

    // Transforms image using FibLFSR
    void transform(sf::Image&, PhotoMagic::FibLFSR*);
    // Display an encrypted copy of the picture, using the LFSR to do the encryption
}

#endif
