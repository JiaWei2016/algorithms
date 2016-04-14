#include <iostream>
#include <stack>
#include <string>

char GetExpectedBracket(char bracket) {
	if (bracket == ')') return '(';
	else if (bracket == ']') return '[';
	else if (bracket == '}') return '{';
}

bool IsOpenBracket(char bracket) {
	if (bracket == '(' || bracket == '{' || bracket == '[')
		return true;
	else
		return false;
}

bool IsClosedBracket(char bracket) {
	if (bracket == ')' || bracket == '}' || bracket == ']')
		return true;
	else
		return false;
}

int main() {
	std::string text;
	getline(std::cin, text);

	int j = 0;
	int popped = 0;
	bool startCounter = false;

	std::stack <char> st;

	//for each element in the input text,
	//if the character is not a closed bracket, push
	//them into a stack
	for (int position = 0; position < text.length(); ++position) {
		char next = text[position];

		if (!IsClosedBracket(next)) {
			st.push(next);
		}

		//if the element is a closed bracket and the stack
		//is empty, this is the first unmatched
		//closed bracket, report the position and return
		else if (st.empty())
		{
			std::cout << ++position;
			return 0;
		}
		else
		{
			char expected = GetExpectedBracket(next);
			char c;
			do
			{
				c = st.top();
				st.pop();

				//if after popping an element from the stack
				//the stack is empty, record the position
				//because this will have to be added to the total
				//if we need to report an unmatched bracket
				//at the end of the routine. See (*)
				if (st.empty()) popped = position + 1;

				if (IsOpenBracket(c) && c != expected) {
					std::cout << ++position;
					return 0;
				}
			} while (!st.empty() && c != expected);

			if (st.empty() && c != expected) {
				std::cout << ++position;
				return 0;
			}
		}
	}

	//if after popping all pairs of brackets
	//there are still elements in the stack,
	//pop them after checking if there are 
	//any open brackets stored. If so, report
	//the position by counting the elements being
	//popped plus any previously popped elements (*)
	while (!st.empty()) {
		if (IsOpenBracket(st.top())) {
			startCounter = true;
		}
		if (startCounter) {
			j++;
		}
		st.pop();
	}
	if (j > 0) {
		std::cout << j + popped;
	}

	//in the end, if there are no elements in the 
	//stack, report success.
	else {
		std::cout << "Success";
	}

	return 0;
}
