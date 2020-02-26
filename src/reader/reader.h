#pragma once

#include <string>

namespace reader {

    class IReader {
        public:
            explicit IReader() = default;
            virtual ~IReader() = default;

            virtual uint32_t Read(std::string& buffer) = 0;
            virtual bool IsEOF() const = 0;
    };

}