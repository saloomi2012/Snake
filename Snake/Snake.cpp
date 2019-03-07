//
//  Snake.cpp
//  Snake
//
//  Created by Suliman Alsaid on 3/6/19.
//  Copyright © 2019 Suliman Alsaid. All rights reserved.
//

#include "Snake.hpp"
#include <iostream>


Snake::Snake() {
    sf::RectangleShape initial;
    initial.setSize({32, 32});
    initial.setPosition(0, 0);
    initial.setFillColor(sf::Color::Green);
    dir = Snake::Right;
    body.push_back(initial);
    deathSound.loadFromFile(resourcePath() + "death.wav");
    death.setBuffer(deathSound);
}

bool Snake::collided() {
    for(int i = 2; i < body.size(); i++) {
        if(body[i].getPosition() == body[0].getPosition()) {
            death.play();
            sf::sleep(sf::milliseconds(1052));
            return true;
        }
    }
    return false;
}

sf::Vector2f Snake::getHeadPosition() { 
    return body[0].getPosition();
}

void Snake::drawSnake(sf::RenderWindow &win) { 
    for(sf::RectangleShape s: body)
        win.draw(s);
}

void Snake::setDirection(Snake::Direction d) {
    dir = d;
}

void Snake::growSnake() {
    sf::RectangleShape rec = body[body.size()-1];
    if(body.size() > 1) {
        std::cout << ">1 Ran" << std::endl;
        body.push_back(rec);
    } else {
        switch(dir) {
            case Up:
                rec.setPosition(getHeadPosition().x, getHeadPosition().y +32);
                break;
            case Down:
                rec.setPosition(getHeadPosition().x, getHeadPosition().y - 32);
                break;
            case Left:
                rec.setPosition(getHeadPosition().x + 32, getHeadPosition().y);
                break;
            case Right:
                rec.setPosition(getHeadPosition().x - 32, getHeadPosition().y);
                break;
        }
        
        body.push_back(rec);
        
        std::cout << "1 Ran" << std::endl;
    }
    
}

void Snake::moveSnake() {
    sf::Vector2f prevPos = getHeadPosition();
    bool headMoved = false;
    switch(dir) {
        case Up:
            if(getHeadPosition().y - 32 >= 0) {
                body[0].setPosition(getHeadPosition().x , getHeadPosition().y - 32);
            }
            headMoved = true;
            break;
        case Down:
            if(getHeadPosition().y + 32 < 480) {
                body[0].setPosition(getHeadPosition().x, getHeadPosition().y + 32);
            }
            headMoved = true;
            break;
        case Left:
            if(getHeadPosition().x - 32 >= 0) {
                body[0].setPosition(getHeadPosition().x - 32, getHeadPosition().y);
            }
            headMoved = true;
            break;
        case Right:
            if(getHeadPosition().x + 32 < 640) {
                body[0].setPosition(getHeadPosition().x + 32, getHeadPosition().y);
            }
            headMoved = true;
            break;
    }
    
    if(headMoved) {
    for(int i = 1; i < body.size(); i++) {
        sf::Vector2f temp = body[i].getPosition();
        body[i].setPosition(prevPos);
        prevPos = temp;
        
    }
    }
    
    std::cout << "Body size: " << body.size()<< std::endl;
}
