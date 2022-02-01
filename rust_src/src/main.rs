#[link(name = "math_c", kind = "static")]
extern "C" {
    fn mul(a: u32, b: u32, c: u32) -> u32;
}
#[inline(never)]
#[no_mangle]
fn multiply(a: u32, b: u32) -> u32 {
    unsafe { mul(a, b, 1) }
}

#[link(name = "math_c", kind = "static")]
extern "C" {
    fn add(a: u32, b: u32) -> u32;
}
// In cpp code, add(a,b) = {return a+2*b}
// If the compiler is smart enough, it will use LTO to
// eliminate the additon
#[inline(never)]
#[no_mangle]
fn add_rust(a: u32, b: u32) -> u32 {
    (unsafe { add(a, b) }) - 2 * b
}

#[link(name = "math_c", kind = "static")]
extern "C" {
    fn get_prime_c(a: u32) -> u32;
}
#[inline(never)]
#[no_mangle]
fn get_prime_c_rust(a: u32) -> u32 {
    unsafe { get_prime_c(a) }
}

use criterion::black_box;

fn main() {
    println!("2*3 = {}!", multiply(2, 3));
    println!("1*1= {}!", multiply(1, 1));

    let a = 1;
    let b = 2;
    println!("1+2-2= {}!", add_rust(black_box(1), black_box(2)));
    println!("get_prime_c_rust(10)= {} ", get_prime_c_rust(black_box(10)));
}
