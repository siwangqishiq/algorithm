/**
* 随机数的生成
**/

#include <iostream>
#include <random>

int main() {
    std::default_random_engine engine;
    //std::uniform_real_distribution
    std::uniform_real_distribution<double> u(-10,10);
    
    for(int i = 0 ; i < 10;i++){
        std::cout << (int)u(engine) << std::endl; 
    }

    return 0;
}