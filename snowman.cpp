#include <iostream>
#include <string>
#include "snowman.hpp"

using namespace std;

// namespace ariel{
//     string snowman(int x){
//         return "_===_\n(.,.)\n( : )\n( : )";
//     }
// }

int reverseNum(int x)
{

    int ans = 0;
    int temp = 0;

    while (x > 0)
    {
        ans *= TEN;
        temp = returnMod10(x);
        ans += temp;
        x /= TEN;
    }
    return ans;
}

int returnMod10(int x)
{
    return x % TEN;
}

bool checkIfValidInput(int x)
{
    int counter = 0;
    while (x > 0)
    {
        if (returnMod10(x) > UNVALID_RANGE_UP && returnMod10(x) < UNVALID_RANGE_DOWN)
        {
            return false;
        }
        counter++;
        x = x / TEN;
    }
    return counter == VALID_LENGTH;
}
void hat(int digit, string &returnedString)
{

    switch (digit)
    {
    case 1:
        returnedString = STREW_HAT;
        break;
    case 2:
        returnedString = MEXICAN_HAT;
        break;
    case 3:
        returnedString = FEZ;
        break;
    default:
        returnedString = RUSSIAN_HAT;
        break;
    }
}
void nose(int digit, string &returnedString)
{

    switch (digit)
    {
    case ONE:
        returnedString = returnedString + NORMAL;
        break;
    case TWO:
        returnedString = returnedString + DOTN;
        break;
    case THREE:
        returnedString = returnedString + LINE;
    default:
        returnedString = returnedString + NONE_N;
        break;
    }
}
void leftEye(int digit, string &returnedString)
{
    switch (digit)
    {
    case ONE:
        returnedString =  STARTING_BRACKKATES + DOT + returnedString;
        break;
    case TWO:
        returnedString = STARTING_BRACKKATES + BIGGER_DOT + returnedString;
        break;
    case THREE:
        returnedString = STARTING_BRACKKATES + BIGGEST_DOT + returnedString;
    default:
        returnedString = STARTING_BRACKKATES + CLOSED_EYE + returnedString;
        break;
    }
}
void rightEye(int digit, string &returnedString)
{
    switch (digit)
    {
    case ONE:
         returnedString = returnedString + DOT + CLOSING_BRACKKATES;
        break;
    case TWO:
        returnedString = returnedString + BIGGER_DOT + CLOSING_BRACKKATES;
        break;
    case THREE:
        returnedString = returnedString + BIGGEST_DOT + CLOSING_BRACKKATES;
    default:
        returnedString = returnedString + CLOSED_EYE + CLOSING_BRACKKATES;
        break;
    }
}
void leftArm(int digit, string &returnedString)
{
    switch (digit)
    {
    case ONE:
        returnedString = NORMAL_ARM + returnedString;
        break;
    case TWO:
        returnedString = UPWARDS_ARM + returnedString;
        break;
    case THREE:
        returnedString = DOWNARDS_ARM + returnedString;
    default:
        returnedString =   returnedString + "\n";
        break;
    }
}

void rightArm(int digit, string &returnedString)
{
    switch (digit)
    {
    case ONE:
        returnedString = returnedString + NORMAL_ARMR;
        break;
    case TWO:
        returnedString = returnedString + UPWARDS_ARMR;
        break;
    case THREE:
        returnedString = returnedString + DOWNARDS_ARMR;
    default:
        returnedString = returnedString + " ";
        break;
    }
}
void torso(int digit, string &returnedString)
{

    switch (digit)
    {
    case ONE:
        returnedString = returnedString + "( : )\n";
        break;
    case TWO:
        returnedString = STARTING_BRACKKATES + VEST + CLOSING_BRACKKATES + "\n";
        break;
    case THREE:
        returnedString = STARTING_BRACKKATES + INWARDS_ARMS + CLOSING_BRACKKATES + "\n";
        break;
    default:
        returnedString = STARTING_BRACKKATES + NONE_T + CLOSING_BRACKKATES + "\n";

        break;
    }
}
void base(int digit, string &returnedString)
{

    switch (digit)
    {
    case ONE:
        returnedString = returnedString + "( : )";
        break;
    case TWO:
        returnedString = STARTING_BRACKKATES + FEET + CLOSING_BRACKKATES;
        break;
    case THREE:
        returnedString = STARTING_BRACKKATES + FLAT + CLOSING_BRACKKATES;
        break;
    default:
        returnedString = STARTING_BRACKKATES + NONE_B + CLOSING_BRACKKATES;
        break;
    }
}

namespace ariel
{
    string snowman(int x)
    {
        bool flag = checkIfValidInput(x);
        int temp = 0;
        int counter = 0;
        int digit = 0;

        if (flag)
        {
            temp = reverseNum(x);
            string buildSnowman;

            while (temp > 0)
            {
                counter++;
                digit = returnMod10(temp);
                switch (counter)
                {
                case ONE:
                    hat(digit, buildSnowman);
                    break;
                case TWO:
                    nose(digit, buildSnowman);
                    break;
                case THREE:
                    leftEye(digit, buildSnowman);
                    break;
                case FOUR:
                    rightEye(digit, buildSnowman);
                    break;
                case FIVE:
                    leftArm(digit, buildSnowman);
                    break;
                case SIX:
                    rightArm(digit, buildSnowman);
                    break;
                case SEVEN:
                    torso(digit, buildSnowman);
                    break;
                default:
                    base(digit, buildSnowman);
                    break;
                }

                temp /= TEN;
            }
            return buildSnowman;
        }
        return ERROR_MASSAGE;
    }
}
