#include "../libraries/evaluateExpression.hpp"
#include "../libraries/customTerminalIO.hpp"

int main(void){
    for(;;){
        terminal::out::print("Input an expression to evaluate : ");

        terminal::in::get_str();
        //char input[terminal::in::str_length];
        //terminal::in::store_str(*input);

        //terminal::out::println(ENDLINE, "Output : ", expression::evaluate(input));
    }
}