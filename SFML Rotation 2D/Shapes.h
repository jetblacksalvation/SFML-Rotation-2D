#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
/*
	Initialize shape data here vvvv

	Concept --
	THIS CLASS WILL BE USED ONLY TO UPDATE POSITION


	I will create a class that has both Real and Virtual points in them
	Why? because in rotations, you dont want to overright the Real data, so you do the transformation and give them to 
	Virtual. I will create a variable that takes the origin/what you rotate around(player), distance, the real postition.  

*/


class vertex {
	sf::Vector2f real_pos;
	sf::Vector2f virtual_pos; 
	//origin/what you rotate around
	sf::Vector2f origin; 


	void update(sf::RenderWindow& window) {
		


	}

};



