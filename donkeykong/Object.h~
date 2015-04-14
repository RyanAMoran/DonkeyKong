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
class Object
{
public:Object (int h, int w, int x, int y, double velX, double velY, double accelY, int cState, int cFrame, int mFrames, int climb, int oTime, int fRate);
																			//non default constructor
  int spritesheetx;		//Variable for x position of image on sprite sheet
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
  void display (SDL_Surface *, SDL_Surface *, int, int, int, int, int, int);	//Displays object
  void climbingdisplay (SDL_Surface *, SDL_Surface *, int, int, int, int, int, int);	//Displays object
  void updateAnimation ();	//Increments frame
  
    //Get functions
  int getspritesheetx ();
  int getspritesheety ();
  int getheight ();
  int getwidth ();
  int getxpos ();
  int getypos ();
  int getcurrentframe ();
  int getcurrentstate ();
  int getclimbing ();
  int getoldtime ();
  int getframerate ();
  SDL_Surface * getMarioSurface ();
  int onFloor;		//1 when object is on floor, 0 when not
  int floorNumber;		//tells which floor object is on
  int previousFloor;		//tells which floor object was on when last placed on a floor
  int direction;		//0 when object is going down, 1 when going up
  virtual void setAnimation ();	//Sets animation parameters according to animation state
  void setcurrentstate (int);	//Determines animation state based on objects current variables
  void Transparent (SDL_Surface * Surf_Dest, int R, int G, int B);	//Makes pink background of mario image transparent
  void handle_input (SDL_Event);	//Handles the keyboard input and adjusts mario's velocity and such accordingly
  void cleanUp ();
  void initializeFloors ();	//Initializes the parameters of the floors
  int checkOnFloor (int);	//Function to check whether or not an object is on top of a floor
  int checkOnLadder (int);	//Function to check whether an object is on a ladder
  int checkOnLadderBarrel ();	// Checks to see if barrel is above or below a ladder
private:};


#endif	/*  */
