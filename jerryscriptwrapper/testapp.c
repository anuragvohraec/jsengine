#include<jerryscriptwrapper.h>
#include<stdio.h>
#include<string.h>

int main(void){
    char * program = "var mapThisDoc = function(documentStr){ var document = JSON.parse(documentStr); var map_results = []; var emit = function(key,value){map_results.push({key:key, value: value});}; (function(doc){  	emit(doc.name,doc.age); })(document); return JSON.stringify(map_results);};mapThisDoc('{\"name\":\"Anurag Vohra\",\"age\":30}');";
    char *r1 = runJSCode(program);
    printf("%s", r1);
}
