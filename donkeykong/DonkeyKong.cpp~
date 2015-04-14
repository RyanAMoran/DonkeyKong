//Random change
//  Created by Jacob Gavin on 3/27/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.

#include "Object.h"		//using inheritance from base class
#include "DonkeyKong.h"
#include <math.h>
#include <iostream>


using namespace std;

//Constructor, sets parameters and loads surface
DonkeyKong::DonkeyKong ():Object (33, 43, 94, 150, 0, 0, 0, 3, 0, 2, 0, 0, 100)
{
  setAnimation ();
}

//function to flip through frames of sprite sheet to animate donkey kong motion
void
DonkeyKong::updateAnimation ()
{
  oldTime = SDL_GetTicks ();
  currentFrame++;
  if (currentFrame >= maxFrames)
    {
      currentFrame = 0;		//ensures currentFrame never exceeds the max amount of frames for a given animation state
    }

}


//Function sets animation parameters according to state of donkey kong
void
DonkeyKong::setAnimation ()
{
  switch (currentState)
    {
    case 1:			//standing still
      spritesheetx = 58;	//x location on sprite sheet
      spritesheety = 150;	//y location on sprite sheet
      currentFrame = 1;		//always begins with frame 1
      maxFrames = 1;		//only 1 total frame
      height = 33;		//height of donkey kong on sprite sheet
      width = 47;		//width of donkey kong on sprite sheet
      break;
    case 2:			//pound chest
      spritesheetx = 57;
      spritesheety = 149;
      currentFrame = 0;
      maxFrames = 4;		//chest pounding animation consists of flipping through 4 total frames on sprite sheet
      height = 33;
      width = 47;
      break;
    case 3:			//throw barrel
      spritesheetx = 8;
      spritesheety = 149;
      currentFrame = 2;		//begin on frame 2 when throwing barrel case occurs
      maxFrames = 6;		// final frame of throwing barrel case is frame 6
      height = 33;
      width = 48;
    }
}
