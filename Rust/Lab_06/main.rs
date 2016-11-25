// Program to calculate inflation rate

use std::io::prelude::*;
use std::io;

macro_rules! read_to_f64 {
    ($e:expr, $i: ident) => {
        print!($e);
        io::stdout().flush().expect("Could not flush stdout");
        let mut $i = String::new();
        io::stdin().read_line(&mut $i).expect("Failed");
        let $i: f64 = $i.trim().parse().expect("Failed");
    }
}

fn input_func() -> (f64, f64, f64) {
    read_to_f64!("Enter the current price: ", current);
    read_to_f64!("Enter the price one year ago: ", one_year);
    read_to_f64!("Enter the price two years ago: ", two_year);
    (current, one_year, two_year)
}

fn calculate(current: &f64, past: &f64) -> f64 {
    (past - current) / past
}

fn print_result(result1: &f64, result2: &f64) {
    if result1 > result2 {
        println!("Inflation is increasing");
        return;
    }
    if result2 > result1 {
        println!("Inflation is decreasing");
        return;
    }
    println!("Inflation is the exact same");
}

fn main() {
    let (current, one_year, two_year) = input_func();

    let result1 = calculate(&current, &one_year);
    let result2 = calculate(&one_year, &two_year);

    print_result(&result1, &result2);
}
