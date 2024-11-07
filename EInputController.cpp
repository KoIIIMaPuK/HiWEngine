#include "EInputController.h"

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  �����, ������� ��������� ������� � ������������ ��
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void EInputController::handleEvent(const sf::Event& FEvent)
{
    // ================================================================================================
    //
    //  ��� �������
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
    //  ��� ����
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
//  �����, ������� ��������� ������� ��������� �������
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void EInputController::updateKeyAndMouseStates()
{
    this->mapPreviousKeyStates = this->mapKeyStates;

    this->mapPreviousMouseButtonStates = this->mapMouseButtonStates;
}








// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  ������� ���������, ������ �� ������������ �������.
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
bool EInputController::isKeyPressed(sf::Keyboard::Key FKey)
{
	return this->mapKeyStates[FKey];
}








// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// ������� ���������, ���� �� �������� �������.
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
bool EInputController::isKeyReleased(sf::Keyboard::Key FKey)
{
    return !this->mapKeyStates[FKey] && this->mapPreviousKeyStates[FKey];
}








// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// ������� ���������, ������ �� ������ ����.
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
// ������� ���������� ������� ������� ������� ����.
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
sf::Vector2i EInputController::getMousePosition()
{
    return sf::Mouse::getPosition();
}