// Utility to calculate profit margins for a fictional farm plot

use std::io::prelude::*;
use std::io;

macro_rules! printflush {
    ($e:expr) => {
        print!($e);
        io::stdout().flush().expect("Could not flush stdout");
    }
}

fn main() {

    let mut total_revenue: f64 = 0.0;
    let mut total_cost: f64 = 0.0;
    let mut land_area: String = String::new();
    let mut num_vegetables: String = String::new();

    printflush!("Enter the total farm area in acres: ");
    io::stdin().read_line(&mut land_area).expect("Failed");

    loop {
        printflush!("Enter the number of vegetables that you'd like to grow (1 or 2): ");
        io::stdin().read_line(&mut num_vegetables).expect("Failed");
        if num_vegetables.trim() == "1" || num_vegetables.trim() == "2" {
            break;
        }
        num_vegetables.clear();
    }

    let land_area: i32 = land_area.trim().parse().expect("Failed");
    let num_vegetables: i32 = num_vegetables.trim().parse().expect("Failed");

    if num_vegetables == 2 {
        let mut percent_area: String = String::new();
        loop {
            printflush!("Enter the percent area for vegetable #1: ");
            io::stdin().read_line(&mut percent_area).expect("Failed");
            let test_percent_area: i32 = percent_area.trim().parse().expect("Failed");
            if 0 < test_percent_area && test_percent_area < 100 {
                break;
            }
            percent_area.clear();
        }
        let percent_area: i32 = percent_area.trim().parse().expect("Failed");

        println!("Calculating profit margins for vegetable #1 using {}% land area",
                 percent_area);
        match calculate_farm_revenue(percent_area, land_area) {
            (c, r) => {
                total_cost += c;
                total_revenue += r;
            }
        }
        println!("Calculating profit margins for vegetable #2 using {}% land area",
                 100 - percent_area);
        match calculate_farm_revenue(percent_area, land_area) {
            (c, r) => {
                total_cost += c;
                total_revenue += r;
            }
        }
    } else {
        println!("Calculating profit margins for vegetable #2 using 100% land area");
        match calculate_farm_revenue(100, land_area) {
            (c, r) => {
                total_cost += c;
                total_revenue += r;
            }
        }
    }

    println!("=================================");
    println!("Total Revenue: ${:.2}", total_revenue);

    if total_revenue > total_cost {
        println!("Total Profit: ${:.2}", total_revenue - total_cost);
    } else {
        println!("Total Loss: ${:.2}", total_cost - total_revenue);
    }
}

fn calculate_farm_revenue(percent_area: i32, land_area: i32) -> (f64, f64) {
    let corrected_area: f64 = land_area as f64 * (percent_area as f64 / 100.0);

    let mut seed_cost: String = String::new();
    let mut plantation_cost: String = String::new();
    let mut fertilizing_cost: String = String::new();
    let mut labor_cost: String = String::new();
    let mut selling_price: String = String::new();

    printflush!("Enter the seed cost per acre: ");
    io::stdin().read_line(&mut seed_cost).expect("Failed");

    printflush!("Enter the plantation cost per acre: ");
    io::stdin().read_line(&mut plantation_cost).expect("Failed");

    printflush!("Enter the fertilizing cost per acre: ");
    io::stdin().read_line(&mut fertilizing_cost).expect("Failed");

    printflush!("Enter the labor cost per acre: ");
    io::stdin().read_line(&mut labor_cost).expect("Failed");

    printflush!("Enter the selling price per acre: ");
    io::stdin().read_line(&mut selling_price).expect("Failed");

    let seed_cost: f64 = seed_cost.trim().parse().expect("Failed");
    let plantation_cost: f64 = plantation_cost.trim().parse().expect("Failed");
    let fertilizing_cost: f64 = fertilizing_cost.trim().parse().expect("Failed");
    let labor_cost: f64 = labor_cost.trim().parse().expect("Failed");
    let selling_price: f64 = selling_price.trim().parse().expect("Failed");

    let total_cost: f64 = (seed_cost * corrected_area) + (plantation_cost * corrected_area) +
                          (fertilizing_cost * corrected_area) +
                          (labor_cost * corrected_area);

    let total_revenue: f64 = selling_price * corrected_area;

    (total_cost, total_revenue)
}
