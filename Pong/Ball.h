#pragma once
#include <SFML/Graphics.hpp>
using namespace sf; 
class Ball
{
private:
	Vector2f m_Position; // Позиція м'яча
	RectangleShape m_Shape; // Об'єкт RectangleShape для м'яча
	float m_Speed = 300.0f; // Швидкість м'яча
	float m_DirectionX = .2f; // Напрямок руху по осі X
	float m_DirectionY = .2f; // Напрямок руху по осі Y
public:
	Ball(float startX, float startY); // Конструктор м'яча
	FloatRect getPosition(); // Отримати позицію м'яча
	RectangleShape getShape(); // Отримати форму м'яча
	void reboundSides(); // Відскок від сторін
	void reboundBatOrTop(); // Відскок від ракетки або верху
	void reboundBottom(); // Відскок від низу
	void update(Time dt); // Оновлення позиції м'яча
};
