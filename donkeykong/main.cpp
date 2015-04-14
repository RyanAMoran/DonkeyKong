//
//  main.m
//  donkeykong
//
//  Created by Jacob Gavin on 3/18/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//

#include "SDL/SDL.h"
#include <iostream>
#include "DonkeyKongGame.h"
using namespace std;

int
main (int argc, char *argv[])
{
  DonkeyKongGame game;
  game.playDonkeyKong ();
  game.cleanUp ();
  return 0;
}
