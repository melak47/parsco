/*
 * MIT License
 *
 * Copyright (c) 2021 David P. Sicilia (dpacbach)
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without re-
 * striction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following con-
 * ditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Soft-
 * ware.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
 * KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PUR-
 * POSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHER-
 * WISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#pragma once

// parsco
#include "parsco/compat.hpp"

namespace parsco {

// unique_coro
//
// This is like unique_ptr but for coroutine handles.
//
struct unique_coro {
  unique_coro( std::coroutine_handle<> h ) : h_( h ) {}

  void destroy() noexcept {
    if( h_ != std::coroutine_handle<>{} ) h_.destroy();
  }

  ~unique_coro() noexcept { destroy(); }

  unique_coro( unique_coro const& ) = delete;
  unique_coro& operator=( unique_coro const& ) = delete;

  unique_coro( unique_coro&& rhs ) {
    h_     = rhs.h_;
    rhs.h_ = std::coroutine_handle<>{};
  }

  unique_coro& operator=( unique_coro&& rhs ) {
    if( this == &rhs ) return *this;
    destroy();
    h_     = rhs.h_;
    rhs.h_ = std::coroutine_handle<>{};
    return *this;
  }

  std::coroutine_handle<> h_;
};

} // namespace parsco