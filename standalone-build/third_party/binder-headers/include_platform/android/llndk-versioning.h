#pragma once
// Local shim for standalone vendor NDK builds.
//
// The NDK's persistable_bundle.h includes <android/llndk-versioning.h> when
// __ANDROID_VENDOR__ is defined (see frameworks/native,
// libs/binder/ndk/include_ndk/android/persistable_bundle.h), but no shipped
// NDK revision provides that file - it is platform-generated. Mirror the
// header's own non-vendor fallback so bindgen can parse the declarations.
// Attributes do not affect the generated bindings for our allowlisted types.
#include <sys/cdefs.h>

#if !defined(__INTRODUCED_IN_LLNDK)
#define __INTRODUCED_IN_LLNDK(level) __attribute__((annotate("introduced_in_llndk=" #level)))
#endif
