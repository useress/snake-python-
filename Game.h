#pragma once
#include <chrono>
#include<iostream>
#include<vector>
#include "Windows.h"
#include <algorithm>


using namespace std;

class Game
{
private:
    const char APPLE_CHAR = 'o';
    const char SNAKE_CHAR = '0';
    const int FIELD_SIZE = 25;
    bool directionUpdated = false;
    string direction = "up";
    int snakeLength = 0;
    pair<int, int> appleCords;
    vector<pair<int, int>> snakeCords{ {10, 3} };
    vector<vector<char>> field;

    
    void spawnApple();
    
public: 
    bool isPlaying;
    chrono::steady_clock::time_point timer = chrono::steady_clock::now();


    void updateDirection();
    void moveSnake();
    void printField();
    Game();

};

