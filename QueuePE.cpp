#include <iostream>
#include <deque>
#include <stack>
#include <string>

using namespace std;

template <class T>
class MyStack {
private:
    stack<T> st;
    deque<string> fh;

public:
    void push(T n) {
        st.push(n);
        fh.push_back("ok");
    }

    void pop()
    {
        if (st.size() > 0)
        {
            T n = st.top();
            fh.push_back(std::to_string(n));
            st.pop();
            return;
        }
        fh.push_back("error");
    }

    void back() {
        if (st.size() > 0)
        {
            T n = st.top();
            fh.push_back(std::to_string(n));
            return;
        }
        fh.push_back("error");
    }

    void size() {
        T n = st.size();
        fh.push_back(std::to_string(n));
    }

    void clear() {
        while (!st.empty()) st.pop();
        fh.push_back("ok");
    }

    void exit()
    {
        fh.push_back("bye");

        typename std::deque<std::string>::iterator iter;
        for (iter = fh.begin(); iter != fh.end(); iter++) std::cout << *iter << std::endl;
    }

};

int main() {

    string n;
    cin >> n;
    int a;
    MyStack<int> C = MyStack<int>();
    while (n != "exit") {
        if (n == "push") {
            std::cin >> a;
            C.push(a);
        }
        if (n == "pop") {
            C.pop();
        }
        if (n == "back") {
            C.back();
        }
        if (n == "size") {
            C.size();
        }
        if (n == "clear") {
            C.clear();
        }
        std::cin >> n;
        if (n == "exit")
        {
            C.exit();
            break;
        }
    }
    return 0;

}