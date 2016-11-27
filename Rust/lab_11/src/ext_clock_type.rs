
use clock_type::*;

pub struct ClockTZ<'a> {
    pub clock: Clock,
    tz: &'a str,
}

impl<'a> ClockTZ<'a> {
    pub fn set_timezone(&mut self, tz: &'a str) {
        self.tz = tz;
    }
    pub fn get_timezone(&self) -> &str {
        self.tz
    }
    pub fn new(hr: u32, min: u32, sec: u32, tz: &'a str) -> ClockTZ {
        ClockTZ {
            clock: Clock::new(hr, min, sec),
            tz: tz,
        }
    }
}
