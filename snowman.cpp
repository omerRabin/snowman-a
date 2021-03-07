#include <iostream>
using namespace std;
#include <stdexcept>
#include "snowman.hpp"

namespace ariel {
	string convert2hat(int x)
{
	int hat = x/10000000;
	if(hat<1 || hat>4) throw std::out_of_range{"x contains incorrect digits!"};
	switch (hat)
	{
	case 1: 
		return " _===_";
		break;
	case 2:
		return "  ___\n .....";	
		break;
	case 3:
		return "   _  \n  /_\\ "; // should finish in one slash
		break;
	case 4:
		return "  ___\n (_*_)";
		break;
	default:
		return "";
	}
}
string convert2nose_mouth(int x)
{
	int nose_mouth = (x/1000000)%10;
	if(nose_mouth<1 || nose_mouth>4) throw std::out_of_range{"x contains incorrect digits!"};

	switch (nose_mouth)
	{
	case 1: 
		return ",";
		break;
	case 2:
		return ".";	
		break;
	case 3:
		return "_";
		break;
	case 4:
		return " ";
		break;
	default:
		return "";	
	}
}
string convert2left_eye(int x)
{
	int left_eye = (x/100000)%10;
	if(left_eye<1 || left_eye>4) throw std::out_of_range{"x contains incorrect digits!"};
	switch (left_eye)
	{
	case 1: 
		return ".";
		break;
	case 2:
		return "o";	
		break;
	case 3:
		return "O";
		break;
	case 4:
		return "-";
		break;
	default:
		return "";	

	}
}
string convert2right_eye(int x)
{
	int right_eye = (x/10000)%10;
	if(right_eye<1 || right_eye>4) throw std::out_of_range{"x contains incorrect digits!"};
	switch (right_eye)
	{
	case 1: 
		return ".";
		break;
	case 2:
		return "o";	
		break;
	case 3:
		return "O";
		break;
	case 4:
		return "-";
		break;
	default:
		return "";	

	}
}
string convert2left_arm(int x)
{
	int left_arm = (x/1000)%10;
	if(left_arm<1 || left_arm>4) throw std::out_of_range{"x contains incorrect digits!"};
	switch (left_arm)
	{
	case 1: 
		return "<";
		break;
	case 2:
		return "\\"; // should be one slash
		break;
	case 3:
		return "/";
		break;
	case 4:
		return " ";
		break;
	default:
		return "";	

	}
}
string convert2right_arm(int x)
{
	int right_arm = (x/100)%10;
	if(right_arm<1 || right_arm>4) throw std::out_of_range{"x contains incorrect digits!"};
	switch (right_arm)
	{
	case 1: 
		return ">";
		break;
	case 2:
		return "/";	
		break;
	case 3:
		return "\\"; // should be one slash
		break;
	case 4:
		return " ";
		break;
	default:
		return "";	

	}
}
string convert2torso(int x)
{
	int torso = (x/10)%10;
	if(torso<1 || torso>4) throw std::out_of_range{"x contains incorrect digits!"};
	switch (torso)
	{
	case 1: 
		return " : ";
		break;
	case 2:
		return "] [";	
		break;
	case 3:
		return "> <";
		break;
	case 4:
		return "   ";
		break;
	default:
		return "";	

	}
}
string convert2base(int x)
{
	int base = x%10;
	if(base<1 || base>4) throw std::out_of_range{"x contains incorrect digits!"};
	switch (base)
	{
	case 1: 
		return " : ";
		break;
	case 2:
		return "\" \"";	
		break;
	case 3:
		return "___";
		break;
	case 4:
		return "   ";
		break;
	default:
		return "";	

	}
}

string snowman(int x) {
	if(x<=0) throw std::out_of_range{"x must be positive!"};
	if(x/10000000 ==0 || x/100000000!=0) throw std::out_of_range{"incorrent length for x!"};
	string snowman="";
		string hat= convert2hat(x);
		string nose_mouth= convert2nose_mouth(x);
		string left_eye= convert2left_eye(x);
		string right_eye= convert2right_eye(x);
		string left_arm= convert2left_arm(x);
		string right_arm= convert2right_arm(x);
		string torso= convert2torso(x);
		string base= convert2base(x);
		//check if hat is one line
		if(hat == "_===_")
		{
			snowman+="\n"+ hat + "\n";
		}
		else
		{
			snowman+= hat+ "\n";
		}
		if(right_arm ==">" || right_arm=="\\") //right arm in second line // should be one slash
		{
			if(left_arm=="<" || left_arm=="/"){ //left arm in second line
				snowman+= " (" + left_eye + nose_mouth+ right_eye + ")\n" + left_arm +"(" +torso+")"+ right_arm + "\n (" + base +")";
			}
			else{ //left arm in first line
				snowman+= left_arm + "(" + left_eye + nose_mouth + right_eye + ")\n ("+ torso + ")" + right_arm + "\n (" + base +")";
			}
		}
		else //right arm in first line
		{
			if(left_arm=="<" || left_arm=="/"){//left arm in second line
				snowman+= " (" + left_eye + nose_mouth+ right_eye + ")" + right_arm +"\n"+ left_arm +"(" +torso+")\n (" + base +")"; 
			}
			else //left arm in first line
			{
				snowman+= left_arm + "(" + left_eye + nose_mouth + right_eye + ")" + right_arm+ "\n (" + torso + ")\n" + " (" + base +")";

			}
			
		}
		return snowman;	
	}
}