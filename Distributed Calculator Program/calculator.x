struct numbers {

    float first_number;
    float second_number;

};

program CALCULATOR {

	version CALCULATOR_FUNCTIONS {
	    float SUM(numbers) = 1;
	    float SUBSTRACT(numbers) = 2;
	    float DIVIDE(numbers) = 3;
	    float MULTIPLY(numbers) = 4;
	} = 1;

} = 0x23451111;
