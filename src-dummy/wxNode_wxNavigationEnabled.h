
#ifndef _wxNode_wxNavigationEnabled_
#define _wxNode_wxNavigationEnabled_

class wxNode_wxNavigationEnabled {
public:
  static void AddMethods(v8::Handle<v8::FunctionTemplate> target);
  static bool AssignableFrom(const v8::Handle<v8::String>& className) { return false; }
  static bool AssignableFrom(const char* className) { return false; }
};

#endif