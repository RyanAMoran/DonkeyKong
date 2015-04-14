//
//  DonkeyKongGame.h
//  donkeykong
//
//  Created by Jacob Gavin on 3/19/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//  Highest class for game. This class instantiates and combines all other necessary classes/objects so that in main.cpp, we simply call the function playDonkeyKong on an instantiated donkeykonggame object

#ifndef DONKEYKONGGAME_H
#define DONKEYKONGGAME_H
//include all other object/class definitions
#include "Floor.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "Object.h"
#include "Mario.h"
#include "Peach.h"
#include "DonkeyKong.h"
#include "Barrel.h"
#include "Hammer.h"
#include "Oil.h"
#include "Fireball.h"
#include <vector> //vector to be used for storing barrel objects

class DonkeyKongGame
{

public:

  DonkeyKongGame ();

  SDL_Surface *OnLoad (char *);	//Function to load game background

  void Display ();		//Renders all of the game objects and background onto the screen

  void Music_introMusic ();
  void Music_backgroundMusic ();
  void Music_walkingMusic ();
  void Music_completeMusic ();
  void Music_deathMusic ();
  void Music_hammerMusic ();
  void Music_jumpMusic ();
  void Music_jumpbarrelMusic ();
  void Music_timeMusic ();

  void scoreAndLevel ();	//keeps track of player score and prints it on screen


  void cleanUp ();		//Cleans up all of the object in the game when it is finished

  void playDonkeyKong ();	//Initiates gameplay and calls all other functions

  void applyBackground (int, int, SDL_Surface *, SDL_Surface *);

  void initializeFloors ();

  int checkOnFloor (int, int, int, int); //used to ensure Mario/fireball/etc. are on the floor

  int checkForCollisions (); //used to detect Mario colliding with barrel, smashing barrel, etc & initiate response to collision

  int checkForWinner ();

  void initializeLevel ();

  void setBarrelSpeedBoost ();

  int runIntroScreen ();

  void onLoad (char);

  void introDisplay ();

  void deathAnimation ();

  int gameOver ();

private:

    SDL_Surface * screen;	//Screen surface
  SDL_Surface *background;	//Surface for game background
  SDL_Surface *message;
  SDL_Surface *introScreen;
  SDL_Surface *floor;
  SDL_Surface *text; //surface reused for all text written on screen such as highscore, level, current score, etc.
  TTF_Font *font; //font loaded in for use when writing text to screen

  Mario mario;			//Mario object
  Peach peach;			//Peach object
  DonkeyKong donkeykong;	//donkeykong object
  Hammer hammer;		//hammer object
  Oil oil;			//oil can object
  Fireball fireball;		//a fireball object
    vector < Barrel > barrels;	//a STL vector of barrel object

  int level; //keeps track of current level. incremented each time Mario reaches Peach

  int lives; //integer to keep track of Mario's remaining lives

  int dkSpeed; //variable for how fast donkey kong moves. Used to make higher levels harder.

  int scoreint;			//integer value to keep track of score
};

#endif
