// SFML Rotation 2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>    
constexpr double pi = 3.14159265359;
bool keys[] = { false, false, false, false, false ,false }; //array to hold keyboard input\

enum DIRECTIONS { LEFT, RIGHT, UP, DOWN }; //left is 0, right is 1, up is 2, down is 3

sf::Vector2f pos{ 500,500 };
sf::Vector2f real{ 550, 550 };
sf::Vector2f real2{ 550, 100 };
sf::Vector2f fake;//doesn't need any initialized variables 
sf::Vector2f fake2;
float angle = 0;// range of 0 - 2pi 

//distance function
float dis(sf::Vector2f p1, sf::Vector2f p2) {

    return sqrtf(
        powf(p1.x - p2.x, 2) + powf(p1.y - p2.y, 2)
    );

}
float tem(sf::Vector2f p1, sf::Vector2f p2) {
    //returns the angle in radians 
    return atan2f(
        p1.y - p2.y, p1.x - p2.x
    );


}

sf::CircleShape player(10);
sf::CircleShape thing(10);
sf::CircleShape thing2(10);
sf::RenderWindow screen(sf::VideoMode(1000, 1000), "pacman"); //set up screen
sf::Event event; //set up event queue
int main()
{
    thing.setFillColor(sf::Color::Red);
    thing2.setFillColor(sf::Color::Blue);
    player.setFillColor(sf::Color::Black);
    std::cout << "Hello World!\n";
    screen.setFramerateLimit(60.0f); //set FPS
    while (screen.isOpen()) {//keep window open until user shuts it down

        while (screen.pollEvent(event)) { //look for events-----------------------

            //this checks if the user has clicked the little "x" button in the top right corner
            if (event.type == sf::Event::EventType::Closed)
                screen.close();
            //KEYBOARD INPUT 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                keys[LEFT] = true;
            }
            else keys[LEFT] = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                keys[RIGHT] = true;
            }
            else keys[RIGHT] = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                keys[UP] = true;
            }
            else keys[UP] = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                keys[DOWN] = true;
            }
            else keys[DOWN] = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                keys[4] = true;
            }
            else keys[4] = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                keys[5] = true;
            }
            else keys[5] = false;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                //circle is drawng from top left, must make centered 

                pos.x = sf::Mouse::getPosition(screen).x;
                pos.y = sf::Mouse::getPosition(screen).y;
                // left click...
            }
            // get global mouse position
            
        }//end event loop---------------------------------------------------------------
        //moves at 5 distance
        //SETTING POSITION
        if (keys[LEFT] == true)
            pos.x += -5;

        else if (keys[RIGHT] == true)
            pos.x += 5;

        if (keys[UP] == true)
            pos.y += -5;

        else if (keys[DOWN] == true)
            pos.y += 5;
        if (keys[4] == true)
            angle -= 0.11;
        else if (keys[5] == true)
            angle += 0.11;
        //add arc tan shit because it's not working right  

        if (angle >= 2 * pi) {
            angle = 0.01f;
        }
        else if (angle < 0) {
            angle = 2 * pi - 0.1f;
        }


        
        fake.x = {cosf(angle + tem(real, pos)) * dis(pos,real) + pos.x};
        fake.y = {sinf(angle + tem(real, pos)) * dis(pos,real) + pos.y };
        
        fake2.x = { cosf(angle+tem(real2, pos)) * dis(pos,real2) + pos.x };
        fake2.y = { sinf(angle + tem(real2, pos)) * dis(pos,real2) + pos.y };
        
        
        player.setPosition(pos);
            //draw stuff here 
        thing.setPosition(fake);
        thing2.setPosition(fake2);

        screen.clear(sf::Color::White);
        screen.draw(thing);
        screen.draw(thing2);
        screen.draw(player);
        screen.display();

    }
        
}
