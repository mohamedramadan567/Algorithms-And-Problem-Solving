#include <iostream>
#include <cstdlib> // for RandomNumber fun
#include <time.h> // for run srand into the main

using namespace std;

enum enQuestionsLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };

struct stQuestion
{
    short Number1 = 0;
    short Number2 = 0;
    enQuestionsLevel QuestionsLevel;
    enOperationType OperationType;
    int PlayerAnswer = 0;
    int CorrectAnswer = 0;
    bool QuestionResult = false;
};

struct stQuizz
{
    stQuestion QuestionList[100];
    short NumberOfQuestions = 0;
    enQuestionsLevel QuestionsLevel;
    enOperationType OpType;
    short NumberOfRightAnswers = 0;
    short NumberOfWrongAnswers = 0;
    bool Pass = false;
};

int RandomNumber(int From, int To) 
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int SimpleCalculator(short Number1, short Number2, enOperationType OpType)
{
    switch(OpType)
    {
        case enOperationType::Add:
        return (Number1 + Number2);

        case enOperationType::Sub:
        return Number1 - Number2;

        case enOperationType::Mult:
        return Number1 * Number2;

        case enOperationType::Div:
        return Number1 / Number2;
        
        default:
        return Number1 + Number2;
    }
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel, enOperationType OpType)
{
    stQuestion Question;
    if(QuestionLevel == enQuestionsLevel::Mix)
    {
        QuestionLevel = (enQuestionsLevel)RandomNumber(1, 3);
    }
    if(OpType == enOperationType::MixOp)
    {
        OpType = (enOperationType)RandomNumber(1, 4);
    }
    Question.OperationType = OpType;

    switch(QuestionLevel)
    {
        case enQuestionsLevel::EasyLevel:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
        Question.QuestionsLevel = QuestionLevel;
        return Question;

        case enQuestionsLevel::MedLevel:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
        Question.QuestionsLevel = QuestionLevel;
        return Question;

        case enQuestionsLevel::HardLevel:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
        Question.QuestionsLevel = QuestionLevel;
        return Question;
    }
    
}

void GenerateQuizzQuestions(stQuizz& Quizz)
{
    for(short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
    {
        Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OpType);
    }
}

short ReadHowManyQuestions()
{
    int Questions;
    
    do
    {
        cout << "How Many Questions do you want to answer ? ";
        cin >> Questions;
    }while(Questions < 0 || Questions > 10);

    return Questions;
}

enOperationType ReadOperationType()
{
    short OpType;
    do
    {
        cout << "\nEnter Operation Type [1]:Add, [2]:Sub, [3]:Mul, [4]:Div, [5]:Mix ? ";
        cin >> OpType;
    }while(OpType < 1 || OpType > 5);
    return (enOperationType) OpType;
}

enQuestionsLevel ReadQuestionsLevel()
{
    short QuestionLevel = 0;
    do
    {
        cout << "\nEnter Questions Level [1]:Easy, [2]:Med, [3]:Hard, [4]:Mix ? ";
        cin >> QuestionLevel;
    }while(QuestionLevel < 1 || QuestionLevel > 4);
    return (enQuestionsLevel) QuestionLevel;
}

string GetQuestionsLevel(enQuestionsLevel QuestionLevel)
{
    string arr[4] = { "Easy", "Mid", "Hard", "Mix" };
    return arr[QuestionLevel - 1];
}

int ReadPlayerAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}

string GetOpType(enOperationType opType)
{
    string arr[5] = { "+", "-", "*", "/", "Mix"};
    return arr[opType - 1];
}

void SetScreenColor(bool Right)
{
    if(Right)
    system("color 2F");
    else
    {
        system("color 4F");
        cout << "\a";
    }
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short Question)
{
    if(Quizz.QuestionList[Question].PlayerAnswer != Quizz.QuestionList[Question].CorrectAnswer)
    {
        Quizz.QuestionList[Question].QuestionResult = false;
        cout << "\nWrong answer :-(\n";
        cout << "The right answer is ";
        cout << Quizz.QuestionList[Question].CorrectAnswer << endl;
        Quizz.NumberOfWrongAnswers++;
    }
    else
    {
        Quizz.QuestionList[Question].QuestionResult = true;
        cout << "\nRight answer :-)\n";
        Quizz.NumberOfRightAnswers++;
    }
    cout << endl;
    SetScreenColor(Quizz.QuestionList[Question].QuestionResult);
}

void PrintTheQuestion(stQuizz& Quizz, short Question)
{
    cout << "\n";
    cout << "[" << Question + 1 << "/" << Quizz.NumberOfQuestions << "]\n\n";
    cout << Quizz.QuestionList[Question].Number1 << endl;
    cout << Quizz.QuestionList[Question].Number2 << " ";
    cout << GetOpType(Quizz.QuestionList[Question].OperationType);
    cout << "\n__________\n";
}

void AskAndCorrectQuestionsListAnswer(stQuizz& Quizz)
{
    for(short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
    {
        PrintTheQuestion(Quizz, Question);
        Quizz.QuestionList[Question].PlayerAnswer = ReadPlayerAnswer();
        CorrectTheQuestionAnswer(Quizz, Question);
    }
    Quizz.Pass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

string GetFinalResults(bool Pass)
{
    if(Pass)
    return "Pass :-)";
    else 
    return "Fail :-(";
}

void PrintQuizzResults(stQuizz Quizz)
{
    cout << "\n________________________\n\n";
    cout << "Final Results is " << GetFinalResults(Quizz.Pass) << endl;
    cout << "\n________________________\n\n";
    cout << "Number of Questions: " << Quizz.NumberOfQuestions << endl;
    cout << "Questions Level: " << GetQuestionsLevel(Quizz.QuestionsLevel) << endl;
    cout << "Op Type: " << GetOpType(Quizz.OpType) << endl;
    cout << "Number of Right answers: " << Quizz.NumberOfRightAnswers << endl;
    cout << "Number of Wrong answers: " << Quizz.NumberOfWrongAnswers << endl;
    cout << "\n________________________\n\n";
    SetScreenColor(Quizz.Pass);
}

void PlayMathGame()
{
    stQuizz Quizz;
    Quizz.NumberOfQuestions = ReadHowManyQuestions();
    Quizz.QuestionsLevel = ReadQuestionsLevel();
    Quizz.OpType = ReadOperationType();
    GenerateQuizzQuestions(Quizz);
    AskAndCorrectQuestionsListAnswer(Quizz);
    PrintQuizzResults(Quizz);
}

void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        PlayMathGame();

        cout << "\nDo you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
    
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL)); 

    //Math Game.
    
    StartGame();
    
    return 0;
}