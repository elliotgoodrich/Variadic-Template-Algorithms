#include "vta/algorithms.hpp"

#include <cstring>
#include <iostream>
#include <string>
#include <utility>

std::size_t string_size(std::string const& str) noexcept { return str.size(); }
std::size_t string_size(char const* str) noexcept { return std::strlen(str); }
std::size_t string_size(char) noexcept { return 1; }

auto const sum = [](auto lhs, auto rhs){ return lhs + rhs; };

template <typename... Args>
std::string concat(Args&&... args) {
	std::string str;
	str.reserve(vta::foldl(sum)(0ul, string_size(args)...));
	vta::map([&str](auto const& append){ str += append; })(args...);
	return str;
}

int main() {
	std::string name = "World";
	auto const hello_world = concat("Hello ", name, '!');
	std::cout << hello_world << std::endl;
}
