#include <string_view>  // std::string_view
#include <optional>  // std::optional
#include <array>  // std::array
#include <iostream>  // std::cout


struct SearchPattern {
    constexpr static std::size_t num_chars{ 256 };
    const std::string_view needle;
    std::array<char, num_chars> bad_char_table{};

    constexpr SearchPattern(const std::string_view needle) noexcept
        : needle(needle) {
        // compute bad char table

        // Rule 1
        // Characters not in the needle jump the length of the needle.
        for (std::size_t i = 0; i < num_chars; i++) {
            bad_char_table[i] = needle.length();
        }


        // Rule 2
        // Characters in the needle except last character jump:
        // length of needle - last position of character - 1
        for (std::size_t i = 0; i < needle.length(); i++) {
            bad_char_table[needle[i]] = needle.length() - i - 1;
        }
    }
};

/** Returns index of first occurrance of pattern in haystack. */
constexpr std::optional<std::size_t> boyer_moore_horspool(SearchPattern pattern, std::string_view haystack) {
    for (std::size_t h = 0; h < haystack.length() - pattern.needle.length() + 1;) {
        // Search this placement of the needle.
        bool found = true;
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
    constexpr SearchPattern needle{ "abc" };
    constexpr auto haystack = "aa abc ddef";
    constexpr auto index = boyer_moore_horspool(needle, haystack);
    static_assert(index == 3, "index is supposed to be 3!");

    if (index) {
        std::cout << "found at index " << index.value() << '\n' << std::flush;
    } else {
        std::cout << "not found" << std::endl;
    }
}
