//
//  Fireball.h
//
//  Created by Ryan Moran on 4/10/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.
//  Class for Fireball object

#ifndef FIREBALL_H
#define FIREBALL_H

#include "Object.h"
#include <SDL/SDL.h>
#include <string>
using namespace std;

class Fireball:public Object
{

public:
  Fireball ();			//Default Constructor

  void bounce ();		//handles rolling a barrel down the floors
  void ensureOnScreen ();	//makes sure fireball stays on screen at all times

  virtual void setAnimation ();	//Sets animation parameters according to animation state
  virtual void updateAnimation ();	//Peach specific version of update animation
  virtual void move ();

private:


};

#endif
