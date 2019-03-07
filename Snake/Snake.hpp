//
//  Snake.hpp
//  Snake
//
//  Created by Suliman Alsaid on 3/6/19.
//  Copyright © 2019 Suliman Alsaid. All rights reserved.
//

#ifndef Snake_hpp
#define Snake_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "ResourcePath.hpp"




class Snake {
    
    
public:
    enum Direction {
        Up, Down, Left, Right
    };
    
   
    
    Snake();
    bool collided();
    sf::Vector2f getHeadPosition();
    void drawSnake(sf::RenderWindow& win);
    void setDirection(Snake::Direction d);
    void growSnake();
    void moveSnake();
    bool pelletSnake(sf::Vector2f pellet);
  
    
private:
    std::vector<sf::RectangleShape> body;
    sf::SoundBuffer deathSound;
    sf::Sound death;
    Snake::Direction dir;
};

#endif /* Snake_hpp */
