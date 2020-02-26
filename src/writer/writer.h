#pragma once

#include <vector>

namespace writer {

    class IWRiter {
        public:
            explicit IWRiter() = default;
            virtual ~IWRiter() = default;

            virtual uint32_t Write(const std::vector<uint8_t>& buffer) = 0;
    };

} // writer