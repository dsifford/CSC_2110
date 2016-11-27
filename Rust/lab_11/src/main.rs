// Program that demonstrates the ClockTZ "derived class" for Clock "class"

mod clock_type;
mod ext_clock_type;
use ext_clock_type::*;

fn main() {
    let mut c = ClockTZ::new(5, 30, 12, "UTC");

    let (hr, min, sec) = c.clock.get_time();
    assert_eq!(hr, 5);
    assert_eq!(min, 30);
    assert_eq!(sec, 12);
    assert_eq!(c.get_timezone(), "UTC");

    c.clock.set_time(9, 42, 33);
    assert_eq!(c.clock.get_hours(), 9);
    assert_eq!(c.clock.get_minutes(), 42);
    assert_eq!(c.clock.get_seconds(), 33);

    c.set_timezone("EST");
    assert_eq!(c.get_timezone(), "EST");
}
