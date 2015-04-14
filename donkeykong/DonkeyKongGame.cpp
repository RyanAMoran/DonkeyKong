//
//  DonkeyKongGame.cpp
//  donkeykong
//
//  Created by Jacob Gavin on 3/19/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//
//include all necessary libraries and header files for all other objects/classes
#include <SDL/SDL.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include "SDL/SDL.h"
#include <SDL/SDL_ttf.h>
#include <string>
#include "DonkeyKongGame.h"
#include "Object.h"
#include "Mario.h"
#include "Peach.h"
#include "DonkeyKong.h"
#include "Barrel.h"
#include "Oil.h"
#include "Fireball.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <sstream>

#include "SDL/SDL_mixer.h"

using namespace std;


SDL_Event event;
//The music that will be played
Mix_Music *intro_sound = NULL;	//intro music
Mix_Music *background_sound = NULL;	// background music
Mix_Music *walking_sound = NULL;	// walking music
Mix_Music *complete_sound = NULL;	// level is done
Mix_Music *death_sound = NULL;	// mario died
Mix_Music *hammer_sound = NULL;	// mario got a hammer
Mix_Music *jump_sound = NULL;	// mario jumped
Mix_Music *jumpbarrel_sound = NULL;	// mario jumped a barrel
Mix_Music *time_sound = NULL;	// time is up

//Constructor for DonkeyKongGame, initializes SDL, creates screen, and loads background
DonkeyKongGame::DonkeyKongGame ()
{
  SDL_Init (SDL_INIT_EVERYTHING);
  screen = SDL_SetVideoMode (550, 471, 32, SDL_SWSURFACE);
  background = SDL_LoadBMP ("DonkeyKongBackground.bmp");
  introScreen = OnLoad ("Intro.bmp");
  floor = OnLoad ("introScene.bmp");
  SDL_WM_SetCaption ("Donkey Kong", "Donkey Kong");
  //Stuff for writing score and level on screen:
  if (TTF_Init () != 0)
    {
      cout << "Error loading TTF libary" << endl;
      SDL_Quit ();
    }

  font = TTF_OpenFont ("kongtext.ttf", 10);
  if (font == NULL)
    {
      cout << "Error opening font " << TTF_GetError () << endl;
      TTF_Quit ();
      SDL_Quit ();
    }


  mario.initializeFloors ();


  level = 1;

  scoreint = 0;
}

SDL_Surface *
DonkeyKongGame::OnLoad (char *File)
{
  SDL_Surface *Surf_Temp = NULL;
  SDL_Surface *Surf_Return = NULL;

  if ((Surf_Temp = SDL_LoadBMP (File)) == NULL)
    {
      cout << "Returned Null" << endl;
      return NULL;
    }

  Surf_Return = SDL_DisplayFormat (Surf_Temp);
  SDL_FreeSurface (Surf_Temp);

  return Surf_Return;
}

void
DonkeyKongGame::Music_introMusic ()
{

  Mix_OpenAudio (22050, MIX_DEFAULT_FORMAT, 2, 4096);
  intro_sound = Mix_LoadMUS ("intro2.wav");
  Mix_PlayMusic (intro_sound, -1);
}

void
DonkeyKongGame::Music_backgroundMusic ()
{

  Mix_OpenAudio (22050, MIX_DEFAULT_FORMAT, 2, 4096);
  background_sound = Mix_LoadMUS ("bacmusic.wav");
  Mix_PlayMusic (background_sound, -1);
}

void
DonkeyKongGame::Music_walkingMusic ()
{

  Mix_OpenAudio (22050, MIX_DEFAULT_FORMAT, 2, 4096);
  background_sound = Mix_LoadMUS ("walking.wav");
  Mix_PlayMusic (background_sound, -1);
}

void
DonkeyKongGame::Music_completeMusic ()
{

  Mix_OpenAudio (22050, MIX_DEFAULT_FORMAT, 2, 4096);
  background_sound = Mix_LoadMUS ("complete.wav");
  Mix_PlayMusic (background_sound, -1);
}

void
DonkeyKongGame::Music_deathMusic ()
{

  Mix_OpenAudio (22050, MIX_DEFAULT_FORMAT, 2, 4096);
  background_sound = Mix_LoadMUS ("death.wav");
  Mix_PlayMusic (background_sound, -1);
}

void
DonkeyKongGame::Music_hammerMusic ()
{

  Mix_OpenAudio (22050, MIX_DEFAULT_FORMAT, 2, 4096);
  background_sound = Mix_LoadMUS ("hammer.wav");
  Mix_PlayMusic (background_sound, -1);
}

void
DonkeyKongGame::Music_jumpMusic ()
{

  Mix_OpenAudio (22050, MIX_DEFAULT_FORMAT, 2, 4096);
  background_sound = Mix_LoadMUS ("jump.wav");
  Mix_PlayMusic (background_sound, -1);
}

void
DonkeyKongGame::Music_jumpbarrelMusic ()
{

  Mix_OpenAudio (22050, MIX_DEFAULT_FORMAT, 2, 4096);
  background_sound = Mix_LoadMUS ("insert.wav");
  Mix_PlayMusic (background_sound, -1);
}

void
DonkeyKongGame::Music_timeMusic ()
{

  Mix_OpenAudio (22050, MIX_DEFAULT_FORMAT, 2, 4096);
  background_sound = Mix_LoadMUS ("wah.wav");
  Mix_PlayMusic (background_sound, -1);
}




//Display function which puts background and all objects on screen
void
DonkeyKongGame::Display ()
{
  int i;

  SDL_FillRect (screen, &screen->clip_rect,
		SDL_MapRGB (screen->format, 0xFF, 0xFF, 0xFF));

  //Apply image to screen
  SDL_BlitSurface (background, NULL, screen, NULL);

  if (mario.getclimbing () == 0)
    {
      mario.display (screen, mario.getMarioSurface (), mario.getxpos (),
		     mario.getypos (),
		     mario.getspritesheetx () +
		     mario.getcurrentframe () * mario.getwidth (),
		     mario.getspritesheety (), mario.getwidth (),
		     mario.getheight ());
    }
  if (mario.getclimbing () == 1)
    {
      mario.climbingdisplay (screen, mario.getMarioSurface (),
			     mario.getxpos (), mario.getypos (),
			     mario.getspritesheetx () +
			     mario.getcurrentframe () * mario.getwidth () * 2,
			     mario.getspritesheety (), mario.getwidth (),
			     mario.getheight ());
    }

  peach.display (screen, peach.getMarioSurface (), peach.getxpos (),
		 peach.getypos (),
		 peach.getspritesheetx () +
		 peach.getcurrentframe () * peach.getwidth (),
		 peach.getspritesheety (), peach.getwidth (),
		 peach.getheight ());

  oil.display (screen, oil.getMarioSurface (), oil.getxpos (),
	       oil.getypos (),
	       oil.getspritesheetx () +
	       oil.getcurrentframe () * oil.getwidth (),
	       oil.getspritesheety (), oil.getwidth (), oil.getheight ());

  donkeykong.display (screen, donkeykong.getMarioSurface (),
		      donkeykong.getxpos (), donkeykong.getypos (),
		      donkeykong.getspritesheetx () +
		      donkeykong.getcurrentframe () * donkeykong.getwidth (),
		      donkeykong.getspritesheety (), donkeykong.getwidth (),
		      donkeykong.getheight ());

  if (mario.hadHammer == 0)
    hammer.display (screen, hammer.getMarioSurface (),
		    hammer.getxpos (), hammer.getypos (),
		    hammer.getspritesheetx () +
		    hammer.getcurrentframe () * hammer.getwidth (),
		    hammer.getspritesheety (), hammer.getwidth (),
		    hammer.getheight ());

  for (i = 0; i < barrels.size (); i++)
    {
      if (barrels[i].alive == 1)
	barrels[i].display (screen, barrels[i].getMarioSurface (),
			    barrels[i].getxpos (), barrels[i].getypos (),
			    barrels[i].getspritesheetx () +
			    barrels[i].getcurrentframe () *
			    barrels[i].getwidth (),
			    barrels[i].getspritesheety (),
			    barrels[i].getwidth (), barrels[i].getheight ());
    }

  if (fireball.alive == 1)
    fireball.display (screen, fireball.getMarioSurface (),
		      fireball.getxpos (), fireball.getypos (),
		      fireball.getspritesheetx () +
		      fireball.getcurrentframe () * fireball.getwidth (),
		      fireball.getspritesheety (), fireball.getwidth (),
		      fireball.getheight ());
  for (int i = 0; i < lives; i++)
    {
      mario.display (screen, mario.getMarioSurface (), 5 + (i * 20), 30,
		     194 + 0 * 20, 0, 20, 20);
    }
  SDL_Flip (screen);

}

//Function to clean up game when over
void
DonkeyKongGame::cleanUp ()
{

  //Free the loaded image
  SDL_FreeSurface (background);
  mario.cleanUp ();

  // free all sound files
  Mix_FreeMusic (intro_sound);
  Mix_FreeMusic (background_sound);
  Mix_FreeMusic (walking_sound);
  Mix_FreeMusic (complete_sound);
  Mix_FreeMusic (death_sound);
  Mix_FreeMusic (hammer_sound);
  Mix_FreeMusic (jump_sound);
  Mix_FreeMusic (jumpbarrel_sound);
  Mix_FreeMusic (time_sound);

  //Quit SDL Mixer
  Mix_CloseAudio ();
}

void
DonkeyKongGame::scoreAndLevel ()
{
  SDL_Rect DestR;
  DestR.x = 120;
  DestR.y = 12;
  SDL_FillRect (text, &text->clip_rect,
		SDL_MapRGB (screen->format, 0xFF, 0xFF, 0xFF));
  SDL_BlitSurface (text, NULL, background, &DestR);
  stringstream strs;
  strs << scoreint;
  string temp_str = strs.str ();
  char *currentScore = (char *) temp_str.c_str ();
  SDL_Color text_color = { 255, 255, 255 };
  text = TTF_RenderText_Solid (font, currentScore, text_color);


  SDL_BlitSurface (text, NULL, background, &DestR);

  DestR.x = 480;
  DestR.y = 68;
  SDL_FillRect (text, &text->clip_rect,
		SDL_MapRGB (screen->format, 0xFF, 0xFF, 0xFF));
  SDL_BlitSurface (text, NULL, background, &DestR);
  stringstream strsLevel;
  strsLevel << level;
  temp_str = strsLevel.str ();
  char *currentLevel = (char *) temp_str.c_str ();
  text = TTF_RenderText_Solid (font, currentLevel, text_color);
  SDL_BlitSurface (text, NULL, background, &DestR);


  ifstream myReadFile;
  myReadFile.open ("highScore.txt");
  int highscore;
  while (!myReadFile.eof ())
    {
      myReadFile >> highscore;
    }
  if (scoreint > highscore)
    {
      highscore = scoreint;
    }
  myReadFile.close ();


  ofstream myWriteFile;
  myWriteFile.open ("highScore.txt");
  myWriteFile << highscore;
  myWriteFile.close ();

  DestR.x = 360;
  DestR.y = 12;
  SDL_FillRect (text, &text->clip_rect,
		SDL_MapRGB (screen->format, 0xFF, 0xFF, 0xFF));
  SDL_BlitSurface (text, NULL, background, &DestR);
  stringstream strsHighScore;
  strsHighScore << highscore;
  temp_str = strsHighScore.str ();
  char *currentHighScore = (char *) temp_str.c_str ();
  text = TTF_RenderText_Solid (font, currentHighScore, text_color);
  SDL_BlitSurface (text, NULL, background, &DestR);

  SDL_Flip (background);



}

//Function to create gameplay
void
DonkeyKongGame::playDonkeyKong ()
{
  bool quit = false;
  while (quit == false)
    {
      if (runIntroScreen ())
	quit = true;
      int counter = 0;
      int i;
      int oldState;
      int winner;
      Music_backgroundMusic ();
      srand (time (NULL));
      while (quit == false)
	{
	  winner = 0;
	  initializeLevel ();
	  counter = 0;
	  while (winner == 0 && quit == false)
	    {
	      if (lives == 0)
		{
		  level = 1;
		  scoreint = 0;
		  ofstream myWriteFile;
		  myWriteFile.open ("levelSave.txt");
		  myWriteFile << level;
		  myWriteFile.close ();
		  myWriteFile.open ("liveSave.txt");
		  myWriteFile << lives;
		  myWriteFile.close ();
		  myWriteFile.open ("scoreSave.txt");
		  myWriteFile << scoreint;
		  myWriteFile.close ();
		  break;
		}
	      if (mario.getoldtime () + mario.getframerate () <
		  SDL_GetTicks ())
		{
		  oldState = mario.currentState;
		  mario.determineAnimation ();
		  if (oldState == mario.currentState)
		    {
		      mario.updateAnimation ();
		    }
		  else
		    {
		      mario.setAnimation ();
		    }
		}
	      if (oil.getoldtime () + oil.getframerate () < SDL_GetTicks ())
		{
		  oil.updateAnimation ();
		}
	      if ((peach.getoldtime () + peach.getframerate () <
		   SDL_GetTicks ()) && (counter % 5) == 0)
		{
		  peach.updateAnimation ();
		  if (counter % 30 == 0 && peach.currentState == 1)
		    {
		      peach.currentState = 2;
		      peach.setAnimation ();
		    }
		  else if (counter % 30 == 0 && peach.currentState == 2)
		    {
		      peach.currentState = 1;
		      peach.setAnimation ();
		    }
		}
	      if (mario.getypos () <= 250)
		{
		  dkSpeed = 250 - ((level - 1) * 20) - 20;
		}
	      else
		{
		  dkSpeed = 250 - ((level - 1) * 20);
		}
              if(level>10){
		  dkSpeed = 250 - ((10 - 1) * 20);
	      }
	      if ((donkeykong.currentState == 3
		   && donkeykong.currentFrame == 2)
		  || (donkeykong.currentState == 2
		      && donkeykong.currentFrame == 0))
		{
		  if (rand () % 10 + 1 >= 3 && donkeykong.currentState != 3
		      && counter % dkSpeed == 0)
		    {
		      donkeykong.currentState = 3;
		      donkeykong.setAnimation ();
		    }
		  else if (donkeykong.currentState != 2
			   && counter % dkSpeed == 0
			   && mario.getypos () > 250)
		    {
		      donkeykong.currentState = 2;
		      donkeykong.setAnimation ();
		    }
		}
	      if (counter % dkSpeed == 0 && donkeykong.currentState == 2)
		{
		  if (donkeykong.currentFrame == 0)
		    {
		      donkeykong.updateAnimation ();
		      donkeykong.updateAnimation ();
		      donkeykong.updateAnimation ();
		    }
		  else
		    {
		      donkeykong.updateAnimation ();
		    }

		}
	      if (counter % dkSpeed == 0 && donkeykong.currentState == 3)
		{
		  if (donkeykong.currentFrame == 2)
		    {
		      donkeykong.updateAnimation ();
		      donkeykong.updateAnimation ();
		      donkeykong.updateAnimation ();
		      donkeykong.updateAnimation ();
		    }
		  else if (donkeykong.currentFrame == 0)
		    {
		      donkeykong.updateAnimation ();
		      donkeykong.updateAnimation ();
		      donkeykong.updateAnimation ();
		    }
		  else if (donkeykong.currentFrame == 3)
		    {
		      if (rand () % 10 + 1 >= 5 || mario.getypos () <= 250)
			{
			  donkeykong.updateAnimation ();
			  donkeykong.updateAnimation ();
			  Barrel barrel;
			  barrel.type = 1;
			  barrels.push_back (barrel);
			  for (i = 0; i < barrels.size (); i++)
			    {
			      if (barrels[i].type == 1)
				{
				  barrels[i].currentState = 1;
				  barrels[i].currentFrame = 2;
				  barrels[i].updateAnimation ();
				  barrels[i].updateAnimation ();
				}
			    }
			}
		      else
			{
			  donkeykong.updateAnimation ();
			  donkeykong.updateAnimation ();
			  donkeykong.updateAnimation ();
			  donkeykong.updateAnimation ();
			  donkeykong.updateAnimation ();
			  Barrel barrel;
			  barrel.type = 2;
			  barrel.xpos = 109;
			  barrel.ypos = 182;
			  barrel.currentState = 3;
			  barrel.setAnimation ();
			  barrels.push_back (barrel);
			  for (i = 0; i < barrels.size (); i++)
			    {
			      if (barrels[i].type == 1)
				{
				  barrels[i].currentState = 1;
				  barrels[i].currentFrame = 2;
				  barrels[i].updateAnimation ();
				  barrels[i].updateAnimation ();
				}
			    }
			}
		    }
		  else
		    {
		      donkeykong.updateAnimation ();
		      donkeykong.updateAnimation ();
		      donkeykong.updateAnimation ();
		    }
		}
	      while (SDL_PollEvent (&event))
		{
		  mario.checkOnFloor (mario.hasHammer);
		  if (mario.getoldtime () + mario.getframerate () <
		      SDL_GetTicks ())
		    {
		      mario.updateAnimation ();
		    }
		  //Handle events for Mario
		  mario.handle_input (event);
		  //If the user has Xed out the window
		  if (event.type == SDL_QUIT)
		    {
		      //Quit the program
		      quit = true;
		      ofstream myWriteFile;
		      myWriteFile.open ("levelSave.txt");
		      myWriteFile << level;
		      myWriteFile.close ();
		      myWriteFile.open ("liveSave.txt");
		      myWriteFile << lives;
		      myWriteFile.close ();
		      myWriteFile.open ("scoreSave.txt");
		      myWriteFile << scoreint;
		      myWriteFile.close ();
		    }
		  mario.updateAnimation ();
		}
	      counter += 1;
	      for (i = 0; i < barrels.size (); i++)
		{
		  barrels[i].roll ();
		}
	      if (fireball.alive == 1)
		fireball.bounce ();	//animates fireball character when he is alive
	      fireball.checkOnFloor (0);
	      mario.move ();
	      mario.checkOnFloor (mario.hasHammer);
	      for (i = 0; i < barrels.size (); i++)
		{
		  if (barrels[i].type == 1)
		    {
		      barrels[i].checkOnFloor (1);
		    }
		  if (barrels[i].checkOnLadderBarrel () == 2)
		    {
		      barrels[i].type = 1;
		      barrels[i].currentState = 1;
		      barrels[i].currentFrame = 2;
		      barrels[i].setAnimation ();
		    }
		  else if (barrels[i].checkOnLadderBarrel () == 1
			   && rand () % 10 + 1 >= 9)
		    {
		      barrels[i].type = 3;
		    }
		  else
		    if (((barrels[i].ypos < mario.ypos + 50
			  && barrels[i].ypos > mario.ypos - 50)
			 || barrels[i].ypos > 450) && barrels[i].type == 2)
		    {
		      if (barrels[i].checkOnFloor (1))
			{
			  barrels[i].type = 1;
			  barrels[i].currentState = 1;
			  barrels[i].currentFrame = 2;
			  barrels[i].setAnimation ();
			}
		    }
		}
	      if (mario.hasHammer == 0)
		{
		  if (mario.checkOnLadder (mario.direction) == 1)
		    {
		      mario.onLadder = 1;

		    }
		  else if (mario.checkOnLadder (mario.direction) == 2)
		    {
		      mario.onLadder = 2;
		      mario.vy = 0;

		    }
		  else
		    {
		      mario.onLadder = 0;
		    }
		}
	      if (checkForCollisions ())
		{		//everything that must be done if checkForCollisions() returns 1 and thus Mario died.
		  Music_deathMusic ();
		  mario.alive = 0;	//set Mario to dead
		  scoreint = scoreint - 100;	//lose points when you die
		  mario.climbing = 0;
		  mario.onLadder = 0;
		  if (mario.rdirection == 0)
		    mario.vx = 2;
		  if (mario.rdirection == 1)
		    mario.vx = -2;
		  mario.vy = -6;
		  mario.currentState = 14;
		  mario.setAnimation ();
		  deathAnimation ();
		  initializeLevel ();	//setting things up for next play through
		  Music_backgroundMusic ();	//play normal background level music
		}
	      if (mario.checkForHammer ())
		{		//everything that must be done when Mario grabs the hammer
		  mario.hasHammer = 1;
		  Music_hammerMusic ();	//play hammer music while Mario has the hammer
		  mario.hammerStartTime = SDL_GetTicks ();
		}
	      if ((SDL_GetTicks () - mario.hammerStartTime > 10000)
		  && (mario.hasHammer))
		{		//limits amount of time Mario has the hammer until it disappears
		  mario.hasHammer = 0;
		  Music_backgroundMusic ();	//play background level music
		  mario.currentState = 1;
		  mario.setAnimation ();
		}
	      fireball.ensureOnScreen ();	//makes sure fireball character never surpasses screen boundaries
	      setBarrelSpeedBoost ();
	      scoreAndLevel ();	//function that uses SDL surface text to write high score, score, level, etc to screen
	      Display ();
	      winner = checkForWinner ();

	    }
	  Music_backgroundMusic ();	//play background level music
	  if (lives == 0)
	    {
	      gameOver ();
	      break;
	    }
	}
    }
  SDL_Quit ();
}

int
DonkeyKongGame::checkForCollisions ()
{
  int i;
  int barrelXmin;
  int barrelXmax;
  int barrelYcenter;
  int hammerXmin;
  int hammerXmax;
  int hammerYmin;
  int hammerYmax;
  if (mario.rdirection == 0)
    {
      hammerXmin = mario.xpos;
      hammerXmax = mario.xpos + 10;
    }
  if (mario.rdirection == 1)
    {
      hammerXmin = mario.xpos + 21;
      hammerXmax = mario.xpos + 31;
    }
  hammerYmin = mario.ypos + 18;
  hammerYmax = mario.ypos + 30;

  if (mario.hasHammer)
    {				//means Mario can now destroy barrels for points
      for (i = 0; i < barrels.size (); i++)
	{			//loop to check for every barrel object in our barrel vector
	  barrelXmin = barrels[i].xpos;
	  barrelXmax = barrels[i].xpos + barrels[i].width;
	  barrelYcenter = barrels[i].ypos + barrels[i].height / 2;
	  if (((barrelXmax >= hammerXmin) && (barrelXmin <= hammerXmax))
	      && ((barrelYcenter >= hammerYmin)
		  && (barrelYcenter <= hammerYmax)))
	    {			//if barrels are in destroying range of Mario with hammer
	      if (barrels[i].alive == 1)
		{
		  scoreint += 200;	//score 200 pts for each killed barrel
		}
	      barrels[i].alive = 0;	//sets barrel to dead when Mario hits it with hammer
	    }
	}
    }


  int barrelxcenter;
  int barrelycenter;
  int marioxcenter = mario.xpos + mario.width / 2;
  int marioycenter = mario.ypos + mario.height / 2;
  int barrelradius = 6;
  int fireballradius = 6;
  int marioradius = 8;
  int mindistance;
  double distance;

  for (i = 0; i < barrels.size (); i++)
    {				//loop to check Mario's position in relation to every barrel object in our vector of barrels
      barrelxcenter = barrels[i].xpos + barrels[i].width / 2;
      barrelycenter = barrels[i].ypos + barrels[i].height / 2;
      mindistance = marioradius + barrelradius;
      distance =
	sqrt (pow (marioxcenter - barrelxcenter, 2) +
	      pow (marioycenter - barrelycenter, 2));
      if ((distance < mindistance) && (barrels[i].alive))
	return 1;		//return 1 if Mario is within death distance of a live barrel. This results in Mario being killed
    }

  if ((mario.xpos < 27 && mario.ypos > 400)
      || (mario.xpos < 138 && mario.ypos < 180 && mario.ypos > 150))
    {
      return 1;			//kills Mario if he runs into oil can or donkey kong objects on screen using their screen positions as death pts
    }

  int fireballxcenter = fireball.xpos + fireball.width / 2;
  int fireballycenter = fireball.ypos + fireball.height / 2;
  mindistance = marioradius + fireballradius;
  distance =
    sqrt (pow (marioxcenter - fireballxcenter, 2) +
	  pow (marioycenter - fireballycenter, 2));
  if ((distance < mindistance) && (fireball.alive))
    return 1;			//kills Mario if he is within death distance of a live fireball

  int oilxcenter = oil.xpos + oil.width / 2;
  int oilycenter = oil.ypos + oil.height / 2;
  barrelradius = 6;
  int oilradius = 8;
  int randomnum = 0;

  for (i = 0; i < barrels.size (); i++)
    {				//loop to check every barrel object in our vector of barrels
      barrelxcenter = barrels[i].xpos + barrels[i].width / 2;
      barrelycenter = barrels[i].ypos + barrels[i].height / 2;
      mindistance = oilradius + barrelradius;
      distance =
	sqrt (pow (oilxcenter - barrelxcenter, 2) +
	      pow (oilycenter - barrelycenter, 2));
      if ((distance < mindistance) && (barrels[i].alive))
	{
	  if (fireball.alive != 1)
	    {
	      fireball.alive = 1;	//set fireball character to alive when first live barrel hits the oil can
	      fireball.vx = 1;
	    }
	  if (i % 3 == 0 && fireball.floorNumber != 5
	      && fireball.floorNumber != 6 && fireball.floorNumber != 7)
	    {			//makes fireball jump to a new floor every third time a live barrel hits the oil can
	      fireball.vy = -(rand () % (30 - 1) + 1);	//randomized y velocity
	      randomnum = rand () % (2 - 1) + 1;
	      if (randomnum == 1)
		{		//randomly decide wether to move fireball character right or left on floor
		  fireball.vx = 1;
		}
	      else
		{
		  fireball.vx = -1;
		}
	    }
	}
    }


  return 0;
}

//function to check if Mario reached Peach at top of map
int
DonkeyKongGame::checkForWinner ()
{				//ultimately results in Mario reaching a harder level
  if ((mario.ypos + mario.height <= 123) && (mario.onFloor)
      && (mario.currentState != 9))
    {				//if Mario reaches the floor level that Peach is standing on
      Music_completeMusic ();
      level++;			//increment level
      scoreint += 500;		//score 500 pts by reaching Peach
      SDL_Delay (3980);
      return 1;
    }
  else
    {
      return 0;
    }
}

//function to set up parameters for starting a level
void
DonkeyKongGame::initializeLevel ()
{
  //Initialize Mario
  mario.xpos = 130;		//place Mario in the starting position at bottom of the screen
  mario.ypos = 435;
  mario.vx = 0;
  mario.vy = 0;
  mario.direction = 1;
  mario.onFloor = 1;
  mario.ay = 0;
  mario.vy = 0;
  mario.floorNumber = 1;	//start on bottom floor
  mario.previousFloor = 1;
  mario.onLadder = 0;
  mario.alive = 1;		//Mario is alive not dead
  fireball.alive = 0;		//fireball is not alive until first live barrel hits the oil can
  fireball.xpos = 25;
  fireball.ypos = 437;
  fireball.vx = 0;
  fireball.vy = 0;
  mario.hasHammer = 0;
  mario.hadHammer = 0;
  mario.hammerStartTime = 0;
  mario.jumping = 0;
  mario.currentState = 1;
  mario.setAnimation ();

  //Initialize Donkey Kong and all of his variables
  donkeykong.height = 33;
  donkeykong.width = 43;
  donkeykong.xpos = 94;
  donkeykong.ypos = 147;
  donkeykong.vx = 0;
  donkeykong.vy = 0;
  donkeykong.ay = 0;
  donkeykong.currentState = 3;
  donkeykong.currentFrame = 0;
  donkeykong.maxFrames = 2;
  donkeykong.climbing = 0;
  donkeykong.oldTime = 0;
  donkeykong.frameRate = 100;
  donkeykong.setAnimation ();

  peach.xpos = 250;
  peach.ypos = 100;

  //Initialize Barrels
  barrels.clear ();		//resets vector of barrels for clean use for new level
}

//function to set speed of barrels based on level. makes each level harder
void
DonkeyKongGame::setBarrelSpeedBoost ()
{
  int i;
  for (i = 0; i < barrels.size (); i++)
    {
      barrels[i].speedBoost = (level - 1) * .3;
    }
}

//function to display Mario's death animation when he dies
void
DonkeyKongGame::deathAnimation ()
{
  mario.currentState = 14;
  mario.setAnimation ();
  int counter = 0;
  Display ();
  SDL_Delay (1000);
  while (counter != 13)
    {
      SDL_Delay (150);
      mario.updateAnimation ();
      counter++;
      Display ();
    }
  if (mario.rdirection == 0)
    {
      mario.currentState = 15;
    }
  else
    {
      mario.currentState = 16;
    }
  mario.setAnimation ();
  Display ();
  SDL_Delay (2000);
  lives--;			//lose a life when you die
}

//function that is called once player loses all their lives
int
DonkeyKongGame::gameOver ()
{
  int counter = 0;
  Music_timeMusic ();
  donkeykong.xpos = 50;
  donkeykong.ypos = 383 - donkeykong.height;
  donkeykong.spritesheetx = 57;
  donkeykong.spritesheety = 149;
  donkeykong.currentFrame = 0;
  mario.xpos = 50;
  mario.currentState = 2;
  mario.ypos = 450 - mario.height;
  peach.xpos = 100;
  peach.ypos = 362;
  introScreen = OnLoad ("game_over.bmp");	//load game over screen into sdl surface introScreen
  SDL_FillRect (screen, NULL, SDL_MapRGB (screen->format, 0, 0, 0));

  SDL_Rect DestR;

  DestR.x = 0;
  DestR.y = 273;

  SDL_Rect SrcR;

  SrcR.x = 0;
  SrcR.y = 2;
  SrcR.w = 550;
  SrcR.h = 200;
  SDL_BlitSurface (floor, &SrcR, screen, &DestR);	//blit a surface to the screen
  while (counter != 60)
    {
      //Check for event
      while (SDL_PollEvent (&event))
	{
	  if (event.type == SDL_QUIT)
	    {
	      SDL_Quit ();
	      exit (0);

	    }
	}
      SDL_FillRect (screen, NULL, SDL_MapRGB (screen->format, 0, 0, 0));	//fill in surface screen with black to blit over
      SDL_BlitSurface (floor, &SrcR, screen, &DestR);	//blit over newly black, blank screen
      mario.display (screen, mario.getMarioSurface (), mario.getxpos (),
		     mario.getypos (),
		     mario.getspritesheetx () +
		     mario.getcurrentframe () * mario.getwidth (),
		     mario.getspritesheety (), mario.getwidth (),
		     mario.getheight ());

      donkeykong.display (screen, donkeykong.getMarioSurface (),
			  donkeykong.getxpos (), donkeykong.getypos (),
			  donkeykong.getspritesheetx () +
			  donkeykong.getcurrentframe () *
			  donkeykong.getwidth (),
			  donkeykong.getspritesheety (),
			  donkeykong.getwidth (), donkeykong.getheight ());

      peach.display (screen, peach.getMarioSurface (), peach.getxpos (),
		     peach.getypos (),
		     peach.getspritesheetx () +
		     peach.getcurrentframe () * peach.getwidth (),
		     peach.getspritesheety (), peach.getwidth (),
		     peach.getheight ());
      peach.updateAnimation ();
      if (peach.currentState == 1 && counter % 4 == 0)
	{
	  peach.currentState = 2;
	  peach.setAnimation ();
	}
      else if (peach.currentState == 2 && counter % 4 == 0)
	{
	  peach.currentState = 1;
	  peach.setAnimation ();
	}
      if (donkeykong.currentFrame == 0 && counter % 3 == 0)
	{
	  donkeykong.currentFrame = 3;
	}
      else if (counter % 3 == 0)
	{
	  donkeykong.currentFrame = 0;
	}
      if (counter == 28)
	{
	  Music_deathMusic ();
	  mario.currentState = 14;
	  mario.setAnimation ();
	}
      else if (counter > 34 && counter < 47)
	{
	  mario.updateAnimation ();
	}
      else if (counter == 47)
	{
	  mario.currentState = 16;
	  mario.setAnimation ();
	}
      else if (counter > 54)
	{
	  Mix_PauseMusic ();
	}

      SDL_Flip (screen);
      SDL_Delay (150);
      counter++;

    }
  DestR.x = 100;
  DestR.y = 50;
  SDL_BlitSurface (introScreen, &SrcR, screen, &DestR);
  SDL_Delay (1000);
  SDL_Flip (screen);
  SDL_Delay (4000);
  mario.currentState = 2;
  mario.setAnimation ();
  mario.currentFrame = 0;
  introScreen = OnLoad ("Intro.bmp");	//load intro bitmap into SDL surface introScreen
}

//Function that controls everything occurring on intro screen including dk movement, mario movement, barrels, etc
int
DonkeyKongGame::runIntroScreen ()
{
  donkeykong.xpos = 50;
  donkeykong.ypos = 383 - donkeykong.height;
  donkeykong.spritesheetx = 57;
  donkeykong.spritesheety = 149;
  donkeykong.currentFrame = 0;
  mario.xpos = 50;
  mario.currentState = 2;
  mario.ypos = 450 - mario.height;
  int count = 0;
  int donkeycount = 0;
  int jumping = 0;
  int size;
  double ay = .1;		//y = 450
  double vy = 0;
  double dt = .12;
  bool quit = false;

  int overallcounter = 0;
  int total = 2000;
  int time1 = 1000;

  if (overallcounter == 0)
    {
      Music_introMusic ();
      overallcounter++;
    }
  while (quit == false)
    {

      int i;
      for (i = 0; i < barrels.size (); i++)
	{
	  if (barrels[i].xpos <= 78 && barrels[i].xpos >= 77.5)
	    {
	      vy = -2.5;
	      jumping = 1;
	      mario.spritesheetx = 172;
	      mario.spritesheety = 0;
	      mario.currentFrame = 1;
	    }

	}

      //Make mario jump over the stream of barrels
      if (count == time1)
	{
	  Barrel barrel;
	  barrels.push_back (barrel);
	  size = barrels.size ();
	  barrels[size - 1].xpos = 550 - barrels[size - 1].width;
	  barrels[size - 1].ypos = 428 - barrels[size - 1].height;
	  barrels[size - 1].currentState = 1;
	  barrels[size - 1].currentFrame = 2;
	  barrels[size - 1].updateAnimation ();
	  barrels[size - 1].updateAnimation ();
	  count = 0;

	}


      //Mario lands on ground
      if ((jumping == 1) && (mario.ypos + mario.height > 450))
	{
	  mario.ypos = 450 - mario.height;
	  jumping = 0;
	  vy = 0;
	  mario.spritesheetx = 153;
	  mario.spritesheety = 0;
	  mario.currentFrame = 0;
	}

      //Move mario if he's jumping
      if (jumping == 1)
	{
	  vy = vy + ay * dt;
	  mario.ypos = mario.ypos + vy * dt + .5 * ay * pow (dt, 2);
	}

      //Check for event
      while (SDL_PollEvent (&event))
	{
	  if (event.type == SDL_KEYDOWN)
	    {
	      //Adjust the velocity
	      switch (event.key.keysym.sym)
		{
		  //Enter game
		case SDLK_RETURN:
		  Music_jumpbarrelMusic ();
		  quit = true;
		}

	    }
	  else if (event.type == SDL_QUIT)
	    {
	      return 1;
	      SDL_Quit ();
	      exit (0);
	    }
	}
      //move barrels
      for (i = 0; i < barrels.size (); i++)
	{
	  barrels[i].xpos -= .1;
	  barrels[i].ypos += .005;
	}


      //Update donkey kong
      if (donkeycount == total)
	{
	  overallcounter++;
	  donkeycount = 0;
	  if (overallcounter != 0)
	    {
	      if (donkeykong.currentFrame == 0)
		{
		  donkeykong.currentFrame = 3;
		}
	      else
		{
		  donkeykong.currentFrame = 0;
		}
	    }


	}


      //Update counters
      count++;
      donkeycount++;
      introDisplay ();
    }
  SDL_Delay (500);
  return 0;
}

//Function for the intro screen the user first sees
void
DonkeyKongGame::introDisplay ()
{
  //first read in all necessary saved data from txt files such as previously saved lives, level, score, highscore
  int i;
  ifstream myReadFile;
  myReadFile.open ("levelSave.txt");
  while (!myReadFile.eof ())
    {
      myReadFile >> level;
    }
  myReadFile.close ();
  myReadFile.open ("liveSave.txt");
  while (!myReadFile.eof ())
    {
      myReadFile >> lives;
    }
  myReadFile.close ();
  myReadFile.open ("scoreSave.txt");
  while (!myReadFile.eof ())
    {
      myReadFile >> scoreint;
    }
  myReadFile.close ();
  if (lives <= 0)
    {				//reset everything to initial values if user exited with 0 lives previously
      lives = 3;
      level = 1;
      scoreint = 0;
    }

  SDL_FillRect (screen, &screen->clip_rect, SDL_MapRGB (screen->format, 0xFF, 0xFF, 0xFF));	//makes the screen surface blank

  SDL_BlitSurface (introScreen, NULL, screen, NULL);	//blit the introScreen surface to the screen surface

  SDL_Rect DestR;

  DestR.x = 0;
  DestR.y = 273;

  SDL_Rect SrcR;

  SrcR.x = 0;
  SrcR.y = 2;
  SrcR.w = 550;
  SrcR.h = 200;

  SDL_BlitSurface (floor, &SrcR, screen, &DestR);	//blit the floor to the screen surface

  mario.display (screen, mario.getMarioSurface (), mario.getxpos (),
		 mario.getypos (),
		 mario.getspritesheetx () +
		 mario.getcurrentframe () * mario.getwidth (),
		 mario.getspritesheety (), mario.getwidth (),
		 mario.getheight ());

  donkeykong.display (screen, donkeykong.getMarioSurface (),
		      donkeykong.getxpos (), donkeykong.getypos (),
		      donkeykong.getspritesheetx () +
		      donkeykong.getcurrentframe () * donkeykong.getwidth (),
		      donkeykong.getspritesheety (), donkeykong.getwidth (),
		      donkeykong.getheight ());

  for (i = 0; i < barrels.size (); i++)
    {
      if (barrels[i].alive == 1)
	barrels[i].display (screen, barrels[i].getMarioSurface (),
			    barrels[i].getxpos (), barrels[i].getypos (),
			    barrels[i].getspritesheetx () +
			    barrels[i].getcurrentframe () *
			    barrels[i].getwidth (),
			    barrels[i].getspritesheety (),
			    barrels[i].getwidth (), barrels[i].getheight ());
    }

  SDL_Flip (screen);
}
