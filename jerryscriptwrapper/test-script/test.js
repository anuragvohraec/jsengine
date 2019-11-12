var giveEmitObject = function(){
    var map_results = [];
    var emit = function(key,value){
         map_results.push({key:key, value: value});
    };
    return {map_results: map_results, emit: emit};
};

var mapThisDoc = function(documentStr){
 var document = JSON.parse(documentStr);
 var emitObj= giveEmitObject();
 var emit = emitObj.emit;
 (function(doc){
  	emit(doc.name,doc.age);
 })(document);
 return JSON.stringify(emitObj.map_results);
};

var a = mapThisDoc('{"name":"Anurag Vohra","age":30}');
print(a);
