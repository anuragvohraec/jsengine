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
    if(jerry_value_is_error(value)){
      jerry_error_t error_type = jerry_get_error_type (value);
      char *err;
      switch (error_type)
      {
      case JERRY_ERROR_NONE:
       err= "{\"error\":\"JERRY_ERROR_NONE\"}";
      case JERRY_ERROR_COMMON:
       err= "{\"error\":\"JERRY_ERROR_COMMON\"}";
      case JERRY_ERROR_EVAL:
       err= "{\"error\":\"JERRY_ERROR_EVAL\"}";
      case JERRY_ERROR_RANGE:
       err= "{\"error\":\"JERRY_ERROR_RANGE\"}";
      case JERRY_ERROR_REFERENCE:
       err= "{\"error\":\"JERRY_ERROR_REFERENCE\"}";
      case JERRY_ERROR_SYNTAX:
       err= "{\"error\":\"JERRY_ERROR_SYNTAX\"}";
      case JERRY_ERROR_TYPE:
       err= "{\"error\":\"JERRY_ERROR_TYPE\"}";
      case JERRY_ERROR_URI:
       err= "{\"error\":\"JERRY_ERROR_URI\"}";
      default:
        break;
      }
      int size= strlen(err)+1;
      char *res = malloc(size);
      res[size]='\0';
      strcpy(res,err);
      jerry_release_value(value);
      return res;
    }else{
      char *err= "{\"error\":\"JERRYSCRIPTWRAPPER ERROR: Unhandled return type, only supports String return types.\"}";
      int size= strlen(err)+1;
      char *res = malloc(strlen(err)+1);
      res[size]='\0';
      strcpy(res,err);
      jerry_release_value(value);
      return res;
    }
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
    /* Initialize engine */
  jerry_init (JERRY_INIT_EMPTY);
   jerry_value_t parsed_code = jerry_parse (NULL, 0, script, strlen(script), JERRY_PARSE_NO_OPTS);
    bool result = jerry_value_is_error (parsed_code);
    jerry_release_value(parsed_code);
      /* Cleanup engine */
  jerry_cleanup ();
    return result?0:1;
}




