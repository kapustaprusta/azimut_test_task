#include "builder.h"
#include "../task/checker_task/checker_task.h"
#include "../reader/text_file_reader/text_file_reader.h"
#include "../writer/text_file_writer/text_file_writer.h"

namespace builder {

    std::shared_ptr<task::ITask> CheckerBuilder::Build(const std::string& input_file_path, const defs::TaskType& type) {
        if (type == defs::TaskType::CHECKER) {
            std::shared_ptr<reader::IReader> file_reader;
            std::shared_ptr<writer::IWRiter> file_writer;

            const auto output_file_path = MakeOutputFilePath(input_file_path);

            try {
                file_reader = std::make_shared<reader::TextFileReader>(input_file_path);
                file_writer = std::make_shared<writer::TextFileWriter>(output_file_path);
            }
            catch (std::exception& e) {
                throw e;
            }

            return std::make_shared<task::CheckerTask>(file_reader, file_writer);
        }
                
        return nullptr;
    }

    std::string CheckerBuilder::MakeOutputFilePath(const std::string& input_file_path) {
        const auto dot_position = input_file_path.find('_');
        return input_file_path.substr(0, dot_position) + "_out.txt";
    }

} // builder