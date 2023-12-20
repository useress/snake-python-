
#include "Game.h"

Game::Game() {

    isPlaying = true;

    field.resize(FIELD_SIZE, vector<char>(FIELD_SIZE));

    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            if (i && j && FIELD_SIZE - i - 1 && FIELD_SIZE - j - 1)
                field[i][j] = '.';
            else
                field[i][j] = '#';

        }
    }
    spawnApple();
    printField();
}

void Game::printField() {
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            bool notSnake = true;
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

            if (pair<int, int>{ i, j } == appleCords) {
                SetConsoleTextAttribute(hConsole, 4);
                cout << APPLE_CHAR << ' ';
                continue;
            }

            for (auto& t : snakeCords) {
                if (t.first == i && t.second == j) {
                    SetConsoleTextAttribute(hConsole, 2);
                    cout << SNAKE_CHAR << ' ';
                    notSnake = false;
                    break;
                }        
            }

            SetConsoleTextAttribute(hConsole, 7);

            if (notSnake)
                cout << field[i][j] << ' ';
        }
        cout << '\n';
    }
}

void Game::moveSnake() {
    pair<int, int> prev = snakeCords[0];

    if (direction == "up") {
        snakeCords[0].first--;
    }
        
    if (direction == "down") {
        snakeCords[0].first++;
    }
        
    if (direction == "left") {
        snakeCords[0].second--;
    }
        
    if (direction == "right") {
        snakeCords[0].second++;
    }
        

    if (field[snakeCords[0].first][snakeCords[0].second] == '#'
        || count(snakeCords.begin(), snakeCords.end(), snakeCords[0]) > 1) {
        isPlaying = false;
        system("cls");
        cout << "Snake Length: " << snakeLength;
        
    }
        

    for (int i = 1; i < snakeCords.size(); i++) {
        swap(prev, snakeCords[i]);
    }

    if (snakeCords[0] == appleCords) {
        spawnApple();
        snakeCords.push_back(prev);
        snakeLength++;
    }
}

void Game::spawnApple() {
    do {
        srand(time(0));
        int x = rand() % 18 + 1;
        int y = rand() % 18 + 1;
        appleCords = { x, y };
    } while (find(snakeCords.begin(), snakeCords.end(), appleCords) != snakeCords.end());
    

}

void Game::updateDirection() {

    if ((GetKeyState('W') < 0 || GetKeyState(VK_UP) < 0) && direction != "down") {
        direction = "up";
        return;
    }
        
    if ((GetKeyState('A') < 0 || GetKeyState(VK_LEFT) < 0) && direction != "right") {
        direction = "left";
        return;
    }
        
    if ((GetKeyState('S') < 0 || GetKeyState(VK_DOWN) < 0) && direction != "up") {
        direction = "down";
        return;
    }
        
    if ((GetKeyState('D') < 0 || GetKeyState(VK_RIGHT) < 0) && direction != "left") {
        direction = "right";
        return;
    }

}


