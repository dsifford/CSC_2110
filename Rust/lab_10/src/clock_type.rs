
pub struct Clock {
    hr: u32,
    min: u32,
    sec: u32,
}

impl Clock {
    pub fn new(hr: u32, min: u32, sec: u32) -> Clock {
        Clock {
            hr: hr,
            min: min,
            sec: sec,
        }
    }
    pub fn set_time(&mut self, hr: u32, min: u32, sec: u32) {
        self.hr = hr;
        self.min = min;
        self.sec = sec;
    }
    pub fn set_hours(&mut self, hr: u32) {
        self.hr = hr;
    }
    pub fn set_minutes(&mut self, min: u32) {
        self.min = min;
    }
    pub fn set_seconds(&mut self, sec: u32) {
        self.sec = sec;
    }
    pub fn get_time(&self) -> (u32, u32, u32) {
        (self.hr, self.min, self.sec)
    }
    pub fn get_hours(&self) -> u32 {
        self.hr
    }
    pub fn get_minutes(&self) -> u32 {
        self.min
    }
    pub fn get_seconds(&self) -> u32 {
        self.sec
    }
    pub fn print_time(&self) {
        println!("{:02}:{:02}:{:02}", self.hr, self.min, self.sec);
    }
    pub fn increment_seconds(&mut self) {
        if self.sec == 59 {
            self.sec = 0;
            self.increment_minutes();
            return;
        }
        self.sec += 1;
    }
    pub fn increment_minutes(&mut self) {
        if self.min == 59 {
            self.min = 0;
            self.increment_hours();
            return;
        }
        self.min += 1;
    }
    pub fn increment_hours(&mut self) {
        if self.hr == 23 {
            self.hr = 0;
            return;
        }
        self.hr += 1;
    }
}
