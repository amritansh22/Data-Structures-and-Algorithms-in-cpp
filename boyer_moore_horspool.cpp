#include <string_view>  // std::string_view
#include <optional>  // std::optional
#include <array>  // std::array
#include <iostream>  // std::cout


struct SearchPattern {
    std::string_view needle;
    std::array<char, 256> bad_char_table;
    SearchPattern(const std::string_view needle) : needle(needle) {
        // compute bad char table
        bad_char_table = {};

        // Rule 1
        // Characters not in the needle jump the length of the needle.
        bad_char_table.fill(needle.length());


        // Rule 2
        // Characters in the needle except last character jump:
        // length of needle - last position of character - 1
        for (std::size_t i = 0; i < needle.length(); i++) {
            bad_char_table[needle[i]] = needle.length() - i - 1;
        }
    }
};

/** Returns index of first occurrance of pattern in haystack. */
std::optional<std::size_t> boyer_moore_horspool(SearchPattern pattern, std::string_view haystack) {
    for (std::size_t h = 0; h < haystack.length() - pattern.needle.length() + 1;) {
        // Search this placement of the needle.
        bool found = false;
        for (std::size_t n = pattern.needle.length() - 1; ; n--) {
            // Check the needle in reverse.
            if (haystack[h + n] != pattern.needle[n]) {
                // Bad character found.
                found = false;
                // Jump based on the bad character table.
                h += pattern.bad_char_table[haystack[h + n]];
                break;
            }
            if (n == 0) {
                break;
            }
        }
        if (found) {
            return h;
        }
    }

    // Not found in the haystack.
    return std::nullopt;
}

int main() {
    auto needle = SearchPattern{ "abc" };
    auto haystack = "aa abc ddef";
    auto index = boyer_moore_horspool(needle, haystack);
    if (index) {
        std::cout << "found at index " << index.value() << '\n' << std::flush;
    } else {
        std::cout << "not found" << std::endl;
    }
}
