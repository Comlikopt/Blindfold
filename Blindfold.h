/*
BSD 3-Clause License
Copyright (c) 2026, Comlikopt

Blindfold that MAKE you: 
1. Use a goto error way of handling exception
2. Use global pointers to pass data ( to carry about the memory )
3. Use previous two steps ALWAYS and INCLUDED when you define a new function
*/

void * _global_input_pointer = 0;
void * _global_output_pointer = 0;

#define DEFINE__CHECK_OR_THEN_GOTO_ERROR_HANDLE_LABEL                               \
    ( CONDITION )                                                                   \
    if ( CONDITION ) goto ERROR_HANDLE_LABEL;                                       \


#define DEFINE__SET_FUNCTION_INPUT_OUTPUT_POINTERS_AS_                              \
    ( INPUT_POINTER, OUTPUT_POINTER )                                               \
    global_input_pointer = INPUT;                                                   \
    global_output_pointer = OUTPUT;                                                 \


#define DEFINE__UNWRAP_FUNCTION_INPUT_AND_OUTPUT_AS_                                \
    ( INPUT_TYPE, OUTPUT_TYPE )                                                     \
    INPUT_TYPE * local_input_pointer = (INPUT_TYPE) _global_input_pointer;          \
    OUTPUT_TYPE * local_output_pointer = (OUTPUT_TYPE) _global_output_pointer;      \


#define DEFINE__RUNABLE                                                             \
    ( NAME, INPUT_TYPE, OUTPUT_TYPE, CODE, ERROR_HANDLE_CODE )                      \
    void NAME ( void )                                                              \
    {                                                                               \
        DEFINE_UNWRAP_FUNCTION_INPUT_AND_OUTPUT_AS_ ( INPUT_TYPE, OUTPUT_TYPE );    \
        CODE                                                                        \
        ERROR_HANDLE_LABEL:                                                         \
        ERROR_HANDLE_CODE                                                           \      
    }                                                                               \


#define DEFINE__RUN_RUNNABLE                                                        \
    ( NAME, INPUT_VAR, OUTPUT_VAR  )                                                \
    DEFINE_SET_FUNCTION_INPUT_OUTPUT_POINTERS ( &INPUT_TYPE, &OUTPUT_TYPE );        \
    NAME ();                                                                        \                                  

