#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using Rule = std::pair<int, std::string>;

static std::string trim(const std::string& s) {
    const auto first = s.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    const auto last = s.find_last_not_of(" \t\r\n");
    return s.substr(first, last - first + 1);
}

void fizzbuzz(const std::vector<Rule>& rules, int limit = 100) {
    std::vector<Rule> ordered = rules;
    std::sort(ordered.begin(), ordered.end(),
              [](const Rule& a, const Rule& b) { return a.first < b.first; });

    for (int i = 1; i <= limit; ++i) {
        std::string output;
        for (const auto& [divisor, word] : ordered) {
            if (i % divisor == 0) output += word;
        }
        if (output.empty()) std::cout << i << "\n";
        else                std::cout << output << "\n";
    }
}

std::vector<Rule> readRules() {
    std::vector<Rule> rules;
    std::string line;
    std::cout << "Enter rules like 3=Fizz. Press Enter on an empty line to finish.\n";

    while (true) {
        std::cout << "Rule: ";
        if (!std::getline(std::cin, line) || line.empty()) break;

        const auto pos = line.find('=');
        if (pos == std::string::npos) {
            std::cout << "Invalid format. Use number=Word, for example 7=Bazz\n";
            continue;
        }

        try {
            const std::string left = trim(line.substr(0, pos));
            const std::string right = trim(line.substr(pos + 1));
            const int divisor = std::stoi(left);
            if (divisor <= 0 || right.empty()) {
                std::cout << "Divisor must be positive and the word cannot be empty.\n";
                continue;
            }
            rules.emplace_back(divisor, right);
        } catch (const std::exception&) {
            std::cout << "Invalid number. Use number=Word, for example 7=Bazz\n";
        }
    }

    std::sort(rules.begin(), rules.end(),
              [](const Rule& a, const Rule& b) { return a.first < b.first; });
    return rules;
}

int main() {
    std::vector<Rule> rules = readRules();
    if (rules.empty()) {
        rules = {{3, "Fizz"}, {5, "Buzz"}};  // default rules
    }
    fizzbuzz(rules);
    return 0;
}