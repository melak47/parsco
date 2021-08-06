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
#include "parsco/ext.hpp"

namespace parsco {

// Sensible defaults.
parser<int>    parse_int();
parser<double> parse_double();

// Assume that this will work the same way for any language.
template<typename Lang>
parser<int> parser_for( lang<Lang>, tag<int> ) {
  return parse_int();
}

template<typename Lang>
parser<double> parser_for( lang<Lang>, tag<double> ) {
  return parse_double();
}

} // namespace parsco
