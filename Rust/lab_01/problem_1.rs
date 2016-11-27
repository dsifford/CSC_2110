use std::io;

fn main() {

    println!("Enter time in seconds: ");
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    let mut secs: i32 = input.trim().parse().expect("Invalid input");
    let mut mins: i32 = 0;
    let mut hours: i32 = 0;
    
    while secs >= 60 {
        mins = mins + 1;
        secs = secs - 60;
    }
    
    while mins >= 60 {
        hours = hours + 1;
        mins = mins - 60;
    }
    
    println!("The elapsed time is {:2}:{:2}:{:2}", hours, mins, secs);
}
