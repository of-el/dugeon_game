//
//  DGame.h
//  lesson3
//
//  Created by Avel Aguilar on 6/19/14.
//  Copyright (c) 2014 Avel Aguilar. All rights reserved.
//

#ifndef lesson3_DGame_h
#define lesson3_DGame_h
//the above ensures non-multiple inclusion of header file.
//Pre-processor operation.

const int ROWS = 10;
const int COLS = 10;

enum BoardElements {bempty = NULL, bplayer, btrap, bgold, bexit};

class DGame
{
private:
    //int Board[ROWS][COLS];
    BoardElements Board[ROWS][COLS];
    
    // Player coordinates
    int playerx, playery;
    
    int cash = 0;
    int lives = 3;
    
    char BoardElementsToChars(BoardElements b) const;
    void checkMove();
    
public:
    // DGame(); defining constructor
    // Default constructor is supplied with no arguments
    // if you create your own construcotr, you have to take care of empty constructor.
    
    DGame();
    void printBoard();
    void movePlayer(char m);
    void gameComplete();
    char move;
    bool complete;
    
    friend std::ostream & operator<<(std::ostream & os, const DGame & dg);
    
};

#endif
