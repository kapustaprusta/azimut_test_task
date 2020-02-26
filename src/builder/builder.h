#pragma once

#include <string>
#include <memory>

#include "../defs/defs.h"
#include "../task/task.h"

namespace builder {

    class CheckerBuilder {
        public:
            explicit CheckerBuilder() = default;
            ~CheckerBuilder() = default;

            std::shared_ptr<task::ITask> Build(const std::string& input_file_path, const defs::TaskType& type = defs::TaskType::CHECKER);

        private:
            std::string MakeOutputFilePath(const std::string& input_file_path);
    };

} // builder