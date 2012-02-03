
#ifndef _wxNode_{{name}}_h_
#define _wxNode_{{name}}_h_

class wxNode_wxWindow;
#include "wxnode.h"
#include "wxNode_wxEvtHandler.h"
{{#includes}}#include "{{.}}"
{{/includes}}

class wxNode_{{name}} : public {{name}}, public wxNodeObject, public NodeExEvtHandlerImpl {
public:
  static void Init(v8::Handle<v8::Object> target);
  static void AddMethods(v8::Handle<v8::FunctionTemplate> target);
  virtual v8::Handle<v8::Object> self() { return m_self; }

protected:
  {{#constructors}}
  {{#overloads}}
  wxNode_{{parent.parent.name}}({{{argDeclCode}}});
  {{/overloads}}
  {{/constructors}}

private:
  static v8::Handle<v8::Value> _init(const v8::Arguments& args);

  {{#methods}}static v8::Handle<v8::Value> _{{name}}(const v8::Arguments& args);
  {{/methods}}

  static v8::Persistent<v8::FunctionTemplate> s_ct;
};

#endif
