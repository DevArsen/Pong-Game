#include "Bat.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{
	// Створюємо об'єкт VideoMode
	VideoMode vm(1920, 1090);
	// Створюємо та відкриваємо вікно для гри в повноекранному режимі
	RenderWindow window(vm, "Pong", Style::Fullscreen);
	int score = 0; // Ініціалізуємо змінну для рахунку
	int lives = 3; // Ініціалізуємо змінну для життів

	// Створюємо ракетку у нижній центральній частині екрану
	Bat bat(1920 / 2, 1080 - 20); // Ракетка розташована на 20 пікселів вище нижнього краю
	// Тут буде стоврений м'яч

	// Створюємо текстовий об'єкт HUD
	Text hud;
	// Крутий ретрошрифт
	Font font;
	font.loadFromFile("fonts/DS-DIGIT.ttf");
	// Встановлюємо шрифт
	hud.setFont(font);
	// Робимо його великим та красивим
	hud.setCharacterSize(75);
	// Вибираємо колір
	hud.setFillColor(Color::White);
	hud.setPosition(20, 20); // Розміщуємо у верхньому лівому куті

	// Таймер для керування часом
	Clock clock;
	while (window.isOpen())
	{
		// Обробка вводу гравця
		Event event; // Створюємо об'єкт події
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				// Вихід із гри під час закриття вікна
				window.close();
		}
		// Обробка виходу гравця
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close(); // Вихід із гри при натисканні Escape
		}
		// Обробка натискання та відпускання клавіш зі стрілками
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			bat.moveLeft(); // Рух ракетки вліво
		}
		else
		{
			bat.stopLeft(); // Зупинка руху вліво
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			bat.moveRight(); // Рух ракетки вправо
		}
		else
		{
			bat.stopRight(); // Зупинка руху вправо
		}

		// Оновлення ракетки, м'яча та HUD
		// Оновлення delta time
		Time dt = clock.restart(); // Отримуємо час, що минув з останнього кадру
		bat.update(dt); // Оновлюємо позицію ракетки

		// Оновлення тексту HUD
		std::stringstream ss; // Створюємо стрім для форматування тексту
		ss << "Score: " << score << "   Lives:" << lives; // Форматуємо рядок з рахунком та життями
		hud.setString(ss.str()); // Встановлюємо текст HUD

		// Відображення ракетки, м'яча та HUD
		window.clear(); // Очищаємо вікно
		window.draw(hud); // Малюємо HUD
		window.draw(bat.getShape()); // Малюємо ракетку
		window.display(); // Відображаємо все на екрані
	}
	return 0; 

}