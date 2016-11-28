
pub struct Money {
    dollars: i32,
    cents: i32,
}

impl Money {
    pub fn new(d: i32, c: i32) -> Money {
        Money {
            dollars: d,
            cents: c,
        }
    }
    pub fn get_dollars(&self) -> i32 {
        self.dollars
    }
    pub fn get_cents(&self) -> i32 {
        self.cents
    }
    pub fn set_dollars(&mut self, d: i32) {
        self.dollars = d;
    }
    pub fn set_cents(&mut self, c: i32) {
        self.cents = c;
    }
    pub fn value(&self) -> f64 {
        let dollars = self.dollars as f64;
        let cents = (self.cents as f64) / 100.0;
        dollars + cents
    }
}
