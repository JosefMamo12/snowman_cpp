/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Josef Mamo
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("check hats:")
{
	//STRAW HAT
	CHECK(nospaces(snowman(11114411)) == nospaces(STREW_HAT + "\n(.,.)\n( : )\n( : )"));
	// //MEXICAN HAT
	CHECK(nospaces(snowman(21114411)) == nospaces(MEXICAN_HAT + "\n(.,.)\n( : )\n( : )"));
	// //FEZ
	CHECK(nospaces(snowman(31114411)) == nospaces(FEZ + "\n(.,.)\n( : )\n( : )"));
	// //RUSSIAN HAT
	CHECK(nospaces(snowman(41114411)) == nospaces(RUSSIAN_HAT + "\n(.,.)\n( : )\n( : )"));
}
TEST_CASE("check nose")
{
	//NORMAL
	CHECK(nospaces(snowman(11114411)) == nospaces("_---_\n(.,.)\n( : )\n( : )"));
	// DOT
	CHECK(nospaces(snowman(12114411)) == nospaces("_---_\n(...)\n( : )\n( : )"));
	//LINE
	CHECK(nospaces(snowman(13114411)) == nospaces("_---_\n(._.)\n( : )\n( : )"));
	//NONE
	CHECK(nospaces(snowman(14114411)) == nospaces("_---_\n(. .)\n( : )\n( : )"));
}
TEST_CASE("check eyes")
{
	//DOT
	CHECK(nospaces(snowman(11114411)) == nospaces("_---_\n(.,.)\n( : )\n( : )"));
	//BIGGER DOT
	CHECK(nospaces(snowman(12224411)) == nospaces("_---_\n(o,o)\n( : )\n( : )"));
	// BIGGEST DOT
	CHECK(nospaces(snowman(13334411)) == nospaces("_---_\n(O_O)\n( : )\n( : )"));
	//CLOSED
	CHECK(nospaces(snowman(11114411)) == nospaces("_---_\n(-,-)\n( : )\n( : )"));
}
TEST_CASE("check hands ")
{
	//NORMAL ARMS
	CHECK(nospaces(snowman(11111111)) == nospaces("_---_\n(.,.)\n<( : )>\n( : )"));
	//UPWARDS ARMS
	CHECK(nospaces(snowman(11112211)) == nospaces("_---_\n\\(.,.)/\n( : )\n( : )"));
	//DOWNWARDS ARMS
	CHECK(nospaces(snowman(11113311)) == nospaces("_---_\n(.,.)\n/( : )\\\n( : )"));
	//NONE BOTH HANDS
	CHECK(nospaces(snowman(11114411)) == nospaces("_---_\n(.,.)\n( : )\n( : )"));
}
TEST_CASE("check torso & base")
{
		//BUTTONS TORSO && BOTTONS BASE
	CHECK(nospaces(snowman(11114411)) == nospaces(STREW_HAT + "\n(.,.)\n( : )\n( : )"));
	// //VEST & FEET
	CHECK(nospaces(snowman(21114422)) == nospaces(MEXICAN_HAT + "\n(.,.)\n(] [)\n(\" \")"));
	// //INWARD ARMS & FLAT
	CHECK(nospaces(snowman(31114433)) == nospaces(FEZ + "\n(.,.)\n(> <)\n(___)"));
	// NONE 
	CHECK(nospaces(snowman(41114444)) == nospaces(RUSSIAN_HAT + "\n(.,.)\n(   )\n(   )"));

}

TEST_CASE("Bad snowman code")
{
	//NOT IN RANGE NUMBER UPPER BOUND BECAUSE OF 5
	CHECK_THROWS(snowman(11552223));

	//NOT IN RANGE NUMBER LOWER BOUND 0 AT START
	CHECK_THROWS(snowman(00234123));

	//LONGER THAN 8 DIGITS
	CHECK_THROWS(snowman(12323123));

	//LESS THAN 8 DIGITS
	CHECK_THROWS(snowman(123));

	//CHECK ZERO INPUT
	CHECK_THROWS(snowman(00000000));

	//NEGATIVE NUMBERS LESS THAN 8 NUMBERS
	CHECK_THROWS(snowman(-1111));

	//NEGATIVE NUMBERS EQUAL TO 8 NUMBERS
	CHECK_THROWS(snowman(-12321313));

	//NEGATIVE NUMBERS BIGGER THAN 8 NUMBERS
	CHECK_THROWS(snowman(-1233123132));
}

/* Add more test cases here */
