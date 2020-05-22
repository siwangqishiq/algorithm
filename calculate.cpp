/**
 * 
 * 实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。

示例 1:

输入: "1 + 1"
输出: 2
示例 2:

输入: " 2-1 + 2 "
输出: 3
示例 3:

输入: "(1+(4+5+2)-3)+(6+8) "
输出: 23
说明：

你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/basic-calculator
 * */

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        return 0;
    }
};

void parseExpr(string s){
    stack<int> t;
    t.push(1);
    t.push(2);
    t.push(3);

    while(!t.empty()){
        cout << t.top() << endl;
        t.pop();
    }
}

enum SYMBOL_TYPE{
    SYMBOL_ADD  = 1, 
    SYMBOL_SUB = 2,
    SYMBOL_VALUE = 3, 
    SYMBOL_LT = 4,
    SYMBOL_RT = 5
};

const int STATE_NORMAL = 1;
const int STATE_READ_VALUE = 2;

struct Symbol{
    SYMBOL_TYPE type;
    string value;
};

void putValueSymbol(string valueStr , int &state , vector<Symbol> &symbols);

//将输入解析为符号表
int parseInputSymbols(string input , vector<Symbol> &symbols){
    const int len = input.length();
    const char *data = input.c_str();

    int index = 0;
    int state = STATE_NORMAL;

    string readStrContent;

    while(index < len){
        const char c = data[index];
        switch(c){
            case ' ':
                break;
            case '+':
                if(state == STATE_READ_VALUE){
                    putValueSymbol(readStrContent , state , symbols); 
                }
                
                if(state == STATE_NORMAL){
                    Symbol symbol;
                    symbol.type = SYMBOL_ADD;
                    symbol.value = "+";
                    symbols.push_back(symbol); 
                }
                break;
            case '-':
                if(state == STATE_READ_VALUE){
                    putValueSymbol(readStrContent , state , symbols);                  
                }

                if(state == STATE_NORMAL){
                    Symbol symbol;
                    symbol.type = SYMBOL_SUB;
                    symbol.value = "-";
                    symbols.push_back(symbol);
                }
                break;
            case '(':
                //state = STATE_NORMAL;
                if(state == STATE_READ_VALUE){
                    putValueSymbol(readStrContent , state , symbols);                  
                }

                if(state == STATE_NORMAL){
                    Symbol symbol;
                    symbol.type = SYMBOL_LT;
                    symbol.value = "(";
                    symbols.push_back(symbol);
                }
                break;
            case ')':
                if(state == STATE_READ_VALUE){
                    putValueSymbol(readStrContent , state , symbols);                  
                }

                if(state == STATE_NORMAL){
                    Symbol symbol;
                    symbol.type = SYMBOL_RT;
                    symbol.value = ")";
                    symbols.push_back(symbol);
                }
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if(state == STATE_NORMAL){
                    state = STATE_READ_VALUE;
                    readStrContent = string(1 , c);
                }else if(state == STATE_READ_VALUE){
                   readStrContent += string(1 , c);                     
                }
                break;
            default:
                return -1;
        }//end switch

        index++;
    }//end while

    if(state == STATE_READ_VALUE){
        putValueSymbol(readStrContent , state , symbols);
    }

    return 1;
}

void putValueSymbol(string valueStr , int &state , vector<Symbol> &symbols) {
    Symbol symbol;
    symbol.type = SYMBOL_VALUE;
    symbol.value = valueStr;
    symbols.push_back(symbol);

    state = STATE_NORMAL;
}

//将符号表解析为后缀表达式
void parseToPostfix(vector<Symbol> &symbols) {
    vector<Symbol *> postfixResult;
    stack<Symbol *> helpStack;

    for(int i = 0 , len = symbols.size() ; i < len ; i++){
        Symbol &symbol = symbols[i];
        SYMBOL_TYPE type = symbol.type;

        //cout << symbol.value << endl;
        switch(type){
            case SYMBOL_ADD:   //  +
            case SYMBOL_SUB:  // -
                //出栈一个元素
                if(!helpStack.empty() && helpStack.top()->type != SYMBOL_LT){
                    cout << "add elem1111 : " << helpStack.top()->value << endl;
                    postfixResult.push_back(helpStack.top());
                    helpStack.pop();
                }

                // while(!helpStack.empty() && helpStack.top()->type != SYMBOL_LT){
                //     cout << "add elem1111 : " << helpStack.top()->value << endl;
                //     postfixResult.push_back(helpStack.top());
                //     helpStack.pop();
                // }
                //入栈
                helpStack.push(&symbol);
                break;
            case SYMBOL_VALUE:
                helpStack.push(&symbol);
                break;
            case SYMBOL_LT: //左括号  (  入栈
                helpStack.push(&symbol);
                break;
            case SYMBOL_RT: //右括号 ) 出栈
                //出栈直到发现第一个左括号
                while(!helpStack.empty()){
                    Symbol *p = helpStack.top();
                    cout << "stackTop : " << p->value << endl; 

                    if(p->type == SYMBOL_LT){
                        cout << "removed" << endl;
                        helpStack.pop();
                        break;
                    }

                    cout << "add elem222 : " << helpStack.top()->value << endl;
                    postfixResult.push_back(helpStack.top());
                    helpStack.pop();
                }//end while
                break;
            default:
                break;
        }//end switch

        cout << "index = " << i << " \t";
        for(Symbol *pSymbol : postfixResult){
            cout << pSymbol->value << " ";
        }//end for each
        cout << endl;
    }//end for i

    // cout<<"stack size = " << helpStack.size() << endl;
    while(!helpStack.empty()){
        postfixResult.push_back(helpStack.top());
        helpStack.pop();
    }//end while

    for(Symbol *pSymbol : postfixResult){
        cout << pSymbol->value << " ";
    }//end for each
    cout << endl;
}

int main() {

    vector<Symbol> symbols;
    // string input = "1 + (2 -3 ) + 4 ";

    string input = "((1+2) +3) + (4 +5)";
    // string input = "5 + (4 + ((1 + 2) + 3))";
    int r = parseInputSymbols(input , symbols);
    std::cout << "result = " << r << std::endl;
    std::cout << input << std::endl;
    
    // for(Symbol &s : symbols){
    //     std::cout <<"type :" << s.type << " value :" << s.value << std::endl;
    // }//end for each
    parseToPostfix(symbols);


    return 0;
}