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
    SYMBOL_VALUE = 1,
    SYMBOL_ADD, 
    SYMBOL_SUB,
    SYMBOL_LT,
    SYMBOL_RT
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
                if(state == STATE_NORMAL){
                    state = STATE_READ_VALUE;
                    readStrContent = string(1 , c);
                }else if(state == STATE_READ_VALUE){
                   readStrContent += string(1 , c);                     
                }
                break;
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

    for(int i = 0 ; i < symbols.size();i++){
        Symbol &symbol = symbols[i];

        switch(symbol.type){
            case SYMBOL_ADD:// + - 运算符
            case SYMBOL_SUB:
            // case SYMBOL_MUL:
            // case SYMBOL_DIV:
                helpStack.push(&symbol);
                break;
            case SYMBOL_LT: // (左边括号
                helpStack.push(&symbol);
                break;
            case SYMBOL_RT:
                while(!helpStack.empty() && helpStack.top()->type != SYMBOL_LT){
                    postfixResult.push_back(helpStack.top());
                    helpStack.pop();
                }

                if(helpStack.top()->type == SYMBOL_LT){
                    helpStack.pop();
                }
                break;
            case SYMBOL_VALUE:
                postfixResult.push_back(&symbol);
                break;
            default:
                break;
        }//end switch
    }//end for i

    while(!helpStack.empty()){
        postfixResult.push_back(helpStack.top());
        helpStack.pop();
    }//end while

    
    cout << "postfix : ";
    for(int i = 0 ; i < postfixResult.size();i++){
        Symbol *&p = postfixResult[i];
        cout << p->value << " ";
    }//end for i
    cout << endl;
}

//后缀表达式求值
int calculatePostfixExp(){
    // a * b + c

    // abc+*

    
    return 0;
}

int main() {

    vector<Symbol> symbols;
    // string input = "1 + (2 -3 ) + 4 ";
    string input = "(1+2)-3-(1+2)+4";
    // string input = "((1+2) +3) + (4 +5)";
    // string input = "5 + (4 + ((1 + 2) + 3))";
    // string input = " 1+ 2 -3";
    // string input = "(a+b)*c-(a+b)/e";
    int r = parseInputSymbols(input , symbols);
    std::cout << "result = " << r << std::endl;
    std::cout << input << std::endl;
    
    // for(Symbol &s : symbols){
    //     std::cout <<"type :" << s.type << " value :" << s.value << std::endl;
    // }//end for each
    parseToPostfix(symbols);


    return 0;
}