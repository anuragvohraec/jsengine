import "package:flutter_test/flutter_test.dart";
import 'package:jsengine/jsengine.dart';


///
/// Make sure you have build the jerryscriptwrapper shared lib (read the readme in jerryscriptwrapper folder to see how its done)
main(){
  test("CASE: Test JS engine",()async{
    searchNativeLibAt("jerryscriptwrapper/build");
    JSEngine jsEngine = JSEngine();

    String p1 = "var helloworld = function (){ return 'Hello World';};helloworld();";
    String r1 = await jsEngine.runJSCode(p1);
    expect(r1, 'Hello World');

    String p2= "asdasdasa()";
    String r2= await jsEngine.runJSCode(p2);
    expect(r2, '''{"error":"JERRY_ERROR_URI"}''');

    String p3= "function mango(){return 1;}; mango();";
    String r3= await jsEngine.runJSCode(p3);
    expect(r3, '''{"error":"JERRYSCRIPTWRAPPER ERROR: Unhandled return type, only supports String return types."}''');
  });

  test("CASE: Validate js code",()async{
    searchNativeLibAt("jerryscriptwrapper/build");
    JSEngine jsEngine = JSEngine();

    //testing valid code
    String p1 = "var helloworld = function (){ return 'Hello World';};helloworld();";
    bool r1 = await jsEngine.validateJSCode(p1);
    expect(r1, true);


    //testing invalid code
    String p2 = "functiion(){return jhelllo;}";
    bool r2 = await jsEngine.validateJSCode(p2);
    expect(r2, false);
  });

}
