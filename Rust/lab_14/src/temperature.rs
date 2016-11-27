
pub enum TempScale {
    C,
    F,
    K,
}

pub struct Temperature {
    temp: f64,
}

impl Temperature {
    pub fn new() -> Temperature {
        Temperature { temp: 0.0 }
    }
    pub fn set_kelvin(&mut self, t: f64) {
        self.temp = t;
    }
    pub fn set_celcius(&mut self, t: f64) {
        self.temp = t + 273.15;
    }
    pub fn set_fahrenheit(&mut self, t: f64) {
        self.temp = ((5.0 / 9.0) * (t - 32.0)) + 273.15;
    }
    pub fn get(&self, scale: TempScale) -> f64 {
        match scale {
            TempScale::K => self.temp,
            TempScale::C => self.temp - 273.15,
            TempScale::F => ((self.temp - 273.15) * 1.8) + 32.0,
        }
    }
}
