import 'package:flutter/material.dart';
import 'dart:async';

import 'package:flutter/services.dart';
import 'package:jsengine/jsengine.dart';

void main() => runApp(MyApp());

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  String jsoutput = 'Unknown';
  JSEngine jsEngine = JSEngine();
  int counter;

  @override
  void initState() {
    super.initState();
    counter=30;
  }


  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        body: Center(
            child: Column(
              children: <Widget>[
                Text(jsoutput),
                RaisedButton(child: Text("Press to see JS runs"), onPressed: () async{
                  counter = counter+1;
                  JSEngine jsEngine = JSEngine();
                  String mapfunct = 'function(doc){emit(doc.name,doc.age); }';
                  String cf ='''var giveEmitObject = function(){var map_results = [];var emit = function(key,value){ map_results.push({key:key, value: value});};return {map_results: map_results, emit: emit};};var mapThisDoc = function(documentStr){ var document = JSON.parse(documentStr); var emitObj= giveEmitObject(); var emit = emitObj.emit; ($mapfunct)(document); return JSON.stringify(emitObj.map_results);};mapThisDoc('{"name":"Anurag Vohra","age":$counter}');''';
                  print("reevaluating");
                  jsoutput = await jsEngine.runJSCode(cf);
                  setState(() { });
                },)
              ],
            )
        ),
      ),
    );
  }
}
