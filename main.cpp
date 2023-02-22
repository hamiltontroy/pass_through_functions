#include <stdio.h>
/*
	the goal for this program is to illustrate the fact 
	that a function can act as a wrapper for another function,
	and can take a specialized list of arguments for said callback function.
*/

template <typename T>
void medium(void (*callback_function)(T), T callback_args)
{
	callback_function(callback_args);
}

void function1(int i)
{
	printf("function1 argument: %d\n", i);
}

struct function2_args
{
	int i;
	float f;
	char c;
};

void function2(struct function2_args args)
{
	printf("function2 arguments: %d %f %c", args.i, args.f, args.c);
}

int main()
{
	// shows that medium() acts as a simple passthrough
	medium(function1, 42);
	medium(function1, 33);
	
	
	// shows that medium can take functions with complex arguments
	struct function2_args weird_struct;
	weird_struct.i = 69;
	weird_struct.f = 3.14;
	weird_struct.c = 'l';
	
	medium(function2, weird_struct);
}
