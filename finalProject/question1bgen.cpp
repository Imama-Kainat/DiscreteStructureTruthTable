#include <iostream>
using namespace std;
                            //all premises true conclusion true argument is valid
                            //all premises true conclusion false argument is invalid
                            //if premises have true ,false value no argument
bool evaluate(bool p, bool q, bool r, bool s, bool t, bool u, string expr) {
    bool result;
    if (expr == "~s") {
        result = !s;
    } else if (expr == "p&t") {
        result = p && t;
        
    }
	else if (expr == "p|t") {
        result = p ||t;
        
    }
	else if (expr == "r|t") {
        result = r ||t;
        
    } else if (expr == "r|s") {
        result = r || s;
    } else if (expr == "u&t") {
        result = u && t;
    } else if (expr == "u|t") {
        result = u || t;
    }else if (expr == "u>p") {
        result = !u || p;
    } else if (expr == "q>(u&t)") {
        result = !q || (u && t);
    } else if (expr == "q>(r|s)") {
        result = !q || (r || s);
    } else {
        cout << "Invalid expression: " << expr << endl;
        result = false;
    }
    return result;
}

int main() {
    int p, q, r, s, t, u;
	bool conclusion, premises;
    string premise1, premise2, premise3, conclusionEq;

    // Read in the premises and conclusion from the user
    //for premises data;
    cout << "Enter premise 1: ";
    cin >> premise1;
    cout << "Enter premise 2: ";
    cin >> premise2;
    cout << "Enter premise 3: ";
    cin >> premise3;
    cout << "Enter conclusion equation: ";
    cin >> conclusionEq;
    // Evaluate the premises and conclusion for all possible truth values of p, q, r, s, t, u
    for (p = 0; p <= 1; p++) {
        for (q = 0; q <= 1; q++) {
            for (r = 0; r <= 1; r++) {
                for (s = 0; s <= 1; s++) {
                    for (t = 0; t <= 1; t++) {
                        for (u = 0; u <= 1; u++) {
                            premises = evaluate(p, q, r, s, t, u, premise1) && evaluate(p, q, r, s, t, u, premise2) && evaluate(p, q, r, s, t, u, premise3);
                            conclusion = evaluate(p, q, r, s, t, u, conclusionEq);
                            if (premises && !conclusion ) {
                                cout << "The argument is not valid." << endl;
                                cout << "Counter!!!! p=" << p << ", q=" << q << ", r=" << r << ", s=" << s << ", t=" << t << ", u=" << u << ", conclusion=" << conclusion<<  endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    // If no counterexample is found, the argument is valid
    //if premises sari true na b ho to b invlid
    cout << "The argument is valid." << endl;
    return 0;
}
