// Program for determining ROI

use std::io::prelude::*;
use std::io;

macro_rules! printflush {
    ($e:expr) => {
        print!($e);
        io::stdout().flush().expect("Could not flush stdout");
    }
}

fn main() {
    const SERVICE_CHARGE: f32 = 0.015;

    let mut num_sold: String = String::new();
    let mut purchase_price: String = String::new();
    let mut selling_price: String = String::new();

    printflush!("Enter # of shares sold: ");
    io::stdin().read_line(&mut num_sold).expect("Failed");

    printflush!("Enter purchase price per share: ");
    io::stdin().read_line(&mut purchase_price).expect("Failed");

    printflush!("Enter the selling price per share: ");
    io::stdin().read_line(&mut selling_price).expect("Failed");

    let num_sold: i32 = num_sold.trim().parse().expect("Failed");
    let purchase_price: f32 = purchase_price.trim().parse().expect("Failed");
    let selling_price: f32 = selling_price.trim().parse().expect("Failed");

    let total_charges: f32 = (purchase_price * SERVICE_CHARGE) +
                             (selling_price * SERVICE_CHARGE) * num_sold as f32;
    let total_investment: f32 = (purchase_price * num_sold as f32) +
                                ((purchase_price * SERVICE_CHARGE) * num_sold as f32);
    let total_sell_amount: f32 = (selling_price * num_sold as f32) -
                                 ((selling_price * SERVICE_CHARGE) * num_sold as f32);
    let delta_investment: f32 = total_sell_amount - total_investment;

    println!("\n\n==== Results ====");
    println!("Amount invested: ${:.2}", total_investment);
    println!("Total charges: ${:.2}", total_charges);
    println!("Delta investment: ${:.2}", delta_investment);
    println!("Total received after sale: ${:.2}", total_sell_amount);

}
