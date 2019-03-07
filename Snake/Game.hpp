//
//  Game.hpp
//  Snake
//
//  Created by Suliman Alsaid on 3/6/19.
//  Copyright © 2019 Suliman Alsaid. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "Snake.hpp"

class Game {
public:
    Game();
    void run();
    void input();
    void update();
    void draw();
    
private:
    sf::RenderWindow win;
    Snake s;
    sf::Clock clock;
    bool alive;
    bool grow;
};
#endif /* Game_hpp */
