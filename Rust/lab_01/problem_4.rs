// Program which determines if a triange is a right triangle

use std::io;
use std::f32;

fn main() {
    let mut side1: String = String::new();
    let mut side2: String = String::new();
    let mut side3: String = String::new();

    println!("Enter the length of the hypotenuse");
    io::stdin()
        .read_line(&mut side1)
        .expect("Failed to read input");

    println!("Enter the length of the base: ");
    io::stdin()
        .read_line(&mut side2)
        .expect("Failed to read input");

    println!("Enter the length of the height: ");
    io::stdin()
        .read_line(&mut side3)
        .expect("Failed to read input");

    let side1: f32 = side1.trim()
        .parse()
        .expect("Float parse failed");

    let side2: f32 = side2.trim()
        .parse()
        .expect("Float parse failed");

    let side3: f32 = side3.trim()
        .parse()
        .expect("Float parse failed");

    if side1.powi(2) == (side2.powi(2) + side3.powi(2)) {
        println!("The triangle is a right triangle");
    }
    else {
        println!("The triangle is not a right triangle");
    }
}
