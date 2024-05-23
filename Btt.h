#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;
class Button
{
public:
	RectangleShape body_;
	RenderWindow& WorkingWindow_;
	
	Button(RectangleShape body, RenderWindow& WorkingWindow) : body_(body), WorkingWindow_(WorkingWindow)
	{ }


	bool GetState()
	{
		Vector2i mouse_pos = Mouse::getPosition(WorkingWindow_);
		//return (body.getPosition().x <= mouse_pos.x <= body.getPosition().x + body.getSize().x && body.getPosition().y <= mouse_pos.y <= body.getPosition().y + body.getSize().y);
		return (body_.getPosition().x <= mouse_pos.x && body_.getPosition().x + body_.getSize().x>= mouse_pos.x) &&(body_.getPosition().y <= mouse_pos.y && body_.getPosition().y + body_.getSize().y >= mouse_pos.y);
		
	}

	bool IsHold()
	{
		Vector2i mouse_pos = Mouse::getPosition(WorkingWindow_);
		return (body_.getPosition().x <= mouse_pos.x && body_.getPosition().x + body_.getSize().x >= mouse_pos.x) && (body_.getPosition().y <= mouse_pos.y && body_.getPosition().y + body_.getSize().y >= mouse_pos.y) && Mouse::isButtonPressed(Mouse::Button::Left);
	}
private:
	
};