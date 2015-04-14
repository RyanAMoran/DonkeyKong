//
//  Barrel.h
//
//  Created by Ryan Moran on 4/1/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.
//  Class for barrel object

#ifndef BARREL_H
#define BARREL_H

#include "Object.h"
#include <SDL/SDL.h>
#include <string>
using namespace std;

class Barrel:public Object
{

public:
  Barrel ();			//Default Constructor

  void roll ();			//handles rolling a barrel down the floors

  virtual void setAnimation ();	//Sets animation parameters according to animation state
  virtual void updateAnimation ();	//barrel specific version of update animation. flips through frames on sprite sheet
  virtual void move ();		//handles velocities and changing x and y positions of the barrel on the screen

  int hitOil;			//1 if barrel has hit the oil can. 0 if it has not
  double speedBoost;		//parameter to increase speed every level. 
  int type;			//used to differentiate between falling barrels, rolling barrels, and rolling barrels that randomly fall down ladders

private:


};

#endif
