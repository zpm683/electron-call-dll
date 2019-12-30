#include <napi.h>
#include <windows.h>

Napi::Value Add(const Napi::CallbackInfo& info) {

  // Get context
  Napi::Env env = info.Env();

  // check the args 
  if (info.Length() < 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  // check the args
  if (!info[0].IsNumber() || !info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  // get args
  int arg0 = info[0].As<Napi::Number>().Int32Value();
  int arg1 = info[1].As<Napi::Number>().Int32Value();

  // typedef DLL Function
  typedef int(*DllAdd)(int, int);
  // get dll hinstance
  HINSTANCE hDll = LoadLibrary("add.dll");
  // get dll function
  DllAdd dllAddFunc = (DllAdd)GetProcAddress(hDll, "Add");
  // call this function
  int result = 0;
  result = dllAddFunc(arg0, arg1);
  // Free Library
  FreeLibrary(hDll);

  // return
  Napi::Number num = Napi::Number::New(env, result);
  return num;
}

// NODE_API_MODULE Init Function
Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, Add));
  return exports;
}

// export
NODE_API_MODULE(addon, Init)


// use nan
// #include <nan.h>

// void Add(const Nan::FunctionCallbackInfo<v8::Value>& info) {
//   typedef int(*DllAdd)(int, int);
//   HINSTANCE hDll = LoadLibrary("add.dll");
//   DllAdd dllAddFunc = (DllAdd)GetProcAddress(hDll, "Add");
//   int result = 0;
//   result = dllAddFunc(6, 6);
//   FreeLibrary(hDll);
//   info.GetReturnValue().Set(result);
// }

// void Init(v8::Local<v8::Object> exports) {
//   exports->Set(Nan::New("add").ToLocalChecked(),
//                Nan::New<v8::FunctionTemplate>(Add)->GetFunction());
// }

// NODE_MODULE(demo, Init)
