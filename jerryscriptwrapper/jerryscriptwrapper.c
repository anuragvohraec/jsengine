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

//runs the JS Code and retrun a string result, else return null in all cases
char* runJSCode(char *program){
  static char RESULT[MAX_SIZE_OF_RESULT];
  jerry_init(JERRY_INIT_EMPTY);
    
  jerry_value_t t1 = jerry_eval(program, strlen(program),0);
  char * t2 = giveMeStringFromJerryValue(t1);
  if(t2==NULL){
    return t2;
  }else{
  int size = strlen(t2);
  strcpy(RESULT, t2);
  free(t2);
  jerry_cleanup();
  return RESULT;
  }
}


//returns 1 if its a valid js code
int validateThisJSCode(char *script){
   jerry_value_t parsed_code = jerry_parse (NULL, 0, script, strlen(script), JERRY_PARSE_NO_OPTS);
    bool result = jerry_value_is_error (parsed_code);
    return result?0:1;
}




