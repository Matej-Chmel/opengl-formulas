# OpenGL formulas

## Vector length

### 2D

$$
v = (x, y)\\
|v| = \sqrt{x^2 + y^2}
$$

```c++
auto len2D(const glm::vec2& v) {
	return std::sqrtf(v.x*v.x + v.y*v.y);
}
```

### 3D

$$
v = (x, y, z)\\
|v| = \sqrt{x^2 + y^2+ z^2}
$$

```c++
auto len3D(const glm::vec3& v) {
	return std::sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
}
```

### ND

$$
v = (v_0, v_1, ..., v_n)\\
|v| = \sqrt{v_0^2 + v_1^2 + ... + v_n^2}
$$

```c++
template <typename glm::length_t D, typename T, enum glm::qualifier Q>
auto len(const glm::vec<D, T, Q>& v) {
	static_assert(D > 0, "Vector dimension must be greater than 0.");
	auto res = v[0]*v[0];

	for(glm::length_t d = 1; d < D; d++)
		res += v[d]*v[d];
	return std::sqrtf(res);
}
```

### GLM

```c++
glm::length(v)
```

