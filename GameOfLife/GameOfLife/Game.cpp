#include "Game.h"

Game::Game()
{
	float value_speed = 1;
	float speed = 1 / value_speed;
	unsigned int fps = 60;
	window = new sf::RenderWindow();
	board = new Board();
	button = new sf::Mouse::Button();

	window->create(sf::VideoMode(WIDTH_W, HEIGTH_W), "Game of life");
	window->setPosition(sf::Vector2i(25, 25));
	window->setFramerateLimit(fps);
}

void Game::draw()
{
	board->generate(window, 0);
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}	
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
			{
				play(false);
			}
		}

		while (sf::Mouse::isButtonPressed(*button) == 1)
		{
			sf::Vector2i positionS = sf::Mouse::getPosition(*window);
			if (positionS.x >= 0 && positionS.y >= 0 && positionS.x <= 1500 && positionS.y <= 800)
			{
				board->draw(window, positionS);
				board->print(window);
				window->display();
			}
		}		
		window->clear();
	}
}

void Game::play(bool drawing)
{
	if (drawing == true)
		board->generate(window, 2);		

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
		}
		if (clock.getElapsedTime().asSeconds() >= speed)
		{
			board->maj();
			clock.restart();
		}
		board->print(window);
		window->display();
		window->clear();
	}
}
void Game::shutDown()
{
	window->close();
}

void Game::menu()
{
	sf::Text text;
	sf::Font font;

	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "Erreur" << std::endl;
	}

	while (window->isOpen())
	{
		handleMenu();

		text.setCharacterSize(50);
		text.setColor(sf::Color::White);
		text.setFont(font);

		text.setPosition(WIDTH_W / 4 + 200, HEIGTH_W / 2 - 200);
		text.setString("Game of Life");
		window->draw(text);

		text.setPosition(WIDTH_W / 4, HEIGTH_W / 2);
		text.setString("Play");
		window->draw(text);

		text.setPosition(WIDTH_W / 4 + 300, HEIGTH_W / 2);
		text.setString("Draw");
		window->draw(text);

		text.setPosition(WIDTH_W / 4 + 600, HEIGTH_W / 2);
		text.setString("Quit");
		window->draw(text);

		text.setPosition(WIDTH_W / 4 + 190, HEIGTH_W / 2 + 70);
		text.setCharacterSize(20);
		text.setString("(Press space to begin after the drawing)");
		window->draw(text);
		window->display();
	}
}

void Game::handleMenu()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (event.mouseButton.y >= HEIGTH_W / 2 && event.mouseButton.y <= HEIGTH_W / 2 + 50)
				{
					if (event.mouseButton.x >= WIDTH_W / 4 && event.mouseButton.x <= WIDTH_W / 4 + 100)
					{
						play(true);
					}

					else if (event.mouseButton.x >= WIDTH_W / 4 + 300 && event.mouseButton.x <= WIDTH_W / 4 + 400)
					{
						draw();
					}

					else if (event.mouseButton.x >= WIDTH_W / 4 + 600 && event.mouseButton.x <= WIDTH_W / 4 + 700)
					{
						shutDown();
					}
				}
			}
		}
	}
}