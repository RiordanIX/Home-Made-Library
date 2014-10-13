#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace buttState
{
enum buttState  // Just button...
{
    normal,
    hovered,
    clicked
};
};

// By inheriting from Drawable, it makes drawing the button more intuitive.
class Button : public sf::Drawable
{
public:
    // The function pointer is what the button will do when clicked.
    // I don't know if a different format would be needed,
    // but I'll add a new constructor if it is.
    Button(std::string, void (*function)());
    ~Button();
    void handleEvent(sf::Event&, sf::RenderWindow& window);
    void changeAction(void (*function)());
    void changeTexture(std::string);
    void setPosition(float, float);
    void setPosition(sf::Vector2f);

private:
    sf::Sprite              m_sprite;
    sf::Texture*            m_texture;
    sf::IntRect             m_spriteAreaNormal;
    sf::IntRect             m_spriteAreaHovered;
    sf::IntRect             m_spriteAreaClicked;
    buttState::buttState    m_state;
    bool                    m_mouseClicked;
    
private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;  // from sf::Drawable
    void updateSpriteBox();
    void setSpriteSize();
    bool contains(sf::RenderWindow&);
    void (*m_function) (); // Function Pointer - function done when button is clicked.
};

#endif // BUTTON_HPP

