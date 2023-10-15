#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Stack
{

    enum { EMPTY = -1, FULL = 20 };


    char st[FULL + 1];

 
    int top;

public:
    
    Stack();
    char Top();
  
    void Push(char c);


    char Pop();


    void Clear();

    bool IsEmpty();

 
    bool IsFull();

    int GetCount();
    bool Check(Stack S, string user);
};


Stack::Stack()
{
    // »ÁÌ‡˜‡Î¸ÌÓ ÒÚÂÍ ÔÛÒÚ
    top = EMPTY;
}

void Stack::Clear()
{
    // ›ÙÙÂÍÚË‚Ì‡ˇ "Ó˜ËÒÚÍ‡" ÒÚÂÍ‡
    // (‰‡ÌÌ˚Â ‚ Ï‡ÒÒË‚Â ‚ÒÂ Â˘Â ÒÛ˘ÂÒÚ‚Û˛Ú,
    // ÌÓ ÙÛÌÍˆËË ÍÎ‡ÒÒ‡, ÓËÂÌÚËÓ‚‡ÌÌ˚Â Ì‡ ‡·ÓÚÛ Ò ‚Â¯ËÌÓÈ ÒÚÂÍ‡,
    // ·Û‰ÛÚ Ëı Ë„ÌÓËÓ‚‡Ú¸)
    top = EMPTY;
}

bool Stack::IsEmpty()
{
    // œÛÒÚ?
    return top == EMPTY;
}

bool Stack::IsFull()
{
    // œÓÎÓÌ?
    return top == FULL;
}

int Stack::GetCount()
{
    
    return top + 1;
}

void Stack::Push(char c)
{
    
    if (!IsFull())
        st[++top] = c;
}

char Stack::Pop()
{
    
    if (!IsEmpty())
        return st[top--];
    else
        return 0;
}
char Stack::Top()
{
    if (IsEmpty()) {
        cout << "Stack Empty" << endl;
        return '\0';
    }
    return st[top];
}
bool Stack::Check(Stack S, string user)
{
    char c;
    for (int i = 0; i < user.length(); i++) {
        c = user[i];
        switch (c) {
        case '(':
            S.Push(')');
            break;
        case '{':
            S.Push('}');
            break;
        case '[':
            S.Push(']');
            break;

        case ')':
            if (S.IsEmpty() || S.Top() != c)
            {
                cout << "Error";
                return false;
            }
            S.Pop();
            break;

        case '}':
            if (S.IsEmpty() || S.Top() != c)
            {
                cout << "Error";
                return false;
            }
            S.Pop();
            break;
        case ']':
            if (S.IsEmpty() || S.Top() != c)
            {
                cout << "Error";
                return false;
            }
            S.Pop();
            break;
        }
    }
    cout << "All Good!" << endl;
    return true;
}
int main()
{
    srand(time(0));
        Stack S;
        string user;
        cout << "Enter str: ";
        getline(cin, user);
        S.Check(S, user);
    cout<<endl;
    return 0;
}

