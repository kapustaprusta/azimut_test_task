#pragma once

#include <string>

namespace writer {

    class IWRiter {
        public:
            explicit IWRiter() = default;
            virtual ~IWRiter() = default;

            virtual uint32_t Write(const std::string& buffer) = 0;
    };

} // writer