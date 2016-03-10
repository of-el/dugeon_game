//
//  DGame.cpp
//  lesson3
//
//  Created by Avel Aguilar on 6/19/14.
//  Copyright (c) 2014 Avel Aguilar. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DGame.h"

DGame::DGame()
{
    srand(time(NULL));
    // Trap & gold coordinates
    int x, y;
    
    for (int rr = 0; rr < ROWS; rr++)
    {
        for (int cc = 0; cc < ROWS; cc++)
            Board[rr][cc] = bempty;
    }
    
    // player
    playerx = 0;
    playery = 1;
    Board[playerx][playery] = bplayer;
    
    // traps
    for (int i = 0; i < 4; i++)
    {
        x = rand() % 10;
        y = rand() % 10;
        Board[x][y] = btrap;

    }
    
    // gold
    for (int i = 0; i < 4; i++)
    {
        x = rand() % 10;
        y = rand() % 10;
        Board[x][y] = bgold;
    }
    
    // exit
    Board[ROWS-1][COLS] = bexit;
    
    complete = false;
    
}

void DGame::printBoard()
{
    std::cout << "\nPrinting board: Fancy-ish style. \n\n";
    int i = 0;
    int j = 0;
    
    for (int y = 0; y <= ROWS; y++)
    {
        if (y >= 1)
        {
            std::cout << i << "|";
            i++;
        }

        for (int x = 0; x < COLS; x++)
        {
            if (y == 0 && x == 0)
            {
                std::cout << "  ";
            }
            if (y == 0)
            {
                std::cout << j << " ";
                j++;
            }
            else
            {
                char c = BoardElementsToChars(Board[x][y]);
                std::cout << c << "|";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::ostream & operator<<(std::ostream & os, const DGame & dg)
{
    int i = 0;
    int j = 0;
    
    os << "\n Printing Board Fancy Style\n\n";
    
    for (int y = 0; y <= ROWS; y++)
    {
        if (y >= 1)
        {
            os << i << "|";
            i++;
        }
        
        for (int x = 0; x < COLS; x++)
        {
            if (y == 0 && x == 0)
            {
                os << "  ";
            }
            if (y == 0)
            {
                os << " " << j << "  ";
                j++;
            }
            else
            {
                char c = dg.BoardElementsToChars(dg.Board[x][y]);
                os << " " << c << " ";
                os << "|";
            }
        }
        os << std::endl;
        os << "  ---------------------------------------\n";
        
    }
    
    os << "Lives: " << dg.lives << " " << "Cash: " << dg.cash << std::endl << std::endl;
}

void DGame::movePlayer(char move)
{
    if ((move == 'w') || (move == 'W'))
    {
        Board[playerx][playery] = bempty;
        playery--;
        checkMove();
        Board[playerx][playery] = bplayer;
    }
        else if ((move == 's') || (move == 'S'))
    {
        Board[playerx][playery] = bempty;
        playery++;
        checkMove();
        Board[playerx][playery] = bplayer;
    }
    else if ((move == 'a') || (move == 'A'))
    {
        Board[playerx][playery] = bempty;
        playerx--;
        checkMove();
        Board[playerx][playery] = bplayer;
    }
    else if ((move == 'd') || (move == 'D'))
    {
        Board[playerx][playery] = bempty;
        playerx++;
        checkMove();
        Board[playerx][playery] = bplayer;
    }
}

void DGame::checkMove()
{
    char pos = Board[playerx][playery];
    
    switch (pos)
    {
        case btrap:
            lives--;
            if (lives == 0)
            {
                complete = true;
            }
            break;
        case bgold:
            cash += 25;
            break;
        default:
            break;
    }
}



void DGame::gameComplete()
{
    if(Board[ROWS-1][COLS-1] == bplayer)
    {
        std::cout << "You did it!\n\n";
        complete = true;
    }
    else if((Board[ROWS-1][COLS-1] != bplayer) && (lives > 0))
    {
        std::cout << "Make your move (up = w, down = s, left = a, right = d).\n\n";
        std::cin >> move;
        movePlayer(move);
        complete = false;
    }
    else if(lives == 0)
    {
        std::cout << "You're dead!\n\n";
        complete = true;
    }

}

char DGame::BoardElementsToChars(BoardElements b) const
{
	char c;
    
	switch(b)
	{
        case bempty:
            c = '.';
            break;
        case bplayer:
            c = 'P';
            break;
        case btrap:
            c = 'T';
            break;
        case bgold:
            c = '$';
            break;
        case bexit:
            c = 'X';
            break;
        default:
            c = 'X';
	}
    
	return c;
    
}