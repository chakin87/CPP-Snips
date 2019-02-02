#include "onPar.h"



OnPar::OnPar()
{
}

OnPar::OnPar(std::string webFormStr)
{
	if (isBalanced(webFormStr)) {
		std::cout << "<br>";
		std::cout << "<b>" << "The String is Balanced!" << "</b>";
		return;
	}
	else {
		std::cout << "<br>";
		std::cout << "<b>" << "The String is Not Balanced! :(" << "</b>";
		return;
	}
}


OnPar::~OnPar()
{
}
bool OnPar::isBalanced(std::string set)
{

	for (int i = 0; i < set.length(); i++)
	{
		if (set[i] == '(' || set[i] == '{' || set[i] == '[')
			stChar.push(set[i]);
		else if (set[i] == ')' || set[i] == '}' || set[i] == ']')
		{
			if (stChar.empty() || !isPair(stChar.top(), set[i]))
				return false;
			else
				stChar.pop();
		}
	}
	return stChar.empty() ? true : false;
}

bool OnPar::isPair(char a, char b)
{
	if (a == '(' && b == ')') return true;
	else if (a == '{' && b == '}') return true;
	else if (a == '[' && b == ']') return true;
	return false;
}