//
//  Game.cpp
//  Snake
//
//  Created by Suliman Alsaid on 3/6/19.
//  Copyright © 2019 Suliman Alsaid. All rights reserved.
//

#include "Game.hpp"


Game::Game(): s(), clock(), win(sf::VideoMode(640, 480), "Snake"){
    alive = true;
    grow = false;
    
    win.setFramerateLimit(60);
}

void Game::run() {
    clock.restart();
    while(alive) {
        input();
        update();
        draw();
    }
}

void Game::input() { 
    sf::Event e;
    while(win.pollEvent(e)) {
        if(e.type == sf::Event::Closed)
            alive = false;
        if(e.type == sf::Event::KeyReleased) {
            if(e.key.code == sf::Keyboard::Enter) {
                grow = true;
            }
        }
        
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        s.setDirection(Snake::Up);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        s.setDirection(Snake::Down);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        s.setDirection(Snake::Left);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        s.setDirection(Snake::Right);
    }
}

void Game::update() {
    if(s.collided()) {
        alive = false;
    } else {
    if(clock.getElapsedTime().asMilliseconds() >= 200) {
        s.moveSnake();
        clock.restart();
    }
    
    if(grow) {
        s.growSnake();
        grow = false;
    }
    }
    
}

void Game::draw() {
    win.clear();
    s.drawSnake(win);
    win.display();
    
}
