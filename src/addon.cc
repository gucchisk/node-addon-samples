#include <napi.h>
#include <stdexcept>

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  try {
    throw std::out_of_range("error");
  } catch (std::runtime_error& e) {
    return Napi::String::New(env, "runtime_error");
  } catch (std::exception& e) {
    return Napi::String::New(env, "exception");
  } catch (...) {
    throw Napi::Error::New(env, "...");
  }
  return Napi::String::New(env, "hello");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(hello, Init);
