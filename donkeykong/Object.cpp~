//
//  Object.cpp
//  SDL_Tutorial
//
//  Created by Ryan Moran on 3/20/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.
//

#include "Object.h"
#include "math.h"
#include <iostream>
  using namespace std;

//Non-default Constructor, sets parameters and loads surface
  Object::Object (int h, int w, int x, int y, double velX, double velY,
		  double accelY, int cState, int cFrame, int mFrames,
		  int climb, int oTime, int fRate)
{
  
    //Set variable based on constructor input
    height = h;
  width = w;
  xpos = x;
  ypos = y;
  vx = velX;
  vy = velY;
  ay = accelY;
  currentState = cState;
  currentFrame = cFrame;
  maxFrames = mFrames;
  climbing = climb;
  oldTime = oTime;
  frameRate = fRate;
  
    //Load sprite sheet surface
    marioSurface = SDL_LoadBMP ("DonkeyKong.bmp");
  
    //Set the animation parameters
    setAnimation ();
  
    //Make pink background of sprite sheet transparent
    Transparent (marioSurface, 255, 0, 255);
} 

//Return Mario surface
  SDL_Surface * Object::getMarioSurface ()
{
  return marioSurface;
}


//Return spritesheetx
  int
Object::getspritesheetx ()
{
  return spritesheetx;
}


//Return spritesheety
  int
Object::getspritesheety ()
{
  return spritesheety;
}


//Return image height
  int
Object::getheight ()
{
  return height;
}


//Return image width
  int
Object::getwidth ()
{
  return width;
}


//Return x position
  int
Object::getxpos ()
{
  return xpos;
}


//Return y position
  int
Object::getypos ()
{
  return ypos;
}


//Return current frame
  int
Object::getcurrentframe ()
{
  return currentFrame;
}


//Return current state
  int
Object::getcurrentstate ()
{
  return currentState;
}


//Set current state
  void
Object::setcurrentstate (int state)
{
  currentState = state;
} 

//Retrun climbing
  int
Object::getclimbing ()
{
  return climbing;
}


//Return old time
  int
Object::getoldtime ()
{
  return oldTime;
}


//Return frame rate
  int
Object::getframerate ()
{
  return frameRate;
}


//Display function takes in parameters of clipping from sprite sheet, makes rectangle, and blits the rectangle
  void
Object::display (SDL_Surface * Surf_Dest, SDL_Surface * Surf_Src, int X,
		 int Y, int X2, int Y2, int W, int H)
{
  
    //Create destination rectangle
    SDL_Rect DestR;
  DestR.x = X;
  DestR.y = Y;
  
    //Create surface rectangle
    SDL_Rect SrcR;
  SrcR.x = X2;
  SrcR.y = Y2;
  SrcR.w = W;
  SrcR.h = H;
  
    //Blit surface to screen
    SDL_BlitSurface (Surf_Src, &SrcR, Surf_Dest, &DestR);
} 

//Display function takes in parameters of clipping from sprite sheet, makes rectangle, and blits the rectangle, only used for mario display when climbing = 1
  void
Object::climbingdisplay (SDL_Surface * Surf_Dest, SDL_Surface * Surf_Src,
			 int X, int Y, int X2, int Y2, int W, int H)
{
  
    //Create destination rectangle
    SDL_Rect DestR;
  DestR.x = X;
  DestR.y = Y;
  
    //CReate surface rectangle
    SDL_Rect SrcR;
  SrcR.x = X2;
  SrcR.y = Y2;
  SrcR.w = W;
  SrcR.h = H;
  
    //Blit surface to screen
    SDL_BlitSurface (Surf_Src, &SrcR, Surf_Dest, &DestR);
} 

//Function updates animation frames
  void
Object::updateAnimation ()
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
Object::setAnimation ()
{
  switch (currentState)
    {
    case 1:			//Facing right
      spritesheetx = 134;
      spritesheety = 0;
      currentFrame = 1;
      maxFrames = 1;
      height = 20;
      width = 20;
      break;
    case 2:			//Running right
      spritesheetx = 153;
      spritesheety = 0;
      currentFrame = 1;
      maxFrames = 1;
      height = 20;
      width = 20;
      break;
    case 3:			//Running left
      spritesheetx = 92;
      spritesheety = 0;
      currentFrame = 1;
      maxFrames = 2;
      height = 20;
      width = 20;
      break;
    case 4:			//Running left2
      spritesheetx = 172;
      spritesheety = 0;
      currentFrame = 1;
      maxFrames = 2;
      height = 20;
      width = 20;
      break;
    case 5:			//Running left with hammer
      spritesheetx = 69;
      spritesheety = 40;
      currentFrame = 1;
      maxFrames = 2;
      height = 31;
      width = 27;
      break;
    case 6:			//Running right with hammer
      spritesheetx = 183;
      spritesheety = 40;
      currentFrame = 1;
      maxFrames = 2;
      height = 31;
      width = 27;
      break;
    case 7:			//Facing left with hammer
      spritesheetx = 97;
      spritesheety = 40;
      currentFrame = 1;
      maxFrames = 2;
      height = 31;
      width = 27;
      break;
    case 8:			//Facing left with hammer
      spritesheetx = 156;
      spritesheety = 40;
      currentFrame = 1;
      maxFrames = 2;
      height = 31;
      width = 27;
      break;
    case 9:			//Climbing
      spritesheetx = 123;
      spritesheety = 20;
      currentFrame = 1;
      maxFrames = 2;
      height = 20;
      width = 19;
      break;
    case 10:			//Stopped on ladder
      spritesheetx = 123;
      spritesheety = 20;
      currentFrame = 1;
      maxFrames = 1;
      height = 20;
      width = 19;
      break;
    case 11:			//Facing ladder
      spritesheetx = 142;
      spritesheety = 20;
      currentFrame = 1;
      maxFrames = 1;
      height = 20;
      width = 19;
      break;
    case 12:			//Running left
      spritesheetx = 92;
      spritesheety = 0;
      currentFrame = 1;
      maxFrames = 1;
      height = 20;
      width = 20;
      break;
    case 13:			//Jumpng right
      spritesheetx = 194;
      spritesheety = 0;
      currentFrame = 1;
      maxFrames = 1;
      height = 20;
      width = 20;
      break;
    }
}


//Function makes pink background on mario surface transparent
  void
Object::Transparent (SDL_Surface * Surf_Dest, int R, int G, int B)
{
  SDL_SetColorKey (Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL,
		     SDL_MapRGB (Surf_Dest->format, R, G, B));
} 

//Free sprite sheet surface
  void
Object::cleanUp ()
{
  SDL_FreeSurface (marioSurface);
} 

//Function to initialize floors
  void
Object::initializeFloors ()
{
  
    //Set floor 1 parameters
    floors[0].setslope (-.009107);
  floors[0].setyint (455);
  floors[0].setxmin (0);
  floors[0].setxmax (550);
  floors[0].setymin (420);
  floors[0].setymax (455);
  
    //Set floor 2 parameters
    floors[1].setslope (.03777);
  floors[1].setyint (388);
  floors[1].setxmin (0);
  floors[1].setxmax (503);
  floors[1].setymin (378);
  floors[1].setymax (415);
  
    //Set floor 3 parameters  
    floors[2].setslope (-.04297);
  floors[2].setyint (352);
  floors[2].setxmin (38);
  floors[2].setxmax (550);
  floors[2].setymin (322);
  floors[2].setymax (361);
  
    //Set floor 4 parameters
    floors[3].setslope (.04118);
  floors[3].setyint (277);
  floors[3].setxmin (0);
  floors[3].setxmax (510);
  floors[3].setymin (265);
  floors[3].setymax (303);
  
    //Set floor 5 parameters
    floors[4].setslope (-.0435);
  floors[4].setyint (245);
  floors[4].setxmin (38);
  floors[4].setxmax (550);
  floors[4].setymin (201);
  floors[4].setymax (250);
  
    //Set floor 6 parameters
    floors[5].setslope (.01569);
  floors[5].setyint (180);
  floors[5].setxmin (0);
  floors[5].setxmax (510);
  floors[5].setymin (140);
  floors[5].setymax (195);
  
    //Set floor 7 parameters
    floors[6].setslope (0);
  floors[6].setyint (123);
  floors[6].setxmin (235);
  floors[6].setxmax (353);
  floors[6].setymin (0);
  floors[6].setymax (130);
} 

//CheckonFLoor function checks to see if an object is on top of a floor, returns 1 if yes, 0 if no
  int
Object::checkOnFloor (int hasHammer)
{
  
    //Create an array of the y position of the 7 floors based on what objects x position is using the slope equation. 
  int yfloor[7];
  yfloor[0] = floors[0].getslope () * xpos + floors[0].getyint ();
  yfloor[1] = floors[1].getslope () * xpos + floors[1].getyint ();
  yfloor[2] = floors[2].getslope () * xpos + floors[2].getyint ();
  yfloor[3] = floors[3].getslope () * xpos + floors[3].getyint ();
  yfloor[4] = floors[4].getslope () * xpos + floors[4].getyint ();
  yfloor[5] = floors[5].getslope () * xpos + floors[5].getyint ();
  yfloor[6] = floors[6].getslope () * xpos + floors[6].getyint ();
  
    //Check to see if object is on floor if object is not climbing, or if object is climbing and within 20 of the floor they are headed to
    if ((climbing == 0)
	|| ((climbing == 1) && (direction == 0)
	    && (yfloor[floorNumber - 1] - (ypos + height) < 20))
	|| ((climbing == 1) && (direction == 1)
	    && ((ypos + height) - yfloor[floorNumber - 1] < 20)))
    {
      
	//Check floor 7 by checking to see if object is between the min and max range
	if ((ypos + height < floors[6].getymax ())
	    && (ypos + height > floors[6].getymin ()))
	{
	  
	    //Check to see if object is within x min and max
	    if ((xpos < floors[6].getxmax ())
		&& (xpos + width > floors[6].getxmin ()))
	    {
	      
		//Lets mario climb down from top floor
		if ((climbing == 1) && (direction == 0)
		    && (ypos + height >= yfloor[6]))
		return 0;
	      
		//If objects is below floor but not more than 10 units below, place object on top of floor
		if (((ypos + height) - yfloor[6] <= 10)
		    && ((ypos + height) - yfloor[6] >= 0))
		{
		  
		    //If object is dead, stop it from moving
		    if (!alive)
		    vx = 0;
		  
		    //If object is jumping, set jumping to zero
		    if (jumping)
		    jumping = 0;
		  
		    //Set on floor and set variables
		    ypos = (yfloor[6]) - height;
		  vy = 0;
		  onFloor = 1;
		  floorNumber = 7;
		  previousFloor = 7;
		  return yfloor[6];
		}
	    }
	}
      
	//Check floor 6 by checking to see if object is between the min and max range
	if ((ypos + height < floors[5].getymax ())
	    && (ypos + height > floors[5].getymin ()))
	{
	  
	    //Check to see if object is within x min and max
	    if ((xpos < floors[5].getxmax ())
		&& (xpos + width > floors[5].getxmin ()))
	    {
	      
		//If objects is below floor but not more than 10 units below, place object on top of floor               
		if (((ypos + height) - yfloor[5] <= 10)
		    && ((ypos + height) - yfloor[5] >= 0))
		{
		  
		    //If object is dead, stop it from moving
		    if (!alive)
		    vx = 0;
		  
		    //If object is jumping, set jumping to zero
		    if (jumping)
		    jumping = 0;
		  
		    //Set on floor and set variables
		    ypos = (yfloor[5]) - height;
		  vy = 0;
		  onFloor = 1;
		  floorNumber = 6;
		  previousFloor = 6;
		  return yfloor[5];
		}
	    }
	}
      
	//Check floor 5 by checking to see if object is between the min and max range
	if ((ypos + height < floors[4].getymax ())
	    && (ypos + height > floors[4].getymin ()))
	{
	  
	    //Check to see if object is within x min and max
	    if ((xpos < floors[4].getxmax ())
		&& (xpos + width > floors[4].getxmin ()))
	    {
	      
		//If objects is below floor but not more than 10 units below, place object on top of floor               
		if (((ypos + height) - yfloor[4] <= 10)
		    && ((ypos + height) - yfloor[4] >= 0))
		{
		  
		    //If object is dead, stop it from moving
		    if (!alive)
		    vx = 0;
		  
		    //If object is jumping, set jumping to zero
		    if (jumping)
		    jumping = 0;
		  
		    //Set on floor and set variables
		    ypos = (yfloor[4]) - height;
		  vy = 0;
		  onFloor = 1;
		  floorNumber = 5;
		  previousFloor = 5;
		  return yfloor[4];
		}
	    }
	}
      
	//Check floor 2 when object has a hammer by checking to see if object is between the min and max range
	if (hasHammer && previousFloor != 2)
	{
	  if ((ypos + height - 5 < floors[3].getymax ())
	       && (ypos + height > floors[3].getymin ()))
	    {
	      
		//Check to see if object is within x min and max
		if ((xpos < floors[3].getxmax ())
		    && (xpos + width > floors[3].getxmin ()))
		{
		  
		    //If objects is below floor but not more than 20 units below, place object on top of floor               
		    if (((ypos + height) - yfloor[3] <= 20)
			&& ((ypos + height) - yfloor[3] >= 0))
		    {
		      
			//If object is dead, stop it from moving
			if (!alive)
			vx = 0;
		      
			//If object is jumping, set jumping to zero
			if (jumping)
			jumping = 0;
		      
			//Set on floor and set variables
			ypos = (yfloor[3]) - height;
		      vy = 0;
		      onFloor = 1;
		      floorNumber = 4;
		      previousFloor = 4;
		      return yfloor[3];
		    }
		}
	    }
	}
      
	//Check floor 4 by checking to see if object is between the min and max range
	if ((ypos + height < floors[3].getymax ())
	    && (ypos + height > floors[3].getymin ()))
	{
	  
	    //Check to see if object is within x min and max
	    if ((xpos < floors[3].getxmax ())
		&& (xpos + width > floors[3].getxmin ()))
	    {
	      
		//If objects is below floor but not more than 10 units below, place object on top of floor               
		if (((ypos + height) - yfloor[3] <= 10)
		    && ((ypos + height) - yfloor[3] >= 0))
		{
		  
		    //If object is dead, stop it from moving
		    if (!alive)
		    vx = 0;
		  
		    //If object is jumping, set jumping to zero
		    if (jumping)
		    jumping = 0;
		  
		    //Set on floor and set variables
		    ypos = (yfloor[3]) - height;
		  vy = 0;
		  onFloor = 1;
		  floorNumber = 4;
		  previousFloor = 4;
		  return yfloor[3];
		}
	    }
	}
      
	//Check floor 1 when object has a hammer by checking to see if object is between the min and max range
	if (hasHammer && previousFloor != 1)
	{
	  if ((ypos + height - 5 < floors[2].getymax ())
	       && (ypos + height > floors[2].getymin ()))
	    {
	      
		//Check to see if object is within x min and max
		if ((xpos < floors[2].getxmax ())
		    && (xpos + width > floors[2].getxmin ()))
		{
		  
		    //If objects is below floor but not more than 20 units below, place object on top of floor               
		    if (((ypos + height) - yfloor[2] <= 20)
			&& ((ypos + height) - yfloor[2] >= 0))
		    {
		      
			//If object is dead, stop it from moving
			if (!alive)
			vx = 0;
		      
			//If object is jumping, set jumping to zero
			if (jumping)
			jumping = 0;
		      
			//Set on floor and set variables
			ypos = (yfloor[2]) - height;
		      vy = 0;
		      onFloor = 1;
		      floorNumber = 3;
		      previousFloor = 3;
		      return yfloor[2];
		    }
		}
	    }
	}
      
	//Check floor 3 by checking to see if object is between the min and max range
	if ((ypos + height < floors[2].getymax ())
	    && (ypos + height > floors[2].getymin ()))
	{
	  
	    //Check to see if object is within x min and max
	    if ((xpos < floors[2].getxmax ())
		&& (xpos + width > floors[2].getxmin ()))
	    {
	      
		//If objects is below floor but not more than 10 units below, place object on top of floor                              
		if (((ypos + height - 10) - yfloor[2] <= 10)
		    && ((ypos + height) - yfloor[2] >= 0))
		{
		  
		    //If object is dead, stop it from moving
		    if (!alive)
		    vx = 0;
		  
		    //If object is jumping, set jumping to zero
		    if (jumping)
		    jumping = 0;
		  
		    //Set on floor and set variables
		    ypos = (yfloor[2]) - height;
		  vy = 0;
		  onFloor = 1;
		  floorNumber = 3;
		  previousFloor = 3;
		  return yfloor[2];
		}
	    }
	}
      
	//Check floor 2 by checking to see if object is between the min and max range
	if ((ypos + height < floors[1].getymax ())
	    && (ypos + height > floors[1].getymin ()))
	{
	  
	    //Check to see if object is within x min and max
	    if ((xpos < floors[1].getxmax ())
		&& (xpos + width > floors[1].getxmin ()))
	    {
	      
		//If objects is below floor but not more than 10 units below, place object on top of floor                                             
		if (((ypos + height - 10) - yfloor[1] <= 10)
		    && ((ypos + height) - yfloor[1] >= 0))
		{
		  
		    //If object is dead, stop it from moving
		    if (!alive)
		    vx = 0;
		  
		    //If object is jumping, set jumping to zero
		    if (jumping)
		    jumping = 0;
		  
		    //Set on floor and set variables
		    ypos = (yfloor[1]) - height;
		  vy = 0;
		  onFloor = 1;
		  floorNumber = 2;
		  previousFloor = 2;
		  return yfloor[1];
		}
	    }
	}
      
	//Check floor 1 by checking to see if object is between the min and max range
	if (ypos + height > floors[0].getymin ())
	{
	  
	    //If objects is below floor but not more than 10 units below, place object on top of floor                             
	    if (((ypos + height) - yfloor[0] <= 10)
		&& ((ypos + height) - yfloor[0] >= 0))
	    {
	      
		//If object is dead, stop it from moving
		if (!alive)
		vx = 0;
	      
		//If object is jumping, set jumping to zero
		if (jumping)
		jumping = 0;
	      
		//Set on floor and set variables
		ypos = (yfloor[0]) - height;
	      onFloor = 1;
	      vy = 0;
	      floorNumber = 1;
	      previousFloor = 1;
	      return yfloor[0];
	    }
	}
    }
  return 0;
}


//Check on Ladder function checks to see if an object is on a ladder, returns 2 if on a broken ladder, returns 1 if on a good ladder, and returns 0 if not on a ladder
  int
Object::checkOnLadder (int direction)
{
  
    //Return 0 if object is jumping or moving side to side
    if (jumping || vx != 0)
    return 0;
  
    //Check when on the first floor and trying to go up
    if ((previousFloor == 1) && (direction == 1))
    
    {
      
	//Check if object is in front of a ladder
	if ((xpos + width / 2 >= 200 && xpos + width / 2 <= 220)
	    || (xpos + width / 2 >= 430 && xpos + width / 2 <= 450))
	
	{
	  
	    //Check if object is infront of broken ladder, return 2 if so
	    if ((xpos + width / 2 >= 200 && xpos + width / 2 <= 220)
		&& (ypos <= 436))
	    {
	      return 2;
	    }
	  
	    //Else return 1 
	    else
	    {
	      return 1;
	    }
	}
    }
  
    //Check for when object is between floors 1 and 2 
    if (((previousFloor == 1) || (previousFloor == 2))
	&& ((floorNumber == 1) || (floorNumber == 2)) && (onFloor == 0))
    {
      
	//Check to see if object is in front of a ladder
	if ((xpos + width / 2 >= 200 && xpos + width / 2 <= 220)
	    || (xpos + width / 2 >= 430 && xpos + width / 2 <= 450))
	
	{
	  
	    //Return 2 if object is in front of a broken ladder moving up
	    if ((previousFloor == 1) && (direction == 1)
		&& (xpos + width / 2 >= 200 && xpos + width / 2 <= 220)
		&& (ypos <= 436))
	    {
	      return 2;
	    }
	  
	    //Return 2 if object is in front a broken ladder moving down
	    else if ((previousFloor == 2) && (direction == 0)
		     && (xpos + width / 2 >= 200 && xpos + width / 2 <= 220)
		     && (ypos + height >= 420))
	    {
	      return 2;
	    }
	  
	    //Else return 1
	    else
	    {
	      return 1;
	    }
	}
    }
  
    //Check when object is on floor 2 and trying to move up
    if ((previousFloor == 2) && (direction == 1))
    
    {
      
	//Check to see if object is infront of ladder, return 1 if yes
	if ((xpos + width / 2 >= 80 && xpos + width / 2 <= 100)
	    || (xpos + width / 2 >= 236 && xpos + width / 2 <= 256))
	
	{
	  return 1;
	}
    }
  
    //Check when object is on floor 2 and trying to move down
    if ((previousFloor == 2) && (direction == 0))
    
    {
      
	//Check to see if object is above a ladder
	if ((xpos + width / 2 >= 200 && xpos + width / 2 <= 220)
	    || (xpos + width / 2 >= 430 && xpos + width / 2 <= 450))
	
	{
	  
	    //Return 2 if object is above a broken ladder
	    if ((xpos + width / 2 >= 200 && xpos + width / 2 <= 220)
		&& (ypos + height >= 420))
	    {
	      return 2;
	    }
	  
	    //Else return 1
	    else
	    {
	      return 1;
	    }
	}
    }
  
    //Check when object is between floors 2 and 3
    if (((previousFloor == 2) || (previousFloor == 3))
	&& ((floorNumber == 2) || (floorNumber == 3)) && (onFloor == 0))
    {
      
	//Return 1 if object is infront of ladder
	if ((xpos + width / 2 >= 80 && xpos + width / 2 <= 100)
	    || (xpos + width / 2 >= 236 && xpos + width / 2 <= 256))
	
	{
	  return 1;
	}
    }
  
    //Check when object is on floor 3 and trying to move up
    if ((previousFloor == 3) && (direction == 1))
    
    {
      
	//Check to see if object is infront of a ladder
	if ((xpos + width / 2 >= 155 && xpos + width / 2 <= 175)
	    || (xpos + width / 2 >= 275 && xpos + width / 2 <= 295)
	    || (xpos + width / 2 >= 432 && xpos + width / 2 <= 452))
	
	{
	  
	    //Return 2 if infront of a broken ladder
	    if ((xpos + width / 2 >= 155 && xpos + width / 2 <= 175)
		&& (ypos <= 318))
	    {
	      return 2;
	    }
	  
	    //Return 1 if in front of good ladder
	    else
	    {
	      return 1;
	    }
	}
    }
  
    //Check when object is on 3rd floor trying to move down
    if ((previousFloor == 3) && (direction == 0))
    
    {
      
	//Return 1 if object is above a ladder
	if ((xpos + width / 2 >= 80 && xpos + width / 2 <= 100)
	    || (xpos + width / 2 >= 236 && xpos + width / 2 <= 256))
	
	{
	  return 1;
	}
    }
  
    //Check when object is between floors 3 and 4
    if (((previousFloor == 3) || (previousFloor == 4))
	&& ((floorNumber == 3) || (floorNumber == 4)) && (onFloor == 0))
    {
      
	//Check to see if object is infront of a ladder
	if ((xpos + width / 2 >= 155 && xpos + width / 2 <= 175)
	    || (xpos + width / 2 >= 275 && xpos + width / 2 <= 295)
	    || (xpos + width / 2 >= 432 && xpos + width / 2 <= 452))
	
	{
	  
	    //Return 2 if object is infront of a broken ladder
	    if (xpos + width / 2 >= 155 && xpos + width / 2 <= 175
		&& direction == 0 && ypos + height >= 308
		&& ypos + height <= 318)
	    {
	      return 2;
	    }
	  
	    //Return 1 if object is in front of a good ladder
	    else
	    {
	      return 1;
	    }
	}
    }
  
    //Check when object is on floor 4 and trying to move up
    if ((previousFloor == 4) && (direction == 1))
    
    {
      
	//Check to see if object is infront of ladder
	if ((xpos + width / 2 >= 79 && xpos + width / 2 <= 99)
	    || (xpos + width / 2 >= 196 && xpos + width / 2 <= 216)
	    || (xpos + width / 2 >= 393 && xpos + width / 2 <= 413))
	
	{
	  
	    //Return 2 if in front of a broken ladder
	    if (xpos + width / 2 >= 393 && xpos + width / 2 <= 413
		&& ypos <= 273 && ypos >= 255)
	    {
	      return 2;
	    }
	  
	    //Else return 1
	    else
	    {
	      return 1;
	    }
	}
    }
  
    //Check when object is on floor 4 and trying to move down
    if ((previousFloor == 4) && (direction == 0))
    
    {
      
	//Check to see if object is infront of a ladder
	if ((xpos + width / 2 >= 155 && xpos + width / 2 <= 175)
	    || (xpos + width / 2 >= 275 && xpos + width / 2 <= 295)
	    || (xpos + width / 2 >= 432 && xpos + width / 2 <= 452))
	
	{
	  
	    //Return 2 if infront of a bad ladder
	    if (xpos + width / 2 >= 155 && xpos + width / 2 <= 175
		&& ypos + height >= 308)
	    {
	      return 2;
	    }
	  
	    //Else return 1
	    else
	    {
	      return 1;
	    }
	}
    }
  
    //Check when object is between floors 4 and 5
    if (((previousFloor == 4) || (previousFloor == 5))
	&& ((floorNumber == 4) || (floorNumber == 5)) && (onFloor == 0))
    {
      
	//Check to see if object is in front of a ladder
	if ((xpos + width / 2 >= 79 && xpos + width / 2 <= 99)
	    || (xpos + width / 2 >= 196 && xpos + width / 2 <= 216)
	    || (xpos + width / 2 >= 393 && xpos + width / 2 <= 413))
	
	{
	  
	    //Return 2 when object is in front of broken ladder going up
	    if (xpos + width / 2 >= 393 && xpos + width / 2 <= 413
		&& ypos <= 273 && ypos >= 255 && direction == 1)
	    {
	      return 2;
	    }
	  
	    //Return 2 when object is infront of broken ladder going down
	    else if (xpos + width / 2 >= 393 && xpos + width / 2 <= 413
		     && ypos + height >= 251 && ypos + height <= 271
		     && direction == 0)
	    {
	      return 2;
	    }
	  
	    //Else return 1
	    else
	    {
	      return 1;
	    }
	}
    }
  
    //Check when object is on floor 5 and trying to move up
    if ((previousFloor == 5) && (direction == 1))
    
    {
      
	//Check to see if object is in front of a ladder
	if ((xpos + width / 2 >= 235 && xpos + width / 2 <= 255)
	    || (xpos + width / 2 >= 431 && xpos + width / 2 <= 451))
	
	{
	  
	    //Return 2 if object is infront of a broken ladder
	    if (xpos + width / 2 >= 235 && xpos + width / 2 <= 255
		&& ypos <= 221 && ypos >= 201)
	    {
	      return 2;
	    }
	  
	    //Return 1 if in front of good ladder
	    else
	    {
	      return 1;
	    }
	}
    }
  
    //Check when object is on floor 5 and trying to move down
    if ((previousFloor == 5) && (direction == 0))
    
    {
      
	//Check to see if object is above a ladder
	if ((xpos + width / 2 >= 79 && xpos + width / 2 <= 99)
	    || (xpos + width / 2 >= 196 && xpos + width / 2 <= 216)
	    || (xpos + width / 2 >= 393 && xpos + width / 2 <= 413))
	
	{
	  
	    //Return 2 if object is above broken ladder
	    if (xpos + width / 2 >= 393 && xpos + width / 2 <= 413
		&& ypos + height >= 251 && ypos + height <= 271)
	    {
	      return 2;
	    }
	  
	    //Else return 1
	    else
	    {
	      return 1;
	    }
	}
    }
  
    //Check for when object is between floors 5 and 6
    if (((previousFloor == 5) || (previousFloor == 6))
	&& ((floorNumber == 5) || (floorNumber == 6)) && (onFloor == 0))
    {
      
	//Check to see if object is in front of a ladder
	if ((xpos + width / 2 >= 235 && xpos + width / 2 <= 255)
	    || (xpos + width / 2 >= 431 && xpos + width / 2 <= 451))
	
	{
	  
	    //Return 2 if object is in front of a broken ladder and moving up
	    if (xpos + width / 2 >= 235 && xpos + width / 2 <= 255
		&& ypos <= 221 && ypos >= 241 && direction == 1)
	    {
	      return 2;
	    }
	  
	    //Return 2 if object is infront of broken ladder and moving down
	    else if (xpos + width / 2 >= 235 && xpos + width / 2 <= 255
		     && ypos + height >= 205 && ypos + height <= 225
		     && direction == 0)
	    {
	      return 2;
	    }
	  
	    //Else return 1
	    else
	    {
	      return 1;
	    }
	}
    }
  
    //Check when object is on floor 6 and trying to move up
    if ((previousFloor == 6) && (direction == 1))
    
    {
      
	//Return 1 if object is in front of ladder
	if ((xpos + width / 2 >= 191 && xpos + width / 2 <= 211)
	    || (xpos + width / 2 >= 216 && xpos + width / 2 <= 236)
	    || (xpos + width / 2 >= 334 && xpos + width / 2 <= 354))
	
	{
	  return 1;
	}
    }
  
    //Check when object is on floor 6 and trying to move down
    if ((previousFloor == 6) && (direction == 0))
    
    {
      
	//Check to see if object is above ladder
	if ((xpos + width / 2 >= 235 && xpos + width / 2 <= 255)
	    || (xpos + width / 2 >= 431 && xpos + width / 2 <= 451))
	
	{
	  
	    //Return 2 if object is above broken ladder
	    if (xpos + width / 2 >= 235 && xpos + width / 2 <= 255
		&& ypos + height >= 205 && ypos + height <= 225)
	    {
	      return 2;
	    }
	  
	    //Else return 1
	    else
	    {
	      return 1;
	    }
	}
    }
  
    //Check when object is in between floors 6 and 7
    if (((previousFloor == 6) || (previousFloor == 7))
	&& ((floorNumber == 6) || (floorNumber == 7)) && (onFloor == 0))
    {
      
	//Check to see if object is infront of ladder and return 1
	if ((xpos + width / 2 >= 191 && xpos + width / 2 <= 211)
	    || (xpos + width / 2 >= 216 && xpos + width / 2 <= 236)
	    || (xpos + width / 2 >= 334 && xpos + width / 2 <= 354))
	
	{
	  return 1;
	}
    }
  
    //Check when object is on floor 7 and trying to move down
    if ((previousFloor == 7) && (direction == 0))
    
    {
      
	//Return 1 if in front of ladder
	if ((xpos + width / 2 >= 191 && xpos + width / 2 <= 211)
	    || (xpos + width / 2 >= 216 && xpos + width / 2 <= 236)
	    || (xpos + width / 2 >= 334 && xpos + width / 2 <= 354))
	
	{
	  return 1;
	}
    }
  
    //Return 0 because object is not in front of ladder
    return 0;
}


// Checks to see if barrel is above or below a ladder
// Return 2 means below a ladder, 1 means above a ladder, 0 if neither
  int
Object::checkOnLadderBarrel ()
{
  if (xpos < 433 && xpos > 431 && ypos > 205 && ypos < 207)
    
    {
      return 2;
    }
  if (xpos > 196 && xpos < 198 && ypos > 264 && ypos < 266)
    
    {
      return 2;
    }
  if (xpos > 76 && xpos < 78 && ypos > 259 && ypos < 261)
    
    {
      return 2;
    }
  if (xpos > 274 && xpos < 276 && ypos > 319 && ypos < 321)
    
    {
      return 2;
    }
  if (xpos > 431 && xpos < 433 && ypos > 312 && ypos < 314)
    
    {
      return 2;
    }
  if (xpos > 235 && xpos < 237 && ypos > 375 && ypos < 376)
    
    {
      return 2;
    }
  if (xpos > 78 && xpos < 80 && ypos > 369 && ypos < 371)
    
    {
      return 2;
    }
  if (xpos > 433 && xpos < 435 && ypos > 438 && ypos < 440)
    
    {
      return 2;
    }
  if (xpos > 196 && xpos < 198 && ypos == 224)
    
    {
      return 1;
    }
  if (xpos > 76 && xpos < 78 && ypos == 229)
    
    {
      return 1;
    }
  if (xpos > 431 && xpos < 433 && ypos == 174)
    
    {
      return 1;
    }
  if (xpos > 274 && xpos < 276 && ypos == 276)
    
    {
      return 1;
    }
  if (xpos > 431 && xpos < 433 && ypos == 282)
    
    {
      return 1;
    }
  if (xpos > 235 && xpos < 237 && ypos == 329)
    
    {
      return 1;
    }
  if (xpos > 78 && xpos < 80 && ypos == 336)
    
    {
      return 1;
    }
  if (xpos > 433 && xpos < 435 && ypos == 392)
    
    {
      return 1;
    }
  return 0;
}


