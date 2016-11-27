// Calculate ticket sales for a fictional football stadium

use std::io;
use std::io::BufRead;
use std::fs::File;

fn main() {
    let mut total_tickets: i32 = 0;
    let mut total_sales: i32 = 0;
    let mut price: i32;
    let mut num_tickets: i32;

    let f = match File::open("./tickets.txt") {
        Ok(file) => file,
        Err(_) => {
            println!("An error occurred while attempting to open the file");
            std::process::exit(1);
        }
    };

    let file = io::BufReader::new(f);
    for line in file.lines() {
        let mut parts = line.as_ref().unwrap().split_whitespace();
        price = match parts.next().unwrap().parse() {
            Ok(n) => n,
            Err(_) => 0,
        };
        num_tickets = match parts.next().unwrap().parse() {
            Ok(n) => n,
            Err(_) => 0,
        };
        total_tickets += num_tickets;
        total_sales += price * num_tickets;
    }

    println!("Total tickets sold: {}", total_tickets);
    println!("Total sales: ${:.2}", total_sales as f32);

}
