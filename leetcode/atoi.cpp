#include <iostream>
#include <vector>
#include <climits>


enum Status{
    INIT,//
    READ_NUMCHAR,
};

int converCharToInt(char c){
    int ret = 0;
    switch(c){
        case '1':
            ret = 1;
            break;
        case '2':
            ret = 2;
            break;
        case '3':
            ret = 3;
            break;
        case '4':
            ret = 4;
            break;
        case '5':
            ret = 5;
            break;
        case '6':
            ret = 6;
            break;
        case '7':
            ret = 7;
            break;
        case '8':
            ret = 8;
            break;
        case '9':
            ret = 9;
            break;
        default:
            break;
    }//end switch
    return ret;
}

int atoi(const char *pStr) {

    long result = 0;
    char *p = (char *)pStr;
    Status state = INIT;
    int flag = 1;
    int val = 0;
    std::vector<int> charNumbers;
    bool isContiue = true;

    while(*p != '\0'){
        char c = *p;
        //std::cout << c << " ";

        val = converCharToInt(c);
        switch(*p){
        case ' ':
            break;
        case '-':
        case '+':
            if(state == INIT){
                flag = (c == '-')?-1:1;
            }
            break;
        
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            if(state == INIT){
                state = READ_NUMCHAR;
            }
             charNumbers.push_back(val);
            break;
        case '0':
            if(state == INIT){
                isContiue = false;
            }else if(state == READ_NUMCHAR){
                 charNumbers.push_back(val);
            }
            break;

        default:
            isContiue = false;
            break;
        }//end switch

        if(!isContiue){
            break;
        }
        p++;
    }//end while
    
    if(charNumbers.size() == 0){
        return result;
    }
    
    //std::vector<int> weights;
    int weight = 1;
    for(int i = charNumbers.size() - 1 ; i >= 0 ; i--){
        // std::cout << " i = " << i << "  , " << charNumbers[i] << std::endl; 
        result += (charNumbers[i] * weight);
        if(result >= INT_MAX){
            result = INT_MAX;
            break;
        }else if(flag == -1 && -1 * result <= INT_MIN){
            result = INT_MIN;
            break;
        }

        weight *= 10;
    }//end for i

    result = result * flag;

    return result;
}


int main(int argc , char **argv){
    int a1 = atoi("Hello World!!!!!");
    std::cout << a1 << std::endl;

    int a2 = atoi(" +12345");
    std::cout << a2 << std::endl;

    int a3 = atoi(" 45678 ");
    std::cout << a3 << std::endl;

    int a4 = atoi("045678 ");
    std::cout << a4 << std::endl;

    int a5 = atoi("456aab!78 ");
    std::cout << a5 << std::endl;

    int a6 = atoi("9999999999999999999999999999999999");
    std::cout << a6 << std::endl;

    int a7 = atoi("-9999999999999999999999999999999999");
    std::cout << a7 << std::endl;

    int a8 = atoi(" -12345");
    std::cout << a8 << std::endl;

    return 0;
}