//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++98, c++03

// <vector>

// vector(initializer_list<value_type> il, const Allocator& a = allocator_type());

#include <vector>
#include <cassert>

#include "test_allocator.h"
#include "min_allocator.h"

int main(int, char**)
{
    {
    std::vector<bool, test_allocator<bool>> d({true, false, false, true}, test_allocator<bool>(3));
    assert(d.get_allocator() == test_allocator<bool>(3));
    assert(d.size() == 4);
    assert(d[0] == true);
    assert(d[1] == false);
    assert(d[2] == false);
    assert(d[3] == true);
    }
    {
    std::vector<bool, min_allocator<bool>> d({true, false, false, true}, min_allocator<bool>());
    assert(d.get_allocator() == min_allocator<bool>());
    assert(d.size() == 4);
    assert(d[0] == true);
    assert(d[1] == false);
    assert(d[2] == false);
    assert(d[3] == true);
    }

  return 0;
}
