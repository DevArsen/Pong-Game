#include "Bat.h"

// Це конструктор, і він викликається під час створення об'єкта
Bat::Bat(float startX, float startY) : m_Position(startX, startY)
{
	m_Shape.setSize(sf::Vector2f(50, 5)); // Встановлюємо розмір ракетки
	m_Shape.setPosition(m_Position); // Встановлюємо початкову позицію ракетки
}

FloatRect Bat::getPosition()
{
	return m_Shape.getGlobalBounds(); // Повертаємо глобальні межі форми ракетки
}

RectangleShape Bat::getShape()
{
	return m_Shape; // Повертаємо об'єкт форми ракетки
}

void Bat::moveLeft()
{
	m_MovingLeft = true; // Встановлюємо прапорець руху вліво
}

void Bat::moveRight()
{
	m_MovingRight = true; // Встановлюємо прапорець руху вправо
}

void Bat::stopLeft()
{
	m_MovingLeft = false; // Скидаємо прапорець руху вліво
}

void Bat::stopRight()
{
	m_MovingRight = false; // Скидаємо прапорець руху вправо
}

void Bat::update(Time dt)
{
	if (m_MovingLeft) {
		m_Position.x -= m_Speed * dt.asSeconds(); // Оновлюємо позицію вліво
	}
	if (m_MovingRight) {
		m_Position.x += m_Speed * dt.asSeconds(); // Оновлюємо позицію вправо
	}
	m_Shape.setPosition(m_Position); // Оновлюємо позицію форми ракетки
}

//194 