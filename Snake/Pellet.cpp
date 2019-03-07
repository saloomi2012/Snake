//
//  Pellet.cpp
//  Snake
//
//  Created by Suliman Alsaid on 3/7/19.
//  Copyright © 2019 Suliman Alsaid. All rights reserved.
//

#include "Pellet.hpp"
#include "ResourcePath.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>


Pellet::Pellet(): pel({32, 32}) {
    eatenSound.loadFromFile(resourcePath() + "eat.wav");
    eaten.setBuffer(eatenSound);
    pel.setFillColor(sf::Color::Red);
    generatePellet();
    
}

bool Pellet::collision(sf::Vector2f snakeHead) { 
    if(snakeHead == pel.getPosition()) {
        eaten.play();
        return true;
    }
    
    return false;
}

void Pellet::generatePellet() {
    
    int rows =  640 / 32;
    int columns = 480 / 32;
    
    srand(time(0));
    
    int x = (rand() % rows) * 32 ;
    int y = (rand() % columns) * 32;
    pel.setPosition(x, y);
    
}

sf::RectangleShape &Pellet::getPellet() { 
    return pel;
}
