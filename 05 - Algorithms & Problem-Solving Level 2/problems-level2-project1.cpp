#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//Project 1 : Paper-Rock-Scissor

//int RandomNumber(int From, int To)
//{
//    int randNum = rand() % (To - From + 1) + From;
//    return randNum;
//}
//
//int ReadRoundsNumber()
//{
//    int rounds;
//    cout << "\nHow many rounds do you want to play ?\n";
//    cin >> rounds;
//    return rounds;
//}
//
//int PlayerTurn()
//{
//    int PlayerChoice;
//    do
//    {
//        cout << "Your choice : ";
//        cout << "[1], Rock, [2]: Paper, [3]: Scissor ? ";
//        cin >> PlayerChoice;
//    } while (PlayerChoice < 1 or PlayerChoice > 3);
//    return PlayerChoice;
//}
//
//int ComputerTurn()
//{
//    return RandomNumber(1, 3);
//}
//
//void PrintChoices(int player, int computer)
//{
//    switch (player)
//    {
//    case 1:
//        cout << "\nPlayer Choice : Rock" << "\n";
//        break;
//    case 2:
//        cout << "\nPlayer Choice : Paper" << "\n";
//        break;
//    case 3:
//        cout << "\nPlayer Choice : Scissor" << "\n";
//        break;
//    default:
//        break;
//    }
//    switch (computer)
//    {
//    case 1:
//        cout << "\nComputer Choice : Rock" << "\n";
//        break;
//    case 2:
//        cout << "\nComputer Choice : Paper" << "\n";
//        break;
//    case 3:
//        cout << "\nComputer Choice : Scissor" << "\n";
//        break;
//    default:
//        break;
//    }
//}
//
//char  Round(int player, int computer)
//{
//    char ResultOfRound = 'D';
//    switch (player)
//    {
//    case 1:
//        if (computer == 1)
//        {
//            system("color 60");
//            cout << "\nDraw -_-'\n";
//            ResultOfRound = 'D';
//            return ResultOfRound;
//        }
//        else if (computer == 2)
//        {
//            cout << "\a";
//            system("color 47");
//            cout << "\nRound winner : [Computer]\n";
//            ResultOfRound = 'L';
//            return ResultOfRound;
//        }
//        else
//        {
//            system("color 27");
//            cout << "\nRound winner : [You]\n";
//            ResultOfRound = 'W';
//            return ResultOfRound;
//        }
//        break;
//    case 2:
//        if (computer == 1)
//        {
//            system("color 27");
//            cout << "\nRound winner : [You]\n";
//            ResultOfRound = 'W';
//            return ResultOfRound;
//        }
//        else if (computer == 2)
//        {
//            system("color 60");
//            cout << "\nDraw -_-'\n";
//            ResultOfRound = 'D';
//            return ResultOfRound;
//
//        }
//        else
//        {
//            cout << "\a";
//            system("color 47");
//            cout << "\nRound winner : [Computer]\n";
//            ResultOfRound = 'L';
//            return ResultOfRound;
//        }
//        break;
//    case 3:
//        if (computer == 1)
//        {
//            cout << "\a";
//            system("color 47");
//            cout << "\nRound winner : [Computer]\n";
//            ResultOfRound = 'L';
//            return ResultOfRound;
//        }
//        else if (computer == 2)
//        {
//            system("color 27");
//            cout << "\nRound winner : [You]\n";
//            ResultOfRound = 'W';
//            return ResultOfRound;
//        }
//        else
//        {
//            system("color 60");
//            cout << "\nDraw -_-'\n";
//            ResultOfRound = 'D';
//            return ResultOfRound;
//        }
//        break;
//    default:
//        break;
//    }
//}
//
//char RepeatGame()
//{
//    char repeat;
//        cout << "\n Do You wanna Play again Y/N? ";
//        cin >> repeat;
//    return repeat;
//}
//
//void RepeatRounds(int roundsNumber)
//{
//    int win = 0, lose = 0, draw = 0;
//    for (int i = 1; i <= roundsNumber; i++)
//    {
//        cout << "\n---------------------[Round " << i << "]-----------------------\n\n";
//        int playerChoice = PlayerTurn();
//        int computerChoice = ComputerTurn();
//        PrintChoices(playerChoice, computerChoice);
//        char RoundResult = Round(playerChoice, computerChoice);
//        cout << "\n-----------------------------------------------------\n";
//        if (RoundResult == 'W')
//            win++;
//        else if (RoundResult == 'L')
//            lose++;
//        else
//            draw++;
//    }
//    cout << "\n                ";
//    cout << "---------<**{GAME-OVER}**>----------\n";
//    cout << "                Rounds :          (" << roundsNumber << ") Rounds.\n";
//    cout << "                You win :         (" << win << ") Times.\n";
//    cout << "                Computer wins :   (" << lose << ") Times.\n";
//    cout << "                Draw :            (" << draw << ") Times.\n";
//    cout << "\n                ";
//    cout << "------------------------------------\n";
//    
//    cout << "                Final result : ";
//    if (win > lose)
//    {
//        system("color 27");
//        cout << "You win ^_^'\n";
//    }
//    else if (win < lose)
//    {
//        system("color 47");
//        cout << "You lose x_x'\n";
//    }
//    else
//    {
//        system("color 60");
//        cout << "Draw ! -_-'\n";
//    }
//}

//Project 1 : Mr.Abu-Hadhoud solution:

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

enum enGameChoice {Stone = 1, Paper = 2, Scissors = 3};

enum enWinner {Player1 = 1, Computer = 2, Draw = 3};

struct stGameResults 
{
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short Computer2WinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

short ReadHowManyRounds()
{
    short GameRounds = 1;
    do
    {
        cout << "How Many Raounds 1 to 10 ? \n";
        cin >> GameRounds;
    } while (GameRounds < 1 || GameRounds > 10);
    return GameRounds;
}

enGameChoice ReadPlayer1Choice()
{
    short Choice = 1;
    do
    {
        cout << "\nYour choice : [1]: Stone, [2]: Paper, [3]: Scissors ? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);
    return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

string ChoiceName(enGameChoice Choice)
{
    string arrGameChoice[3] = { "Stone", "Paper", "Scissors" };
    return arrGameChoice[Choice - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
    {
        return enWinner::Draw;
    }
    switch (RoundInfo.Player1Choice)
    {

    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
            return enWinner::Computer;
        break;

    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
            return enWinner::Computer;
        break;

    case enGameChoice::Scissors:
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
            return enWinner::Computer;
        break;

    }
    //If you reach here Than player 1 is the winner:
    return enWinner::Player1;
}

string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = { "Player1", "Computer", "No winner" };
    return arrWinnerName[Winner - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player1:
        system("color 2F"); //turn screen to Green
        break;
    case enWinner::Computer:
        system("color 4F"); //turn screen to Red
        cout << "\a";
        break;
    default:
        system("color 6F"); //turn screen to Yellow
        break;
    }
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
    cout << "\n____________Round [" << RoundInfo.RoundNumber << "]____________\n\n";
    cout << "Player1 Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner : [" << RoundInfo.WinnerName << "]\n";
    cout << "__________________________________\n" << endl;
    SetWinnerScreenColor(RoundInfo.Winner);
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes)
        return enWinner::Player1;
    else if (ComputerWinTimes > Player1WinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}

stGameResults FillGameResults(int GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
    stGameResults GameResults;
    GameResults.GameRounds = GameRounds;
    GameResults.Player1WinTimes = Player1WinTimes;
    GameResults.Computer2WinTimes = ComputerWinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.GameWinner);
    return GameResults;
}

stGameResults PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
    for (short GameRounds = 1; GameRounds <= HowManyRounds; GameRounds++)
    {
        cout << "\nRound [" << GameRounds << "] begins:\n";
        RoundInfo.RoundNumber = GameRounds;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        //Increase win/draw counters:
        if (RoundInfo.Winner == enWinner::Player1)
            PlayerWinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        PrintRoundResults(RoundInfo);
    }
    return FillGameResults(HowManyRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short NumberOfTabs)
{
    string t = "";
    for (int i = 1; i < NumberOfTabs; i++)
    {
        t = t + "\t";
        cout << t;
    }
    return t;
}

void ShowGameOverScreen()
{
    cout << Tabs(2) << "__________________________________________________________\n\n";
    cout << Tabs(2) << " +++ G a m e O v e r +++ \n";
        cout << Tabs(2) <<"__________________________________________________________\n\n";
}

void ShowFinalGameResults(stGameResults GameResults)
{
    cout << Tabs(2) << "_____________________ [Game Results]_____________________\n\n";
    cout << Tabs(2) << "Game Rounds : " << GameResults.GameRounds << endl;
    cout << Tabs(2) << "Player1 won times : " << GameResults.Player1WinTimes << endl;
    cout << Tabs(2) << "Computer won times : " << GameResults.Computer2WinTimes << endl;
    cout << Tabs(2) << "Draw times : " << GameResults.DrawTimes << endl;
    cout << Tabs(2) << "Final Winner : " << GameResults.WinnerName << endl;
    cout << Tabs(2) << "___________________________________________________________\n";
    SetWinnerScreenColor(GameResults.GameWinner);
}


void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);
        cout << endl << Tabs(3) << "Do you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}



int main()
{
    srand((unsigned)time(NULL));
    /*RepeatRounds(ReadRoundsNumber());
    char repeat = RepeatGame();
    while (repeat == 'y')
    {
        system("cls");
        system("color 07");
        RepeatRounds(ReadRoundsNumber());
        repeat = RepeatGame();
    } */

    //Mr.Abu-Hadhoud Solution :
    StartGame();
        
}
