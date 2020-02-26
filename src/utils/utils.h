#pragma once

#include <string>

namespace utils {

    inline bool IsFlightInfoEqual(const std::string& flight_info_1, const std::string& flight_info_2) {
        auto l_split_info = [](const std::string& flight_info) -> std::pair<std::string, int> {
            auto prev_char = '\0';
            // ищем первую цифру номера рейса
            for (auto char_idx = 2; char_idx < flight_info.size(); char_idx++) {
                if (flight_info[char_idx] >= '0' && flight_info[char_idx] <= '9') {
                    if (prev_char == ' ') {
                        char_idx--;
                    }

                    const auto airlines_code = flight_info.substr(0, char_idx);
                    const auto flight_number = std::stoi(flight_info.substr(char_idx));

                    return std::make_pair(airlines_code, flight_number);
                }

                prev_char = flight_info[char_idx];
            }

            return {};
        };

        return l_split_info(flight_info_1) == l_split_info(flight_info_2);
    }

} // utils