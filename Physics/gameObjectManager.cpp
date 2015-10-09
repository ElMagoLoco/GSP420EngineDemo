#include "gameObjectManager.h"
#include "physicsObject.h"

#include <string>
#include <vector>





gameObjectManager::gameObjectManager()
{

}


gameObjectManager::~gameObjectManager()
{
}


// Add a game object that is not controlled by physics but reacts to collisions
int gameObjectManager::addBoxDynamicRigidBody(std::string theName,int x, int y, int halfW, int halfH, bool isActive, physicsObject* gameObjectLink)
{

	if (gameObjectLink == NULL) return -1; 

	gameObjectLink->shapeList = "Box";
	gameObjectLink->isActive     = isActive; 
	gameObjectLink->objectName   = theName; 
	gameObjectLink->x = x;
	gameObjectLink->y = y;
	gameObjectLink->isDynamic    = true;
	gameObjectLink->isStatic     = false;
	gameObjectLink->halfHeight = halfH;
	gameObjectLink->halfWidth =  halfW;

	gameManangerMap[theName] = gameObjectLink;

	return 0;
}


// Add a game object that is not controlled by physics but reacts to collisions
int gameObjectManager::addBoxNonDynamicRigidBody(std::string theName, int x, int y, int halfW, int halfH, bool isActive, physicsObject* gameObjectLink)
{
	
	if (gameObjectLink == NULL) return -1;
	gameObjectLink->shapeList = "Box";
	gameObjectLink->isActive = isActive;
	gameObjectLink->objectName = theName;
	gameObjectLink->x = x;
	gameObjectLink->y = y;
	gameObjectLink->isDynamic = false;
	gameObjectLink->isStatic = false;
	gameObjectLink->halfHeight = halfH;
	gameObjectLink->halfWidth = halfW;

	gameManangerMap[theName] = gameObjectLink;

	return 0;
}

// Add a game object that is not controlled by physics but reacts to collisions
int gameObjectManager::addBoxNonMovingRigidBody(std::string theName, int x, int y, int halfW, int halfH, bool isActive, physicsObject* gameObjectLink)
{
	if (gameObjectLink == NULL) return -1;
	
	gameObjectLink->shapeList = "Box";
	gameObjectLink->isActive = isActive;
	gameObjectLink->objectName = theName;
	gameObjectLink->x = x;
	gameObjectLink->y = y;
	gameObjectLink->isDynamic = false;
	gameObjectLink->isStatic  = true;
	gameObjectLink->halfHeight = halfH;
	gameObjectLink->halfWidth = halfW;

	gameManangerMap[theName] = gameObjectLink;

	return 0;
}

// Add a game object that is not controlled by physics but reacts to collisions
int gameObjectManager::addPolygonDynamicRigidBody(std::string theName, int x, int y, std::vector<float32> vertices, bool isActive, physicsObject* gameObjectLink)
{
	if (gameObjectLink == NULL) return -1;
    gameObjectLink->shapeList = "Polygon";
	gameObjectLink->shape = vertices;
	gameObjectLink->isActive = isActive;
	gameObjectLink->objectName = theName;
	gameObjectLink->x = x;
	gameObjectLink->y = y;
	gameObjectLink->isDynamic = true;
	gameObjectLink->isStatic = false;
	gameObjectLink->halfHeight = 0;
	gameObjectLink->halfWidth = 0;

	gameManangerMap[theName] = gameObjectLink;

	return 0;
}

int gameObjectManager::addPolygonNonDynamicRigidBody(std::string theName, int x, int y, std::vector<float32> vertices, bool isActive, physicsObject* gameObjectLink)
{
	if (gameObjectLink == NULL) return -1;
	gameObjectLink->shapeList = "Polygon";
	gameObjectLink->shape = vertices;
	gameObjectLink->isActive = isActive;
	gameObjectLink->objectName = theName;
	gameObjectLink->x = x;
	gameObjectLink->y = y;
	gameObjectLink->isDynamic = false;
	gameObjectLink->isStatic = false;
	gameObjectLink->halfHeight = 0;
	gameObjectLink->halfWidth = 0;

	gameManangerMap[theName] = gameObjectLink;

	return 0;
}


int gameObjectManager::addPolygonNonMovingRigidBody(std::string theName, int x, int y, std::vector<float32> vertices, bool isActive, physicsObject* gameObjectLink)
{
	if (gameObjectLink == NULL) return -1;
	gameObjectLink->shapeList = "Polygon";
	gameObjectLink->shape = vertices;
	gameObjectLink->isActive = isActive;
	gameObjectLink->objectName = theName;
	gameObjectLink->x = x;
	gameObjectLink->y = y;
	gameObjectLink->isDynamic = false;
	gameObjectLink->isStatic = true;
	gameObjectLink->halfHeight = 0;
	gameObjectLink->halfWidth = 0;

	gameManangerMap[theName] = gameObjectLink;

	return 0;
}


// finds and returns a the instance of the object by name
physicsObject* gameObjectManager::findByName(std::string name)
{
	return (physicsObject*) gameManangerMap[name];
}


// finds and returns a the instance of the object by name
int gameObjectManager::removeByName(std::string name)
{
	return 0;
}

