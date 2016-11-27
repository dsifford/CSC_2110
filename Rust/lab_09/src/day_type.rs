pub trait IsDayType {
    fn set(&mut self, day: Day);
    fn get(&self) -> Day;
    fn tomorrow(&self) -> Day;
    fn yesterday(&self) -> Day;
    fn add_days(&self, n: u32) -> Day;
}

pub enum Day {
    SUN,
    MON,
    TUES,
    WED,
    THURS,
    FRI,
    SAT,
}

impl Day {
    pub fn print(self) {
        match self {
            Day::SUN => println!("Sunday"),
            Day::MON => println!("Monday"),
            Day::TUES => println!("Tuesday"),
            Day::WED => println!("Wednesday"),
            Day::THURS => println!("Thursday"),
            Day::FRI => println!("Friday"),
            Day::SAT => println!("Saturday"),
        }
    }
    pub fn to_str<'a>(self) -> &'a str {
        match self {
            Day::SUN => "Sunday",
            Day::MON => "Monday",
            Day::TUES => "Tuesday",
            Day::WED => "Wednesday",
            Day::THURS => "Thursday",
            Day::FRI => "Friday",
            Day::SAT => "Saturday",
        }
    }
}

pub struct DayType {
    day: Day,
}

impl DayType {
    pub fn new() -> DayType {
        DayType { day: Day::SUN }
    }
}

impl IsDayType for DayType {
    fn set(&mut self, day: Day) {
        self.day = day;
    }
    fn get(&self) -> Day {
        match self.day {
            Day::SUN => Day::SUN,
            Day::MON => Day::MON,
            Day::TUES => Day::TUES,
            Day::WED => Day::WED,
            Day::THURS => Day::THURS,
            Day::FRI => Day::FRI,
            Day::SAT => Day::SAT,
        }
    }
    fn tomorrow(&self) -> Day {
        match self.day {
            Day::SUN => Day::MON,
            Day::MON => Day::TUES,
            Day::TUES => Day::WED,
            Day::WED => Day::THURS,
            Day::THURS => Day::FRI,
            Day::FRI => Day::SAT,
            Day::SAT => Day::SUN,
        }
    }
    fn yesterday(&self) -> Day {
        match self.day {
            Day::SUN => Day::SAT,
            Day::MON => Day::SUN,
            Day::TUES => Day::MON,
            Day::WED => Day::TUES,
            Day::THURS => Day::WED,
            Day::FRI => Day::THURS,
            Day::SAT => Day::FRI,
        }
    }
    fn add_days(&self, n: u32) -> Day {
        let mut today = match self.day {
            Day::SUN => 0,
            Day::MON => 1,
            Day::TUES => 2,
            Day::WED => 3,
            Day::THURS => 4,
            Day::FRI => 5,
            Day::SAT => 6,
        };
        for _ in 0..n {
            if today == 6 {
                today = 0;
                continue;
            }
            today += 1;
        }
        match today {
            0 => Day::SUN,
            1 => Day::MON,
            2 => Day::TUES,
            3 => Day::WED,
            4 => Day::THURS,
            5 => Day::FRI,
            _ => Day::SAT,
        }
    }
}
