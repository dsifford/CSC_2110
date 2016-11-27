// Program that outputs roots of a quadratic equation

use std::io::prelude::*;
use std::io;
use std::f64;

macro_rules! printflush {
    ($e:expr) => {
        print!($e);
        io::stdout().flush().expect("Could not flush stdout");
    }
}

fn main() {
    let mut input = String::new();
    let (a, b, c): (f64, f64, f64);

    printflush!("Enter value of 'a': ");
    io::stdin().read_line(&mut input).expect("Failed");
    a = input.trim().parse().expect("Failed");
    input.clear();

    printflush!("Enter value of 'b': ");
    io::stdin().read_line(&mut input).expect("Failed");
    b = input.trim().parse().expect("Failed");
    input.clear();

    printflush!("Enter value of 'c': ");
    io::stdin().read_line(&mut input).expect("Failed");
    c = input.trim().parse().expect("Failed");
    input.clear();

    let discriminant: f64 = f64::powi(b, 2) - (4.0 * a * c);

    match discriminant {
        n if n < 0.0 => println!("Equation has two complex roots"),
        n if n == 0.0 => {
            println!("Equation has one real root");
            println!("Root: {}", -b / (2.0 * a));
        }
        _ => {
            println!("Equation has two real roots");
            println!("Roots: {}, {}",
                     (-b + f64::sqrt(discriminant)) / (2.0 * a),
                     (-b - f64::sqrt(discriminant)) / (2.0 * a));
        }
    }
}
