#[link(name = "math_c", kind = "static")]
extern "C" {
    fn mul(a: u32, b: u32, c: u32) -> u32;
}

#[link(name = "math_c", kind = "static")]
extern "C" {
    fn add(a: u32, b: u32) -> u32;
}

#[inline(never)]
#[no_mangle]
fn multiply(a: u32, b: u32) -> u32 {
    unsafe { mul(a, b, 1) }
}

#[inline(never)]
#[no_mangle]
fn add_rust(a: u32, b: u32) -> u32 {
    (unsafe { add(a, b) }) -2*b
}

use criterion::{black_box};
fn main() {
    println!("2*3 = {}!", multiply(2, 3));
    println!("1*1= {}!", multiply(1, 1));

    let a = 1;
    let b = 2;
    println!("1+2-2= {}!", add_rust(black_box(1), black_box(2)));
}
