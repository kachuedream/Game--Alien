#include "Animation.h"

Animation::Animation()
{
	switchTime = 0;
}

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation()
{

}

void Animation::init(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / imageCount.x;
	uvRect.height = texture->getSize().y / imageCount.y;
}

void Animation::update(int row, float deltaTime, bool faceRight)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		currentImage.x %= imageCount.x;
	}

	uvRect.top = currentImage.y * uvRect.height;

	if (faceRight)
	{
		uvRect.left = currentImage.x * uvRect.width;
	}
	else
	{
		uvRect.left = (currentImage.x + 1) * uvRect.width;
		uvRect.width = -abs(uvRect.width);
	}
}