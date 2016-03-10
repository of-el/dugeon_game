//
//  main.cpp
//  HW3
//
//  Created by Avel Aguilar on 6/19/14.
//  Copyright (c) 2014 Avel Aguilar. All rights reserved.
//

#include <iostream>

#include "DGame.h"

using std::cout;
using std::cin;

int main(void)
{
    cout << "Starting program.\n";
    
    DGame dg;
    
    while(!dg.complete)
    {
    //dg.printBoard();
    cout << dg;
    dg.gameComplete();
    }
        
    system("pause");
    
    return 0;
}


