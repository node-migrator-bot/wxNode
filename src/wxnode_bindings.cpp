
#include <v8.h>
#include <node.h>
#include "wxNodeClass.h"
#include "app.h"
#include "frame.h"

extern "C" {
  static void init(v8::Handle<v8::Object> target) {
    wxNodeClass::Init(target);
    NodeWxApp::Init(target);
    NodeWxFrame::Init(target);
  }

  NODE_MODULE(wxnode_bindings, init);
}

//-----------------------------------------------------------------------------
// Replacement code for IMPLEMENT_APP_NO_MAIN()

#if wxCHECK_VERSION(2, 8, 0)
  DECLARE_APP(NodeWxApp)
  IMPLEMENT_APP(NodeWxApp)
  static NodeWxApp* _app = NULL;
#else
  static NodeWxApp* _app = NULL;
  wxApp* wxCreateApp() { return _app; }
  wxAppInitializer wxTheAppInitializer((wxAppInitializerFunction)wxCreateApp);
#endif