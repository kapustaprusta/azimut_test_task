#pragma once

#include <fstream>

#include "../reader.h"

namespace reader {

    class TextFileReader final : public IReader {
        public:
            explicit TextFileReader(const std::string& file_path);
            ~TextFileReader() final;

            uint32_t Read(std::string& buffer) override;
            bool IsEOF() const override;

        private:
            std::ifstream file_stream_;
    };

}