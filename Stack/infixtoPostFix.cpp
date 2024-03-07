#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '/' || ch == '*') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

void infixtopostfix(string inp, string& out) {
    stack<char> stk;

    for (char i : inp) {
        if (isalnum(i)) {
            out += i;
        } else if (i == '(') {
            stk.push(i);
        } else if (i == ')') {
            while (!stk.empty() && stk.top() != '(') {
                out += stk.top();
                stk.pop();
            }
            stk.pop();
        } else {
            while (!stk.empty() && precedence(stk.top()) >= precedence(i)) {
                out += stk.top();
                stk.pop();
            }
            stk.push(i);
        }
    }

    while (!stk.empty()) {
        out += stk.top();
        stk.pop();
    }
}

int main() {
    string inp = "a+b*(c-d)/e";
    string out;
    infixtopostfix(inp, out);
    cout << out << endl;
    return 0;
}

#include <stack>
#include <vector>

using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> stk;

    StockSpanner() {

    }

    int next(int price) {
        int span = 1;
        while (!stk.empty() && stk.top().first <= price) {
            span += stk.top().second;
            stk.pop();
        }
        stk.push({price, span});
        return span;
    }
};


#include <stack>
using namespace std;

class StockSpanner {
public:
    stack<int> stk;

    StockSpanner() {

    }

    void cloneStack(stack<int>& st, stack<int>& temp) {
        if(st.empty()) return;
        int t = st.top();
        st.pop();
        cloneStack(st, temp);
        temp.push(t);
        st.push(t);
    }

    int next(int price) {
        int count = 1;
        stack<int> temp;
        cloneStack(stk, temp);
        while (!temp.empty() && temp.top() <= price) {
            temp.pop();
            count++;
        }

        stk.push(price);
        return count;
    }
};


