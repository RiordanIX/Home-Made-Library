#include "button.hpp"

Button::Button(std::string filename, void (*funct)()):
    m_state(buttState::normal),
    m_mouseClicked(false),
    m_function(funct)
{
    m_texture.loadFromFile(filename);   /// The file name is needed for which file to load.

    m_spriteAreaNormal = sf::IntRect(0, /// Buttons should follow this stacking format: NORMAL
                          0,
                          m_texture.getSize().x,
                          (m_texture.getSize().y / 3));

    m_spriteAreaHovered = sf::IntRect(0,                        ///                     HOVERED
                           (m_texture.getSize().y / 3),
                           m_texture.getSize().x,
                           (m_texture.getSize().y / 3));

    m_spriteAreaClicked = sf::IntRect(0,                        ///                     CLICKED
                           (m_texture.getSize().y * 2 / 3),// 2 first to min rounding errors.
                           m_texture.getSize().x,
                           (m_texture.getSize().y / 3));

    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(m_spriteAreaNormal);
}

void Button::changeAction(void (*funct)())
{
    m_function = funct;
}

bool Button::contains(sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Need window input to make offsets work.
    sf::FloatRect rekt = m_sprite.getGlobalBounds();

    return (mousePos.x <= (rekt.width + rekt.left) &&
            mousePos.x >= (rekt.left) &&
            mousePos.y <= (rekt.height + rekt.top) &&
            mousePos.y >= (rekt.top));
}

/* My convention will be to have buttons that are as follows:
 *      NORMAL
 *      HOVERED
 *      CLICKED
 */
void Button::updateSpriteBox()
{
    switch (m_state)
    {
    case buttState::normal:
        m_sprite.setTextureRect(m_spriteAreaNormal);
        break;
    case buttState::hovered:
        m_sprite.setTextureRect(m_spriteAreaHovered);
        break;
    case buttState::clicked:
        m_sprite.setTextureRect(m_spriteAreaClicked);
        break;
    }
}

void Button::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    switch (event.type)
    {
    case sf::Event::MouseButtonPressed:
        if (contains(window))
        {
            m_state = buttState::clicked;
            updateSpriteBox();
            m_mouseClicked = true;
        }
        else
        {
            m_state = buttState::normal;
            updateSpriteBox();
        }
        break;

    case sf::Event::MouseMoved:
        if (contains(window))
        {
            if (m_mouseClicked)
            {
                m_state = buttState::clicked;
            }
            else
            {
                m_state = buttState::hovered;
            }
        }
        else
        {
            m_state = buttState::normal;
        }
        updateSpriteBox();
        break;

    case sf::Event::MouseButtonReleased:    // updateSpriteBox() is in the if statements here to get the appearance I want.
        if (contains(window))
        {
            m_state = buttState::hovered;
            updateSpriteBox();
            m_function();
        }
        else
        {
            m_state = buttState::normal;
            updateSpriteBox();
        }
        m_mouseClicked = false;
        break;

    case sf::Event::MouseLeft:      // Mouse leaves window
        m_state = buttState::normal;
        updateSpriteBox();
        break;

    case sf::Event::MouseEntered:   // Mouse Re-enters window
        if (contains(window))       // If the mouse is on the button
        {
            if (m_mouseClicked)     // And if the mouse is still held down.
            {
                m_state = buttState::clicked;
            }
            else
            {
                m_state = buttState::hovered;
            }
        }
        else
        {
            m_state = buttState::normal;
        }
        updateSpriteBox();
        break;

    default:
        break;
    }
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const // To make drawing the button more inline with the SFML way of drawing.
{
    target.draw(m_sprite, states);
}
