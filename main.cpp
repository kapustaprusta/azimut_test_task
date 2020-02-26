#include <iostream>
#include <memory>

#include "src/builder/builder.h"
#include "src/threadpool/threadpool.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "invalid arguments number" << "\n";
        return 0;
    }

    const auto builder = std::make_unique<builder::CheckerBuilder>();
    const auto thread_pool = std::make_unique<threadpool::ThreadPool>(2);

    std::vector<std::shared_ptr<task::ITask>> tasks;
    for (uint32_t arg_idx = 1; arg_idx < argc; arg_idx++) {
        try {
            // если путь указан неверно будет выбрашено исключение
            tasks.emplace_back(builder->Build(argv[arg_idx]));
        }
        catch (std::exception& e) {
            std::cout << e.what() << '\n';
            return 0;
        }
    }

    for (const auto& task : tasks) {
        thread_pool->Schedule([task]() -> void {
            task->Start();
        });
    }
    
    return 0;
}