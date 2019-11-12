import "package:flutter_test/flutter_test.dart";
import 'package:jsengine/jsengine.dart';


///
/// Make sure you have build the jerryscriptwrapper shared lib (read the readme in jerryscriptwrapper folder to see how its done)
main(){
  test("CASE: Test JS engine",()async{
    searchNativeLibAt("jerryscriptwrapper/build");
    JSEngine jsEngine = JSEngine();
    String program = "var helloworld = function (){ return 'Hello World';};helloworld();";
    String result = await jsEngine.runJSCode(program);
    expect(result, 'Hello World');
  });
}