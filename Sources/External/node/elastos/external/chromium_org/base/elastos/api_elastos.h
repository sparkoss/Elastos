// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_ANDROID_JNI_ANDROID_H_
#define BASE_ANDROID_JNI_ANDROID_H_

//#include <jni.h>
#include <sys/types.h>

#include <string>

#include "ElAndroid.h"
#include "elastos.h"

//#include "base/elastos/scoped_elastos_ref.h"
#include "base/atomicops.h"
#include "base/base_export.h"
#include "base/compiler_specific.h"

namespace base {
namespace android {

// Used to mark symbols to be exported in a shared library's symbol table.
#define JNI_EXPORT __attribute__ ((visibility("default")))

// Contains the registration method information for initializing JNI bindings.
struct RegistrationMethod {
  const char* name;
  bool (*func)();
};

// Attaches the current thread to the VM (if necessary) and return the JNIEnv*.
//LLBASE_EXPORT JNIEnv* AttachCurrentThread();

// Same to AttachCurrentThread except that thread name will be set to
// |thread_name| if it is the first call. Otherwise, thread_name won't be
// changed. AttachCurrentThread() doesn't regard underlying platform thread
// name, but just resets it to "Thread-???". This function should be called
// right after new thread is created if it is important to keep thread name.
//LBASE_EXPORT JNIEnv* AttachCurrentThreadWithName(const std::string& thread_name);

// Detaches the current thread from VM if it is attached.
//LLBASE_EXPORT void DetachFromVM();

// Initializes the global JVM. It is not necessarily called before
// InitApplicationContext().
//LLBASE_EXPORT void InitVM(JavaVM* vm);

// Returns true if the global JVM has been initialized.
//LLBASE_EXPORT bool IsVMInitialized();

// Initializes the global application context object. The |context| can be any
// valid reference to the application context. Internally holds a global ref to
// the context. InitVM and InitApplicationContext maybe called in either order.
//LLBASE_EXPORT void InitApplicationContext(JNIEnv* env, const JavaRef<jobject>& context);
BASE_EXPORT void InitApplicationContext(const Elastos::AutoPtr<IInterface>& context);

// Initializes the global ClassLoader used by the GetClass and LazyGetClass
// methods. This is needed because JNI will use the base ClassLoader when there
// is no Java code on the stack. The base ClassLoader doesn't know about any of
// the application classes and will fail to lookup anything other than system
// classes.
//LLBASE_EXPORT void InitReplacementClassLoader(
//    JNIEnv* env,
//    const JavaRef<jobject>& class_loader);

// Gets a global ref to the application context set with
// InitApplicationContext(). Ownership is retained by the function - the caller
// must NOT release it.
// update the name for compile conflict
BASE_EXPORT Elastos::AutoPtr<IInterface> GetAppContext();

// Finds the class named |class_name| and returns it.
// Use this method instead of invoking directly the JNI FindClass method (to
// prevent leaking local references).
// This method triggers a fatal assertion if the class could not be found.
// Use HasClass if you need to check whether the class exists.
//LLBASE_EXPORT ScopedJavaLocalRef<jclass> GetClass(JNIEnv* env, const char* class_name);

// The method will initialize |atomic_class_id| to contain a global ref to the
// class. And will return that ref on subsequent calls.  It's the caller's
// responsibility to release the ref when it is no longer needed.
// The caller is responsible to zero-initialize |atomic_method_id|.
// It's fine to simultaneously call this on multiple threads referencing the
// same |atomic_method_id|.
//LLBASE_EXPORT jclass LazyGetClass(
//LL    JNIEnv* env,
//LL    const char* class_name,
//LL    base::subtle::AtomicWord* atomic_class_id);

/*
// This class is a wrapper for JNIEnv Get(Static)MethodID.
class BASE_EXPORT MethodID {
 public:
  enum Type {
    TYPE_STATIC,
    TYPE_INSTANCE,
  };

  // Returns the method ID for the method with the specified name and signature.
  // This method triggers a fatal assertion if the method could not be found.
  template<Type type>
  static jmethodID Get(JNIEnv* env,
                       jclass clazz,
                       const char* method_name,
                       const char* jni_signature);

  // The caller is responsible to zero-initialize |atomic_method_id|.
  // It's fine to simultaneously call this on multiple threads referencing the
  // same |atomic_method_id|.
  template<Type type>
  static jmethodID LazyGet(JNIEnv* env,
                           jclass clazz,
                           const char* method_name,
                           const char* jni_signature,
                           base::subtle::AtomicWord* atomic_method_id);
};
*/

// Returns true if an exception is pending in the provided JNIEnv*.
//LLBASE_EXPORT bool HasException(JNIEnv* env);

// If an exception is pending in the provided JNIEnv*, this function clears it
// and returns true.
//LLBASE_EXPORT bool ClearException(JNIEnv* env);

// This function will call CHECK() macro if there's any pending exception.
//LLBASE_EXPORT void CheckException(JNIEnv* env);

}  // namespace android
}  // namespace base

#endif  // BASE_ANDROID_JNI_ANDROID_H_
