/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 *
 * AUTHORS: omer rabin
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;
#include <stdexcept>
#include <string>
#include<iostream>
#include <algorithm>
using namespace std;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}
//---------------------------------------------
//static int input;
TEST_CASE("Good snowman code") {
	//string actual=snowman(11114411);
	//==================================1-10: check valid outputs
 	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(33232124)) == nospaces("_\n/_\\\n \\(o_O)(][)>()"));
	CHECK(nospaces(snowman(32443333)) == nospaces(" _\n/_\\\n(-.-)\n/(><)\\\n (___)"));
	CHECK(nospaces(snowman(41341144)) == nospaces(" ___\n(_*_)\n(O,-)\n<(  )>\n( )"));
	CHECK(nospaces(snowman(44242123)) == nospaces(" ___\n(_*_)\n\\(o-)\n(][)>\n(___)"));
	CHECK(nospaces(snowman(12341214)) == nospaces(" _===_\n(O.-)/\n<( : )\n( )"));
	CHECK(nospaces(snowman(12333321)) == nospaces(" _===_\n(O.O)\n/(][)\\\n( : )"));
	CHECK(nospaces(snowman(23232223)) == nospaces(" ___\n.....\n\\(o_O)/\n(] [)\n(___)"));
	CHECK(nospaces(snowman(31333342)) == nospaces(" _\n/_\\\n(O,O)\n/(  )\\\n(\" \")"));
	CHECK(nospaces(snowman(43232122)) == nospaces(" ___\n(_*_)\n\\(o_O)\n(] [)>\n(\" \")"));

}
//=======================================================
TEST_CASE("Bad snowman code") { // bad input

	//=================================11-13: size less then 8 
    CHECK_THROWS(snowman(555)); 
	CHECK_THROWS(snowman(2));
	CHECK_THROWS(snowman(1234221));
	//=================================14-16: size more then 8
	CHECK_THROWS(snowman(1234123123));
	CHECK_THROWS(snowman(122231113));
	CHECK_THROWS(snowman(1222311193));
	//=================================17-19: contains digits not between 1-4
	CHECK_THROWS(snowman(52931255)); 
	CHECK_THROWS(snowman(58931465)); 
	CHECK_THROWS(snowman(52000345)); 
	//=================================20
	CHECK_THROWS(snowman(-23343555)); // negative number 

}


