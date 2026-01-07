#include "Ball.h"

// Функція-конструктор
Ball::Ball(float startX, float startY) : m_Position(startX, startY)
{
	m_Shape.setSize(sf::Vector2f(10, 10)); // Встановлюємо розмір м'яча
	m_Shape.setPosition(m_Position); // Встановлюємо початкову позицію м'яча

}

FloatRect Ball::getPosition()
{
	return m_Shape.getGlobalBounds(); // Повертаємо глобальні межі форми м'яча
}
RectangleShape Ball::getShape()
{
	return m_Shape; // Повертаємо об'єкт форми м'яча
}
float Ball::getXVelocity()
{
	return m_DirectionX;
}
void Ball::reboundSides()
{
	m_DirectionX = -m_DirectionX; // Змінюємо напрямок руху по осі X
}
void Ball::reboundBatOrTop()
{
	m_DirectionY = -m_DirectionY; // Змінюємо напрямок руху по осі Y
}
void Ball::reboundBottom()
{
	m_Position.y = 0; // Скидаємо позицію м'яча по осі Y
	m_Position.x = 500; // Скидаємо позицію м'яча по осі X
	m_DirectionY = -m_DirectionY; // Змінюємо напрямок руху по осі Y
}
//204  