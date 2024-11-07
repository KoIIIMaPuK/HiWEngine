#include "EInputController.h"

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  Метод, который принимает события и обрабатывает их
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void EInputController::handleEvent(const sf::Event& FEvent)
{
    // ================================================================================================
    //
    //  Для клавиши
    //
    if (FEvent.type == sf::Event::KeyPressed) {
        this->mapKeyStates[FEvent.key.code] = true;
    }
    if (FEvent.type == sf::Event::KeyReleased) {
        this->mapKeyStates[FEvent.key.code] = false;
    }
    //
    // ================================================================================================




    // ================================================================================================
    //
    //  Для мыши
    //
    if (FEvent.type == sf::Event::MouseButtonPressed) {
        this->mapMouseButtonStates[FEvent.mouseButton.button] = true;
    }
    if (FEvent.type == sf::Event::MouseButtonReleased) {
        this->mapMouseButtonStates[FEvent.mouseButton.button] = false;
    }
    //
    // ================================================================================================
}







// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  Метод, который сохраняет текущее состояние клавиши
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void EInputController::updateKeyAndMouseStates()
{
    this->mapPreviousKeyStates = this->mapKeyStates;

    this->mapPreviousMouseButtonStates = this->mapMouseButtonStates;
}








// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  Функция проверяет, нажата ли определенная клавиша.
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
bool EInputController::isKeyPressed(sf::Keyboard::Key FKey)
{
	return this->mapKeyStates[FKey];
}








// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// Функция проверяет, была ли отпущена клавиша.
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
bool EInputController::isKeyReleased(sf::Keyboard::Key FKey)
{
    return !this->mapKeyStates[FKey] && this->mapPreviousKeyStates[FKey];
}








// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// Функция проверяет, нажата ли кнопка мыши.
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
bool EInputController::isMouseButtonPressed(sf::Mouse::Button FButton)
{
    return this->mapMouseButtonStates[FButton];
}








bool EInputController::isMouseButtonReleased(sf::Mouse::Button FButton)
{
    return !this->mapMouseButtonStates[FButton] && this->mapPreviousMouseButtonStates[FButton];;
}









// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// Функция возвращает текущую позицию курсора мыши.
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
sf::Vector2i EInputController::getMousePosition()
{
    return sf::Mouse::getPosition();
}