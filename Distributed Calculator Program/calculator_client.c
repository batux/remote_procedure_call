#include "calculator.h"
#include <stdio.h>

void calculate(CLIENT *calculator_client, char* host, float first_number, float second_number, int operation_type){ 

	// Sum Fuction 		   --> operation_type = 1
	// Substract Function  --> operation_type = 2
	// Divide Function     --> operation_type = 3
	// Multiply Function   --> operation_type = 4
	

	float *operation_result;
	
    numbers input_parameters_container;

    input_parameters_container.first_number = first_number;
    input_parameters_container.second_number = second_number;

    float first_arg = 0.0f;
    float second_arg = 0.0f;

    first_arg = input_parameters_container.first_number;
    second_arg = input_parameters_container.second_number;

    printf("FIRST NUMBER : %f\n", first_arg);
    printf("SECOND NUMBER : %f\n", second_arg);
    printf("OPERATION TYPE : %d\n", operation_type);

    
    switch(operation_type) {
    	case 1: {
    		operation_result = sum_1(&input_parameters_container, calculator_client);
    		break;
    	}
    	case 2: {
    		operation_result = substract_1(&input_parameters_container, calculator_client);
    		break;
    	}
    	case 3: {
    		operation_result = divide_1(&input_parameters_container, calculator_client);
    		break;
    	}
    	case 4: {
    		operation_result = multiply_1(&input_parameters_container, calculator_client);
    		break;
    	}
    }


	if (operation_result == (float *) NULL) {
		printf("ERROR-1001: Invalid response! \n");
		clnt_perror(calculator_client, "ERROR-1001: Invalid response!");  
	}  
	else { 
		printf("Calculation result is : %f", *operation_result);
		printf("\n");
		clnt_destroy(calculator_client);  
	}  

}


int main(int argc, char *argv[])  
{  

	CLIENT *calculator_client;

	char *host; 
	int operation_type;
	float first_argument, second_argument; 


	if(argc != 5) {  
		printf ("ERROR-1004: Less Parameters List Error! [Parameters Size: %s]\n", argv[0]); 
		exit(1);  
	}  
	
	host = argv[1];  
	
	if ((first_argument = atof(argv[2])) == 0 && *argv[2] != '0') { 
		fprintf(stderr, "ERROR-1003: Invalid Value: %s\n", argv[2]);  
		exit(1);  
	} 

	if ((second_argument = atof(argv[3])) == 0 && *argv[3] != '0') { 
		fprintf(stderr, "ERROR-1003: Invalid Value: %s\n", argv[3]);  
		exit(1);  
	}  
	
	if ((operation_type = atoi(argv[4])) == 0 && *argv[4] != '0') { 
		fprintf(stderr, "ERROR-1003: Invalid Value: %s\n", argv[4]);  
		exit(1);  
	} 

    
    calculator_client = clnt_create(host, CALCULATOR, CALCULATOR_FUNCTIONS, "tcp");

    if(calculator_client == NULL) {
    	clnt_pcreateerror(host);
    	printf("ERROR-1000: RPC Calculator Client can not be created! \n");
    	exit(1);
    }

	calculate(calculator_client, host, first_argument, second_argument, operation_type);

	exit(0);
}  