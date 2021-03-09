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
TEST_CASE("Good snowman code") {
	//==================================1-4 check all possible options
	CHECK(nospaces(ariel::snowman(12341234))==nospaces("_===_\n(O.-)/\n<(> <)\n(   )"));
    CHECK(nospaces(ariel::snowman(23412341))==nospaces("___\n.....\n\\(-_.)\n(   )\\\n( : )"));
    CHECK(nospaces(ariel::snowman(34123412))==nospaces("_\n/_\\\n(. o)\n/( : )\n(\" \")"));
    CHECK(nospaces(ariel::snowman(41234123))==nospaces("___\n(_*_)\n(o,O)\n(] [)>\n(___)"));
	//==================================5-14: check some valid outputs for beutiful printing
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
	//======================= more specific check for all items==============================15-46
	//hat
	string h1=nospaces(ariel::snowman(11111111));
	CHECK(h1.substr(0,5)=="_===_");
	string h2=nospaces(ariel::snowman(21111111));
	CHECK(h2.substr(0,8)=="___.....");
	string h3=nospaces(ariel::snowman(31111111));
	CHECK(h3.substr(0,4)=="_/_\\");
	string h4=nospaces(ariel::snowman(41111111));
	CHECK(h4.substr(0,8)=="___(_*_)");
	// Nose/Mouth
	string n_m1=nospaces(ariel::snowman(11111111));
	CHECK(n_m1.substr(7,1)==","); // because all noses is one length except of the fourth and strating in index 7 after eye that exist in index 6
	string n_m2=nospaces(ariel::snowman(12111111));
	CHECK(n_m2.substr(7,1)==".");
	string n_m3=nospaces(ariel::snowman(13111111));
	CHECK(n_m3.substr(7,1)=="_");
	string n_m4=nospaces(ariel::snowman(14111111));
	CHECK(n_m4.substr(7,0)=="");
	// left eye
	string l_e1=nospaces(ariel::snowman(11111111));
	CHECK(l_e1.substr(6,1)=="."); // because all left eyes is one length and strating in index 6 after "(" that exist in index 5
	string l_e2=nospaces(ariel::snowman(11211111));
	CHECK(l_e2.substr(6,1)=="o");
	string l_e3=nospaces(ariel::snowman(11311111));
	CHECK(l_e3.substr(6,1)=="O");
	string l_e4=nospaces(ariel::snowman(11411111));
	CHECK(l_e4.substr(6,1)=="-");
	// right eye
	string r_e1=nospaces(ariel::snowman(11111111));
	CHECK(r_e1.substr(8,1)=="."); // because all right eyes is one length and strating in index 8 after nose that exist in index 7
	string r_e2=nospaces(ariel::snowman(11121111));
	CHECK(r_e2.substr(8,1)=="o");
	string r_e3=nospaces(ariel::snowman(11131111));
	CHECK(r_e3.substr(8,1)=="O");
	string r_e4=nospaces(ariel::snowman(11141111));
	CHECK(r_e4.substr(8,1)=="-");
	// left hand
	string l_h1=nospaces(ariel::snowman(11111111)); //all left hands is one length 
	CHECK(l_h1.substr(10,1)=="<"); //strating in index 10 after ")" that exist in index 9
	string l_h2=nospaces(ariel::snowman(11112111)); // strating in index 5 after hat that finished in index 4
	CHECK(l_h2.substr(5,1)=="\\"); 
	string l_h3=nospaces(ariel::snowman(11113111)); //same explain like the first
	CHECK(l_h3.substr(10,1)=="/");
	string l_h4=nospaces(ariel::snowman(11114111));
	CHECK(l_h4.substr(10,0)=="");
	// right hand
	//all right hands is one length  
	string r_h1=nospaces(ariel::snowman(11111111)); // strating in index 14 after ")" of torso that exist in index 13
	CHECK(r_h1.substr(14,1)==">"); 
	string r_h2=nospaces(ariel::snowman(11111211)); // starting in index 10 after ")" of the face that finish in index 9
	CHECK(r_h2.substr(10,1)=="/"); 
	string r_h3=nospaces(ariel::snowman(11111311));
	CHECK(r_h3.substr(14,1)=="\\"); 
	string r_h4=nospaces(ariel::snowman(11111411));
	CHECK(r_h4.substr(14,0)=="");
	
	//torse
	string t1=nospaces(ariel::snowman(11111111)); // all strating in index 12 after "("  that exist in index 11
	CHECK(t1.substr(12,1)==":"); 
	string t2=nospaces(ariel::snowman(11111121)); 
	CHECK(t2.substr(12,2)=="]["); 
	string t3=nospaces(ariel::snowman(11111131));
	CHECK(t3.substr(12,2)=="><"); 
	string t4=nospaces(ariel::snowman(11111141));
	CHECK(t4.substr(12,0)=="");
	
	//base
	string b1=nospaces(ariel::snowman(11111111)); // all strating in index 16 after "(" of the first line that exist in index 15
	CHECK(b1.substr(16,1)==":"); 
	string b2=nospaces(ariel::snowman(11111112)); 
	CHECK(b2.substr(16,2)=="\"\""); 
	string b3=nospaces(ariel::snowman(11111113));
	CHECK(b3.substr(16,3)=="___"); 
	string b4=nospaces(ariel::snowman(11111114));
	CHECK(b4.substr(16,0)=="");
}

//=======================================================
TEST_CASE("Bad snowman code") { // bad input

	//=================================47-53: size less then 8 
    CHECK_THROWS(snowman(555)); 
	CHECK_THROWS(snowman(2));
	CHECK_THROWS(snowman(1234221));
	CHECK_THROWS(snowman(123231));
	CHECK_THROWS(snowman(12131));
	CHECK_THROWS(snowman(1212));
	CHECK_THROWS(snowman(122));
	//=================================54-56: size more then 8
	CHECK_THROWS(snowman(1234123123));
	CHECK_THROWS(snowman(122231113));
	CHECK_THROWS(snowman(1222311193));
	//=================================57-59: contains digits not between 1-4
	CHECK_THROWS(snowman(52931255)); 
	CHECK_THROWS(snowman(58931465)); 
	CHECK_THROWS(snowman(52000345)); 
	//=================================60: negative number 
	CHECK_THROWS(snowman(-23343555)); 

}


