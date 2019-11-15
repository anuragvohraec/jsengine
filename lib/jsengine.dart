import 'dart:ffi';
import 'dart:isolate';
import 'package:ffi/ffi.dart';
import 'package:jsengine/src/otherlibsextensions.dart';


///JSEngine class to run JS code and get result
///
class JSEngine{

  //Runs JS code and restuns the result in string format
  Future<String> runJSCode(String jscode) async{
    try{
      ReceivePort receivePortForHandShake = ReceivePort();
      Isolate isolate = await Isolate.spawn(_runJSInInsolateAndReturnResultFunction, receivePortForHandShake.sendPort);

      SendPort sendPortForSendingPorgram = await receivePortForHandShake.first;
      ReceivePort receivePortPortJSresult = ReceivePort();

      sendPortForSendingPorgram.send([receivePortPortJSresult.sendPort, jscode]);

      String result = await receivePortPortJSresult.first;
      return result;
    }catch(e,s){
      print(e);
      print(s);
      return null;
    }

  }

  //Validate the JSCode
  Future<bool> validateJSCode(String jscode) async{
    try{
      ReceivePort receivePortForHandShake = ReceivePort();
      Isolate isolate = await Isolate.spawn(_validateJSCodeInIsolate, receivePortForHandShake.sendPort);

      SendPort sendPortForSendingPorgram = await receivePortForHandShake.first;
      ReceivePort receivePortPortJSresult = ReceivePort();

      sendPortForSendingPorgram.send([receivePortPortJSresult.sendPort, jscode]);

      int result = await receivePortPortJSresult.first;
      return result==1?true:false;
    }catch(e,s){
      print(e);
      print(s);
      return null;
    }
  }

}


typedef _runJSCode = Pointer<Utf8> Function(Pointer<Utf8> program);

DynamicLibrary libjsw = DynamicLibrary.open("libjerryscriptwrapper.so");
_runJSCode _runJSCodeNative = libjsw.lookup<NativeFunction<_runJSCode>>("runJSCode").asFunction();

typedef _validateJSCodeSign = Int32 Function(Pointer<Utf8> program);
typedef _validateJSCodeFunc = int Function(Pointer<Utf8> program);

_validateJSCodeFunc _validateJSCodeNative = libjsw.lookup<NativeFunction<_validateJSCodeSign>>("validateThisJSCode").asFunction();




///Changes the location where js engine needs to look at for the jerryscriptwrapper shared lib
///
///Use it for testing purpose only, not tested for how it will behave at run time
///
_runJSCode searchNativeLibAt(String pathToLib){
  libjsw = DynamicLibrary.open("$pathToLib/libjerryscriptwrapper.so");
  _runJSCodeNative = libjsw.lookup<NativeFunction<_runJSCode>>("runJSCode").asFunction();
  _validateJSCodeNative = libjsw.lookup<NativeFunction<_validateJSCodeSign>>("validateThisJSCode").asFunction();
}

///Runs code inside an isolate
_runJSInInsolateAndReturnResultFunction(SendPort sendPortFromMain) async{
  ReceivePort receiveDataFromMain = ReceivePort();
  sendPortFromMain.send(receiveDataFromMain.sendPort);

  var array = await receiveDataFromMain.first;
  var sendPortForResult = array[0];
  String jscode = array[1];

  String result  = _runJSCodeInsideIsolate(jscode);
  sendPortForResult.send(result);
}

//The main JSEngine native interaction
String _runJSCodeInsideIsolate(String jscode){
  Pointer<Utf8> programPtr = Utf8.toUtf8(jscode);
  Pointer<Utf8> resultPtr = _runJSCodeNative(programPtr);
  return ExtUtf8.fromUtf8(resultPtr);
}


///validate JS code
_validateJSCodeInIsolate(SendPort sendPortFromMain) async{
  ReceivePort receiveDataFromMain = ReceivePort();
  sendPortFromMain.send(receiveDataFromMain.sendPort);

  var array = await receiveDataFromMain.first;
  var sendPortForResult = array[0];
  String jscode = array[1];
  Pointer<Utf8> jscodePtr= ExtUtf8.toUtf8(jscode);
  int result  = _validateJSCodeNative(jscodePtr);
  sendPortForResult.send(result);
}
