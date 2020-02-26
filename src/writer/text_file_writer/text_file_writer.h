#pragma once

#include <string>
#include <fstream>

#include "../writer.h"

namespace writer {

    class TextFileWriter final : public IWRiter {
        public:
            explicit TextFileWriter(const std::string& file_path);
            ~TextFileWriter();

            uint32_t Write(const std::vector<uint8_t>& buffer) override;

        private:
            std::ofstream file_stream_;
    };

} // writer