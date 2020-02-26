#pragma once

#include <string>
#include <fstream>

#include "../reader.h"

namespace reader {

    class TextFileReader final : public IReader {
        public:
            explicit TextFileReader(const std::string& file_path);
            ~TextFileReader();

            uint32_t Read(std::vector<uint8_t>& buffer) override;
            bool IsEOF() const override;

        private:
            std::ifstream file_stream_;
    };

}