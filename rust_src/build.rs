fn main() {
    cc::Build::new()
        .file("mul.cpp")
        .flag("-flto=thin")
        .flag("-std=c++20")
        .compile("libmul.a");
}
