#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;
bool flag=true;
bool evaluate(string expression, bool* variables, int n) {//..............................................1 handle brackets,&,| >,<>,~
    // Base case: expression contains only one variable
    if (expression.length() == 1) {
        int var_index = expression[0] - 'a';
        return variables[var_index];
    }
   
    int num_brackets = 0;// getting brackets
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(') {
            num_brackets++;
        } else if (expression[i] == ')') {//Bracket
            num_brackets--;
        } else if (num_brackets == 0 && (expression[i] == '&' || expression[i] == '|' || expression[i] == '>'||expression[i] == '<')) {
            bool left_value = evaluate(expression.substr(0, i), variables, n);
            bool right_value = evaluate(expression.substr(i+1), variables, n);
            if (expression[i] == '&') {
                return (left_value && right_value);
            } else if (expression[i] == '|') {//OR
                return (left_value || right_value);
            } else if (expression[i] == '>') {//Implies
                return (!left_value || right_value);
            }
            else if(expression[i] == '<' && expression[i+1]=='>')//Biconditional
            return(left_value && right_value) || (!left_value && !right_value);
        } else if (num_brackets == 0 && expression[i] == '~') {
            return !evaluate(expression.substr(i+1), variables, n);
        }
    }
}
//Print Truth Table
void print_truth_table(string expression, int n, char* variable_names, bool* variables) {
    cout << " ";
    for (int i = 0; i < n; i++) {
        cout << " | " << variable_names[i];
    }
    cout << " | " << expression << endl;
    for (int i = 0; i < n; i++) {
        cout << "__";
    }
    cout << "__";
    for (int i = 0; i < expression.length(); i++) {
        cout << "___";
    }
    cout << endl;
    int num_rows = pow(2, n);
    for (int i = 0; i < num_rows; i++) {
        for (int j = n - 1; j >= 0; j--) {
            bool value = (i / (int)pow(2, j)) % 2;
            variables[j] = value;
            cout << " | " << (value ? "T" : "F");
        }
        cout << " | " << (evaluate(expression, variables, n) ? "T" : "F") << endl;
    }
}
//Split expression
vector<string> split_expression(string expression) {
    vector<string> sub_expressions;
    int num_brackets = 0;
    int start_pos = 0;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(') {
            num_brackets++;
        } else if (expression[i] == ')') {
            num_brackets--;
        }
        if (num_brackets == 0 && (expression[i] == '&' || expression[i] == '|' || expression[i] == '>')) {
            sub_expressions.push_back(expression.substr(start_pos, i-start_pos));
            start_pos = i+1;
        }
    }
    sub_expressions.push_back(expression.substr(start_pos));
    return sub_expressions;
}
int main() {
    	string expression;
	cout << "Enter a logical statement: ";
	getline(cin, expression);
	
	string strings[50];
	int stringssize = 0;
	int num_brackets = 0;
	int start_pos_arr[100] = { 0 };
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '(') {
				start_pos_arr[num_brackets] = i;
				num_brackets++;
		}
		else if (expression[i] == ')') {
			num_brackets--;
			for (int j = start_pos_arr[num_brackets]; j <= i; j++)
			{
				strings[stringssize].push_back(expression[j]);

			}
			stringssize++;
		}
	}
	for (int i = 0; i<stringssize; i++)
	{
		cout << strings[i] << endl;
	}
	
	
	int n = 0;//.................................................number of variables
	char variable_names[26];
	bool variables[26];

	// Determine the number of variables in the expression
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] >= 'a' && expression[i] <= 'z' || expression[i] >= 'A' && expression[i] <= 'Z') {
			if (i == 0 || expression[i - 1] != expression[i]) {
				variable_names[n] = expression[i];
				n++;
			}
		}
	}//non repeat premises

	int countvar = n, temp = false;
	for (int i = 0; i<countvar; i++) {
		for (int j = 0; j<countvar; j++) {
			if (variable_names[i] == variable_names[j]) {
				if (i != j)	temp = true;
			}

		}

	}
	if (temp)
		n -= 1;
	// Print the truth table
	//dont check the repeating 
	cout << "total variable is " << n << endl;
	print_truth_table(expression, n, variable_names, variables);
}