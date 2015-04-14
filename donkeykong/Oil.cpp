
//  Created by Ryan Moran on 4/10/14
//  Copyright (c) 2014 Ryan Moran. All rights reserved.

#include "Object.h"
#include "Oil.h"
#include <math.h>
#include <iostream>


using namespace std;

//Constructor, sets parameters and loads surface
Oil::Oil ():Object (25, 19, 16, 430, 0, 0, 0, 1, 1, 2, 0, 0, 100)
{
  setAnimation ();
}

//function used to flip through images of sprite sheet for animation
void
Oil::updateAnimation ()
{
  oldTime = SDL_GetTicks ();
  currentFrame++;
  if (currentFrame >= maxFrames)
    {
      currentFrame = 0;
    }
}


//Function sets animation parameters according to state of mario
void
Oil::setAnimation ()
{
  switch (currentState)
    {
    case 1:			//burning oil
      spritesheetx = 125;
      spritesheety = 255;
      currentFrame = 1;
      maxFrames = 2;		//flipping through two image frames
      height = 25;
      width = 19;
      break;
    }
}
