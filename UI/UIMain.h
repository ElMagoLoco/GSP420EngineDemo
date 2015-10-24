//Who needs what?
//Main:
//	update functions
//	gamestate change
//Graphics:
//	position & filename of sprites
//Physics:
//	Size & position of buttons
#pragma once
#include "..\EngineDemo\GameState.h"
#include "..\D3D9Graphics\GFX.h"
#include "defines.h"
#include <vector>
#include "..\Main\DirectInput.h"
#include "..\Main\Player.h"
#include "..\EngineDemo\Game.h"
#include "..\EngineDemo\GameState.h"
using namespace std;
using GFXCore::SpriteData;


class UIMain {
protected:
	Player * player;
	GAMESTATE currentState;
	//GFXCore::Graphics gfx;
	// Stores the position of sprites that LoadSprite loads into an array so that they can be accessed later
	vector<int> menuSpriteIDs;
	vector<int> gameSpriteIDs;
	vector<int> pauseSpriteIDs;
	vector<int> exitSpriteIDs;
	int currentScore;
	int missileAmmo;
	RECT hpBarSize;

private:
	//bool spriteClicked(DirectInput *suppliedInput, int spriteID)
	//{
	//	if (suppliedInput->MouseDX() >  GFXCore::Graphics::get()->getSpritePosX(spriteID) 
	//		&& suppliedInput->MouseDX() < GFXCore::Graphics::get()->getSpritePosX(spriteID) 
	//		+ GFXCore::Graphics::get()->getSpriteWidth(spriteID))
	//	{
	//		if (suppliedInput->MouseDY() > GFXCore::Graphics::get()->getSpritePosY(spriteID) 
	//			&& suppliedInput->MouseDY() < GFXCore::Graphics::get()->getSpritePosY(spriteID) 
	//			+ GFXCore::Graphics::get()->getSpriteHeight(spriteID))
	//		{
	//			return true;
	//		}
	//	}
	//	return false;
	//}
	bool spriteClicked(float x, float y, int spriteID)
	{
		if (x >  GFXCore::Graphics::get()->getSpritePosX(spriteID) 
			&& x < GFXCore::Graphics::get()->getSpritePosX(spriteID) + GFXCore::Graphics::get()->getSpriteWidth(spriteID))
		{
			if (y > GFXCore::Graphics::get()->getSpritePosY(spriteID)
				&& y < GFXCore::Graphics::get()->getSpritePosY(spriteID) + GFXCore::Graphics::get()->getSpriteHeight(spriteID))
			{
				return true;
			}
		}
		return false;
	}
public:

	UIMain(): currentState(STATE_INIT), currentScore(0), missileAmmo(0) {
//		player = &(PLAYER);//Instance()->player);
		hpBarSize.top = 350;
		hpBarSize.bottom = 400;
		hpBarSize.left = 100;
		hpBarSize.right = 500;
	}
	~UIMain() {}

	
	void updateMenu(float x, float y) {
		// tells graphics what to draw
		GFX->addToSpriteRenderList(&menuSpriteIDs[0], menuSpriteIDs.size());

		// check for mouse input
		int MOUSE_LEFT = 0;
		if(spriteClicked(x, y, menuSpriteIDs[2]))
		{
			currentState = STATE_PLAY;
		}

		if (spriteClicked(x, y, menuSpriteIDs[3]))
		{
			currentState = STATE_CREDIT;
		}
	}

	void updateGame() {
		//int healthSize = PLAYER.getMaxHealth();
		//int currAmmo = PLAYER.getMissileAmmo();
		// tells graphics what to draw
		GFX->addToSpriteRenderList(&gameSpriteIDs[0], gameSpriteIDs.size());

		// update health bar and number of missiles

		//Health bar update
//		for(healthSize; healthSize > PLAYER.getHealth(); --healthSize) //reduce the health bar size from the difference.
		{
			//hpBarSize.right = 500 * (healthSize / 100);
			// TODO: SAM: commented out tillI fix the background issue
			//GFX->updateSprite(gameSpriteIDs.at(HEALTH), D3DXVECTOR3(350, 400, 0.0f), hpBarSize); // update the information
		}

		//Missle Bar Update
		//for (int i = 0; i < )
		//GFX->text->updateText(currAmmogetMissile//update the information
		
		// Main has getHealth(), getMaxHealth(), and getMissileAmmo() functions that we can use. 
		//  They've also provided me with their code. I haven't uploaded it, but if you want to 
		//  see it, let me know.
	}

	void updatePause(const bool paused) {
		if (paused)
		{
			GFX->addToSpriteRenderList(&pauseSpriteIDs[0], pauseSpriteIDs.size());
		}
	}
	void updateCredits(float x, float y) {
		// tell Graphics which sprites to draw
		GFX->addToSpriteRenderList(&exitSpriteIDs[0], exitSpriteIDs.size());
		currentState = STATE_CREDIT;

		if (spriteClicked(x, y, exitSpriteIDs[0])) {
			currentState = STATE_MENU;
		}
	}
	void updateExit() {
		// tell Graphics which sprites to draw
		//GFX->addToSpriteRenderList(&exitSpriteIDs[0], exitSpriteIDs.size());
		currentState = STATE_EXIT;
	}
};