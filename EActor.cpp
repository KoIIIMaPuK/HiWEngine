#include "EActor.h"

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  [0] ����������� 
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
EActor::EActor(const sf::Vector2f position, const std::string& texturePath) 
    : position(position), velocity(0, 0), rotation(0.0)
{
    // ================================================================================================
    //
    // ���� ���:
    //      ��������� �������� �� �������� �������� �������� �� ����� 
    //      ������������ ��������� ������
    //
    if(!objectTexture.loadFromFile(texturePath)) {
        throw std::runtime_error("Failed to load texture from: " + texturePath);
    }
    //
    // ================================================================================================
    
    // ================================================================================================
    //
    // ������������� �������� �������
    //
    objectActorSprite.setTexture(objectTexture);
    //
    // ================================================================================================

    // ================================================================================================
    //
    // ������������� ������� �������
    //
    objectActorSprite.setPosition(this->position);
    //
    // ================================================================================================

}







// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  [1] �����������
//  
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
EActor::EActor()
    : position(0, 0), velocity(0, 0), rotation(0.0)
{
    // ================================================================================================
    //
    // ���� ���:
    //      ��������� �������� �� �������� �������� �������� �� ����� 
    //      ������������ ��������� ������
    //
    if (!objectTexture.loadFromFile("Images/Sprite-0006.png")) 
    {
        throw std::runtime_error("Failed to load texture from: Images/Sprite-0006.png");
    }
    //
    // ================================================================================================

    // ================================================================================================
    //
    // ������������� �������� �������
    //
    objectActorSprite.setTexture(objectTexture);
    //
    // ================================================================================================

    // ================================================================================================
    //
    // ������������� ������� �������
    //
    objectActorSprite.setPosition(this->position);
    //
    // ================================================================================================
}








// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  [2] �����������
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
EActor::EActor(const sf::Vector2f position)
    : position(position), velocity(0, 0), rotation(0.0)
{
    // ================================================================================================
    //
    // ���� ���:
    //      ��������� �������� �� �������� �������� �������� �� ����� 
    //      ������������ ��������� ������
    //
    if (!objectTexture.loadFromFile("Images/Sprite-0006.png"))
    {
        throw std::runtime_error("Failed to load texture from: Images/Sprite-0006.png");
    }
    //
    // ================================================================================================

    // ================================================================================================
    //
    // ������������� �������� �������
    //
    objectActorSprite.setTexture(objectTexture);
    //
    // ================================================================================================

    // ================================================================================================
    //
    // ������������� ������� �������
    //
    objectActorSprite.setPosition(this->position);
    //
    // ================================================================================================
}









// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  ����� ��� ��������� �����
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void EActor::draw(sf::RenderWindow& window)
{
    window.draw(objectActorSprite);
}









// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  ��������� ������� �����
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void EActor::setPosition(const sf::Vector2f& position) 
{
    this->position = position;
}










// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  ��������� ������� �����
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
sf::Vector2f EActor::getPosition() 
const {
    return this->position;
}










// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  ��������� ���� ��������
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void EActor::setRotation(float angle) 
{
    this->rotation = angle;
}










// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  ��������� ���� ��������
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
float EActor::getRotation() 
const {
    return this->rotation;
}










// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  ��������� ��������
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void EActor::setVelocity(const sf::Vector2f& velocity)
{
    this->velocity = velocity;
}










// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  ��������� ��������
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
sf::Vector2f EActor::getVelocity() 
const {
    return this->velocity;
}














// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  ���������� ��������� ������
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void EActor::Update(float deltaTime)
{
    this->position += this->velocity * deltaTime;
    this->objectActorSprite.setScale(this->scaleX, this->scaleY);
    this->objectActorSprite.setPosition(this->position);
    this->objectActorSprite.setRotation(this->rotation);
}











// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  ��������� ������� ����� �� ���� ����
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void EActor::setScaleXY(const float scaleXY)
{
    scaleX = scaleXY; scaleY = scaleXY;
}










// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  ��������� ������� ����� �� ��� X
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void EActor::setScaleX(const float scaleX)
{
    this->scaleX = scaleX;
}









// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//  ��������� ������� ����� �� ��� Y
//
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void EActor::setScaleY(const float scaleY)
{
    this->scaleY = scaleY;
}