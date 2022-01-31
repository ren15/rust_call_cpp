fn main() {
    cc::Build::new()
        .file("mul.cpp")
        .flag("-flto=thin")
        .compile("libmul.a");
}
