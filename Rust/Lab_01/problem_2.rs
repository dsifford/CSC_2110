// Outputs profit/cost margins for a fictional milk corporation.

use std::io;

fn main() {
    const COST: f32 = 0.38;
    const PROFIT: f32 = 0.27;
    const LITERS_PER_CARTON: f32 = 3.78;

    let mut liters: String = String::new();
    let cost: f32;
    let profit: f32;
    let cartons: i32;

    println!("Enter number of liters produced:");
    io::stdin()
        .read_line(&mut liters)
        .expect("String could not be parsed.");

    let liters: f32 = liters.trim()
        .parse()
        .expect("Input must be a number.");

    cartons = (liters / LITERS_PER_CARTON) as i32;
    cost = liters * COST;
    profit = liters * PROFIT;

    println!("Number of milk cartons needed: {}", cartons);
    println!("Cost of producing milk: {}", cost);
    println!("Profit of producing milk: {}", profit);
}
