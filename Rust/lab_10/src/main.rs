// Implement the "class" ClockType

mod clock_type;
use clock_type::*;

fn main() {
    let mut c = Clock::new(6, 7, 8);
    assert_eq!(c.get_hours(), 6);
    assert_eq!(c.get_minutes(), 7);
    assert_eq!(c.get_seconds(), 8);

    c.set_hours(1);
    c.set_minutes(2);
    c.set_seconds(3);
    assert_eq!(c.get_hours(), 1);
    assert_eq!(c.get_minutes(), 2);
    assert_eq!(c.get_seconds(), 3);

    c.increment_hours();
    c.increment_minutes();
    c.increment_seconds();
    assert_eq!(c.get_hours(), 2);
    assert_eq!(c.get_minutes(), 3);
    assert_eq!(c.get_seconds(), 4);

    c.set_time(23, 59, 59);
    c.increment_seconds();
    let (hours, mins, secs) = c.get_time();
    assert_eq!(hours, 0);
    assert_eq!(mins, 0);
    assert_eq!(secs, 0);

    println!("Next line should print all zeros for time");
    c.print_time();
}
