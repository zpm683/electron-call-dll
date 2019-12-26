#include <nan.h>

void Add(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  typedef int(*DllAdd)(int, int);
  HINSTANCE hDll = LoadLibrary("add.dll");
  DllAdd dllAddFunc = (DllAdd)GetProcAddress(hDll, "Add");
  int result = 0;
  result = dllAddFunc(6, 6);
  FreeLibrary(hDll);
  info.GetReturnValue().Set(result);
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("add").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Add)->GetFunction());
}

NODE_MODULE(demo, Init)
