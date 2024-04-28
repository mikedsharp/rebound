#ifndef JAVASCRIPT_CALLBACK_HANDLER_H
#define JAVASCRIPT_CALLBACK_HANDLER_H

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/bind.h>
class JavascriptCallbackHandler
{
public:
    JavascriptCallbackHandler();
    ~JavascriptCallbackHandler();
    static void ToggleMusic(emscripten::val cb);
    static void MuteMasterVolume(emscripten::val cb);
    static void UnmuteMasterVolume(emscripten::val cb);
};

#endif // JAVASCRIPT_CALLBACK_HANDLER_H

#endif
