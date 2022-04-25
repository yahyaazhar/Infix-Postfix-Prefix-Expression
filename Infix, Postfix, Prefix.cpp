/*Infix, Postfix, Prefix
  Name: M Yahya*/

#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
	int size = 0, top = 0;
	char* arr;

	int postCheck = 0;
	int postInsert;

	Stack(int s) {
		size = s;
		top = 0;
		arr = new char[size];
		for (int i = 0; i < size; i++) {
			arr[i] = 'N';
		}
	}

	bool IsFull() {
		if (top == size) {
			return true;
		}
		else {
			return false;
		}
	}

	bool IsEmpty() {
		if (top == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void Push(char value) {
		if (!IsFull()) {
			arr[top] = value;
			top++;
		}
		else {
			cout << "Stack is Full!\n";
		}
	}

	char Pop() {
		if (!IsEmpty()) {
			char i;
			i = arr[top - 1];
			arr[top - 1] = 'N';
			top--;
			cout << "\t\t\t" << i << endl;
			return i;
		}
		else {
			return 'N';
		}
	}

	int prece(char c) {
        if (c == '*' || c == '/') {
			cout << "high pre\n";
			return 3;
		}
	    else if (c == '+' || c == '-') {
			cout << "low\n";
			return 2;
		}
		else {
			return 1;
		}
	}


	void expression(string exp) {
		for (int i = 0; i < exp.length(); i++) {
			if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z') {
				if (arr[top] == 'N') {
					Push(exp[i]);
				}
				else if (arr[i] == '*' || arr[i] == '/' || arr[i] == '+' || arr[i] == '-') {
					Push(exp[i]);
				}
			}
			else if (exp[i] == '*' || exp[i] == '/' && prece(arr[top]) > prece(exp[i])) {
				Push(exp[i]);
			}

			else if (exp[i] == '*' || exp[i] == '/' && prece(arr[top]) <= prece(exp[i])) {
				Pop();
			}

			else if (exp[i] == '+' || exp[i] == '-' && prece(arr[top]) > prece(exp[i])) {
				Push(exp[i]);
			}
			else if (exp[i] == '+' || exp[i] == '-' && prece(arr[top]) <= prece(exp[i])) {
				cout << "low\n";
				Pop();
			}
		}
	}

	
	void Display() {
		cout << endl;
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
	}
};

int main() {
	Stack str(9);
	string expre = "a*b-d/z+c";
	str.expression(expre);

	str.Display();
	cout << endl;

	
}