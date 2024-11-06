// Copyright 2024 Wilson Van

#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main(int argc, char* argv[]) {
    sf::Image input;
    sf::Image encrypted;
    sf::Image decrypted;
    std::string seed = argv[3];
    sf::Texture t1;
    sf::Sprite s1;
    sf::Texture t2;
    sf::Sprite s2;
    sf::Texture t3;
    sf::Sprite s3;
    sf::Texture t4;
    sf::Sprite s4;
    PhotoMagic::FibLFSR encryption_seed(seed);
    PhotoMagic::FibLFSR decryption_seed(seed);
    if (!input.loadFromFile(argv[1]))
        return -1;
    if (!encrypted.loadFromFile(argv[1]))
        return -1;
    t1.loadFromImage(input);
    s1.setTexture(t1);
    PhotoMagic::transform(encrypted, &encryption_seed);
    encrypted.saveToFile(argv[2]);
    t2.loadFromImage(encrypted);
    s2.setTexture(t2);
    t3.loadFromImage(encrypted);
    s3.setTexture(t3);
    decrypted.loadFromFile(argv[2]);
    PhotoMagic::transform(decrypted, &decryption_seed);
    t4.loadFromImage(decrypted);
    s4.setTexture(t4);
    s2.move(encrypted.getSize().x, 0);
    s4.move(decrypted.getSize().x, 0);
    sf::Vector2u size = input.getSize();
    sf::RenderWindow window1(sf::VideoMode(size.x * 2, size.y), "encrypting");
    sf::RenderWindow window2(sf::VideoMode(size.x * 2, size.y), "decrypting");
    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window2.close();
        }
        window1.clear();
        window1.draw(s1);
        window1.draw(s2);
        window1.display();
        window2.clear();
        window2.draw(s3);
        window2.draw(s4);
        window2.display();
    }
    return 0;
}
