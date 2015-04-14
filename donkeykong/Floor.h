//
//  Floor.h
//  donkeykong
//
//  Created by Jacob Gavin on 3/25/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//
#ifndef FLOOR_H
#define FLOOR_H

class Floor
{

public:

  Floor ();
  double getslope ();
  double getyint ();

  int getxmin ();
  int getxmax ();
  int getymin ();
  int getymax ();

  void setslope (double);
  void setyint (double);
  void setxmin (int);
  void setxmax (int);
  void setymin (int);
  void setymax (int);

private:

  double slope;
  double yint;
  int xmin;
  int xmax;
  int ymin;
  int ymax;

};

#endif
