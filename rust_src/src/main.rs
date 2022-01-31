#[link(name = "mul", kind = "static")]
extern "C" {
    fn mul(a: u32, b: u32) -> u32;
}

#[inline(never)]
#[no_mangle]
fn multiply(a: u32, b: u32) -> u32 {
    unsafe { mul(a, b) }
}

fn main() {
    println!("2*3 = {}!", multiply(2, 3));
    println!("1*1= {}!", multiply(1, 1));
}
