#include "Menu.h"


void Engine::Menu::setInitText(sf::Text& text, sf::String str, float xpos, float ypos)
{
	text.setFont(font);
	text.setFillColor(menu_text_color);
	text.setString(str);
	text.setCharacterSize(size_font);
	text.setPosition(xpos, ypos);
	text.setOutlineThickness(2);
	text.setOutlineColor(border_color);

}

void Engine::Menu::Aligmenu(int posx)
{
	float nullx = 0;

	for (int i = 0; i < max_menu; i++)
	{
		switch (posx)
		{
		case 0:
			nullx = 0;
			break;
		case 1:
			nullx = mainMenu[i].getLocalBounds().width;
			break;
		case 2:
			nullx = nullx = mainMenu[i].getLocalBounds().width / 2;
			break;
		}
		mainMenu[i].setPosition(mainMenu[i].getPosition().x - nullx, mainMenu[i].getPosition().y);

	}

}
Engine::Menu::Menu(sf::RenderWindow& window, float menux, float menuy, sf::String name[], int numItems, int sizeFont, int step)
	: mywindow(window), menu_X(menux), menu_Y(menuy), size_font(sizeFont), menu_step(step)
{
	if (!font.loadFromFile("C:/Users/Admin/Desktop/Arial/arialmt.ttf")) exit(32);
	max_menu = numItems;  // Используйте переданное количество элементов
	mainMenu = new sf::Text[max_menu];  // Создайте массив нужного размера

	for (int i = 0, ypos = menu_Y; i < max_menu; i++, ypos += menu_step) {
		setInitText(mainMenu[i], name[i], menu_X, ypos);
	}
	mainMenuSelected = 0;
	mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);
}
void Engine::Menu::MoveUp()
{
	mainMenuSelected--;

	if (mainMenuSelected >= 0)
	{
		mainMenu[mainMenuSelected].setFillColor(chose_text_color);
		mainMenu[mainMenuSelected + 1].setFillColor(menu_text_color);
	}
	else
	{
		mainMenu[0].setFillColor(menu_text_color);
		mainMenuSelected = max_menu - 1;
		mainMenu[mainMenuSelected].setFillColor(chose_text_color);
	}
}
void Engine::Menu::MoveDown()
{
	mainMenuSelected++;

	if (mainMenuSelected < max_menu)
	{
		mainMenu[mainMenuSelected-1].setFillColor(menu_text_color);
		mainMenu[mainMenuSelected].setFillColor(chose_text_color);
	}
	else
	{
		mainMenu[max_menu-1].setFillColor(menu_text_color);
		mainMenuSelected = 0;
		mainMenu[mainMenuSelected].setFillColor(chose_text_color);
	}
}

void Engine::Menu::Draw()
{
	for (int i = 0; i < max_menu; i++) mywindow.draw(mainMenu[i]);
}

void Engine::Menu::setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor)
{
	menu_text_color = menColor;
	chose_text_color = ChoColor;
	border_color = BordColor;
	for (int i = 0; i < max_menu; i++)
	{
		mainMenu[i].setFillColor(menu_text_color);
		mainMenu[i].setOutlineColor(border_color);
	}
	mainMenu[mainMenuSelected].setFillColor(chose_text_color);
}

