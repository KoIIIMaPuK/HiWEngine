#pragma once
#include <SFML/Graphics.hpp>


namespace Engine {


	class Menu
	{
		float menu_X;
		float menu_Y;
		int menu_step;
		int max_menu;
		int size_font;
		int mainMenuSelected;
		sf::Font font;
		sf::Text* mainMenu;


		sf::Color menu_text_color = sf::Color::White;
		sf::Color chose_text_color = sf::Color::Yellow;
		sf::Color border_color = sf::Color::Black;

		void setInitText(sf::Text& text, sf::String str, float xpos, float ypos);

		sf::RenderWindow& mywindow;

	public:
	
		Menu(sf::RenderWindow& window, float menux, float menuy, sf::String name[], int numItems, int sizeFont = 60, int step = 80);



		~Menu()
		{
			delete[] mainMenu;
		}
		void Draw();

		void MoveUp();

		void MoveDown();

		void setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor);

		void Aligmenu(int posx);

		int getSelectedMenuNumber()
		{
			return mainMenuSelected;
		}

	};

}