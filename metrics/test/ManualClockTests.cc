//  Copyright 2018 Benjamin Bader
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#include "ManualClock.h"

#include <chrono>

#include "gtest/gtest.h"

namespace cppmetrics {

TEST(ManualClockTests, equivalent_to_system_clock)
{
  auto now = std::chrono::system_clock::now();
  auto now_as_epoch = std::chrono::system_clock::to_time_t(now);

  ManualClock clock{std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch())};

  EXPECT_EQ(now_as_epoch, clock.now_as_time_t());
}

}
