// Implementation of "class" dayType

mod day_type;
use day_type::*;

fn main() {
    let mut d = DayType::new();
    assert_eq!(d.get().to_str(), "Sunday");
    assert_eq!(d.tomorrow().to_str(), "Monday");
    assert_eq!(d.yesterday().to_str(), "Saturday");
    assert_eq!(d.add_days(7).to_str(), "Sunday");
    assert_eq!(d.add_days(18).to_str(), "Thursday");
    assert_eq!(d.add_days(428).to_str(), "Monday");
    assert_eq!(d.get().to_str(), "Sunday");

    d.set(Day::THURS);
    assert_eq!(d.get().to_str(), "Thursday");
    assert_eq!(d.tomorrow().to_str(), "Friday");
    assert_eq!(d.yesterday().to_str(), "Wednesday");

    d.set(Day::SAT);
    assert_eq!(d.get().to_str(), "Saturday");
    assert_eq!(d.tomorrow().to_str(), "Sunday");
    assert_eq!(d.yesterday().to_str(), "Friday");
    assert_eq!(d.add_days(1529).to_str(), "Tuesday");

    println!("Next line should be 'Saturday'");
    d.get().print();
}
