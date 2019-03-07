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
        if(clock.getElapsedTime().asMilliseconds() > 200) {
            s.moveSnake();
            clock.restart();
        }
        
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        s.setDirection(Snake::Down);
        if(clock.getElapsedTime().asMilliseconds() > 200) {
            s.moveSnake();
            clock.restart();
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        s.setDirection(Snake::Left);
        if(clock.getElapsedTime().asMilliseconds() > 200) {
            s.moveSnake();
            clock.restart();
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        s.setDirection(Snake::Right);
        if(clock.getElapsedTime().asMilliseconds() > 200) {
            s.moveSnake();
            clock.restart();
        }
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
    
        if(p.collision(s.getHeadPosition())) {
            s.growSnake();
            p.generatePellet();
            while(s.pelletSnake(p.getPellet().getPosition())) {
                p.generatePellet();
            }
        }
    }
    
}

void Game::draw() {
    win.clear();
    s.drawSnake(win);
    win.draw(p.getPellet());
    win.display();
    
}
