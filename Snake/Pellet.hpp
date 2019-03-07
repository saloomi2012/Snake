//
//  Pellet.hpp
//  Snake
//
//  Created by Suliman Alsaid on 3/7/19.
//  Copyright © 2019 Suliman Alsaid. All rights reserved.
//

#ifndef Pellet_hpp
#define Pellet_hpp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Pellet  {
public:
    Pellet();
    bool collision(sf::Vector2f snakeHead);
    void generatePellet();
    sf::RectangleShape& getPellet();
    
private:
    sf::RectangleShape pel;
    sf::SoundBuffer eatenSound;
    sf::Sound eaten;
    
    
    
};

#endif /* Pellet_hpp */
