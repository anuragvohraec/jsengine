JSEngine for dart, based on jerryscript.

## Prerequisite
Make sure you have created the libjerrywrapper.so (so file if linux system, or respective shared lib file).\
Build instruction for **jerryscriptwrapper** shared lib is present inside **jerryscriptwrapper** folder of this source code.

## Usage
A simple usage example:

```dart
import 'package:jsengine/jsengine.dart';

JSEngine jsEngine = JSEngine(pathToLibSoFile: "jerryscriptwrapper/build/libjerryscriptwrapper.so");
  String mapfunct = 'function(doc){emit(doc.name,doc.age); }';
  String cf ="var giveEmitObject = function(){var map_results = [];var emit = function(key,value){ map_results.push({key:key, value: value});};return {map_results: map_results, emit: emit};};var mapThisDoc = function(documentStr){ var document = JSON.parse(documentStr); var emitObj= giveEmitObject(); var emit = emitObj.emit; ($mapfunct)(document); return JSON.stringify(emitObj.map_results);};mapThisDoc('{\"name\":\"Anurag Vohra\",\"age\":30}');";
  String result = jsEngine.runJSCode(cf);
```

## Features and bugs

Please file feature requests and bugs at the [issue tracker][tracker].

[tracker]: https://github.com/anuragvohraec/jsengine/issues


## Observation
If your test are getting hanged, then delete the "build/testfile.dill.track.dill"