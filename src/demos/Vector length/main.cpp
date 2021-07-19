#include <array>
#include <cmath>
#include <glm/gtx/string_cast.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <iostream>
#include <nameof.hpp>
#include <type_traits>

template
<typename glm::length_t D, typename T, enum glm::qualifier Q>
auto len(const glm::vec<D, T, Q>& v) {
	static_assert(
		D > 0, "Vector dimension must be greater than 0."
		);
	auto res = v[0]*v[0];

	for(glm::length_t d = 1; d < D; d++)
		res += v[d]*v[d];
	return std::sqrtf(res);
}
auto len2D(const glm::vec2& v) {
	return std::sqrtf(v.x*v.x + v.y*v.y);
}
auto len3D(const glm::vec3& v) {
	return std::sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
}

template <typename V>
void test(const V& v) {
	std::cout << glm::to_string(v) << '\n';

	if constexpr(std::is_same<V, glm::vec2>::value)
		std::cout << NAMEOF(len2D) << " -> " << len2D(v) << '\n';
	else if constexpr(std::is_same<V, glm::vec3>::value)
		std::cout << NAMEOF(len3D) << " -> " << len3D(v) << '\n';

	std::cout << NAMEOF(len(glm::vec4{})) << " -> " << len(v)
		<< '\n' << NAMEOF(glm::length(glm::vec4{})) << " -> "
		<< glm::length(v) << "\n\n";
}
template <typename V, size_t S>
void test(const std::array<V, S>& arr) {
	for(auto& v : arr)
		test(v);
}

int main() {
	const auto testData2D = std::array{
		glm::vec2{0.f},
		glm::vec2{0.f, 1.f},
		glm::vec2{1.f},
		glm::vec2{1.f, 2.f},
		glm::vec2{2.f, 1.f},
		glm::vec2{3.f, 10.f}
	};
	const auto testData3D = std::array{
		glm::vec3{0.f},
		glm::vec3{1.f},
		glm::vec3{1.f, 2.f, 3.f},
		glm::vec3{10.f, 5.f, 10.f}
	};
	const auto testData4D = std::array{
		glm::vec4{0.f},
		glm::vec4{1.f},
		glm::vec4{1.f, 2.f, 3.f, 4.f},
		glm::vec4{4.f, 4.f, 5.f, 1.f}
	};

	test(testData2D);
	test(testData3D);
	test(testData4D);

	(void)getchar();
	return 0;
}
