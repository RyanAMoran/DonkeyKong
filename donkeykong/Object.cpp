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
  

//Non-default Constructor, sets parameters and loads surface
  Object::Object (int h, int w, int x, int y, double velX, double velY,
		  double accelY, int cState, int cFrame, int mFrames,
		  int climb, int oTime, int fRate)
{
  
    //Set variable based on constructor input
    height = h;
  
  
  
  
  
  
  
  
  
  
  
  
  
    //Load sprite sheet surface
    marioSurface = SDL_LoadBMP ("DonkeyKong.bmp");
  
    //Set the animation parameters
    setAnimation ();
  
    //Make pink background of sprite sheet transparent
    Transparent (marioSurface, 255, 0, 255);


//Return Mario surface
  SDL_Surface * Object::getMarioSurface ()
{
  



//Return spritesheetx
  int
Object::getspritesheetx ()
{
  



//Return spritesheety
  int
Object::getspritesheety ()
{
  



//Return image height
  int
Object::getheight ()
{
  



//Return image width
  int
Object::getwidth ()
{
  



//Return x position
  int
Object::getxpos ()
{
  



//Return y position
  int
Object::getypos ()
{
  



//Return current frame
  int
Object::getcurrentframe ()
{
  



//Return current state
  int
Object::getcurrentstate ()
{
  



//Set current state
  void
Object::setcurrentstate (int state)
{
  


//Retrun climbing
  int
Object::getclimbing ()
{
  



//Return old time
  int
Object::getoldtime ()
{
  



//Return frame rate
  int
Object::getframerate ()
{
  



//Display function takes in parameters of clipping from sprite sheet, makes rectangle, and blits the rectangle
  void
Object::display (SDL_Surface * Surf_Dest, SDL_Surface * Surf_Src, int X,
		 int Y, int X2, int Y2, int W, int H)
{
  
    //Create destination rectangle
    SDL_Rect DestR;
  
  
  
    //Create surface rectangle
    SDL_Rect SrcR;
  
  
  
  
  
    //Blit surface to screen
    SDL_BlitSurface (Surf_Src, &SrcR, Surf_Dest, &DestR);


//Display function takes in parameters of clipping from sprite sheet, makes rectangle, and blits the rectangle, only used for mario display when climbing = 1
  void
Object::climbingdisplay (SDL_Surface * Surf_Dest, SDL_Surface * Surf_Src,
			 int X, int Y, int X2, int Y2, int W, int H)
{
  
    //Create destination rectangle
    SDL_Rect DestR;
  
  
  
    //CReate surface rectangle
    SDL_Rect SrcR;
  
  
  
  
  
    //Blit surface to screen
    SDL_BlitSurface (Surf_Src, &SrcR, Surf_Dest, &DestR);


//Function updates animation frames
  void
Object::updateAnimation ()
{
  
  
  
    {
      
    



//Function sets animation parameters according to state of mario
  void
Object::setAnimation ()
{
  
    {
    
      spritesheetx = 134;
      
      
      
      
      
      
    
      spritesheetx = 153;
      
      
      
      
      
      
    
      spritesheetx = 92;
      
      
      
      
      
      
    
      spritesheetx = 172;
      
      
      
      
      
      
    
      spritesheetx = 69;
      
      
      
      
      
      
    
      spritesheetx = 183;
      
      
      
      
      
      
    
      spritesheetx = 97;
      
      
      
      
      
      
    
      spritesheetx = 156;
      
      
      
      
      
      
    
      spritesheetx = 123;
      
      
      
      
      
      
    
      spritesheetx = 123;
      
      
      
      
      
      
    
      spritesheetx = 142;
      
      
      
      
      
      
    
      spritesheetx = 92;
      
      
      
      
      
      
    
      spritesheetx = 194;
      
      
      
      
      
      
    



//Function makes pink background on mario surface transparent
  void
Object::Transparent (SDL_Surface * Surf_Dest, int R, int G, int B)
{
  
		     SDL_MapRGB (Surf_Dest->format, R, G, B));


//Free sprite sheet surface
  void
Object::cleanUp ()
{
  


//Function to initialize floors
  void
Object::initializeFloors ()
{
  
    //Set floor 1 parameters
    floors[0].setslope (-.009107);
  
  
  
  
  
  
    //Set floor 2 parameters
    floors[1].setslope (.03777);
  
  
  
  
  
  
    //Set floor 3 parameters  
    floors[2].setslope (-.04297);
  
  
  
  
  
  
    //Set floor 4 parameters
    floors[3].setslope (.04118);
  
  
  
  
  
  
    //Set floor 5 parameters
    floors[4].setslope (-.0435);
  
  
  
  
  
  
    //Set floor 6 parameters
    floors[5].setslope (.01569);
  
  
  
  
  
  
    //Set floor 7 parameters
    floors[6].setslope (0);
  
  
  
  
  


//CheckonFLoor function checks to see if an object is on top of a floor, returns 1 if yes, 0 if no
  int
Object::checkOnFloor (int hasHammer)
{
  
    //Create an array of the y position of the 7 floors based on what objects x position is using the slope equation. 
  int yfloor[7];
  
  
  
  
  
  
  
  
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
		  
		  
		  
		  
		  
		
	    
	
      
	//Check floor 2 when object has a hammer by checking to see if object is between the min and max range
	if (hasHammer && previousFloor != 2)
	{
	  
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
		  
		  
		  
		  
		  
		
	    
	
      
	//Check floor 1 when object has a hammer by checking to see if object is between the min and max range
	if (hasHammer && previousFloor != 1)
	{
	  
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
	      
	    
	  
	    //Else return 1 
	    else
	    {
	      
	    
	
    
  
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
	      
	    
	  
	    //Return 2 if object is in front a broken ladder moving down
	    else if ((previousFloor == 2) && (direction == 0)
		     && (xpos + width / 2 >= 200 && xpos + width / 2 <= 220)
		     && (ypos + height >= 420))
	    {
	      
	    
	  
	    //Else return 1
	    else
	    {
	      
	    
	
    
  
    //Check when object is on floor 2 and trying to move up
    if ((previousFloor == 2) && (direction == 1))
    
    {
      
	//Check to see if object is infront of ladder, return 1 if yes
	if ((xpos + width / 2 >= 80 && xpos + width / 2 <= 100)
	    || (xpos + width / 2 >= 236 && xpos + width / 2 <= 256))
	
	{
	  
	
    
  
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
	      
	    
	  
	    //Else return 1
	    else
	    {
	      
	    
	
    
  
    //Check when object is between floors 2 and 3
    if (((previousFloor == 2) || (previousFloor == 3))
	&& ((floorNumber == 2) || (floorNumber == 3)) && (onFloor == 0))
    {
      
	//Return 1 if object is infront of ladder
	if ((xpos + width / 2 >= 80 && xpos + width / 2 <= 100)
	    || (xpos + width / 2 >= 236 && xpos + width / 2 <= 256))
	
	{
	  
	
    
  
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
	      
	    
	  
	    //Return 1 if in front of good ladder
	    else
	    {
	      
	    
	
    
  
    //Check when object is on 3rd floor trying to move down
    if ((previousFloor == 3) && (direction == 0))
    
    {
      
	//Return 1 if object is above a ladder
	if ((xpos + width / 2 >= 80 && xpos + width / 2 <= 100)
	    || (xpos + width / 2 >= 236 && xpos + width / 2 <= 256))
	
	{
	  
	
    
  
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
	      
	    
	  
	    //Return 1 if object is in front of a good ladder
	    else
	    {
	      
	    
	
    
  
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
	      
	    
	  
	    //Else return 1
	    else
	    {
	      
	    
	
    
  
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
	      
	    
	  
	    //Else return 1
	    else
	    {
	      
	    
	
    
  
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
	      
	    
	  
	    //Return 2 when object is infront of broken ladder going down
	    else if (xpos + width / 2 >= 393 && xpos + width / 2 <= 413
		     && ypos + height >= 251 && ypos + height <= 271
		     && direction == 0)
	    {
	      
	    
	  
	    //Else return 1
	    else
	    {
	      
	    
	
    
  
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
	      
	    
	  
	    //Return 1 if in front of good ladder
	    else
	    {
	      
	    
	
    
  
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
	      
	    
	  
	    //Else return 1
	    else
	    {
	      
	    
	
    
  
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
	      
	    
	  
	    //Return 2 if object is infront of broken ladder and moving down
	    else if (xpos + width / 2 >= 235 && xpos + width / 2 <= 255
		     && ypos + height >= 205 && ypos + height <= 225
		     && direction == 0)
	    {
	      
	    
	  
	    //Else return 1
	    else
	    {
	      
	    
	
    
  
    //Check when object is on floor 6 and trying to move up
    if ((previousFloor == 6) && (direction == 1))
    
    {
      
	//Return 1 if object is in front of ladder
	if ((xpos + width / 2 >= 191 && xpos + width / 2 <= 211)
	    || (xpos + width / 2 >= 216 && xpos + width / 2 <= 236)
	    || (xpos + width / 2 >= 334 && xpos + width / 2 <= 354))
	
	{
	  
	
    
  
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
	      
	    
	  
	    //Else return 1
	    else
	    {
	      
	    
	
    
  
    //Check when object is in between floors 6 and 7
    if (((previousFloor == 6) || (previousFloor == 7))
	&& ((floorNumber == 6) || (floorNumber == 7)) && (onFloor == 0))
    {
      
	//Check to see if object is infront of ladder and return 1
	if ((xpos + width / 2 >= 191 && xpos + width / 2 <= 211)
	    || (xpos + width / 2 >= 216 && xpos + width / 2 <= 236)
	    || (xpos + width / 2 >= 334 && xpos + width / 2 <= 354))
	
	{
	  
	
    
  
    //Check when object is on floor 7 and trying to move down
    if ((previousFloor == 7) && (direction == 0))
    
    {
      
	//Return 1 if in front of ladder
	if ((xpos + width / 2 >= 191 && xpos + width / 2 <= 211)
	    || (xpos + width / 2 >= 216 && xpos + width / 2 <= 236)
	    || (xpos + width / 2 >= 334 && xpos + width / 2 <= 354))
	
	{
	  
	
    
  
    //Return 0 because object is not in front of ladder
    return 0;



// Checks to see if barrel is above or below a ladder
// Return 2 means below a ladder, 1 means above a ladder, 0 if neither
  int
Object::checkOnLadderBarrel ()
{
  
    
    {
      
    
  
    
    {
      
    
  
    
    {
      
    
  
    
    {
      
    
  
    
    {
      
    
  
    
    {
      
    
  
    
    {
      
    
  
    
    {
      
    
  
    
    {
      
    
  
    
    {
      
    
  
    
    {
      
    
  
    
    {
      
    
  
    
    {
      
    
  
    
    {
      
    
  
    
    {
      
    
  
    
    {
      
    
  


