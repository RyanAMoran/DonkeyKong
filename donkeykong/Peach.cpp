
//  Created by Jacob Gavin on 3/27/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.

#include "Object.h"		//using inheritance from base class
#include "Peach.h"
#include <math.h>
#include <iostream>


using namespace std;

//Constructor, sets parameters and loads surface
Peach::Peach ():Object (21, 20, 250, 100, 0, 0, 0, 1, 1, 2, 0, 0, 100)
{
  setAnimation ();
}

//function that flips through frames of spritesheet image
void
Peach::updateAnimation ()
{
  oldTime = SDL_GetTicks ();
  currentFrame++;
  if (currentFrame >= maxFrames)
    {
      currentFrame = 0;		//ensures currentFrame never exceeds the max amount of frames for a given animation state
    }
}


//Function sets animation parameters according to state of mario
void
Peach::setAnimation ()
{
  switch (currentState)
    {
    case 1:			//running left
      spritesheetx = 110;	//x location to look at on sprite sheet
      spritesheety = 124;	//y location to look at on sprite sheet
      currentFrame = 1;		//always begins at frame 1 when case 1 occurs
      maxFrames = 2;		//running left is animated by flipping back and forth between two frames
      height = 21;		//height of peach image on sprite sheet
      width = 22;		//width of peach image on sprite sheet
      break;
    case 2:			//running right
      spritesheetx = 154;
      spritesheety = 124;
      currentFrame = 1;
      maxFrames = 2;		//running right consists of flipping between two frames
      height = 21;
      width = 22;
      break;
    }
}
