#include <utki/debug.hpp>

#include "../../src/r4/matrix4.hpp"

#include <sstream>

int main(int argc, char** argv){

	// test constructor(vector4, vector4, vector4, vector4)
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		std::stringstream ss;
		ss << m;
		auto str = ss.str();
		auto cmp = "\n\t/1 2 3 4\\"
		           "\n\t|5 6 7 8|"
		           "\n\t|9 10 11 12|"
		          "\n\t\\13 14 15 16/";
		ASSERT_INFO_ALWAYS(str == cmp, "str = " << str)
	}

	// test constructor(quaternion)
	{
		r4::quaternion<float> q;
		q.set_rotation(1, 2, 3, utki::pi<float>() / 6);

		r4::matrix4<float> m{q};

		m *= 1000.0f;

		std::stringstream ss;
		ss << m.to<int>();
		auto str = ss.str();
		auto cmp = "\n\t/-741 -1232 1401 0\\"
		           "\n\t|1767 -339 303 0|"
		           "\n\t|-598 1303 330 0|"
		          "\n\t\\0 0 0 1000/";
		ASSERT_INFO_ALWAYS(str == cmp, "str = " << str)
	}

	// test operator*(vector2)
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		auto r = m * r4::vector2<int>{3, 4};

		ASSERT_INFO_ALWAYS(r[0] == 1 * 3 + 2 * 4 + 4, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1] == 5 * 3 + 6 * 4 + 8, "r = " << r)
	}

	// test operator*(vector3)
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		auto r = m * r4::vector3<int>{3, 4, 5};

		ASSERT_INFO_ALWAYS(r[0] == 1 * 3 + 2 * 4 + 3 * 5 + 4, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1] == 5 * 3 + 6 * 4 + 7 * 5 + 8, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2] == 9 * 3 + 10 * 4 + 11 * 5 + 12, "r = " << r)
	}

	// test operator*(vector4)
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		auto r = m * r4::vector4<int>{3, 4, 5, 6};

		ASSERT_INFO_ALWAYS(r[0] == 1 * 3 + 2 * 4 + 3 * 5 + 4 * 6, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1] == 5 * 3 + 6 * 4 + 7 * 5 + 8 * 6, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2] == 9 * 3 + 10 * 4 + 11 * 5 + 12 * 6, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3] == 13 * 3 + 14 * 4 + 15 * 5 + 16 * 6, "r = " << r)
	}

	// test operator*(matrix4)
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		r4::matrix4<int> m2{
		 	{17, 18, 19, 20},
			{21, 22, 23, 24},
			{25, 26, 27, 28},
			{29, 30, 31, 32}
		};

		auto r = m * m2;

		ASSERT_INFO_ALWAYS(r[0][0] == 1 * 17 + 2 * 21 + 3 * 25 + 4 * 29, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1][0] == 5 * 17 + 6 * 21 + 7 * 25 + 8 * 29, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2][0] == 9 * 17 + 10 * 21 + 11 * 25 + 12 * 29, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3][0] == 13 * 17 + 14 * 21 + 15 * 25 + 16 * 29, "r = " << r)

		ASSERT_INFO_ALWAYS(r[0][1] == 1 * 18 + 2 * 22 + 3 * 26 + 4 * 30, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1][1] == 5 * 18 + 6 * 22 + 7 * 26 + 8 * 30, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2][1] == 9 * 18 + 10 * 22 + 11 * 26 + 12 * 30, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3][1] == 13 * 18 + 14 * 22 + 15 * 26 + 16 * 30, "r = " << r)

		ASSERT_INFO_ALWAYS(r[0][2] == 1 * 19 + 2 * 23 + 3 * 27 + 4 * 31, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1][2] == 5 * 19 + 6 * 23 + 7 * 27 + 8 * 31, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2][2] == 9 * 19 + 10 * 23 + 11 * 27 + 12 * 31, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3][2] == 13 * 19 + 14 * 23 + 15 * 27 + 16 * 31, "r = " << r)

		ASSERT_INFO_ALWAYS(r[0][3] == 1 * 20 + 2 * 24 + 3 * 28 + 4 * 32, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1][3] == 5 * 20 + 6 * 24 + 7 * 28 + 8 * 32, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2][3] == 9 * 20 + 10 * 24 + 11 * 28 + 12 * 32, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3][3] == 13 * 20 + 14 * 24 + 15 * 28 + 16 * 32, "r = " << r)
	}

	// test transpose()
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		m.transpose();

		std::stringstream ss;
		ss << m;
		auto str = ss.str();
		auto cmp = "\n\t/1 5 9 13\\"
		           "\n\t|2 6 10 14|"
		           "\n\t|3 7 11 15|"
		          "\n\t\\4 8 12 16/";
		ASSERT_INFO_ALWAYS(str == cmp, "str = " << str)
	}

	// test operator*=(matrix4)
	{
		r4::matrix4<int> r{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		r4::matrix4<int> m2{
		 	{17, 18, 19, 20},
			{21, 22, 23, 24},
			{25, 26, 27, 28},
			{29, 30, 31, 32}
		};

		r *= m2;

		ASSERT_INFO_ALWAYS(r[0][0] == 1 * 17 + 2 * 21 + 3 * 25 + 4 * 29, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1][0] == 5 * 17 + 6 * 21 + 7 * 25 + 8 * 29, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2][0] == 9 * 17 + 10 * 21 + 11 * 25 + 12 * 29, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3][0] == 13 * 17 + 14 * 21 + 15 * 25 + 16 * 29, "r = " << r)

		ASSERT_INFO_ALWAYS(r[0][1] == 1 * 18 + 2 * 22 + 3 * 26 + 4 * 30, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1][1] == 5 * 18 + 6 * 22 + 7 * 26 + 8 * 30, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2][1] == 9 * 18 + 10 * 22 + 11 * 26 + 12 * 30, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3][1] == 13 * 18 + 14 * 22 + 15 * 26 + 16 * 30, "r = " << r)

		ASSERT_INFO_ALWAYS(r[0][2] == 1 * 19 + 2 * 23 + 3 * 27 + 4 * 31, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1][2] == 5 * 19 + 6 * 23 + 7 * 27 + 8 * 31, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2][2] == 9 * 19 + 10 * 23 + 11 * 27 + 12 * 31, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3][2] == 13 * 19 + 14 * 23 + 15 * 27 + 16 * 31, "r = " << r)

		ASSERT_INFO_ALWAYS(r[0][3] == 1 * 20 + 2 * 24 + 3 * 28 + 4 * 32, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1][3] == 5 * 20 + 6 * 24 + 7 * 28 + 8 * 32, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2][3] == 9 * 20 + 10 * 24 + 11 * 28 + 12 * 32, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3][3] == 13 * 20 + 14 * 24 + 15 * 28 + 16 * 32, "r = " << r)
	}

	// test operator*=(n)
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		m *= 3;

		std::stringstream ss;
		ss << m;
		auto str = ss.str();
		auto cmp = "\n\t/3 6 9 12\\"
		           "\n\t|15 18 21 24|"
		           "\n\t|27 30 33 36|"
		          "\n\t\\39 42 45 48/";
		ASSERT_INFO_ALWAYS(str == cmp, "str = " << str)
	}

	// test right_mul(matrix4)
	{
		r4::matrix4<int> r{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		r4::matrix4<int> m2{
		 	{17, 18, 19, 20},
			{21, 22, 23, 24},
			{25, 26, 27, 28},
			{29, 30, 31, 32}
		};

		r.right_mul(m2);

		ASSERT_INFO_ALWAYS(r[0][0] == 1 * 17 + 2 * 21 + 3 * 25 + 4 * 29, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1][0] == 5 * 17 + 6 * 21 + 7 * 25 + 8 * 29, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2][0] == 9 * 17 + 10 * 21 + 11 * 25 + 12 * 29, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3][0] == 13 * 17 + 14 * 21 + 15 * 25 + 16 * 29, "r = " << r)

		ASSERT_INFO_ALWAYS(r[0][1] == 1 * 18 + 2 * 22 + 3 * 26 + 4 * 30, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1][1] == 5 * 18 + 6 * 22 + 7 * 26 + 8 * 30, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2][1] == 9 * 18 + 10 * 22 + 11 * 26 + 12 * 30, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3][1] == 13 * 18 + 14 * 22 + 15 * 26 + 16 * 30, "r = " << r)

		ASSERT_INFO_ALWAYS(r[0][2] == 1 * 19 + 2 * 23 + 3 * 27 + 4 * 31, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1][2] == 5 * 19 + 6 * 23 + 7 * 27 + 8 * 31, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2][2] == 9 * 19 + 10 * 23 + 11 * 27 + 12 * 31, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3][2] == 13 * 19 + 14 * 23 + 15 * 27 + 16 * 31, "r = " << r)

		ASSERT_INFO_ALWAYS(r[0][3] == 1 * 20 + 2 * 24 + 3 * 28 + 4 * 32, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1][3] == 5 * 20 + 6 * 24 + 7 * 28 + 8 * 32, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2][3] == 9 * 20 + 10 * 24 + 11 * 28 + 12 * 32, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3][3] == 13 * 20 + 14 * 24 + 15 * 28 + 16 * 32, "r = " << r)
	}

	// test left_mul(matrix4)
	{
		r4::matrix4<int> m2{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		r4::matrix4<int> r{
		 	{17, 18, 19, 20},
			{21, 22, 23, 24},
			{25, 26, 27, 28},
			{29, 30, 31, 32}
		};

		r.left_mul(m2);

		ASSERT_INFO_ALWAYS(r[0][0] == 1 * 17 + 2 * 21 + 3 * 25 + 4 * 29, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1][0] == 5 * 17 + 6 * 21 + 7 * 25 + 8 * 29, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2][0] == 9 * 17 + 10 * 21 + 11 * 25 + 12 * 29, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3][0] == 13 * 17 + 14 * 21 + 15 * 25 + 16 * 29, "r = " << r)

		ASSERT_INFO_ALWAYS(r[0][1] == 1 * 18 + 2 * 22 + 3 * 26 + 4 * 30, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1][1] == 5 * 18 + 6 * 22 + 7 * 26 + 8 * 30, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2][1] == 9 * 18 + 10 * 22 + 11 * 26 + 12 * 30, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3][1] == 13 * 18 + 14 * 22 + 15 * 26 + 16 * 30, "r = " << r)

		ASSERT_INFO_ALWAYS(r[0][2] == 1 * 19 + 2 * 23 + 3 * 27 + 4 * 31, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1][2] == 5 * 19 + 6 * 23 + 7 * 27 + 8 * 31, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2][2] == 9 * 19 + 10 * 23 + 11 * 27 + 12 * 31, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3][2] == 13 * 19 + 14 * 23 + 15 * 27 + 16 * 31, "r = " << r)

		ASSERT_INFO_ALWAYS(r[0][3] == 1 * 20 + 2 * 24 + 3 * 28 + 4 * 32, "r = " << r)
		ASSERT_INFO_ALWAYS(r[1][3] == 5 * 20 + 6 * 24 + 7 * 28 + 8 * 32, "r = " << r)
		ASSERT_INFO_ALWAYS(r[2][3] == 9 * 20 + 10 * 24 + 11 * 28 + 12 * 32, "r = " << r)
		ASSERT_INFO_ALWAYS(r[3][3] == 13 * 20 + 14 * 24 + 15 * 28 + 16 * 32, "r = " << r)
	}

	// test set_identity()
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		m.set_identity();

		std::stringstream ss;
		ss << m;
		auto str = ss.str();
		auto cmp = "\n\t/1 0 0 0\\"
		           "\n\t|0 1 0 0|"
		           "\n\t|0 0 1 0|"
		          "\n\t\\0 0 0 1/";
		ASSERT_INFO_ALWAYS(str == cmp, "str = " << str)
	}

	// test set_frustum(l, r, b, t, n, f)
	{
		r4::matrix4<float> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		m.set_frustum(-2, 2, -1.5, 1.5, 2, 100);
		m *= 1000.0f;

		std::stringstream ss;
		ss << m.to<int>();
		auto str = ss.str();
		auto cmp = "\n\t/1000 0 0 0\\"
		           "\n\t|0 1333 0 0|"
		           "\n\t|0 0 -1040 -4081|"
		          "\n\t\\0 0 -1000 0/";
		ASSERT_INFO_ALWAYS(str == cmp, "str = " << str)
	}

	// test set(quaternion)
	{
		r4::matrix4<float> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		m.set(r4::quaternion<float>{2, 3, 4, 5});

		std::stringstream ss;
		ss << m.to<int>();
		auto str = ss.str();
		auto cmp = "\n\t/-49 -28 46 0\\"
		           "\n\t|52 -39 4 0|"
		           "\n\t|-14 44 -25 0|"
		          "\n\t\\0 0 0 1/";
		ASSERT_INFO_ALWAYS(str == cmp, "str = " << str)
	}

	// test scale(x, y)
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		m.scale(3, 4);

		std::stringstream ss;
		ss << m;
		auto str = ss.str();
		auto cmp = "\n\t/3 8 3 4\\"
		           "\n\t|15 24 7 8|"
		           "\n\t|27 40 11 12|"
		          "\n\t\\39 56 15 16/";
		ASSERT_INFO_ALWAYS(str == cmp, "str = " << str)
	}

	// test scale(x, y, z)
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		m.scale(3, 4, 5);

		std::stringstream ss;
		ss << m;
		auto str = ss.str();
		auto cmp = "\n\t/3 8 15 4\\"
		           "\n\t|15 24 35 8|"
		           "\n\t|27 40 55 12|"
		          "\n\t\\39 56 75 16/";
		ASSERT_INFO_ALWAYS(str == cmp, "str = " << str)
	}

	// test scale(s)
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		m.scale(3);

		std::stringstream ss;
		ss << m;
		auto str = ss.str();
		auto cmp = "\n\t/3 6 9 4\\"
		           "\n\t|15 18 21 8|"
		           "\n\t|27 30 33 12|"
		          "\n\t\\39 42 45 16/";
		ASSERT_INFO_ALWAYS(str == cmp, "str = " << str)
	}

	// test scale(vector2)
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		m.scale(r4::vector2<int>{3, 4});

		std::stringstream ss;
		ss << m;
		auto str = ss.str();
		auto cmp = "\n\t/3 8 3 4\\"
		           "\n\t|15 24 7 8|"
		           "\n\t|27 40 11 12|"
		          "\n\t\\39 56 15 16/";
		ASSERT_INFO_ALWAYS(str == cmp, "str = " << str)
	}

	// test scale(vector3)
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		m.scale(r4::vector3<int>{3, 4, 5});

		std::stringstream ss;
		ss << m;
		auto str = ss.str();
		auto cmp = "\n\t/3 8 15 4\\"
		           "\n\t|15 24 35 8|"
		           "\n\t|27 40 55 12|"
		          "\n\t\\39 56 75 16/";
		ASSERT_INFO_ALWAYS(str == cmp, "str = " << str)
	}

	// test translate(x, y)
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		m.translate(3, 4);

		std::stringstream ss;
		ss << m;
		auto str = ss.str();
		auto cmp = "\n\t/1 2 3 15\\"
		           "\n\t|5 6 7 47|"
		           "\n\t|9 10 11 79|"
		          "\n\t\\13 14 15 111/";
		ASSERT_INFO_ALWAYS(str == cmp, "str = " << str)
	}

	// test translate(x, y, z)
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		m.translate(3, 4, 5);

		std::stringstream ss;
		ss << m;
		auto str = ss.str();
		auto cmp = "\n\t/1 2 3 30\\"
		           "\n\t|5 6 7 82|"
		           "\n\t|9 10 11 134|"
		          "\n\t\\13 14 15 186/";
		ASSERT_INFO_ALWAYS(str == cmp, "str = " << str)
	}

	// test translate(vector2)
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		m.translate(r4::vector2<int>{3, 4});

		std::stringstream ss;
		ss << m;
		auto str = ss.str();
		auto cmp = "\n\t/1 2 3 15\\"
		           "\n\t|5 6 7 47|"
		           "\n\t|9 10 11 79|"
		          "\n\t\\13 14 15 111/";
		ASSERT_INFO_ALWAYS(str == cmp, "str = " << str)
	}

	// test translate(vector3)
	{
		r4::matrix4<int> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		m.translate(r4::vector3<int>{3, 4, 5});

		std::stringstream ss;
		ss << m;
		auto str = ss.str();
		auto cmp = "\n\t/1 2 3 30\\"
		           "\n\t|5 6 7 82|"
		           "\n\t|9 10 11 134|"
		          "\n\t\\13 14 15 186/";
		ASSERT_INFO_ALWAYS(str == cmp, "str = " << str)
	}

	// test rotate(quaternion)
	{
		r4::matrix4<float> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		r4::quaternion<float> quat{2, 3, 4, 5};

		r4::matrix4<float> rot;
		rot.set(quat);

		auto cmp = m * rot;

		m.rotate(quat);

		ASSERT_INFO_ALWAYS(m.to<int>() == cmp.to<int>(), "m = " << m << " cmp = " << cmp)
	}

	// test rotate(vector3)
	{
		r4::matrix4<float> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		r4::vector3<float> vec{2, 3, 4};

		r4::matrix4<float> rot;
		rot.set(r4::quaternion<float>{vec});

		auto cmp = m * rot;

		m.rotate(vec);

		cmp *= 1000.0f;
		m *= 1000.0f;

		ASSERT_INFO_ALWAYS(m.to<int>() == cmp.to<int>(), "m = " << m << " cmp = " << cmp)
	}

	// test rotate(n)
	{
		r4::matrix4<float> m{
		 	{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
		};

		float angle = 4;

		r4::vector3<float> vec{0, 0, angle};

		r4::matrix4<float> rot;
		rot.set(r4::quaternion<float>{vec});

		auto cmp = m * rot;

		m.rotate(angle);

		cmp *= 1000.0f;
		m *= 1000.0f;

		ASSERT_INFO_ALWAYS(m.to<int>() == cmp.to<int>(), "m = " << m << " cmp = " << cmp)
	}

    // test operator<<
    {
        r4::matrix4<int> m;
		m.set_identity();

		std::stringstream ss;

		ss << m;

		auto cmp = "\n\t/1 0 0 0\\\n\t|0 1 0 0|\n\t|0 0 1 0|\n\t\\0 0 0 1/";

		// TRACE_ALWAYS(<< "m = " << ss.str() << std::endl)
		// TRACE_ALWAYS(<< "cmp = " << cmp << std::endl)

		ASSERT_ALWAYS(ss.str() == cmp)
        // v.negate();

        // ASSERT_ALWAYS(!v.is_negative())
        // ASSERT_ALWAYS(v.x == -13)
        // ASSERT_ALWAYS(v.y == 14)
    }

    return 0;
}