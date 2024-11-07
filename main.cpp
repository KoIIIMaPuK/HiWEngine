#include <SFML/Graphics.hpp>
#include "Menu.h"
using namespace sf;
using namespace Engine;

void InitText(Text& mtext, float xpos, float ypos, String str, int size_font = 60,
    Color menu_text_color = Color::Blue, int bord = 0, Color border_color = Color::Black)
{
    mtext.setString(str); // Установка строки текста
    mtext.setCharacterSize(size_font); // Установка размера шрифта
    mtext.setFillColor(menu_text_color); // Установка цвета текста
    mtext.setPosition(xpos, ypos); // Установка позиции текста

    // Если требуется граница, можно добавить ее
    if (bord > 0) {
        // Создаем текст с границей
        Text borderText = mtext; // Копируем текст
        borderText.setFillColor(border_color); // Устанавливаем цвет границы
        borderText.setPosition(xpos - bord, ypos - bord); // Сдвигаем текст для границы
        // Здесь вы можете добавить код для рисования границы, если хотите
    }
}
void EngineStart();
void Options();
void About_Engine();


int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!",Style::Default );

    //window.setMouseCursorVisible(false);
    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;


    RectangleShape background(Vector2f(width, height));

    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    Texture texture_window;
    if (!texture_window.loadFromFile("C:/Users/Admin/Desktop/previes.jpg")) return 4;
    background.setTexture(&texture_window);

    Font font;
    if (!font.loadFromFile("C:/Users/Admin/Desktop/Arial/arialmt.ttf")) return 5;

    Text Titul;
    Titul.setFont(font);
    InitText(Titul, 480, 50, L"HIW-Engine", 150, Color(111, 147, 0),3);


    String name_menu[4]{ L"start",L"Settings",L"About Engine",L"Quit" };


    Engine::Menu mymenu(window, 950, 350, name_menu, 100, 120);
    mymenu.setColorTextMenu(Color(0, 114, 187), Color::Red, Color::Black);
    mymenu.Aligmenu(2);



    Text Version;
    Version.setFont(font);
    InitText(Version, 1520, 980, L"V 0.0.0.2", 100, Color(0, 114, 187), 3);
    //Engine::Menu Settings();
    // попробуйка создать что-то для меню

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyReleased)
            {
                //выбор пунктика
                if (event.key.code == Keyboard::Up) { mymenu.MoveUp(); }
                if (event.key.code == Keyboard::Down) { mymenu.MoveDown(); }
                if (event.key.code == Keyboard::Return)
                {
                    switch (mymenu.getSelectedMenuNumber())
                    {
                    case 0: EngineStart(); break;
                    case 1: Options(); break;
                    case 2: About_Engine(); break;
                    case 3: window.close(); break;

                    }
                }
            }
        } 
        window.clear();
        window.draw(background);
        window.draw(Titul);
        window.draw(Version);
        mymenu.Draw();
        window.display();
    }
    return 0;
}

void EngineStart()
{
    RenderWindow Play(VideoMode::getDesktopMode(), L"Проект 1-й", Style::Fullscreen);

    RectangleShape background_play(Vector2f(1920, 1080));

    Texture texture_play;
    if (!texture_play.loadFromFile("C:/Users/Admin/Desktop/previes.jpg")) exit(1);
    background_play.setTexture(&texture_play);
    
    while (Play.isOpen())
    {
        Event event_play;
        while (Play.pollEvent(event_play))
        {
            if (event_play.type == Event::KeyPressed);
            {
                if (event_play.key.code == Keyboard::Escape) { Play.close(); }
            }
        }
        Play.clear();
        Play.draw(background_play);
        Play.display();
    }
}
void Options()
{
    RenderWindow Options(VideoMode::getDesktopMode(), L"Настройки", Style::Fullscreen);

    RectangleShape background_opt(Vector2f(1920, 1080));
    Texture texture_opt;
    if (!texture_opt.loadFromFile("C:/Users/Admin/Desktop/previes.jpg")) exit(2);

    background_opt.setTexture(&texture_opt);
    while (Options.isOpen())
    {
        Event event_opt;
        while (Options.pollEvent(event_opt))
        {
            if (event_opt.type == Event::Closed) Options.close();
            if (event_opt.type == Event::KeyPressed)
            {
                if (event_opt.key.code == Keyboard::Escape) Options.close();
            }
        }
        Options.clear();
        Options.draw(background_opt);
        Options.display();
    }
}
void About_Engine()
{
    RenderWindow About(VideoMode::getDesktopMode(), L"О движке", Style::Fullscreen);

    RectangleShape background_ab(Vector2f(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
    Texture texture_ab;
    if (!texture_ab.loadFromFile("C:/Users/Admin/Desktop/previes.jpg")) exit(2);

    background_ab.setTexture(&texture_ab);
    while (About.isOpen())
    {
        Event event_play;
        while (About.pollEvent(event_play))
        {
            if (event_play.type == Event::Closed) About.close();
            if (event_play.type == Event::KeyPressed)
            {
                if (event_play.key.code == Keyboard::Escape) About.close();
            }
        }
        About.clear();
        About.draw(background_ab);
        About.display();
    }
}