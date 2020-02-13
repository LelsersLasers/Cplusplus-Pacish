#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
using namespace std;
string a = "y";
int tallness = 20;
int wideness = 30;
int targetfps;
int sleepdelay;
int fruitX;
int fruitY;
int oldFruitX;
int oldFruitY;
int coinX;
int coinY;
int AIoneX;
int AIoneY;
int AItwoX;
int AItwoY;
int AIthreeX;
int AIthreeY;
bool easyMode;
bool gameon = true;
bool gamerepeat = true;
string question = "n";
int score = 0;
char dircetion;
time_t time0;
time_t time1;
clock_t time2;
clock_t time3;
double secondstwo;
double seconds;
int frames = -1;

void AIonemove()
{
    int AIoneXdif = AIoneX - fruitX;
    int AIoneYdif = AIoneY - fruitY;
    int PosAIoneXdif;
    int PosAIoneYdif;
    if (AIoneXdif < 0)
    {
        PosAIoneXdif = AIoneXdif * -1;
    }
    else
    {
        PosAIoneXdif = AIoneXdif;
    }
    if (AIoneYdif < 0)
    {
        PosAIoneYdif = AIoneYdif * -1;
    }
    else
    {
        PosAIoneYdif = AIoneYdif;
    }
    if (PosAIoneXdif >= PosAIoneYdif)
    {
        if (AIoneXdif < 0)
        {
            AIoneX = AIoneX + 1;
        }
        else
        {
            AIoneX = AIoneX - 1;
        }
    }
    else
    {
        if (AIoneYdif < 0)
        {
            AIoneY = AIoneY + 1;
        }
        else
        {
            AIoneY = AIoneY - 1;
        }
    }
}

void AItwomove()
{
    int AItwoXdif = AItwoX - fruitX;
    int AItwoYdif = AItwoY - fruitY;
    int PosAItwoXdif;
    int PosAItwoYdif;
    if (AItwoXdif < 0)
    {
        PosAItwoXdif = AItwoXdif * -1;
    }
    else
    {
        PosAItwoXdif = AItwoXdif;
    }
    if (AItwoYdif < 0)
    {
        PosAItwoYdif = AItwoYdif * -1;
    }
    else
    {
        PosAItwoYdif = AItwoYdif;
    }
    if (PosAItwoXdif >= PosAItwoYdif)
    {
        if (AItwoXdif < 0)
        {
            AItwoX = AItwoX + 1;
        }
        else
        {
            AItwoX = AItwoX - 1;
        }
    }
    else
    {
        if (AItwoYdif < 0)
        {
            AItwoY = AItwoY + 1;
        }
        else
        {
            AItwoY = AItwoY - 1;
        }
    }
}
void AIthreemove()
{
    int AIthreeXdif = AIthreeX - fruitX;
    int AIthreeYdif = AIthreeY - fruitY;
    int PosAIthreeXdif;
    int PosAIthreeYdif;
    if (AIthreeXdif < 0)
    {
        PosAIthreeXdif = AIthreeXdif * -1;
    }
    else
    {
        PosAIthreeXdif = AIthreeXdif;
    }
    if (AIthreeYdif < 0)
    {
        PosAIthreeYdif = AIthreeYdif * -1;
    }
    else
    {
        PosAIthreeYdif = AIthreeYdif;
    }
    if (PosAIthreeXdif <= PosAIthreeYdif)
    {
        if (AIthreeYdif < 0)
        {
            AIthreeY = AIthreeY + 1;
        }
        else
        {
            AIthreeY = AIthreeY - 1;
        }
    }
    else
    {
        if (AIthreeXdif < 0)
        {
            AIthreeX = AIthreeX + 1;
        }
        else
        {
            AIthreeX = AIthreeX - 1;
        }
    }
}














void movement()
{

    if (_kbhit())
    {
        dircetion = _getch();
    }
    oldFruitX = fruitX;
    oldFruitY = fruitY;
    if (dircetion == 'w')
        {
            fruitY = fruitY - 1;
        }
        else if (dircetion == 's')
        {
            fruitY = fruitY + 1;
        }
        else if (dircetion == 'a')
        {
            fruitX = fruitX - 1;
        }
        else if (dircetion == 'd')
        {
            fruitX = fruitX + 1;
        }
        else
        {
            fruitY = fruitY - 1;
        }

}

void logic()
{
    if (fruitX <= 0 || fruitX >= wideness-1 || fruitY <= 0 || fruitY >= tallness-1)
    {
        if (easyMode){
            fruitX = oldFruitX;
            fruitY = oldFruitY;
        }
        else{
            gameon = false;
        }
    }
    if (fruitX == coinX && fruitY == coinY)
    {
        score = score + 100;
        coinY = rand()% (tallness-2) + 1;
        coinX = rand()% (wideness-2) + 1;
    }
    if (fruitX == AIoneX && fruitY == AIoneY)
    {
        gameon = false;
    }
    if (fruitX == AItwoX && fruitY == AItwoY)
    {
        gameon = false;
    }
    if (fruitX == AIthreeX && fruitY == AIthreeY)
    {
        gameon = false;
    }
}





void draw()
{
    frames = frames + 1;
    system("CLS");
    for (int height = 0; height < tallness; height = height + 1)
    {
        for (int length = 0; length < wideness; length = length + 1)
        {
            if (height == 0)
            {
              cout << "#";
            }
            else if (height == tallness - 1)
            {
                cout << "#";
            }
            else if (length == 0)
            {
                cout << "#";
            }
            else if (length == wideness - 1)
            {
                cout << "#";
            }
            else if (length == fruitX && height == fruitY)
            {
                cout << "0";
            }
            else if (length == coinX && height == coinY)
            {
                cout << "C";
            }
            else if (length == AIoneX && height == AIoneY)
            {
                cout << "Y";
            }
            else if (length == AItwoX && height == AItwoY)
            {
                cout << "Y";
            }
            else if (length == AIthreeX && height == AIthreeY)
            {
                cout << "Y";
            }
            else
            {
                cout << " ";
            }


        }
        cout << "" << endl;
    }
    time(&time1);
    seconds = time0 - time1;
    time3 = clock();
    secondstwo = time3 - time2;
    cout << "fps: " << 1/secondstwo*1000 <<endl;
    cout << "sleep time: " << sleepdelay <<endl;
    cout << "score: " << score << endl;

    if (targetfps > 1/secondstwo*1000)
    {
        if (sleepdelay >= 1)
        {
            sleepdelay = sleepdelay - 1;
        }
    else if  (targetfps < 1/secondstwo*1000)
    {
        sleepdelay = sleepdelay + 1;
    }
    time2 = clock();
}
}



int main()
{
    cout << "Enter target Frames per second (fps). Note: higher fps will be harder and more likely to fluctuate: " << endl;
    cin >> targetfps;
    cout << "Easy Mode? (y/n)" << endl;
    cin >> a;
    if (a == "y"){
        easyMode = true;
    }
    srand(time(NULL));
    while (gamerepeat){
        fruitY = rand()% (tallness-2) + 1;
        fruitX = rand()% (wideness-2) + 1;
        coinY = rand()% (tallness-2) + 1;
        coinX = rand()% (wideness-2) + 1;
        AIoneX = rand()% (wideness-2) + 1;
        AItwoX = rand()% (wideness-2) + 1;
        AIthreeX = rand()% (wideness-2) + 1;
        AIoneY = rand()% (tallness-2) + 1;
        AItwoY = rand()% (tallness-2) + 1;
        AIthreeY = rand()% (tallness-2) + 1;
        sleepdelay = 1000/(targetfps*3);
        score = 0;
        draw();
        Sleep(1500);
        time(&time0);
        time2 = clock();

        while (gameon)
        {
            movement();
            AIonemove();
            logic();
            draw();
            Sleep(sleepdelay);
            AIthreemove();
            logic();
            Sleep(sleepdelay);
            movement();
            AItwomove();
            if (gameon){
                logic();
                draw();
                Sleep(sleepdelay);
            }
        }
        cout << "You died." << endl;
        cout << "Score: " << score << endl;
        Sleep(100);
        question = "n";
        cout << "Play again? (y/n)" << endl;
        Sleep(5);
        cin >> question;
        Sleep(5);
        if (question == "n"){
            gamerepeat = false;
        }
        else {

            gamerepeat = true;
            gameon = true;
        }
    }
    cout << "safe to exit" << endl;
    cin >> score;
    return 0;
}



