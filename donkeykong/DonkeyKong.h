
//
//  DonkeyKong.h
//  donkeykong
//
//  Created by Ryan Moran on 3/26/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.
//  Class for peach object

#ifndef DONKEYKONG_H
#define DONKEYKONG_H

#include "Object.h"		//uses inheritance to access functions of base object class
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>
using namespace std;

class DonkeyKong:public Object
{

public:
  DonkeyKong ();		//Default Constructor

  virtual void setAnimation ();	//Sets animation parameters according to animation state
  virtual void updateAnimation ();	//Donkey Kong specific version of update animation

private:


};

#endif
