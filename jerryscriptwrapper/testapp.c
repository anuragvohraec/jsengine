#include<jerryscriptwrapper.h>
#include<stdio.h>
#include<string.h>


int main(void){
    char * program = "var mapThisDoc = function(documentStr){ var document = JSON.parse(documentStr); var map_results = []; var emit = function(key,value){map_results.push({key:key, value: value});}; (function(doc){  	emit(doc.name,doc.age); })(document); return JSON.stringify(map_results);};mapThisDoc('{\"name\":\"Anurag Vohra\",\"age\":30}');";
    char *r1 = runJSCode(program);
    printf("%s", r1);

    char * p2 = "functiion(){return jhelllo;}";
    int r2 = validateThisJSCode(p2);
    printf("r2: %d", r2);

    char * p3 = "function sayHello(){return 'hello';}";
    int r3 = validateThisJSCode(p3);
    printf("r3: %d", r3);

    char * p4 = "asdasdasa()";
    char *r4 = runJSCode(p4);
    printf("%s", r4);

    char * p5 ="function mango(){return 1;}; mango();";
    char * r5 = runJSCode(p5);
    printf("%s", r5);
}