// Create and test a Money "class"

mod money;
use money::*;

fn main() {
    let mut m = Money::new(12, 50);

    assert_eq!(m.get_dollars(), 12);
    assert_eq!(m.get_cents(), 50);
    assert_eq!(m.value(), 12.50);

    m.set_dollars(41);
    m.set_cents(98);

    assert_eq!(m.value(), 41.98);
}
