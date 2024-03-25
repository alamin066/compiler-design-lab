#include <bits/stdc++.h>
using namespace std;
vector<string>Identifier;
vector<string>Keyword;
vector<char>Symbol;
vector<char>Operator;
vector<string>Integer;
vector<string>Float;
vector<char>Exponential;
vector<string>Invalid;

bool IsAlpha(char ch) {

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' &&  ch <= 'Z'))
    {

     return true;
    }
     return false;
}
bool IsDigit(char ch) {
    if (ch >= '0' && ch <= '9') return true;
    return false;
}
bool IsIdentifier(char s[]) {
    if (!IsAlpha(s[0]) && s[0] != '_') return false;
    int len = strlen(s);
    for (int i = 1; i < len; i++) {
        if (IsAlpha(s[i]) || IsDigit(s[i]) || s[i] == '_') continue;
        return false;
    }
    return true;
}
bool IsInteger(char s[]) {
    int cnt = 0;
    if (strlen(s) == 0) return false;
    for (int i = 0; i < strlen(s); i++) if (IsDigit(s[i])) cnt++;
    if (cnt == strlen(s)) return true;
    return false;
}
bool Isfloat(char s[]) {
    int cnt = 0;
    int dot = 0;
    for (int i = 0 ; i < strlen(s) ; i++) {
        if (IsDigit(s[i])) cnt++;
        else if (s[i] == '.') dot++;
    }
    if (dot == 1 && (cnt + 1 == strlen(s))) return true;
    return false;
}

bool IsKeyword(char s[]) {
    char keywords[33][1000] = {"auto", "break" ,"case","char","const",
    "continue","default","do","double","else","enum","extern",
    "float","for", "goto","if","int", "long","register",
    "return","short","signed","sizeof","static","struct",
    "switch","typedef", "union","unsigned","void","volatile",
    "while","string"};
    for (int i = 0; i < 33; i++) if (strcmp(keywords[i] , s) == 0) return true;
    return false;
}
bool IsOperator(char ch) {
    char operators[] = {'<', '>', '=','!','&','`','|','+','-','*','/','\0'};
    for (int i = 0; i < strlen(operators); i++) if (ch == operators[i]) return true;
    return false;
}
bool IsExponential(char ch){
    if(ch=='^')return true;
    return false;
}
bool IsSymbol(char ch) {
    char Symbol[] = {',', ';', ':',')','(','{','}','[',']','\0'};
    for (int i = 0; i < strlen(Symbol); i++) if (ch == Symbol[i]) return true;
    return false;
}
int main() {
    printf("press $ and enter to stop taking inputs----->\n\n");
    char str[1000];
    char temp[1000];
    scanf("%[^$]s", str);
    int st = 0;
    for (int i = 0; i < strlen(str) ; i++) {
        temp[0] = '\0';
        if (i + 1 == strlen(str) || str[i] == ' ' || str[i] == '\n' || IsSymbol(str[i]) || IsOperator(str[i])|| IsExponential(str[i])) {
            // taking substring starting from st and end at i - 1
            int k = 0 ;
            while (st < i) {
                temp[k] = str[st];
                k++;
                st++;
            }
            temp[k] = '\0';

            if (IsKeyword(temp)) {
                Keyword.push_back(temp);
                //printf("%s is a keywords\n",temp);
            } else if (Isfloat(temp)) {
                Float.push_back(temp);
                //printf("%s is a float\n",temp);
            } else if (IsInteger(temp)) {
               Integer.push_back(temp);
                //printf("%s is an Integer\n",temp);
            } else if (IsIdentifier(temp)) {
               Identifier.push_back(temp);
              // printf("%s is an Identifier\n",temp);
            } else if (strlen(temp)) {
                Invalid.push_back(temp);
                //printf("%s is invalid\n");
            }

            if (IsSymbol(str[i])) {
                 Symbol.push_back(str[i]);
                //printf("%c is a Symbol\n",str[i]);
            } else if (IsOperator(str[i])) {
                if (i + 1 < strlen(str) && IsOperator(str[i + 1])) {

                      Operator.push_back(str[i]);
                      Operator.push_back(str[i+1]);
                     //printf("%c%c is an operator\n",str[i] , str[i + 1]);
                    i++;
                } else {
                     Operator.push_back(str[i]);
                     //printf("%c is an operator\n" , str[i]);
                }
            }
            else if(IsExponential(str[i])){
                 Exponential.push_back(str[i]);
            }
            st = i + 1;
        }
    }
      cout<<"Token : "<<Identifier.size()+Keyword.size()+Symbol.size()+Operator.size()+Integer.size()+Float.size()+Exponential.size()<<endl;
     //Identifier
     cout<<"Identifier : "<<Identifier.size()<<" "<<"----->  ";
     for(auto i : Identifier)
     cout<<i<<" ";
     cout<<endl;
     //keyword
     cout<<"Keyword    : "<<Keyword.size()<<" "<<"----->  ";
     for(auto i : Keyword)
     cout<<i<<" ";
     cout<<endl;
     //Symbol
     cout<<"Symbol     : "<<Symbol.size()<<" "<<"----->  ";
     for(auto i : Symbol)
     cout<<i<<" ";
     cout<<endl;
     //Operator
     cout<<"Operator   : "<<Operator.size()<<" "<<"----->  ";
     for(auto i : Operator)
     cout<<i<<" ";
     cout<<endl;
     //Integer
     cout<<"Integer    : "<<Integer.size()<<" "<<"----->  ";
     for(auto i : Integer)
     cout<<i<<" ";
     cout<<endl;
     //Float
     cout<<"Float      : "<<Float.size()<<" "<<"----->  ";
     for(auto i : Float)
     cout<<i<<" ";
     cout<<endl;
     cout<<"Exponential: "<<Exponential.size()<<" "<<"----->  ";
     for(auto i : Exponential)
     cout<<i<<" ";
     cout<<endl;
    return 0;
}
