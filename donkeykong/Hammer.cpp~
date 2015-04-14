//  Created by Ryan Moran on 4/1/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.


#include "Object.h" //using inheritance to access base class functions
#include "Hammer.h"
#include <math.h>
#include <iostream>


using namespace std;

//Constructor, sets parameters and loads surface
Hammer::Hammer ():Object (18, 10, 45, 315, 0, 0, 0, 1, 1, 1, 0, 0, 100)
{
  setAnimation ();
}

//note that once mario grabs the hammer, we actually switch to combined images of mario and the hammer, which can be seen as case(s) in mario.cpp setAnimation

//Function sets animation parameters according to state of mario
void
Hammer::setAnimation ()
{
  switch (currentState)
    {
    case 1:
      spritesheetx = 195; //x location on sprite sheet
      spritesheety = 263; //y location on sprite sheet
      currentFrame = 0;
      maxFrames = 1;
      height = 18;
      width = 10;
      break;
    }
}
