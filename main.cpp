// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  С/C++ Библиотеки
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
#include <iostream>
#include <iostream>
#include <cstdlib>




// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// SFML Библиотеки
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
#include <SFML/Graphics.hpp>

#include "Menu.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include "EUIController.h"
using namespace sf;
using namespace Engine;



#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

constexpr unsigned short WINDOW_HEIGHT  = 720;      // Высота окна
constexpr unsigned short WINDOW_WIDTH   = 1280;	    // Ширина окна 



int main()
{
    setlocale(LC_ALL, "ru");
    EInputController rrr;
   
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Button Example");
   
    // Проверям как создать загрузочный экран 
    //Мейби создать класс для создания загрузочного экрана
 
        // "C:/Users/Admin/Desktop/image.png"

    // "C:/Users/Admin/Desktop/previes.jpg"

    sf::RenderWindow load(sf::VideoMode(1920, 1080), "Loading screan", sf::Style::Fullscreen);

    // "C:\Users\Admin\Desktop\IconHiwEngine.png"
    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/Admin/Desktop/WWWWWWW.png")) {
            // Если не удалось загрузить изображение, выходим
    }

    EUIController test_button(40,20,500, 40.0, "Yarr");
    EUIController test_button2(30,1000, 800, 150, 200, "Button",sf::Color::Red,sf::Color::Blue, sf::Color::White);
    EUIController test_button3(30,100, 100, 100, 100, "GSHGOUh", sf::Color(123,123,213), sf::Color::Black, sf::Color::Magenta);
    sf::Sprite sprite(texture);
    sprite.setScale(
        static_cast<float>(load.getSize().x) / texture.getSize().x,
        static_cast<float>(load.getSize().y) / texture.getSize().y
    );
    sf::Clock clock;
    float loadingTime = 0.0f;
    while (load.isOpen())
    {
        sf::Event loader;
        while (load.pollEvent(loader)) {
            if (loader.type == sf::Event::Closed)
                load.close();
        }


        if (clock.getElapsedTime().asSeconds() > loadingTime) {
            // Закрываем окно после завершения загрузки
            load.close();
            break; // Выходим из цикла
        }


        load.clear();
        load.draw(sprite);
        load.display();

    }


    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)

                window.close(); 
        }
        window.clear();

     
        test_button.draw(window);
        test_button2.draw(window);
        test_button3.draw(window);
        test_button.update(window);
        test_button2.update(window);
        test_button3.update(window, sf::Color(57, 75, 169), sf::Color::Blue);
        window.display();
    }
}
