fn main() {
    cc::Build::new()
        .cpp(true)
        .file("cxx/math_c.cpp")
        .flag("-flto=thin")
        .flag("-std=c++20")
        .compile("libmath_c.a");
}
