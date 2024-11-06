// Copyright 2024 Wilson Van

#include "PhotoMagic.hpp"

void PhotoMagic::transform(sf::Image& image, PhotoMagic::FibLFSR* seed) {
    sf::Vector2u size = image.getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;
    unsigned int random_eight_bit;
    sf::Color pixel;
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            pixel = image.getPixel(x, y);
        random_eight_bit = seed->generate(8);
            pixel.r = pixel.r ^ random_eight_bit;
            random_eight_bit = seed->generate(8);
            pixel.g = pixel.g ^ random_eight_bit;
            random_eight_bit = seed->generate(8);
            pixel.b = pixel.b ^ random_eight_bit;
            image.setPixel(x, y, pixel);
        }
    }
}
