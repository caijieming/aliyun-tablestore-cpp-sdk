/*
BSD 3-Clause License

Copyright (c) 2017, Alibaba Cloud
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once
#ifndef TABLESTORE_UTIL_RANDOM_HPP
#define TABLESTORE_UTIL_RANDOM_HPP

#include <algorithm>
#include <stdint.h>

namespace aliyun {
namespace tablestore {
namespace util {
namespace random {

class Random
{
public:
    virtual ~Random()
    {}

    virtual uint64_t next() =0;
    virtual uint64_t upperBound() const =0;
    virtual uint64_t seed() const =0;
};

Random* newDefault();
Random* newDefault(uint64_t seed);

int64_t nextInt(Random&, int64_t exclusiveUpper);
int64_t nextInt(Random&, int64_t inclusiveLower, int64_t exclusiveUpper);

template<class T>
void shuffle(Random& rng, T& xs)
{
    int64_t from = xs.size();
    for(--from; from > 0; --from) {
        int64_t to = nextInt(rng, from);
        std::swap(xs[from], xs[to]);
    }
}

} // namespace random
} // namespace util
} // namespace tablestore
} // namespace aliyun
#endif
