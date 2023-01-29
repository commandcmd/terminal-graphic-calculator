#include "../libraries/cursesTerminalScreen.hpp"
#include "../libraries/evaluateExpression.hpp"
#include <iostream>

int map(int input, int min1, int max1, int min2, int max2){
    if(max2 - min2 <= 0 || max1 - min1 <= 0)return 0;
    return (int)((input * (max2 - min2)) / ((max1 - min1)));
}

int main(void){
    std::string input;

    std::cout << "Input an expression: \n\ry = ";
    std::getline(std::cin >> std::ws, input);

    std::cout << "Input : " << input << std::endl;

    terminal::init();

    double output;

    for(int i = 0;i < 100;i++){
        for(int j = 0;j < input.length();j++){
            if(input[j] == 'x'){
                input.erase(j);
                input.insert(j, std::to_string(i));
                continue;
            }
            else if(input[j] == '\0')break;
        }

        output = expression::evaluate(input);
        if(output < -999 || output > 999)break;
        double newOutput = map(output, -1000, 1000, 0, 40);

        std::cout << "i = " << i << "\nnewOutput = " << newOutput << "\noutput = " << output << "\nInput = " << input << '\n' << std::endl;

        terminal::drawPixel(i, newOutput, '*', BLACK, WHITE);
    }

    terminal::updateDisplay();

    terminal::input::getChar();

    terminal::end();

    return 0;
}

int main(void){
    std::string input;

    std::cout << "Input an expression to graph : \n\ry = ";
    std::getline(std::cin >> std::ws, input);

    std::cout << "Input : " << input << std::endl;

    terminal::init();
}