//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <functional>
// REQUIRES: c++98 || c++03 || c++11 || c++14

// template <class Fn, class T>
//   binder2nd<Fn>
//   bind2nd(const Fn& op, const T& x);

#define _LIBCPP_DISABLE_DEPRECATION_WARNINGS

#include <functional>
#include <cassert>

#include "../test_func.h"

int main(int, char**)
{
    assert(std::bind2nd(test_func(1), 5)(10) == 5.);

  return 0;
}
