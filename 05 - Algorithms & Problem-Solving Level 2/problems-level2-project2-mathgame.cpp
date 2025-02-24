#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//Project 2 : Math Game:

enum QuestionsLevel {Easy = 1, Medium = 2, Hard = 3, MixLevel = 4};
enum OperationType {Add = 1, Sub = 2, Mult = 3, Div = 4, MixType = 5};
struct OperationInfo
{
    int Operand1=0;
    int Operand2=0;
    char OperatorType='+';
    int YourAnswer=0;
    int RightAnswer=0;
    short Right=0;
    short Wrong = 0;
};
struct ResulInfo
{
    short NumberOfQuestions=0;
    string LevelOfQuestion="";
    string TypeOfOperation="";
    short NumberOfRightAnswers=0;
    short NumberOfWrongAnswers=0;
    string FinalResult="";
};

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

short ReadHowManyQuestions()
{
    short QuestionsNumber = 1;
    do
    {
        cout << "\nHow Many questions do you want to answer ? ";
        cin >> QuestionsNumber;
    } while (QuestionsNumber < 1);
    return QuestionsNumber;
}

string LevelName(QuestionsLevel Level)
{
    string arrLevelName[4] = { "Easy", "Medium", "Hard", "Mix"};
    return arrLevelName[Level - 1];
}

string TypeName(OperationType Type)
{
    string arrTypeName[5] = { "Add", "Sub", "Mult", "Div", "Mix" };
    return arrTypeName[Type - 1];
}

QuestionsLevel ReadQuestionLevel()
{
    short Level = 1;
    do
    {
        cout << "\nEnter Question Level : [1]: Easy, [2]: Medium, [3]: Hard, [4]: Mix ? ";
        cin >> Level;
    } while (Level < 1 || Level > 4);
    return (QuestionsLevel)Level;
}

OperationType ReadOperationType()
{
    short Type = 1;
    do
    {
        cout << "\nEnter Operation Type : [1]: Add, [2]: Sub, [3]: Mult, [4]: Div, [5]: Mix ? ";
        cin >> Type;
    } while (Type < 1 || Type > 5);
    return (OperationType)Type;
}

QuestionsLevel CheckOperationLevel()
{
        return (QuestionsLevel)RandomNumber(1, 3);
}

OperationType CheckOperationType()
{
    return (OperationType)RandomNumber(1, 4);
}

void SetAnswerScreenColor(OperationInfo Operation)
{
    switch (Operation.Right)
    {
    case 1:
        system("color 2F"); //turn screen to Green
        break;
    case 0:
        system("color 4F"); //turn screen to Red
        cout << "\a";
        break;
    }
}

int ReadYourAnswer()
{
    int YourAnswer;
    cin >> YourAnswer;
    return YourAnswer;
}

OperationInfo FillOperation(QuestionsLevel Level, OperationType Type)
{
    OperationInfo FilledOperation;
    FilledOperation.Right = 0;
    FilledOperation.Wrong = 0;
    switch (Level)
    {
    case Easy:
        FilledOperation.Operand1 = RandomNumber(1, 10);
        FilledOperation.Operand2 = RandomNumber(1, 10);
        break;
    case Medium:
        FilledOperation.Operand1 = RandomNumber(10, 50);
        FilledOperation.Operand2 = RandomNumber(10, 50);
        break;
    case Hard:
        FilledOperation.Operand1 = RandomNumber(50, 100);
        FilledOperation.Operand2 = RandomNumber(50, 100);
        break;
    case MixLevel:
        FilledOperation.Operand1 = RandomNumber(1, 100);
        FilledOperation.Operand2 = RandomNumber(1, 100);
        break;
    }

    switch (Type)
    {
    case Add:
        FilledOperation.OperatorType = '+';
        FilledOperation.RightAnswer = FilledOperation.Operand1 + FilledOperation.Operand2;
        break;
    case Sub:
        FilledOperation.OperatorType = '-';
        FilledOperation.RightAnswer = FilledOperation.Operand1 - FilledOperation.Operand2;
        break;
    case Mult:
        FilledOperation.OperatorType = '*';
        FilledOperation.RightAnswer = FilledOperation.Operand1 * FilledOperation.Operand2;
        break;
    case Div:
        FilledOperation.OperatorType = '/';
        if (FilledOperation.Operand1 < FilledOperation.Operand2)
            FilledOperation.RightAnswer = 0;
        else
            FilledOperation.RightAnswer = FilledOperation.Operand1 / FilledOperation.Operand2;
        break;
    case MixType:
        int characterOp = RandomNumber(42, 47);
        if (characterOp != 44 && characterOp != 46)
            FilledOperation.OperatorType = char(characterOp);
        switch ((int)FilledOperation.OperatorType)
        {
        case 42:
            FilledOperation.RightAnswer = FilledOperation.Operand1 * FilledOperation.Operand2;
            break;
        case 43:
            FilledOperation.RightAnswer = FilledOperation.Operand1 + FilledOperation.Operand2;
            break;
        case 45:
            FilledOperation.RightAnswer = FilledOperation.Operand1 - FilledOperation.Operand2;
            break;
        case 47:
            if (FilledOperation.Operand1 < FilledOperation.Operand2)
                FilledOperation.RightAnswer = 0;
            else
                FilledOperation.RightAnswer = FilledOperation.Operand1 / FilledOperation.Operand2;
            break;
        }
    }
    return FilledOperation;
}

void PlayQuestion(OperationInfo Operation, QuestionsLevel Level, OperationType Type)
{
    cout << "\n" << Operation.Operand1 << "\n";
    cout << Operation.Operand2 << " " << Operation.OperatorType << "\n";
    cout << "\n_____________________\n";
    Operation.YourAnswer = ReadYourAnswer();
    if (Operation.YourAnswer == Operation.RightAnswer)
    {
        SetAnswerScreenColor(Operation);
        cout << "Right Answer, Good :-)\n";
    }
    else
    {
        SetAnswerScreenColor(Operation);
        cout << "Wrong Answer :-(\n";
    }
    cout << "The Right Answer Is : " << Operation.RightAnswer << "\n\n";
}

ResulInfo FillResult(short QuestionsNumber, QuestionsLevel Level, OperationType Type, short Right, short Wrong) {
    ResulInfo FilledResult;
    FilledResult.NumberOfQuestions = QuestionsNumber;
    FilledResult.LevelOfQuestion = LevelName(Level);
    FilledResult.TypeOfOperation = TypeName(Type);
    FilledResult.NumberOfRightAnswers = Right;
    FilledResult.NumberOfWrongAnswers = Wrong;
    return FilledResult;
}

ResulInfo PlayGame(short QuestionsNumber)
{
    OperationInfo Operation;
    QuestionsLevel Level = ReadQuestionLevel();
    OperationType Type = ReadOperationType();
    short Right = 0, Wrong = 0;
    for (short QuestionCounter = 1; QuestionCounter <= QuestionsNumber; QuestionCounter++)
    {
        cout << "\n\nQuestion [" << QuestionCounter << "/" << QuestionsNumber << "]\n";
        Operation = FillOperation(Level, Type);
        PlayQuestion(Operation, Level, Type);
        if (Operation.YourAnswer == Operation.RightAnswer)
            Right += 1;
        else
            Wrong += 1;
    }

    return FillResult(QuestionsNumber, Level, Type, Right, Wrong);
}

void ShowFinalResult(ResulInfo Final)
{
    cout << "\n__________________________________\n";
    if (Final.NumberOfRightAnswers >= Final.NumberOfWrongAnswers)
        cout << "\nFinal Results Is PASS :-D\n";
    else
        cout << "\nFinal Results Is FAIL :-(\n";
    cout << "\n__________________________________\n";
    cout << "\nNumber of questions: " << Final.NumberOfQuestions << "\n";
    cout << "\nQuestions Level    : " << Final.LevelOfQuestion << "\n";
    cout << "\nOperations Type    : " << Final.TypeOfOperation << "\n";
    cout << "\nNumber of Right Answers : " << Final.NumberOfRightAnswers << "\n";
    cout << "\nNumber of Wrong Answers : " << Final.NumberOfWrongAnswers << "\n";
    cout << "\n__________________________________\n";
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartMathGame() {
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        ResulInfo GameResult = PlayGame(ReadHowManyQuestions());
        ShowFinalResult(GameResult);
        cout << "\n\nDo you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}


int main()
{
    StartMathGame();
}

