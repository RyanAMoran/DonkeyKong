//
//  Object.h
//  donkeykong
//
//  Created by Ryan Moran on 3/20/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.
//  Class for mario object

#ifndef OBJECT_H
#define OBJECT_H
  
#include <SDL/SDL.h>
#include <string>
#include "Floor.h"
  using namespace std;

{

	    double accelY, int cState, int cFrame, int mFrames, int climb,
	    int oTime, int fRate);
  //non default constructor
  
  int spritesheety;		//Variable for y position of image on sprite sheet
  int height;			//Height of image on sprite sheet
  int width;			//Width of image on sprite sheet
  double xpos;			//X position of object on screen
  double ypos;			//Y position of object on screen
  double vx;			//X velocity of object
  double vy;			//Y velocity of object
  double ax;			//X acceleration of object
  double ay;			//Y acceleration of object
  int currentState;		//current animation state of object
  int currentFrame;		//current animation frame of object
  int maxFrames;		//max number of frames for animation state
  int climbing;			//1 when object is climbing, 0 when not
  int oldTime;			//Variable used to control time
  int frameRate;		//Frame rate of animation
  int jumping;			//1 when object is jumping, 0 when not
  int alive;			//1 when object is alive, 0 when not
  SDL_Surface *marioSurface;	//SDL surface for sprite sheet
  Floor floors[7];
  
  void climbingdisplay (SDL_Surface *, SDL_Surface *, int, int, int, int, int, int);	//Displays object
  
  
    //Get functions
  int getspritesheetx ();
  
  
  
  
  
  
  
  
  
  
  
  
  int floorNumber;		//tells which floor object is on
  int previousFloor;		//tells which floor object was on when last placed on a floor
  int direction;		//0 when object is going down, 1 when going up
  
  void setcurrentstate (int);	//Determines animation state based on objects current variables
  
  
  
  
  
  
  



#endif /* 