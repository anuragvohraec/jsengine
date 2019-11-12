#include<jerryscriptwrapper.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE_OF_RESULT 8000

//returns String from jerry value if its string, else returns NULL
char* giveMeStringFromJerryValue(jerry_value_t value){
  if(jerry_value_is_string(value)){
    jerry_value_t str = jerry_value_to_string(value);
    jerry_release_value(value);

    jerry_size_t size = jerry_get_string_size(str);
    char *res = malloc(size+1);
    jerry_string_to_char_buffer(str,res,size+1);
    jerry_release_value(str);
    *(res+size)='\0';
    return res;
  }else{
    return NULL;
  }
}


char* runJSCode(char *program){
  static char RESULT[MAX_SIZE_OF_RESULT];
  jerry_init(JERRY_INIT_EMPTY);
    
  jerry_value_t t1 = jerry_eval(program, strlen(program),0);
  char * t2 = giveMeStringFromJerryValue(t1);
  int size = strlen(t2);
  strcpy(RESULT, t2);
  free(t2);
  jerry_cleanup();
  return RESULT;
}



